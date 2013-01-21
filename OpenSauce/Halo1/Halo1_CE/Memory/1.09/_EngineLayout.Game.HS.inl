/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

//////////////////////////////////////////////////////////////////////////
// Scripting.cpp
#if __EL_INCLUDE_FILE_ID == __EL_GAME_SCRIPTING
	ENGINE_DPTR(t_recorded_animations_data, recorded_animations,		0x64B960, 0x5BD740);
	ENGINE_DPTR(t_hs_syntax_data, hs_syntax,							0x8155B4, 0x6E1474);
	ENGINE_DPTR(t_object_list_header_data, object_list_header,			0x8155A4, 0x6E1464);
	ENGINE_DPTR(t_list_object_reference_data, list_object_reference,	0x8155A8, 0x6E1468);
	ENGINE_DPTR(t_hs_globals_data, hs_globals,							0x8155AC, 0x6E146C);
	ENGINE_DPTR(t_hs_thread_data, hs_threads,							0x8155B0, 0x6E1470);

	FUNC_PTR(HS_UPDATE_HOOK, 0x48CF98, 0x484878);

	static uint32* K_MAX_HS_SYNTAX_NODES_PER_SCENARIO_UPGRADE_ADDRESS_LIST[] = {
		CAST_PTR(uint32*, PLATFORM_VALUE(0x485E9B, 0x47D78B)),
	};

	static uint32* K_TOTAL_SCENARIO_HS_SYNTAX_DATA_UPGRADE_ADDRESS_LIST[] = {
		//CAST_PTR(uint32*, PLATFORM_VALUE(0x485E93, 0x47D783)), // don't modify this one, modify the size check using the address below
		CAST_PTR(uint32*, PLATFORM_VALUE(0x485EEA, 0x47D7DA))
	};

	static byte* K_ADDRESS_OF_SCENARIO_HS_SYNTAX_DATA_SIZE_CHECK = CAST_PTR(byte*, PLATFORM_VALUE(0x485E97, 0x47D787));


//////////////////////////////////////////////////////////////////////////
// ScriptLibrary.cpp
#elif __EL_INCLUDE_FILE_ID == __EL_GAME_SCRIPT_LIBRARY
	FUNC_PTR(HS_MACRO_FUNCTION_PARSE,		0x48A220, 0x481A70);
	FUNC_PTR(HS_COMPILE_AND_EVALUATE,		0x487150, 0x47EA30); // currently unused
	FUNC_PTR(HS_NULL_EVALUATE,				0x4824E0, 0x476140);
	FUNC_PTR(HS_NULL_WITH_PARAMS_EVALUATE,	0x480110, 0x47B8B0);

	//////////////////////////////////////////////////////////////////////////
	// script functions related
	ENGINE_PTR(int32, hs_function_table_count,				0x5F9C10, 0x555690);
	ENGINE_DPTR(hs_function_definition, hs_function_table,	0x624118, 0x599AD8);

	#pragma region hs function table references
	static int16* K_HS_FUNCTION_TABLE_COUNT_REFERENCES_16bit[] = {
		CAST_PTR(int16*, PLATFORM_VALUE(0x486301, 0x47DBF1)),
		CAST_PTR(int16*, PLATFORM_VALUE(0x487034, 0x47E914)),
	};
	static int32* K_HS_FUNCTION_TABLE_COUNT_REFERENCES_32bit[] = {
		CAST_PTR(int32*, PLATFORM_VALUE(0x48661A, 0x47DEFA)),
	};

	// really hs_function_definition***
	static void* K_HS_FUNCTION_TABLE_REFERENCES[] = { // RIVERSIDE MOTHER FUCKER! *techno beat*
#if PLATFORM_IS_USER
		CAST_PTR(void*,0x47D126+3), CAST_PTR(void*,0x47D185+3), CAST_PTR(void*,0x47D1E5+3), CAST_PTR(void*,0x47D236+3), CAST_PTR(void*,0x47D2B6+3), CAST_PTR(void*,0x47D316+3), 
		CAST_PTR(void*,0x47D375+3), CAST_PTR(void*,0x47D3D5+3), CAST_PTR(void*,0x47D435+3), CAST_PTR(void*,0x47D485+3), CAST_PTR(void*,0x47D4D5+3), CAST_PTR(void*,0x47D525+3), 
		CAST_PTR(void*,0x47D585+3), CAST_PTR(void*,0x47D5D5+3), CAST_PTR(void*,0x47D625+3), CAST_PTR(void*,0x47D675+3), CAST_PTR(void*,0x47D6C5+3), CAST_PTR(void*,0x47D716+3), 
		CAST_PTR(void*,0x47D785+3), CAST_PTR(void*,0x47D7D5+3), CAST_PTR(void*,0x47D825+3), CAST_PTR(void*,0x47D875+3), CAST_PTR(void*,0x47D8C6+3), CAST_PTR(void*,0x47D926+3), 
		CAST_PTR(void*,0x47D985+3), CAST_PTR(void*,0x47D9D5+3), CAST_PTR(void*,0x47DA35+3), CAST_PTR(void*,0x47DAC6+3), CAST_PTR(void*,0x47DB55+3), CAST_PTR(void*,0x47DBD5+3), 
		CAST_PTR(void*,0x47DC26+3), CAST_PTR(void*,0x47DCC5+3), CAST_PTR(void*,0x47DD16+3), CAST_PTR(void*,0x47DD76+3), CAST_PTR(void*,0x47DDD6+3), CAST_PTR(void*,0x47DE35+3), 
		CAST_PTR(void*,0x47DE86+3), CAST_PTR(void*,0x47DEF5+3), CAST_PTR(void*,0x47DF75+3), CAST_PTR(void*,0x47E005+3), CAST_PTR(void*,0x47E085+3), CAST_PTR(void*,0x47E0D5+3), 
		CAST_PTR(void*,0x47E155+3), CAST_PTR(void*,0x47E1F5+3), CAST_PTR(void*,0x47E235+3), CAST_PTR(void*,0x47E275+3), CAST_PTR(void*,0x47E2F5+3), CAST_PTR(void*,0x47E335+3), 
		CAST_PTR(void*,0x47E395+3), CAST_PTR(void*,0x47E405+3), CAST_PTR(void*,0x47E466+3), CAST_PTR(void*,0x47E4C6+3), CAST_PTR(void*,0x47E525+3), CAST_PTR(void*,0x47E575+3), 
		CAST_PTR(void*,0x47E5D5+3), CAST_PTR(void*,0x47E665+3), CAST_PTR(void*,0x47E6B5+3), CAST_PTR(void*,0x47E705+3), CAST_PTR(void*,0x47E765+3), CAST_PTR(void*,0x47E7C6+3), 
		CAST_PTR(void*,0x47E825+3), CAST_PTR(void*,0x47E896+3), CAST_PTR(void*,0x47E906+3), CAST_PTR(void*,0x47E976+3), CAST_PTR(void*,0x47E9E6+3), CAST_PTR(void*,0x47EA75+3), 
		CAST_PTR(void*,0x47EB05+3), CAST_PTR(void*,0x47EB75+3), CAST_PTR(void*,0x47EC05+3), CAST_PTR(void*,0x47EC56+3), CAST_PTR(void*,0x47ECB6+3), CAST_PTR(void*,0x47ED15+3), 
		CAST_PTR(void*,0x47ED65+3), CAST_PTR(void*,0x47EDA6+3), CAST_PTR(void*,0x47EE25+3), CAST_PTR(void*,0x47EE75+3), CAST_PTR(void*,0x47EEC5+3), CAST_PTR(void*,0x47EF16+3), 
		CAST_PTR(void*,0x47EF76+3), CAST_PTR(void*,0x47EFD5+3), CAST_PTR(void*,0x47F025+3), CAST_PTR(void*,0x47F0C5+3), CAST_PTR(void*,0x47F105+3), CAST_PTR(void*,0x47F165+3), 
		CAST_PTR(void*,0x47F1C5+3), CAST_PTR(void*,0x47F245+3), CAST_PTR(void*,0x47F2C6+3), CAST_PTR(void*,0x47F346+3), CAST_PTR(void*,0x47F3B6+3), CAST_PTR(void*,0x47F415+3), 
		CAST_PTR(void*,0x47F455+3), CAST_PTR(void*,0x47F4A5+3), CAST_PTR(void*,0x47F515+3), CAST_PTR(void*,0x47F565+3), CAST_PTR(void*,0x47F5F6+3), CAST_PTR(void*,0x47F675+3), 
		CAST_PTR(void*,0x47F6F5+3), CAST_PTR(void*,0x47F785+3), CAST_PTR(void*,0x47F806+3), CAST_PTR(void*,0x47F8A5+3), CAST_PTR(void*,0x47F925+3), CAST_PTR(void*,0x47F9A5+3), 
		CAST_PTR(void*,0x47F9F6+3), CAST_PTR(void*,0x47FA55+3), CAST_PTR(void*,0x47FAA5+3), CAST_PTR(void*,0x47FB25+3), CAST_PTR(void*,0x47FBA5+3), CAST_PTR(void*,0x47FCA5+3), 
		CAST_PTR(void*,0x47FCE5+3), CAST_PTR(void*,0x47FD35+3), CAST_PTR(void*,0x47FD85+3), CAST_PTR(void*,0x47FDC5+3), CAST_PTR(void*,0x47FE05+3), CAST_PTR(void*,0x47FE55+3), 
		CAST_PTR(void*,0x47FEA5+3), CAST_PTR(void*,0x47FEF5+3), CAST_PTR(void*,0x47FF65+3), CAST_PTR(void*,0x47FFA5+3), CAST_PTR(void*,0x47FFF5+3), CAST_PTR(void*,0x480045+3), 
		CAST_PTR(void*,0x480095+3), CAST_PTR(void*,0x480115+3), CAST_PTR(void*,0x480155+3), CAST_PTR(void*,0x4801A5+3), CAST_PTR(void*,0x480235+3), CAST_PTR(void*,0x4802A5+3), 
		CAST_PTR(void*,0x480315+3), CAST_PTR(void*,0x480365+3), CAST_PTR(void*,0x4803B5+3), CAST_PTR(void*,0x480405+3), CAST_PTR(void*,0x480455+3), CAST_PTR(void*,0x480495+3), 
		CAST_PTR(void*,0x4804D5+3), CAST_PTR(void*,0x480515+3), CAST_PTR(void*,0x480555+3), CAST_PTR(void*,0x480595+3), CAST_PTR(void*,0x4805E5+3), CAST_PTR(void*,0x480635+3), 
		CAST_PTR(void*,0x4806C5+3), CAST_PTR(void*,0x480715+3), CAST_PTR(void*,0x480765+3), CAST_PTR(void*,0x4807C5+3), CAST_PTR(void*,0x480815+3), CAST_PTR(void*,0x480865+3), 
		CAST_PTR(void*,0x4808A5+3), CAST_PTR(void*,0x4808F5+3), CAST_PTR(void*,0x480945+3), CAST_PTR(void*,0x480995+3), CAST_PTR(void*,0x4809E5+3), CAST_PTR(void*,0x480A35+3), 
		CAST_PTR(void*,0x480A85+3), CAST_PTR(void*,0x480AC5+3), CAST_PTR(void*,0x480B05+3), CAST_PTR(void*,0x480B55+3), CAST_PTR(void*,0x480B95+3), CAST_PTR(void*,0x480BE5+3), 
		CAST_PTR(void*,0x480C35+3), CAST_PTR(void*,0x480C75+3), CAST_PTR(void*,0x480CF5+3), CAST_PTR(void*,0x480D75+3), CAST_PTR(void*,0x480DC5+3), CAST_PTR(void*,0x480E15+3), 
		CAST_PTR(void*,0x480E65+3), CAST_PTR(void*,0x480EC5+3), CAST_PTR(void*,0x480F15+3), CAST_PTR(void*,0x480F75+3), CAST_PTR(void*,0x480FD5+3), CAST_PTR(void*,0x481035+3), 
		CAST_PTR(void*,0x4810A5+3), CAST_PTR(void*,0x4810E5+3), CAST_PTR(void*,0x481135+3), CAST_PTR(void*,0x481175+3), CAST_PTR(void*,0x4811C5+3), CAST_PTR(void*,0x481225+3), 
		CAST_PTR(void*,0x481285+3), CAST_PTR(void*,0x481305+3), CAST_PTR(void*,0x481385+3), CAST_PTR(void*,0x4813E5+3), CAST_PTR(void*,0x481435+3), CAST_PTR(void*,0x481485+3), 
		CAST_PTR(void*,0x4814E5+3), CAST_PTR(void*,0x481535+3), CAST_PTR(void*,0x481585+3), CAST_PTR(void*,0x4815D5+3), CAST_PTR(void*,0x481626+3), CAST_PTR(void*,0x481686+3), 
		CAST_PTR(void*,0x4816E6+3), CAST_PTR(void*,0x481746+3), CAST_PTR(void*,0x4817A5+3), CAST_PTR(void*,0x481835+3), CAST_PTR(void*,0x481896+3), CAST_PTR(void*,0x481906+3), 
		CAST_PTR(void*,0x481975+3), CAST_PTR(void*,0x4819C6+3), CAST_PTR(void*,0x481A26+3), CAST_PTR(void*,0x481A86+3), CAST_PTR(void*,0x481AE6+3), CAST_PTR(void*,0x481B46+3), 
		CAST_PTR(void*,0x481BE5+3), CAST_PTR(void*,0x481C35+3), CAST_PTR(void*,0x481C85+3), CAST_PTR(void*,0x481CD5+3), CAST_PTR(void*,0x481D25+3), CAST_PTR(void*,0x481D85+3), 
		CAST_PTR(void*,0x481E35+3), CAST_PTR(void*,0x481F15+3), CAST_PTR(void*,0x481F66+3), CAST_PTR(void*,0x4822A5+3), CAST_PTR(void*,0x482325+3), CAST_PTR(void*,0x482375+3), 
		CAST_PTR(void*,0x4823C5+3), CAST_PTR(void*,0x482415+3), CAST_PTR(void*,0x4824F5+3), CAST_PTR(void*,0x482575+3), CAST_PTR(void*,0x4826B5+3), CAST_PTR(void*,0x482715+3), 
		CAST_PTR(void*,0x482765+3), CAST_PTR(void*,0x4827B5+3), CAST_PTR(void*,0x482A25+3), CAST_PTR(void*,0x482AA5+3), CAST_PTR(void*,0x482AF5+3), CAST_PTR(void*,0x482B65+3), 
		CAST_PTR(void*,0x482BE5+3), CAST_PTR(void*,0x482C25+3), CAST_PTR(void*,0x482C75+3), CAST_PTR(void*,0x482CB5+3), CAST_PTR(void*,0x482D05+3), CAST_PTR(void*,0x482D55+3), 
		CAST_PTR(void*,0x482DA5+3), CAST_PTR(void*,0x482DF5+3), CAST_PTR(void*,0x482E35+3), CAST_PTR(void*,0x482EA5+3), CAST_PTR(void*,0x482F15+3), CAST_PTR(void*,0x482F85+3), 
		CAST_PTR(void*,0x483016+3), CAST_PTR(void*,0x483076+3), CAST_PTR(void*,0x4830D5+3), CAST_PTR(void*,0x483175+3), CAST_PTR(void*,0x4831E5+3), CAST_PTR(void*,0x483255+3), 
		CAST_PTR(void*,0x4832B5+3), CAST_PTR(void*,0x483315+3), CAST_PTR(void*,0x483375+3), CAST_PTR(void*,0x4833D5+3), CAST_PTR(void*,0x483425+3), CAST_PTR(void*,0x483496+3), 
		CAST_PTR(void*,0x4834F5+3), CAST_PTR(void*,0x483545+3), CAST_PTR(void*,0x483595+3), CAST_PTR(void*,0x4835D5+3), CAST_PTR(void*,0x483635+3), CAST_PTR(void*,0x4836A6+3), 
		CAST_PTR(void*,0x483736+3), CAST_PTR(void*,0x4837A5+3), CAST_PTR(void*,0x483805+3), CAST_PTR(void*,0x483865+3), CAST_PTR(void*,0x4838C5+3), CAST_PTR(void*,0x483925+3), 
		CAST_PTR(void*,0x483985+3), CAST_PTR(void*,0x4839E5+3), CAST_PTR(void*,0x483A75+3), CAST_PTR(void*,0x483AC5+3), CAST_PTR(void*,0x483B15+3), CAST_PTR(void*,0x483B65+3), 
		CAST_PTR(void*,0x483BC5+3), CAST_PTR(void*,0x483C55+3), CAST_PTR(void*,0x483CA5+3), CAST_PTR(void*,0x483D65+3), CAST_PTR(void*,0x483DB5+3), CAST_PTR(void*,0x483E15+3), 
		CAST_PTR(void*,0x483EB5+3), CAST_PTR(void*,0x483F15+3), CAST_PTR(void*,0x483F85+3), CAST_PTR(void*,0x483FE5+3), CAST_PTR(void*,0x484045+3), CAST_PTR(void*,0x4840B5+3), 
		CAST_PTR(void*,0x484125+3), CAST_PTR(void*,0x484175+3), CAST_PTR(void*,0x484205+3), CAST_PTR(void*,0x484295+3), CAST_PTR(void*,0x4842D5+3), CAST_PTR(void*,0x484325+3), 
		CAST_PTR(void*,0x4843C5+3), CAST_PTR(void*,0x484415+3), CAST_PTR(void*,0x484465+3), CAST_PTR(void*,0x484515+3), CAST_PTR(void*,0x484565+3), CAST_PTR(void*,0x4845E6+3), 
		CAST_PTR(void*,0x484656+3), CAST_PTR(void*,0x4846E5+3), CAST_PTR(void*,0x484756+3), CAST_PTR(void*,0x4847B5+3), CAST_PTR(void*,0x4847F5+3), CAST_PTR(void*,0x484845+3), 
		CAST_PTR(void*,0x484895+3), CAST_PTR(void*,0x4848E5+3), CAST_PTR(void*,0x484935+3), CAST_PTR(void*,0x4849D5+3), CAST_PTR(void*,0x484A25+3), CAST_PTR(void*,0x484AC5+3), 
		CAST_PTR(void*,0x484B15+3), CAST_PTR(void*,0x484B75+3), CAST_PTR(void*,0x484BC5+3), CAST_PTR(void*,0x484C25+3), CAST_PTR(void*,0x484C75+3), CAST_PTR(void*,0x484CC5+3), 
		CAST_PTR(void*,0x484D15+3), CAST_PTR(void*,0x484D65+3), CAST_PTR(void*,0x484DB5+3), CAST_PTR(void*,0x484E15+3), CAST_PTR(void*,0x484E65+3), CAST_PTR(void*,0x484EC5+3), 
		CAST_PTR(void*,0x484F15+3), CAST_PTR(void*,0x484F65+3), CAST_PTR(void*,0x484FB5+3), CAST_PTR(void*,0x485005+3), CAST_PTR(void*,0x485055+3), CAST_PTR(void*,0x4850A5+3), 
		CAST_PTR(void*,0x4850F5+3), CAST_PTR(void*,0x485155+3), CAST_PTR(void*,0x485225+3), CAST_PTR(void*,0x485275+3), CAST_PTR(void*,0x4852B5+3), CAST_PTR(void*,0x485305+3), 
		CAST_PTR(void*,0x485365+3), CAST_PTR(void*,0x4853E5+3), CAST_PTR(void*,0x485465+3), CAST_PTR(void*,0x4854A5+3), CAST_PTR(void*,0x485565+3), CAST_PTR(void*,0x4855A5+3), 
		CAST_PTR(void*,0x485685+3), CAST_PTR(void*,0x485735+3), CAST_PTR(void*,0x4857C5+3), CAST_PTR(void*,0x485905+3), CAST_PTR(void*,0x485AE5+3), CAST_PTR(void*,0x485B65+3), 
		CAST_PTR(void*,0x485BB5+3), CAST_PTR(void*,0x4862E8+0), CAST_PTR(void*,0x486615+0), CAST_PTR(void*,0x486F2F+0), CAST_PTR(void*,0x486FE0+0), CAST_PTR(void*,0x487059+0), 
		CAST_PTR(void*,0x487459+3), CAST_PTR(void*,0x487BA0+3), CAST_PTR(void*,0x487CBB+3), CAST_PTR(void*,0x487DB8+3), CAST_PTR(void*,0x487EA8+3), CAST_PTR(void*,0x488116+3), 
		CAST_PTR(void*,0x4881B6+3), CAST_PTR(void*,0x488246+3), CAST_PTR(void*,0x488875+0), CAST_PTR(void*,0x489692+0), CAST_PTR(void*,0x48A230+3), CAST_PTR(void*,0x48D1D8+0), 
		CAST_PTR(void*,0x48D3D4+0),

#elif PLATFORM_IS_DEDI
		CAST_PTR(void*,0x474C96+3), CAST_PTR(void*,0x474CF5+3), CAST_PTR(void*,0x474D55+3), CAST_PTR(void*,0x474DA6+3), CAST_PTR(void*,0x474E26+3), CAST_PTR(void*,0x474E86+3), 
		CAST_PTR(void*,0x474EE5+3), CAST_PTR(void*,0x474F45+3), CAST_PTR(void*,0x474FA5+3), CAST_PTR(void*,0x474FF5+3), CAST_PTR(void*,0x475045+3), CAST_PTR(void*,0x475095+3), 
		CAST_PTR(void*,0x4750F5+3), CAST_PTR(void*,0x475145+3), CAST_PTR(void*,0x475195+3), CAST_PTR(void*,0x4751E5+3), CAST_PTR(void*,0x475235+3), CAST_PTR(void*,0x475286+3), 
		CAST_PTR(void*,0x4752F5+3), CAST_PTR(void*,0x475345+3), CAST_PTR(void*,0x475395+3), CAST_PTR(void*,0x4753E5+3), CAST_PTR(void*,0x475436+3), CAST_PTR(void*,0x475496+3), 
		CAST_PTR(void*,0x4754F5+3), CAST_PTR(void*,0x475545+3), CAST_PTR(void*,0x4755A5+3), CAST_PTR(void*,0x475636+3), CAST_PTR(void*,0x4756C5+3), CAST_PTR(void*,0x475745+3), 
		CAST_PTR(void*,0x475796+3), CAST_PTR(void*,0x475835+3), CAST_PTR(void*,0x475886+3), CAST_PTR(void*,0x4758E6+3), CAST_PTR(void*,0x475946+3), CAST_PTR(void*,0x4759A5+3), 
		CAST_PTR(void*,0x4759F6+3), CAST_PTR(void*,0x475A65+3), CAST_PTR(void*,0x475AE5+3), CAST_PTR(void*,0x475B75+3), CAST_PTR(void*,0x475BF5+3), CAST_PTR(void*,0x475C45+3), 
		CAST_PTR(void*,0x475CC5+3), CAST_PTR(void*,0x475D65+3), CAST_PTR(void*,0x475DA5+3), CAST_PTR(void*,0x475DE5+3), CAST_PTR(void*,0x475E65+3), CAST_PTR(void*,0x475EA5+3), 
		CAST_PTR(void*,0x475F05+3), CAST_PTR(void*,0x475F65+3), CAST_PTR(void*,0x475FD6+3), CAST_PTR(void*,0x476036+3), CAST_PTR(void*,0x476095+3), CAST_PTR(void*,0x4760E5+3), 
		CAST_PTR(void*,0x476155+3), CAST_PTR(void*,0x4761E5+3), CAST_PTR(void*,0x476235+3), CAST_PTR(void*,0x476285+3), CAST_PTR(void*,0x4762E5+3), CAST_PTR(void*,0x476346+3), 
		CAST_PTR(void*,0x4763A5+3), CAST_PTR(void*,0x476416+3), CAST_PTR(void*,0x476486+3), CAST_PTR(void*,0x4764F6+3), CAST_PTR(void*,0x476566+3), CAST_PTR(void*,0x4765F5+3), 
		CAST_PTR(void*,0x476685+3), CAST_PTR(void*,0x4766F5+3), CAST_PTR(void*,0x476785+3), CAST_PTR(void*,0x4767D6+3), CAST_PTR(void*,0x476836+3), CAST_PTR(void*,0x476895+3), 
		CAST_PTR(void*,0x4768E5+3), CAST_PTR(void*,0x476926+3), CAST_PTR(void*,0x4769A5+3), CAST_PTR(void*,0x4769F5+3), CAST_PTR(void*,0x476A45+3), CAST_PTR(void*,0x476A96+3), 
		CAST_PTR(void*,0x476AF6+3), CAST_PTR(void*,0x476B55+3), CAST_PTR(void*,0x476BA5+3), CAST_PTR(void*,0x476C45+3), CAST_PTR(void*,0x476C85+3), CAST_PTR(void*,0x476CE5+3), 
		CAST_PTR(void*,0x476D45+3), CAST_PTR(void*,0x476DC5+3), CAST_PTR(void*,0x476E46+3), CAST_PTR(void*,0x476EC6+3), CAST_PTR(void*,0x476F36+3), CAST_PTR(void*,0x476F95+3), 
		CAST_PTR(void*,0x476FD5+3), CAST_PTR(void*,0x477025+3), CAST_PTR(void*,0x477095+3), CAST_PTR(void*,0x4770E5+3), CAST_PTR(void*,0x477176+3), CAST_PTR(void*,0x4771F5+3), 
		CAST_PTR(void*,0x477275+3), CAST_PTR(void*,0x477305+3), CAST_PTR(void*,0x477386+3), CAST_PTR(void*,0x477425+3), CAST_PTR(void*,0x4774A5+3), CAST_PTR(void*,0x477525+3), 
		CAST_PTR(void*,0x477576+3), CAST_PTR(void*,0x4775D5+3), CAST_PTR(void*,0x477625+3), CAST_PTR(void*,0x4776A5+3), CAST_PTR(void*,0x477725+3), CAST_PTR(void*,0x477825+3), 
		CAST_PTR(void*,0x477865+3), CAST_PTR(void*,0x4778B5+3), CAST_PTR(void*,0x477905+3), CAST_PTR(void*,0x477945+3), CAST_PTR(void*,0x477985+3), CAST_PTR(void*,0x4779D5+3), 
		CAST_PTR(void*,0x477A25+3), CAST_PTR(void*,0x477A75+3), CAST_PTR(void*,0x477AE5+3), CAST_PTR(void*,0x477B25+3), CAST_PTR(void*,0x477B75+3), CAST_PTR(void*,0x477BC5+3), 
		CAST_PTR(void*,0x477C15+3), CAST_PTR(void*,0x477C95+3), CAST_PTR(void*,0x477CE5+3), CAST_PTR(void*,0x477D75+3), CAST_PTR(void*,0x477DE5+3), CAST_PTR(void*,0x477E55+3), 
		CAST_PTR(void*,0x477EA5+3), CAST_PTR(void*,0x477EF5+3), CAST_PTR(void*,0x477F45+3), CAST_PTR(void*,0x477F95+3), CAST_PTR(void*,0x477FD5+3), CAST_PTR(void*,0x478015+3), 
		CAST_PTR(void*,0x478055+3), CAST_PTR(void*,0x478095+3), CAST_PTR(void*,0x4780D5+3), CAST_PTR(void*,0x478125+3), CAST_PTR(void*,0x478175+3), CAST_PTR(void*,0x478205+3), 
		CAST_PTR(void*,0x478255+3), CAST_PTR(void*,0x4782A5+3), CAST_PTR(void*,0x478305+3), CAST_PTR(void*,0x478355+3), CAST_PTR(void*,0x4783A5+3), CAST_PTR(void*,0x4783E5+3), 
		CAST_PTR(void*,0x478435+3), CAST_PTR(void*,0x478485+3), CAST_PTR(void*,0x4784D5+3), CAST_PTR(void*,0x478525+3), CAST_PTR(void*,0x478575+3), CAST_PTR(void*,0x4785C5+3), 
		CAST_PTR(void*,0x478605+3), CAST_PTR(void*,0x478645+3), CAST_PTR(void*,0x478695+3), CAST_PTR(void*,0x4786D5+3), CAST_PTR(void*,0x478725+3), CAST_PTR(void*,0x478775+3), 
		CAST_PTR(void*,0x4787B5+3), CAST_PTR(void*,0x478835+3), CAST_PTR(void*,0x4788B5+3), CAST_PTR(void*,0x478905+3), CAST_PTR(void*,0x478955+3), CAST_PTR(void*,0x4789A5+3), 
		CAST_PTR(void*,0x478A05+3), CAST_PTR(void*,0x478A55+3), CAST_PTR(void*,0x478AB5+3), CAST_PTR(void*,0x478B15+3), CAST_PTR(void*,0x478B75+3), CAST_PTR(void*,0x478BE5+3), 
		CAST_PTR(void*,0x478C25+3), CAST_PTR(void*,0x478C75+3), CAST_PTR(void*,0x478CB5+3), CAST_PTR(void*,0x478D05+3), CAST_PTR(void*,0x478D65+3), CAST_PTR(void*,0x478DC5+3), 
		CAST_PTR(void*,0x478E45+3), CAST_PTR(void*,0x478EC5+3), CAST_PTR(void*,0x478F25+3), CAST_PTR(void*,0x478F75+3), CAST_PTR(void*,0x478FC5+3), CAST_PTR(void*,0x479025+3), 
		CAST_PTR(void*,0x479075+3), CAST_PTR(void*,0x4790C5+3), CAST_PTR(void*,0x479115+3), CAST_PTR(void*,0x479166+3), CAST_PTR(void*,0x4791C6+3), CAST_PTR(void*,0x479226+3), 
		CAST_PTR(void*,0x479286+3), CAST_PTR(void*,0x4792E5+3), CAST_PTR(void*,0x479375+3), CAST_PTR(void*,0x4793D6+3), CAST_PTR(void*,0x479446+3), CAST_PTR(void*,0x4794B5+3), 
		CAST_PTR(void*,0x479506+3), CAST_PTR(void*,0x479566+3), CAST_PTR(void*,0x4795C6+3), CAST_PTR(void*,0x479626+3), CAST_PTR(void*,0x479686+3), CAST_PTR(void*,0x479725+3), 
		CAST_PTR(void*,0x479775+3), CAST_PTR(void*,0x4797C5+3), CAST_PTR(void*,0x479815+3), CAST_PTR(void*,0x479865+3), CAST_PTR(void*,0x4798C5+3), CAST_PTR(void*,0x479975+3), 
		CAST_PTR(void*,0x479A55+3), CAST_PTR(void*,0x479AA6+3), CAST_PTR(void*,0x479DE5+3), CAST_PTR(void*,0x479E65+3), CAST_PTR(void*,0x479EB5+3), CAST_PTR(void*,0x479F05+3), 
		CAST_PTR(void*,0x479F55+3), CAST_PTR(void*,0x47A015+3), CAST_PTR(void*,0x47A095+3), CAST_PTR(void*,0x47A1D5+3), CAST_PTR(void*,0x47A235+3), CAST_PTR(void*,0x47A285+3), 
		CAST_PTR(void*,0x47A2D5+3), CAST_PTR(void*,0x47A545+3), CAST_PTR(void*,0x47A5C5+3), CAST_PTR(void*,0x47A615+3), CAST_PTR(void*,0x47A685+3), CAST_PTR(void*,0x47A705+3), 
		CAST_PTR(void*,0x47A775+3), CAST_PTR(void*,0x47A7C5+3), CAST_PTR(void*,0x47A805+3), CAST_PTR(void*,0x47A855+3), CAST_PTR(void*,0x47A8A5+3), CAST_PTR(void*,0x47A8F5+3), 
		CAST_PTR(void*,0x47A945+3), CAST_PTR(void*,0x47A985+3), CAST_PTR(void*,0x47A9F5+3), CAST_PTR(void*,0x47AA65+3), CAST_PTR(void*,0x47AAD5+3), CAST_PTR(void*,0x47AB66+3), 
		CAST_PTR(void*,0x47ABC6+3), CAST_PTR(void*,0x47AC25+3), CAST_PTR(void*,0x47ACC5+3), CAST_PTR(void*,0x47AD35+3), CAST_PTR(void*,0x47ADA5+3), CAST_PTR(void*,0x47AE05+3), 
		CAST_PTR(void*,0x47AE65+3), CAST_PTR(void*,0x47AEC5+3), CAST_PTR(void*,0x47AF25+3), CAST_PTR(void*,0x47AF75+3), CAST_PTR(void*,0x47AFE6+3), CAST_PTR(void*,0x47B045+3), 
		CAST_PTR(void*,0x47B095+3), CAST_PTR(void*,0x47B0E5+3), CAST_PTR(void*,0x47B125+3), CAST_PTR(void*,0x47B185+3), CAST_PTR(void*,0x47B1F6+3), CAST_PTR(void*,0x47B286+3), 
		CAST_PTR(void*,0x47B2F5+3), CAST_PTR(void*,0x47B355+3), CAST_PTR(void*,0x47B3B5+3), CAST_PTR(void*,0x47B415+3), CAST_PTR(void*,0x47B475+3), CAST_PTR(void*,0x47B4D5+3), 
		CAST_PTR(void*,0x47B535+3), CAST_PTR(void*,0x47B5C5+3), CAST_PTR(void*,0x47B615+3), CAST_PTR(void*,0x47B665+3), CAST_PTR(void*,0x47B6B5+3), CAST_PTR(void*,0x47B715+3), 
		CAST_PTR(void*,0x47B7A5+3), CAST_PTR(void*,0x47B7F5+3), CAST_PTR(void*,0x47B8B5+3), CAST_PTR(void*,0x47B925+3), CAST_PTR(void*,0x47B985+3), CAST_PTR(void*,0x47B9F5+3), 
		CAST_PTR(void*,0x47BA55+3), CAST_PTR(void*,0x47BAB5+3), CAST_PTR(void*,0x47BB25+3), CAST_PTR(void*,0x47BB95+3), CAST_PTR(void*,0x47BBE5+3), CAST_PTR(void*,0x47BC75+3), 
		CAST_PTR(void*,0x47BD05+3), CAST_PTR(void*,0x47BD45+3), CAST_PTR(void*,0x47BDC6+3), CAST_PTR(void*,0x47BE36+3), CAST_PTR(void*,0x47BEC5+3), CAST_PTR(void*,0x47BF36+3), 
		CAST_PTR(void*,0x47BF95+3), CAST_PTR(void*,0x47BFD5+3), CAST_PTR(void*,0x47C025+3), CAST_PTR(void*,0x47C075+3), CAST_PTR(void*,0x47C0C5+3), CAST_PTR(void*,0x47C115+3), 
		CAST_PTR(void*,0x47C1B5+3), CAST_PTR(void*,0x47C205+3), CAST_PTR(void*,0x47C2A5+3), CAST_PTR(void*,0x47C2F5+3), CAST_PTR(void*,0x47C355+3), CAST_PTR(void*,0x47C3A5+3), 
		CAST_PTR(void*,0x47C405+3), CAST_PTR(void*,0x47C455+3), CAST_PTR(void*,0x47C4A5+3), CAST_PTR(void*,0x47C4F5+3), CAST_PTR(void*,0x47C545+3), CAST_PTR(void*,0x47C595+3), 
		CAST_PTR(void*,0x47C5F5+3), CAST_PTR(void*,0x47C645+3), CAST_PTR(void*,0x47C6A5+3), CAST_PTR(void*,0x47C6F5+3), CAST_PTR(void*,0x47C745+3), CAST_PTR(void*,0x47C795+3), 
		CAST_PTR(void*,0x47C7E5+3), CAST_PTR(void*,0x47C835+3), CAST_PTR(void*,0x47C885+3), CAST_PTR(void*,0x47C8D5+3), CAST_PTR(void*,0x47C935+3), CAST_PTR(void*,0x47CA05+3), 
		CAST_PTR(void*,0x47CA55+3), CAST_PTR(void*,0x47CA95+3), CAST_PTR(void*,0x47CAE5+3), CAST_PTR(void*,0x47CB45+3), CAST_PTR(void*,0x47CBC5+3), CAST_PTR(void*,0x47CC45+3), 
		CAST_PTR(void*,0x47CC85+3), CAST_PTR(void*,0x47CD45+3), CAST_PTR(void*,0x47CD85+3), CAST_PTR(void*,0x47CE65+3), CAST_PTR(void*,0x47CF15+3), CAST_PTR(void*,0x47CF75+3), 
		CAST_PTR(void*,0x47D085+3), CAST_PTR(void*,0x47D265+3), CAST_PTR(void*,0x47D2C5+3), CAST_PTR(void*,0x47D335+3), CAST_PTR(void*,0x47D5A5+3), CAST_PTR(void*,0x47DBD8+0), 
		CAST_PTR(void*,0x47DEF5+0), CAST_PTR(void*,0x47E80F+0), CAST_PTR(void*,0x47E8C0+0), CAST_PTR(void*,0x47E939+0), CAST_PTR(void*,0x47ED39+3), CAST_PTR(void*,0x47F480+3), 
		CAST_PTR(void*,0x47F59B+3), CAST_PTR(void*,0x47F698+3), CAST_PTR(void*,0x47F788+3), CAST_PTR(void*,0x47F9F6+3), CAST_PTR(void*,0x47FA96+3), CAST_PTR(void*,0x47FB26+3), 
		CAST_PTR(void*,0x4800C5+0), CAST_PTR(void*,0x480EE2+0), CAST_PTR(void*,0x481A80+3), CAST_PTR(void*,0x484AB8+0), CAST_PTR(void*,0x484CB4+0),
#endif
	};
	#pragma endregion

	//////////////////////////////////////////////////////////////////////////
	// script globals related
	ENGINE_PTR(int32, hs_external_globals_count,			0x5F9D0C, 0x55578C);
	ENGINE_DPTR(hs_global_definition, hs_external_globals,	0x626988, 0x59C328);

	static int16* K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCES_16bit[] = {
		CAST_PTR(int16*, PLATFORM_VALUE(0x486211, 0x47DB01)),
	};
	static int32* K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCES_32bit[] = {
		CAST_PTR(int32*, PLATFORM_VALUE(0x4866CA, 0x47DFAA)), CAST_PTR(int32*, PLATFORM_VALUE(0x48BDFA, 0x4836DA)),
		CAST_PTR(int32*, PLATFORM_VALUE(0x48CC1B, 0x4844FB)), CAST_PTR(int32*, PLATFORM_VALUE(0x48CD2F, 0x48460F)),
		CAST_PTR(int32*, PLATFORM_VALUE(0x48CD8D, 0x48466D)), CAST_PTR(int32*, PLATFORM_VALUE(0x48CE90, 0x484770)),
		CAST_PTR(int32*, PLATFORM_VALUE(0x48D4AA, 0x484D8A)),
	};
	static void* K_HS_EXTERNAL_GLOBALS_REFERENCES[] = {
		CAST_PTR(void*, PLATFORM_VALUE(0x48619C, 0x47DA8C)), CAST_PTR(void*, PLATFORM_VALUE(0x4861CC, 0x47DABC)), 
		CAST_PTR(void*, PLATFORM_VALUE(0x4861F9, 0x47DAE9)), CAST_PTR(void*, PLATFORM_VALUE(0x486530, 0x47DE20)), 
		CAST_PTR(void*, PLATFORM_VALUE(0x4866C5, 0x47DFA5)), CAST_PTR(void*, PLATFORM_VALUE(0x489392, 0x480BE2)), 
		CAST_PTR(void*, PLATFORM_VALUE(0x48BD8E, 0x48366E)), CAST_PTR(void*, PLATFORM_VALUE(0x48D306, 0x484BE6)), 
		CAST_PTR(void*, PLATFORM_VALUE(0x48DC3B, 0x48551B)), CAST_PTR(void*, PLATFORM_VALUE(0x48DDA7, 0x485687)),
	};

	//////////////////////////////////////////////////////////////////////////

	FUNC_PTR(HS_VALID_ACCESS_FLAGS, 0x486340, 0x47DC30);

	//////////////////////////////////////////////////////////////////////////
	// InitializeCreateScriptFunction()
	FUNC_PTR(HS_ARGUMENTS_EVALUATE,	0x48D5A0, 0x484E80);
	FUNC_PTR(HS_RETURN,				0x48D390, 0x484C70);

#endif