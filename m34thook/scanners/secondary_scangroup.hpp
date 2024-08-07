#pragma once

#if !defined(MH_ETERNAL_V6)
//"Couldn't open"
using locate_idmapfilelocal_write_body = memscanner_t<
	scanbytes<0x48, 0x8b, 0xd6, 0x48, 0x8d, 0xd>,
	riprel32_data_equals<  0x43, 0x6F, 0x75, 0x6C, 0x64, 0x6E, 0x27, 0x74, 0x20, 0x6F,
	0x70, 0x65, 0x6E, 0x20, 0x25, 0x73, 0x00>,
	scanbytes<0xE8>,
	match_riprel32_to<&descan::g_idlib_warning>
>;
#else
//v1=140A757A7 
//v6=140BAB957 
using locate_idmapfilelocal_write_body = memscanner_t<
	scanbytes<0x48, 0x8B, 0x75>,
	skip<1>, //skip ptr offset "0x68", might change later, but is same between v1 and v6
	scanbytes<0x48, 0x8D, 0x0D>,
	riprel32_data_equals<  0x77, 0x72, 0x69, 0x74, 0x69, 0x6E, 0x67, 0x20, 0x25, 0x73,
	0x2E, 0x2E, 0x2E, 0x0A, 0x00> //writing %s...\n
>;
#endif


#if 0
using locate_idfilecompressed_getfile = memscanner_t<
	scanbytes<0x48, 0x8b, 0xc8, 0x48, 0x8b, 0xd8, 0x48, 0x8b, 0x10, 0xff, 0x52, 0x68, 0x48, 0x8B, 0xD>,
	match_riprel32_to<&descan::g_doom_memorysystem>,
	scanbytes<0x45, 0x33, 0xc9,
	0xc7, 0x44, 0x24, 0x28, 0x2, 0x0, 0x0, 0x0, 0x48, 0x8b, 0xf0, 0xc7, 0x44, 0x24, 0x20, 0x10, 0x0, 0x0, 0x0, 0x4c, 0x8d, 0x70, 0x1, 0x4c, 0x8b, 0x11, 0x45>>;
//	0x8d, 0x41, 0xd, 0x49, 0x8b, 0xd6, 0x41, 0xff, 0x52, 0x20, 0x4c, 0x8b, 0xb, 0x4c, 0x8b, 0xc6, 0x48, 0x8b, 0xd0, 0x48, 0x8b, 0xcb, 0x48, 0x8b, 0xf8, 0x41, 0xff, 0x51, 0x30, 0x44, 0x88, 0x2c, 0x37, 0x49, 0x8b, 0xd4>>;
#else
#if !defined(MH_ETERNAL_V6)
using locate_idfilecompressed_getfile = memscanner_t<
	scanbytes<0x48, 0x8B, 0x53, 0x08, 0x48, 0x8D, 0x0D>,
	riprel32_data_equals<  0x69, 0x64, 0x46, 0x69, 0x6C, 0x65, 0x52, 0x65, 0x73, 0x6F,
	0x75, 0x72, 0x63, 0x65, 0x43, 0x6F, 0x6D, 0x70, 0x72, 0x65,
	0x73, 0x73, 0x65, 0x64, 0x3A, 0x3A, 0x47, 0x65, 0x74, 0x46,
	0x69, 0x6C, 0x65, 0x3A, 0x20, 0x43, 0x6F, 0x75, 0x6C, 0x64,
	0x20, 0x6E, 0x6F, 0x74, 0x20, 0x64, 0x65, 0x63, 0x6F, 0x6D,
	0x70, 0x72, 0x65, 0x73, 0x73, 0x20, 0x74, 0x65, 0x78, 0x74,
	0x20, 0x66, 0x6F, 0x72, 0x20, 0x25, 0x73, 0x00>>;
#else
using locate_idfilecompressed_getfile = memscanner_t<
	scanbytes<0x48, 0x8D, 0x0D>,
	riprel32_data_equals<  0x69, 0x64, 0x46, 0x69, 0x6C, 0x65, 0x52, 0x65, 0x73, 0x6F,
	0x75, 0x72, 0x63, 0x65, 0x43, 0x6F, 0x6D, 0x70, 0x72, 0x65,
	0x73, 0x73, 0x65, 0x64, 0x3A, 0x3A, 0x47, 0x65, 0x74, 0x46,
	0x69, 0x6C, 0x65, 0x3A, 0x20, 0x43, 0x6F, 0x75, 0x6C, 0x64,
	0x20, 0x6E, 0x6F, 0x74, 0x20, 0x64, 0x65, 0x63, 0x6F, 0x6D,
	0x70, 0x72, 0x65, 0x73, 0x73, 0x20, 0x74, 0x65, 0x78, 0x74,
	0x20, 0x66, 0x6F, 0x72, 0x20, 0x25, 0x73, 0x00>>;
#endif
#endif

using locate_idlib_fatalerror_body = memscanner_t<
	scanbytes<0x4c, 0x8b, 0x44, 0x24, 0x30, 0x4c, 0x8d, 0x4c, 0x24, 0x38, 0xba, 0x8, 0x0, 0x0, 0x0, 0x8d, 0x4a, 0xf9, 0xe8>,
	match_riprel32_to<&descan::g_idlib_vprintf>
>;

using locate_idlib_error_body = memscanner_t<
	scanbytes<0x4c, 0x8b, 0x44, 0x24, 0x30, 0x4c, 0x8d, 0x4c, 0x24, 0x38, 0xba, 0x7, 0x0, 0x0, 0x0, 0x8d, 0x4a, 0xfa, 0xe8>,
	match_riprel32_to<&descan::g_idlib_vprintf>
>;
//v1=140B7B9AF
using locate_find_next_ent_with_class = memscanner_t<
	/*scanbytes<0x49, 0x8D, 0x8E >,
	skip<4>,
	scanbytes<0xE8>,
	skip<4>,*/

	scanbytes<0x4C, 0x8D, 0x05>,
	riprel32_data_equals<  0x69, 0x64, 0x49, 0x6E, 0x66, 0x6F, 0x4C, 0x65, 0x76, 0x65,
	0x6C, 0x46, 0x61, 0x64, 0x65, 0x49, 0x6E, 0x00>, //idInfoLevelFadeIn
	scanbytes<0x48, 0x8b, 0xd7, 0x48, 0x8b, 0xce, 0xe8>>;

//v1=1407CE210 
//nth call = 2
using locate_idImage_SubImageUpload = memscanner_t<
	scanbytes<0x48, 0x8D, 0x15>,
	riprel32_data_equals<  0x5F, 0x62, 0x6C, 0x61, 0x63, 0x6B, 0x53, 0x74, 0x6F, 0x72,
	0x61, 0x67, 0x65, 0x00>>; //_blackStorage

  //14059D13D
  //the string lea could just be used, but prefixing the leas with some actual byte comparisons is more performant
using locate_idRenderModelGui_AllocTris = memscanner_t<
	scanbytes<0x48, 0x8b, 0x1, 0xff, 0x90>, skip<1>, scanbytes<0x0, 0x0, 0x0, 0x48, 0x8b, 0xe8, 0x83, 0x78>,
	skip<1>,
	scanbytes<0x2, 0x75>,
	skip<1>, //0x14 in v1 and v6, but lets be careful
	scanbytes<0x48, 0x8D, 0x0D >, //idRenderModelGui::AllocTris: Trying to alloc triangles from the 
	riprel32_data_equals<  0x69, 0x64, 0x52, 0x65, 0x6E, 0x64, 0x65, 0x72, 0x4D, 0x6F,
	0x64, 0x65, 0x6C, 0x47, 0x75, 0x69, 0x3A, 0x3A, 0x41, 0x6C,
	0x6C, 0x6F, 0x63, 0x54, 0x72, 0x69, 0x73, 0x3A, 0x20, 0x54,
	0x72, 0x79, 0x69, 0x6E, 0x67, 0x20, 0x74, 0x6F, 0x20, 0x61,
	0x6C, 0x6C, 0x6F, 0x63, 0x20, 0x74, 0x72, 0x69, 0x61, 0x6E,
	0x67, 0x6C, 0x65, 0x73, 0x20, 0x66, 0x72, 0x6F, 0x6D, 0x20,
	0x74, 0x68, 0x65, 0x20, 0x67, 0x6C, 0x6F, 0x62, 0x61, 0x6C,
	0x20, 0x70, 0x6F, 0x6F, 0x6C, 0x20, 0x77, 0x68, 0x69, 0x6C,
	0x65, 0x20, 0x74, 0x68, 0x65, 0x20, 0x62, 0x61, 0x74, 0x63,
	0x68, 0x20, 0x72, 0x65, 0x6E, 0x64, 0x65, 0x72, 0x65, 0x72,
	0x20, 0x69, 0x73, 0x20, 0x72, 0x75, 0x6E, 0x6E, 0x69, 0x6E,
	0x67, 0x2E, 0x20, 0x57, 0x61, 0x69, 0x74, 0x69, 0x6E, 0x67,
	0x20, 0x66, 0x6F, 0x72, 0x20, 0x6A, 0x6F, 0x62, 0x20, 0x63,
	0x6F, 0x6D, 0x70, 0x6C, 0x65, 0x74, 0x69, 0x6F, 0x6E, 0x20,
	0x66, 0x69, 0x72, 0x73, 0x74, 0x2E, 0x00>>;
//v1 = 1408D90C0
using locate_resourcelist_add = memscanner_t<
	scanbytes<0xb2, 0x1, 0x48, 0x8b, 0xc8, 0x4c, 0x8b, 0xf0, 0x33, 0xed, 0xe8>,
	skip<3>,
	scanbytes<0xFF, 0x84, 0xc0, 0xb9, 0x1, 0x0, 0x0, 0x0, 0xf, 0x45, 0xe9, 0x48, 0x83, 0x7f>, skip<1>, scanbytes<0x0>,
	match_within_variable_distance<8,
	memscanner_t<scanbytes<0x48, 0x8b, 0x4f>, skip<1>, scanbytes<0x48, 0x8d, 0x15>> //this jmp is short in v1, long in v6
	>,
	riprel32_data_equals<  0x75, 0x6E, 0x6E, 0x61, 0x6D, 0x65, 0x64, 0x00> //"unnamed"
>;
//v1=1407C0706
using locate_idimagemanager_scratchimage = memscanner_t<
	scanbytes<0x48, 0x83, 0xc4>, skip<1>, scanbytes<0x5f, 0xc3, 0x48, 0x8d, 0xd>,
	riprel32_data_equals<  0x69, 0x64, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x4D, 0x61, 0x6E,
	0x61, 0x67, 0x65, 0x72, 0x3A, 0x3A, 0x53, 0x63, 0x72, 0x61,
	0x74, 0x63, 0x68, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x20, 0x63,
	0x61, 0x6C, 0x6C, 0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 0x68,
	0x20, 0x65, 0x6D, 0x70, 0x74, 0x79, 0x20, 0x6E, 0x61, 0x6D,
	0x65, 0x00>>;

//hopefully this is enough
//we need this to locate the offset for vertexcolor
using locate_idcolor_packcolor = memscanner_t<
	scanbytes<0xf3, 0xf, 0x10, 0x1, 0x41, 0xba, 0xff, 0x0, 0x0, 0x0, 0xf3, 0xf, 0x10, 0xd>,
	riprel32_data_equals<  0x00, 0x00, 0x7F, 0x43>,
	scanbytes<0xf3, 0xf, 0x59, 0xc1, 0xf3, 0xf, 0x2c, 0xd0, 0x85, 0xd2, 0x79>>;

//v1=1403F33A2
using locate_idstaticmodel_finish = memscanner_t<
	scanbytes<0x41, 0xb1, 0x1, 0x48, 0x8d, 0x8d>,
	skip<2>,
	scanbytes<0x0, 0x0, 0x45, 0xf, 0xb6, 0xc1, 0x33, 0xd2, 0xe8>,
	skip_and_capture_rva<&descan::g_idRenderModelStatic_FinishStaticModel>,
	scanbytes<0x8B>,
	masked_eq_byte<0xF0, 0xD0>, //0x8B D7 "mov     edx, edi" on v1, mov edx, esi on v6

	scanbytes<0x48, 0x8D, 0x0D>,
	riprel32_data_equals<  0x25, 0x69, 0x20, 0x74, 0x6F, 0x74, 0x61, 0x6C, 0x20, 0x74,
	0x72, 0x69, 0x61, 0x6E, 0x67, 0x6C, 0x65, 0x73, 0x0A, 0x00>>;




#if !defined(MH_ETERNAL_V6)
using locate_body_of_getlevelmap = memscanner_t<
	scanbytes<0x48, 0x89, 0x74, 0x24, 0x20, 0x48, 0x89, 0x74, 0x24, 0x28, 0x48, 0x8b, 0x1, 0x48, 0x89, 0x74, 0x24, 0x78, 0x48, 0x89, 0xb4, 0x24, 0x80, 0x0, 0x0, 0x0, 0x40, 0x88, 0x74, 0x24, 0x48, 0x48, 0x89, 0x74, 0x24, 0x50, 0x66, 0xc7, 0x44, 0x24, 0x58, 0x0, 0x1, 0x48, 0x89, 0x74, 0x24, 0x68, 0x40, 0x88, 0x74, 0x24, 0x70, 0xff, 0x50, 0x8, 0x84, 0xc0, 0xf, 0xb6, 0x44, 0x24, 0x33, 0x40, 0xf, 0x94, 0xc7>
>;
#else
using locate_getlevelmap_offset = memscanner_t<
	scanbytes<0x48, 0x8b, 0xcb, 0x48, 0x8b, 0x3, 0xFF, 0x90>,
	skip_and_capture_4byte_value<&descan::g_vftbl_offset_getlevelmap>,
	scanbytes<0x4c, 0x8b, 0xe8, 0x48, 0x85, 0xc0, 0x75>,
	skip<1>,//jmp target
	scanbytes<0x48, 0x8D, 0x0D>,
	riprel32_data_equals<  0x43, 0x6F, 0x75, 0x6C, 0x64, 0x20, 0x6E, 0x6F, 0x74, 0x20,
	0x47, 0x65, 0x74, 0x4C, 0x65, 0x76, 0x65, 0x6C, 0x4D, 0x61,
	0x70, 0x00>
>;
#endif
//0014041B2FC
using locate_getentitystate_in_body = memscanner_t<

	scanbytes<0x4c, 0x8b, 0x46, 0x78, 0x41, 0x80, 0x38, 0x0, 0x74>,
	skip<1>,
	scanbytes<0x48, 0x8D, 0x15>,
	riprel32_data_equals<  0x69, 0x6E, 0x68, 0x65, 0x72, 0x69, 0x74, 0x20, 0x3D, 0x20,  //inherit = "%s";
	0x22, 0x25, 0x73, 0x22, 0x3B, 0x0A, 0x00>>;
using locate_sqrt = memscanner_t<scanbytes<0xf2, 0xf, 0x11, 0x44, 0x24, 0x8, 0x48, 0x83, 0xec, 0x58, 0x48, 0xb9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf0, 0x7f, 0xf2, 0xf, 0x11, 0x44, 0x24, 0x68, 0x48, 0x8b, 0x54, 0x24, 0x68, 0x48, 0x8b, 0xc2, 0x48, 0x23, 0xc1, 0x48, 0x3b, 0xc1>>;

using locate_sqrtf = memscanner_t<scanbytes<0xf3, 0xf, 0x11, 0x44, 0x24, 0x8, 0x48, 0x83, 0xec, 0x58, 0xb9, 0x0, 0x0, 0x80, 0x7f, 0xf3, 0xf, 0x11, 0x44, 0x24, 0x68, 0x8b, 0x54, 0x24, 0x68, 0x8b, 0xc2, 0x23, 0xc1, 0x3b, 0xc1>>;

#if !defined(MH_ETERNAL_V6)
//1.0 14056AD03
using locate_atomicstring_set = memscanner_t<scanbytes<0xf, 0xb6, 0x45, 0xb3, 0xf, 0x57, 0xc0, 0x0f, 0x28, 0x0D>,
	riprel32_data_equals<  0x6F, 0x12, 0x43, 0x3E, 0x6F, 0x12, 0xC3, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x42>,
	scanbytes<0x4c, 0x89, 0x6c, 0x24, 0x48, 0x66, 0xf, 0x7f, 0x44, 0x24, 0x50, 0x4c, 0x89, 0x6c, 0x24, 0x60, 0xc7, 0x44, 0x24, 0x68, 0x6f, 0x12, 0xc3, 0x3e, 0xc7, 0x44, 0x24, 0x6c, 0x6f, 0x12, 0x43, 0x3e>>;
#else
//sprint_detached
//should work in all versions
using locate_atomicstring_set = memscanner_t<
	scanbytes<0x48, 0x8D, 0x15>,
	riprel32_data_equals<  0x73, 0x70, 0x72, 0x69, 0x6E, 0x74, 0x5F, 0x64, 0x65, 0x74,
	0x61, 0x63, 0x68, 0x65, 0x64, 0x00>,
	scanbytes<0x48, 0x8D, 0x0D>,
	skip<4>,
	scanbytes<0xE8>
	//last four bytes = riprel to atomstrset
>;
#endif

/*
	in 6.66 - 1406FFCB1 
	in v1 - 14066AE46 
	exact same sequence
	.text:000000014066AE46 66 0F 6E C0                             movd    xmm0, eax
.text:000000014066AE4A F2 0F 59 0D 36 91 F4 01                 mulsd   xmm1, cs:qword_1425B3F88
.text:000000014066AE52 0F 5B C0                                cvtdq2ps xmm0, xmm0
.text:000000014066AE55 F2 0F 58 0D 3B 91 F4 01                 addsd   xmm1, cs:qword_1425B3F98
.text:000000014066AE5D 66 0F 5A D1                             cvtpd2ps xmm2, xmm1
.text:000000014066AE61 F3 0F 11 54 24 28                       movss   dword ptr [rsp+28h], xmm2 ; h
.text:000000014066AE67 F3 0F 10 15 31 9B F0 01                 movss   xmm2, cs:flt_1425749A0 ; x
.text:000000014066AE6F F3 0F 11 44 24 20                       movss   dword ptr [rsp+20h], xmm0 ; w
.text:000000014066AE75 E8 B6 3D F3 FF                          call    _ZN16idRenderModelGui10DrawFilledERK6idVec4ffff
*/
//g_idRenderModelGui__DrawFilled

using locate_idRenderModelGui_DrawFilled = memscanner_t<
	scanbytes<0x66, 0xf, 0x6e, 0xc0, 0xf2, 0xf, 0x59, 0xd>,
	riprel32_data_equals< 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x3F>,
	scanbytes<0xf, 0x5b, 0xc0, 0xf2, 0xf, 0x58, 0xd>,
	riprel32_data_equals< 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x40>,
	scanbytes<0x66, 0xf, 0x5a, 0xd1, 0xf3, 0xf, 0x11, 0x54, 0x24>,
	skip<1>, //skip rsp offset even though its 0x28 in all versions

	scanbytes<0xf3, 0xf, 0x10, 0x15>,
	riprel32_data_equals< 0x00, 0x00, 0x20, 0x41>,
	scanbytes<0xf3, 0xf, 0x11, 0x44, 0x24>,
	//skip rsp offset even though same in all ver
	skip<1>,
	scanbytes<0xe8>>; //last 4 bytes = rva to drawfilled

//honestly i could have done this with a much simpler scanner but i like the challenge
using locate_idRenderModelGui_DrawString = memscanner_t <

	scanbytes<0x89, 0x4c, 0x24, 0x28, 0x41, 0x8b, 0xc0, 0x41, 0x2b, 0xc1, 0x48, 0x8d, 0x8d>,

	masked_eq_u32<0xFFFFFF00, 0x100>, //0x100 in v1, 0x110 in v6.66
	scanbytes<0x89, 0x44, 0x24, 0x20, 0xe8>,
	match_riprel32_to<&descan::g_va_va>,
	scanbytes<0xf3, 0x44, 0xf, 0x11, 0x64, 0x24, 0x30, 0x4c, 0x8b, 0xc8, 0xc6, 0x44, 0x24, 0x28, 0x0, 0x41, 0xf, 0x28, 0xd0, 0x41, 0xf, 0x28, 0xcd>,
	masked_eq_byte<0x48, 0x48>,
	scanbytes<0x89>,
	masked_eq_byte<0x5F, 0x5C>,
	scanbytes<0x24, 0x20>,
	masked_eq_byte<0b11111110, 0x48>,
	scanbytes<0x8B>,
	masked_eq_byte<0xF8, 0xC8>,
	scanbytes<0xE8>
	//last 4 = rva to drawstring
	>;

/*

v1 = 1404412DF
v6.66 = 140491C1F
no changes between them lol, even the jmp displ is the same...
*/
//we cant extract this one from DrawString because it gets inlined into its body in v6.66
using locate_idRenderModelGui_DrawChar = memscanner_t<
	scanbytes<0x48, 0x8b, 0x84, 0x24, 0x78, 0x40, 0x0, 0x0, 0x80, 0x38, 0x2e, 0x74>,
	skip<1>, //skip the jmp
	scanbytes<0xf3, 0xf, 0x59, 0xd>,
	riprel32_data_equals<  0x00, 0x00, 0x40, 0x40>,

	scanbytes<0xf3, 0xf, 0x59, 0xd>,
	riprel32_data_equals<  0x00, 0x00, 0x00, 0x3E>,
	//now we're at v1 1404412FC , v6.66 140491C3C
	//todo:this could definitely be shortened... we ought to be pretty certain right now and could just use mh_disassembler 

	scanbytes<0x41, 0xb9, 0x2e, 0x0, 0x0, 0x0, 0x48, 0x8b, 0x8f, 0xd8, 0x0, 0x0, 0x0, 0x66, 0xf, 0x6e, 0xc6, 0xf, 0x5b, 0xc0, 0x66, 0x41, 0xf, 0x6e, 0xfd, 0xf3, 0xf, 0x5c, 0xc1, 0xf3, 0x44, 0xf, 0x11, 0x4c, 0x24, 0x20, 0xf, 0x5b, 0xff, 0xf3, 0xf, 0x2c, 0xc0, 0xf, 0x28, 0xd7, 0x66, 0xf, 0x6e, 0xf0, 0xf, 0x5b, 0xf6, 0xf, 0x28, 0xce, 0xe8>
>;


namespace scanners_phase2 {
#if !defined(MH_ETERNAL_V6)
	BSCANENT(entry_phase2_locate_findclassinfo, &descan::g_idtypeinfo_findclassinfo, scanbehavior_locate_func<scanner_locate_findclassinfo>);
#else
	BSCANENT(entry_phase2_locate_findclassinfo, &descan::g_idtypeinfo_findclassinfo, scanbehavior_locate_csrel_after<scanner_locate_findclassinfo>);
#endif
	BSCANENT(entry_phase2_locate_idfilecompressed_getfile, &descan::g_idfilecompressed_getfile, scanbehavior_locate_func<locate_idfilecompressed_getfile>);

	BSCANENT(entry_phase2_locate_resourcelist_for_classname, &descan::g_resourcelist_for_classname, scanbehavior_locate_csrel_after<scanner_locate_resourcelist_for_classname>);

	BSCANENT(locate_idmapfilelocal_write_body_entry, &descan::g_idmapfile_write, scanbehavior_locate_func<locate_idmapfilelocal_write_body>);

	BSCANENT(locate_findenuminfo_entry, &descan::g_idtypeinfo_findenuminfo, scanbehavior_locate_csrel_after<scanner_locate_findenuminfo>);
	BSCANENT(locate_idlib_fatalerror_entry, &descan::g_idlib_fatalerror, scanbehavior_locate_func<locate_idlib_fatalerror_body>);


	BSCANENT(locate_idlib_error_entry, &descan::g_idlib_error, scanbehavior_locate_func<locate_idlib_error_body>);
	BSCANENT(find_next_ent_with_class_locator_entry, &descan::g_find_next_entity_with_class, scanbehavior_locate_csrel_after<locate_find_next_ent_with_class>);

	BSCANENT(locate_subimage_upload_entry, &descan::g_idImage_SubImageUpload, scanbehavior_locate_nth_call_after<2, locate_idImage_SubImageUpload>);
	BSCANENT(locate_rendermodelgui_alloctris_entry, &descan::g_idRenderModelGui_AllocTris, scanbehavior_locate_func_with_start_search<locate_idRenderModelGui_AllocTris>);

	BSCANENT(locate_commonlocal_frame_job_pointer, &descan::g_idCommonLocal_Frame_CallbackPtr, scanbehavior_pointer_scan<&descan::g_idCommonLocal_Frame>);
	BSCANENT(locate_resourcelist_add_entry, &descan::g_idResourceList_Add, scanbehavior_locate_func_with_start_search<locate_resourcelist_add>);

	BSCANENT(locate_idimagemanager_scratchimage_entry, &descan::g_idImageManager_ScratchImage, scanbehavior_locate_func_with_start_search<locate_idimagemanager_scratchimage>);
	//this could be replaced by using first_call_target on the drawfilled result
	BSCANENT(entry_find_idcolor_pack, &descan::g_idcolor_packcolor, scanbehavior_locate_func<locate_idcolor_packcolor>);

	BSCANENT(locate_idstaticmodel_finish_entry, &descan::g_idRenderModelStatic_FinishStaticModel, scanbehavior_identity<&descan::g_idRenderModelStatic_FinishStaticModel,locate_idstaticmodel_finish>);
	BSCANENT(getentitystate_needsoffset, &descan::g_declentitydef_gettextwithinheritance, scanbehavior_locate_func_with_start_search<locate_getentitystate_in_body>);
	#if !defined(MH_ETERNAL_V6)
	BSCANENT(locate_getlevelmap_entry, &descan::g_maplocal_getlevelmap, scanbehavior_locate_func<locate_body_of_getlevelmap>);
#else
	BSCANENT(locate_getlevelmap_entry, nullptr, scanbehavior_locate_func<locate_getlevelmap_offset>);

#endif
#if !defined(MH_ETERNAL_V6)
	BSCANENT(atomicstringset_locator_entry, &descan::g_atomic_string_set, scanbehavior_locate_csrel_preceding<locate_atomicstring_set>);
#else
	BSCANENT(atomicstringset_locator_entry, &descan::g_atomic_string_set, scanbehavior_locate_csrel_after<locate_atomicstring_set>);
#endif
	BSCANENT(sqrtf_locator_entry, &descan::g_sqrtf, scanbehavior_locate_func<locate_sqrtf>);
	BSCANENT(sqrt_locator_entry, &descan::g_sqrt, scanbehavior_locate_func<locate_sqrt>);

	BSCANENT(drawfilled_located_entry, &descan::g_idRenderModelGui__DrawFilled, scanbehavior_locate_csrel_after< locate_idRenderModelGui_DrawFilled>);
	BSCANENT(drawstring_locator_entry, &descan::g_idRenderModelGui__DrawString, scanbehavior_locate_csrel_after< locate_idRenderModelGui_DrawString>);
	BSCANENT(drawchar_locator_entry, &descan::g_idRenderModelGui__DrawChar, scanbehavior_locate_csrel_after< locate_idRenderModelGui_DrawChar>);
	//9 scanners
#define		PAR_SCANGROUP_P2_1 				entry_phase2_locate_findclassinfo, entry_phase2_locate_idfilecompressed_getfile
#define		PAR_SCANGROUP_P2_2				entry_phase2_locate_resourcelist_for_classname,locate_subimage_upload_entry
#define		PAR_SCANGROUP_P2_3				locate_idmapfilelocal_write_body_entry,locate_findenuminfo_entry,drawfilled_located_entry
#define		PAR_SCANGROUP_P2_4				locate_idlib_fatalerror_entry,locate_idlib_error_entry, sqrtf_locator_entry,drawchar_locator_entry

#define		PAR_SCANGROUP_P2_5 				locate_resourcelist_add_entry,find_next_ent_with_class_locator_entry, getentitystate_needsoffset
#define		PAR_SCANGROUP_P2_6				locate_idstaticmodel_finish_entry,locate_commonlocal_frame_job_pointer,drawstring_locator_entry
#define		PAR_SCANGROUP_P2_7				entry_find_idcolor_pack,locate_rendermodelgui_alloctris_entry,atomicstringset_locator_entry
#define		PAR_SCANGROUP_P2_8				locate_idimagemanager_scratchimage_entry,locate_getlevelmap_entry, sqrt_locator_entry
#if defined(DISABLE_PHASE2_PARALLEL_SCANGROUPS)

	using secondary_scangroup_type = scangroup_t<
		PAR_SCANGROUP_P2_1,
		PAR_SCANGROUP_P2_2,
		PAR_SCANGROUP_P2_3,
		PAR_SCANGROUP_P2_4,
		PAR_SCANGROUP_P2_5,
		PAR_SCANGROUP_P2_6,
		PAR_SCANGROUP_P2_7,
		PAR_SCANGROUP_P2_8
	>;

#else
	using secondary_scangroup_type = parallel_scangroup_group_t<
		scangroup_t<PAR_SCANGROUP_P2_1>,
		scangroup_t<PAR_SCANGROUP_P2_2>,
		scangroup_t<PAR_SCANGROUP_P2_3>,
		scangroup_t<PAR_SCANGROUP_P2_4>,
		scangroup_t<PAR_SCANGROUP_P2_5>,
		scangroup_t<PAR_SCANGROUP_P2_6>,
		scangroup_t<PAR_SCANGROUP_P2_7>,
		scangroup_t<PAR_SCANGROUP_P2_8>
	>;

#endif
	static secondary_scangroup_type secondary_scangroup_pass{};
}