#include "xbyak/xbyak.h"
#include "mh_defs.hpp"

#include "game_exe_interface.hpp"
#include "doomoffs.hpp"
#include "meathook.h"
#include "cmdsystem.hpp"
#include "idtypeinfo.hpp"
#include "eventdef.hpp"
#include "scanner_core.hpp"
#include "idLib.hpp"
#include "idStr.hpp"
#include "clipboard_helpers.hpp"
#include <vector>
#include "errorhandling_hooks.hpp"
#include "gameapi.hpp"
#include "idmath.hpp"
#include "memscan.hpp"
#include "mh_memmanip_cmds.hpp"
#include "snaphakalgo.hpp"
#include <string.h>
#include "mh_guirender.hpp"
#include "mh_editor_mode.hpp"
#include <string>
#include "mh_staticmodel.hpp"
extern void cmd_optimize(idCmdArgs* args);
void test_persistent_text(idCmdArgs* args) {

	add_persistent_text(400, 400, ~0u, 3.0f, args->argv[1]);

}
static mh_fieldcached_t<idVec3> g_field_hphys_bodylinear{};

void test_physics_op(idCmdArgs* args) {
	void* looktarg = get_player_look_target();

	if (!looktarg)
		return;

	void* ephys = get_entity_physics_obj(looktarg);

	if (!ephys) {
		idLib::Printf("Couldnt get phys obj\n");
		return;
	}

	/*if(!is_subclass_of_rttisig(ephys, RTTISIG(".?AVidHavokPhysics_Base@@"))) {
		idLib::Printf("Not using havokphysics\n");
		return;
	}*/
	idVec3* linvel = g_field_hphys_bodylinear(ephys, "idHavokPhysics_Base", "bodyOrigin");

	linvel->z += atof(args->argv[1]);

}

static void meathook_cpuinfo(idCmdArgs* args) {
	char cpuinfo_buffer[4096];
	g_shalgo.m_print_cpu_info(&g_shalgo, cpuinfo_buffer, 4096);

	set_clipboard_data(cpuinfo_buffer);
	idLib::Printf(cpuinfo_buffer);
}

static void image_fill(idCmdArgs* args) {
	if (args->argc < 5) {
		idLib::Printf("nope\n");
		return;
	}
	const char* imagename = args->argv[1];
	unsigned width = atoi(args->argv[2]);
	unsigned height = atoi(args->argv[3]);

	unsigned fillvalue = atoi(args->argv[4]);


	char* tmparray = new char[width * height * 4];

	memset(tmparray, fillvalue, width * height * 4);


	upload_2d_imagedata(imagename, tmparray, width, height);

	delete[] tmparray;


}
/*
	trying to figure out what fspec char '8' does
*/
static void locate_eventdef_type(idCmdArgs* args) {

	if (args->argc < 2)
		return;

	unsigned srchchar = args->argv[1][0];

	auto evif = idEventDefInterfaceLocal::Singleton();

	unsigned evcount = evif->GetNumEvents();

	for (unsigned i = 0; i < evcount; ++i) {
		idEventDef* even = evif->GetEventForNum(i);

		const char* fspec = even->formatspec;

		for (unsigned i = 0; fspec[i]; ++i) {
			if (fspec[i] == srchchar) {
				idLib::Printf("Got a hit for char, arg in event %s\n", even->name);
			}
		}

		if (even->returnType == srchchar) {
			idLib::Printf("Got a hit for char, rettype for event %s\n", even->name);
		}
	}
}

static void mh_dump_bmodel(idCmdArgs* args) {
	if (args->argc < 4)
		return;

	void* smodel = locate_resourcelist_member("idStaticModel", args->argv[1]);
	if (!smodel) {
		idLib::Printf("Couldn't find %s\n", args->argv[1]);
		return;
	}

	call_as<void>(descan::g_idStaticModel_WriteStaticBModel, smodel, args->argv[2], 0, args->argv[3][0] != '0');

}
#include "objfiles/objloader.h"

static constexpr __int64 VertexSizeFromMask(unsigned int a1)
{
	return (a1 & 4)
		+ ((a1 >> 2) & 4)
		+ ((a1 >> 2) & 8)
		+ ((a1 >> 1) & 4)
		+ ((a1 >> 4) & 4)
		+ ((a1 >> 9) & 4)
		+ ((a1 >> 7) & 8)
		+ ((a1 >> 15) & 4)
		+ ((a1 >> 12) & 8)
		+ (HIWORD(a1) & 4)
		+ ((a1 >> 13) & 8)
		+ ((a1 >> 17) & 4)
		+ ((a1 & 1) != 0 ? 0xC : 0)
		+ ((a1 & 0x100000) != 0 ? 3 : 0)
		+ ((a1 & 0x200000) != 0 ? 3 : 0)
		+ ((a1 & 0x400000) != 0 ? 6 : 0)
		+ ((a1 & 0x800000) != 0 ? 6 : 0)
		+ ((a1 & 0x1000) != 0 ? 0xC : 0)
		+ 4 * (a1 & 2);
}


static constexpr unsigned default_size = VertexSizeFromMask(0x1801F);
static void mh_test_genbmodel(idCmdArgs* args) {

	auto sm = idStaticModelPtr::CreateNew();
	idDrawVert* resvert = nullptr;
	unsigned short* residx = nullptr;

	sp::ObjLoader obj;
	obj.load(args->argv[1]);
	unsigned numverts = obj.getVertCount();
	unsigned numind = obj.getIndexCount();

#if 1
	sm.Setup_Singlesurface_hack(numverts, numind, &resvert, &residx);

	memset(resvert, 0, sizeof(idDrawVert) * numverts);
	memset(residx, 0, sizeof(residx[0]) * numind);
	
	const unsigned int* idxs = obj.getFaces();

	for (unsigned i = 0; i < numind; ++i) {
		residx[i] = idxs[i] ;
	}


	for (unsigned i = 0; i < numverts; ++i) {
		idDrawVert& vrt = resvert[i];
		idVec3 norm = *(const idVec3*)(&obj.getNormals()[i * 3]);

		vrt.normal[0] = norm.x;
		vrt.normal[1] = norm.y;
		vrt.normal[2] = norm.z;

		
	const float* st = &obj.getTexCoords(0)[i * 2];

		vrt.materialUV.x = st[0];
		vrt.materialUV.y = st[1];


		idVec3 pos = ((const idVec3*)obj.getPositions())[i];

		vrt.pos = pos;


	}

#else
	call_as<void>(descan::g_idStaticModel_MakeTexturedCube, sm.m_ptr, 10.0f, 10.0f);
#endif
	sm.make_standard_tris();
	sm.Finalize_geo();

	sm.Write(args->argv[2],true);




}
void install_miscndev_cmds() {

	idCmd::register_command("mh_cpuinfo", meathook_cpuinfo, "takes no args, dumps info about your cpu for dev purposes");
	//idCmd::register_command("image_fill", image_fill, "test");
	idCmd::register_command("mh_optimize", cmd_optimize, "Patches the engine to make stuff run faster. do not use online, might result in slightly different floating point results (probably not though)");
	idCmd::register_command("mh_locate_fspec_char_uses", locate_eventdef_type, "<char> Finds all usages of a provided char in event formatspecs/rettypes");
	idCmd::register_command("mh_dump_bmodel", mh_dump_bmodel, "<name> <output path> <skip_compression> Finds a staticmodel and then executes writestaticbmodel to the provided path");
	idCmd::register_command("mh_test_genbmodel", mh_test_genbmodel, "<obj path> <output path> (YOU MUST BE ON V1 WITH RANDOMBASEADDR FLAG OFF ON EXE FOR THIS RIGHT NOW) generate bmodel in standalone resource from .obj");
}
