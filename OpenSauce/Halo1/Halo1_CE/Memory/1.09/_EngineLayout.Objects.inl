/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

//////////////////////////////////////////////////////////////////////////
// Objects.cpp
#if __EL_INCLUDE_FILE_ID == __EL_OBJECTS_OBJECTS
	ENGINE_PTR(s_object_type_definition**, object_type_definitions,				0x6376A4, 0x5AD07C);
	ENGINE_PTR(s_widget_type_definition*,  widget_type_definitions,				0x6376D8, 0x5AD0B0);

	ENGINE_DPTR(t_widget_data, widgets,											0x7FB398, 0x6C69D8);
	ENGINE_DPTR(t_flag_data, flags,												0x7FB3A8, 0x6C69E8);
	ENGINE_DPTR(t_antenna_data, antennas,										0x7FB3AC, 0x6C69EC);
	ENGINE_DPTR(t_glow_data, glow,												0x7FB3A0, 0x6C69E0);
	ENGINE_DPTR(t_glow_particles_data, glow_particles,							0x7FB3A4, 0x6C69E4);
	ENGINE_DPTR(t_light_volumes_data, light_volumes,							0x653CC0, 0x5C5BA8);
	ENGINE_DPTR(t_lightnings_data, lightnings,									0x653CC4, 0x5C5BAC);

	ENGINE_DPTR(Render::cached_object_render_states_data_t, cached_object_render_states,	0x75E0EC, 0x629728);
	ENGINE_DPTR(s_unit_globals_data, unit_globals,								0x68A8F0, 0x5F30E8);
	ENGINE_DPTR(t_device_groups_data, device_groups,							0x815DB0, 0x6E1C70);
	ENGINE_DPTR(t_object_header_data, object_header,							0x7FB3B0, 0x6C69F0);
	ENGINE_DPTR(s_objects_pool_data, objects_pool,								0x653C04, 0x5C5AEC);
	ENGINE_DPTR(s_object_globals_data, object_globals,							0x653C0C, 0x5C5AF4);
	ENGINE_DPTR(s_object_name_list_data, object_name_list,						0x653C08, 0x5C5AF0);

	ENGINE_DPTR(collideable_object_data, collideable_object,					0x7FB3D0, 0x6C6A10);
	ENGINE_DPTR(t_cluster_collideable_object_reference_data, cluster_collideable_object_reference,	0x7FB3D4, 0x6C6A14);
	ENGINE_DPTR(t_collideable_object_cluster_reference_data, collideable_object_cluster_reference,	0x7FB3D8, 0x6C6A18);
	ENGINE_DPTR(noncollideable_object_data, noncollideable_object,				0x7FB3C0, 0x6C6A00);
	ENGINE_DPTR(t_cluster_noncollideable_object_reference_data, cluster_noncollideable_object_reference,0x7FB3C4, 0x6C6A04);
	ENGINE_DPTR(t_noncollideable_object_cluster_reference_data, noncollideable_object_cluster_reference,0x7FB3C8, 0x6C6A08);

	ENGINE_PTR(size_t, object_memory_pool_allocation_size,						0x4F875D+0x30, 0x4DF74D+0x30);

	FUNC_PTR(OBJECT_TYPES_PLACE_ALL_MOD_VEHI_REMAP,		0x4F7833+0x30, 0x4DE893+0x30);
	FUNC_PTR(OBJECTS_UPDATE__OBJECT_IN_PLAYER_PVS_NOP1,	0x4F8B84+0x30, PTR_NULL);
	FUNC_PTR(OBJECTS_UPDATE__OBJECT_IN_PLAYER_PVS_NOP2,	0x4F8C1A+0x30, PTR_NULL);
	FUNC_PTR(OBJECTS_UPDATE_HOOK,						0x4F8D6E, 0x4DFB10);
	FUNC_PTR(OBJECTS_GARBAGE_COLLECTION,				0x4FD8F0, 0x4E47E0);
	FUNC_PTR(OBJECT_DAMAGE_OBJECT_BODY_HOOK,			0x4F34AA, 0x4DC70A);
	//FUNC_PTR(UNIT_CAN_ENTER_SEAT_MOD,					0x56A3E3, 0x518D73);
	FUNC_PTR(UNIT_CAUSE_PARENT_MELEE_DAMAGE_HOOK,		0x573C69, 0x522379);
	FUNC_PTR(UNIT_CAUSE_PARENT_MELEE_DAMAGE_HOOK_RETN,	0x573C71, 0x522381);
	FUNC_PTR(BIPED_UPDATE_MOVING_HOOK,					0x561B96, 0x5105B6);
	FUNC_PTR(BIPED_JUMP_MOD_STUN_PENALTY_FIELD_REF,		0x56283E+0x30, 0x51125E+0x30);

#if PLATFORM_IS_USER
	namespace render_objects_mods
	{
		static uintptr_t K_MAXIMUM_RENDERED_OBJECTS_REFS_32bit[] = {
			0x45B60C+1 +0x10,
			0x512755+1 +0x30,	0x512789+1+0x30,
		};
		static uintptr_t K_MAXIMUM_RENDERED_OBJECTS_REFS_16bit[] = {
			0x5127BF+7+0x30,
		};
		static uintptr_t K_RENDER_OBJECT_GLOBALS__RENDERED_OBJECTS_REFS[] = {
			0x512613+3+0x30,
			0x51275A+1+0x30, 0x51279E+3+0x30,
			0x5127F3+3+0x30,
		};
	};
#endif

	namespace Weapon
	{
		FUNC_PTR(FIRST_PERSON_WEAPON_RENDER_UPDATE,							0x4953D0, FUNC_PTR_NULL);
		FUNC_PTR(RENDER_WINDOW_CALL_HOOK_FIRST_PERSON_WEAPON_RENDER_UPDATE,	0x50FD37, FUNC_PTR_NULL);
	};


//////////////////////////////////////////////////////////////////////////
// Equipment.cpp
#elif __EL_INCLUDE_FILE_ID == __EL_OBJECTS_EQUIPMENT


//////////////////////////////////////////////////////////////////////////
// Units.cpp
#elif __EL_INCLUDE_FILE_ID == __EL_OBJECTS_UNITS

	static uint32 K_UNIT_ZOOM_LEVEL_OFFSET_REFS[] = {
		PLATFORM_VALUE(0x459F81, 0x456AF1)+0x10, PLATFORM_VALUE(0x55D7A9, 0x50C209)+0x30, PLATFORM_VALUE(0x565CD9, 0x514669)+0x30,
		PLATFORM_VALUE(0x5667AD, 0x51513D)+0x30, PLATFORM_VALUE(0x5667BB, 0x51514B)+0x30, PLATFORM_VALUE(0x566849, 0x5151D9)+0x30,
		PLATFORM_VALUE(0x566D52, 0x5156E2)+0x30, PLATFORM_VALUE(0x5694EA, 0x517E7A)+0x30, PLATFORM_VALUE(0x569556, 0x517EE6)+0x30,
		PLATFORM_VALUE(0x56964E, 0x517FDE)+0x30,
	};
	static uint32 K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REFS[] = {
		PLATFORM_VALUE(0x473DE1, 0x46B8E1)+0x10, PLATFORM_VALUE(0x55EDD4, 0x50D824)+0x30, PLATFORM_VALUE(0x565CDF, 0x51466F)+0x30,
		PLATFORM_VALUE(0x5667A7, 0x515137)+0x30, PLATFORM_VALUE(0x567562, 0x515EF2)+0x30, PLATFORM_VALUE(0x56955D, 0x517EED)+0x30,
	};

	static uint32 K_NUMBER_OF_UNIT_GRENADE_TYPES_REFS[] = {
		PLATFORM_VALUE(0x476B4A, 0x46E5CA)+1+0x10, PLATFORM_VALUE(0x47F2FC, 0x476E7C)+1+0x10, PLATFORM_VALUE(0x4B51F9, 0x4A1649)+1+0x30, 
		PLATFORM_VALUE(0x566774, 0x515104)+1+0x30, 
#if PLATFORM_IS_USER
		PLATFORM_VALUE(0x4B665C, NULL)+1+0x30, 
#endif
		PLATFORM_VALUE(0x572CA6, 0x5213A6)+4+0x30, 
	};
	static uint32 K_MAXIMUM_UNIT_GRENADE_INDEX_REFS[] = {
		PLATFORM_VALUE(0x474BF4, 0x46C6F4)+2+0x10, // 16bit
		PLATFORM_VALUE(0x56D703, 0x51BE53)+1+0x30, // 32bit
		PLATFORM_VALUE(0x56D70F, 0x51BE5F)+3+0x30, // 8bit
	};

	FUNC_PTR(ACTOR_DIED_UNIT_GRENADE_COUNT_MOD,					0x428D35, 0x428D45);
	FUNC_PTR(PLAYER_ADD_EQUIPMENT_UNIT_GRENADE_COUNT_MOD,		0x476AC7+0x10, 0x46E547+0x10);
	FUNC_PTR(BIPED_NEW_FROM_NETWORK_UNIT_GRENADE_COUNT_MOD,		0x55EE1A+0x30, 0x50D86A+0x30);
	FUNC_PTR(BIPED_UPDATE_BASELINE_UNIT_GRENADE_COUNT_MOD1,		0x55EEB6+0x30, 0x50D906+0x30);
	FUNC_PTR(BIPED_UPDATE_BASELINE_UNIT_GRENADE_COUNT_MOD2,		0x55EED4+0x30, 0x50D924+0x30);
	FUNC_PTR(BIPED_BUILD_UPDATE_DELTA_UNIT_GRENADE_COUNT_MOD1,	0x55EFDF+0x30, 0x50DA2F+0x30);
	FUNC_PTR(BIPED_BUILD_UPDATE_DELTA_UNIT_GRENADE_COUNT_MOD2,	0x55EFF5+0x30, 0x50DA45+0x30);
	FUNC_PTR(BIPED_PROCESS_UPDATE_DELTA_UNIT_GRENADE_COUNT_MOD,	0x55F1A6+0x30, 0x50DBF6+0x30);
	FUNC_PTR(BIPED_UPDATE_CHECK_PARENT_UNIT_TYPE,				0x55CBCA+0x30, 0x50B62A+0x30);

	//////////////////////////////////////////////////////////////////////////
	// Units.Boarding
	FUNC_PTR(UNIT_CAN_ENTER_SEAT_HOOK,							0x56A340, 0x518CD0);
	
	//////////////////////////////////////////////////////////////////////////
	// Units.Animations
	FUNC_PTR(UNIT_UPDATE_ANIMATION_PRIMARY_KEYFRAME_JMP_TABLE_ADJUST_SIZE,		0x569096, 0x517A26);
	FUNC_PTR(UNIT_UPDATE_ANIMATION_PRIMARY_KEYFRAME_INDIRECT_TABLE_PTR,			0x5690A2, 0x517A32);
	FUNC_PTR(UNIT_UPDATE_ANIMATION_PRIMARY_KEYFRAME_SWITCH_RETN,				0x5692B7, 0x517C47);
	ENGINE_PTR(byte, unit_update_animation_primary_keyframe_jmp_tbl_count,		0x56909B, 0x517A2B);
	ENGINE_PTR(void**, unit_update_animation_primary_keyframe_jmp_ptr,			0x5690AC, 0x517A3C);
	static const uintptr_t* UNIT_UPDATE_ANIMATION_PRIMARY_KEYFRAME_JMP_TABLE = CAST_PTR(
		const uintptr_t*, PLATFORM_VALUE(0x5693AC, 0x517D3C)
	);
	
	FUNC_PTR(UNIT_UPDATE_ANIMATION_FINAL_KEYFRAME_JMP_TABLE_ADJUST_SIZE,		0x5690EB, 0x517A7B);
	FUNC_PTR(UNIT_UPDATE_ANIMATION_FINAL_KEYFRAME_INDIRECT_TABLE_PTR,			0x5690F7, 0x517A87);
	FUNC_PTR(UNIT_UPDATE_ANIMATION_FINAL_KEYFRAME_SWITCH_RETN,					0x5692A4, 0x517C34);
	ENGINE_PTR(byte, unit_update_animation_final_keyframe_jmp_tbl_count,		0x5690F0, 0x517A80);
	ENGINE_PTR(void**, unit_update_animation_final_keyframe_jmp_ptr,			0x569101, 0x517A91);
	static const uintptr_t* UNIT_UPDATE_ANIMATION_FINAL_KEYFRAME_JMP_TABLE = CAST_PTR(
		const uintptr_t*, PLATFORM_VALUE(0x5693C4, 0x517D54)
	);

	static void** K_UNIT_ANIMATION_STATE_INTERRUPTABLE_CALLS[] = {
		CAST_PTR(void**, PLATFORM_VALUE(0x569010, 0x5179A0)), 
		CAST_PTR(void**, PLATFORM_VALUE(0x56936C, 0x517CFC)),  
		CAST_PTR(void**, PLATFORM_VALUE(0x56AC38, 0x5195C8))
	};
	static void** K_UNIT_ANIMATION_BUSY_CALLS[] = {
		CAST_PTR(void**, PLATFORM_VALUE(0x40B5EA, 0x40B5FA)), 
		CAST_PTR(void**, PLATFORM_VALUE(0x4343A8, 0x4343B8)),  
		CAST_PTR(void**, PLATFORM_VALUE(0x55D045, 0x50BAA5)),
		CAST_PTR(void**, PLATFORM_VALUE(0x5666FF, 0x51508F)),
		CAST_PTR(void**, PLATFORM_VALUE(0x56675B, 0x5150EB)),
		CAST_PTR(void**, PLATFORM_VALUE(0x566D56, 0x5156E6)),
		CAST_PTR(void**, PLATFORM_VALUE(0x56B788, 0x51A118)),
		CAST_PTR(void**, PLATFORM_VALUE(0x56EE6B, 0x51D5BB)),
		CAST_PTR(void**, PLATFORM_VALUE(0x56F7D5, 0x51DF25)),
		CAST_PTR(void**, PLATFORM_VALUE(0x570239, 0x51E989))
	};
	FUNC_PTR(K_UNIT_ANIMATION_STATE_LOOPS_CALL,		0x5692AA, 0x517C3A);
	FUNC_PTR(K_UNIT_ANIMATION_WEAPON_IK_CALL,		0x567FEE, 0x51697E);
	FUNC_PTR(K_UNIT_ANIMATION_VEHICLE_IK_CALL,		0x567F86, 0x516916);

#else
	#error Undefined engine layout include for: __EL_INCLUDE_OBJECTS
#endif