/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

namespace NearbyObjects
{
	static void* player_examine_nearby_objects_server_jmp_table_yelo[Yelo::Enums::_object_type_sound_scenery+1];
	static void* player_examine_nearby_objects_client_jmp_table_yelo[Yelo::Enums::_object_type_sound_scenery+1];
	
	// Replaces PlayerExamineNearbyObjectsServer function's switch table with our own
	static void InitializePlayerExamineNearbyObjectsServerJmpTable()
	{
		// copy the game's jmp table to our own
		for(int32 x = 0; x <= Yelo::Enums::_object_type_control; x++)
			player_examine_nearby_objects_server_jmp_table_yelo[x] = (void*)PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_JMP_TABLE[x];

		// write the game's default jump case into our jump table for cases 9-11
		for(int32 x = Yelo::Enums::_object_type_light_fixture; x <= Yelo::Enums::_object_type_sound_scenery; x++)
			player_examine_nearby_objects_server_jmp_table_yelo[x] = (void*)PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_JMP_TABLE[0];
		
		// set the game's client jump table count to our's
		*K_NUMBER_OF_PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_JMP_TABLE_ENTRIES = Yelo::Enums::_object_type_sound_scenery;
		// set the game's client jump table address to our's
		GET_PTR(player_examine_nearby_objects_server_jmp_ptr) = player_examine_nearby_objects_server_jmp_table_yelo;
	}

	// Replaces PlayerExamineNearbyObjectsClient function's switch table with our own
	static void InitializePlayerExamineNearbyObjectsClientJmpTable()
	{
		// copy the game's jmp table to our own
		for(int32 x = 0; x <= Yelo::Enums::_object_type_control; x++)
			player_examine_nearby_objects_client_jmp_table_yelo[x] = (void*)PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_JMP_TABLE[x];

		// write the game's default jump case into our jump table for cases 9-11
		for(int32 x = Yelo::Enums::_object_type_light_fixture; x <= Yelo::Enums::_object_type_sound_scenery; x++)
			player_examine_nearby_objects_client_jmp_table_yelo[x] = (void*)PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_JMP_TABLE[0];
		
		// set the game's client jump table count to our's
		*K_NUMBER_OF_PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_JMP_TABLE_ENTRIES = Yelo::Enums::_object_type_sound_scenery;
		// set the game's client jump table address to our's
		GET_PTR(player_examine_nearby_objects_client_jmp_ptr) = player_examine_nearby_objects_client_jmp_table_yelo;
	}

	void PlayerExamineNearbyBiped(datum_index player_index, datum_index biped_index)
	{
		s_player_datum* player = (*Players::Players())[player_index];

		// Make sure we're not detecting ourself
		if (player->slave_unit_index != biped_index)
		{
			// Add check to see if biped is on our team to allow differentiation between unit seat entering and weapon swapping
			// Problem: when you enter a biped seat, their team changes to yours
			Engine::Players::PlayerExamineNearbyVehicle(player_index, biped_index);
		}
	}

	API_FUNC_NAKED void PLATFORM_API PlayerExamineNearbyBipedServerJMP()
	{
		static uint32 RETN_ADDRESS = GET_FUNC_PTR(PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_JMP_TABLE_RETN);

		__asm {
			pushad

			push	ecx		// datum_index biped_index
			push	edi		// datum_index player_index
			call	PlayerExamineNearbyBiped

			popad

			jmp		RETN_ADDRESS
		}
	}

	API_FUNC_NAKED void PLATFORM_API PlayerExamineNearbyBipedClientJMP()
	{
		static uint32 RETN_ADDRESS = GET_FUNC_PTR(PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_JMP_TABLE_RETN);

		__asm {
			pushad

			push	ecx		// datum_index biped_index
			push	edi		// datum_index player_index
			call	PlayerExamineNearbyBiped

			popad

			jmp		RETN_ADDRESS
		}
	}
	
	// Initializes new yelo nearby object detection
	void InitializeYeloNearbyObjects()
	{
		// Detect nearby biped objects server side for seat entry
		player_examine_nearby_objects_server_jmp_table_yelo[Yelo::Enums::_object_type_biped] = 
			&PlayerExamineNearbyBipedServerJMP;
		// Detect nearby biped objects client side for seat entry
		player_examine_nearby_objects_client_jmp_table_yelo[Yelo::Enums::_object_type_biped] = 
			&PlayerExamineNearbyBipedClientJMP;
	}

	void Initialize()
	{
		InitializePlayerExamineNearbyObjectsServerJmpTable();
		InitializePlayerExamineNearbyObjectsClientJmpTable();
		
		InitializeYeloNearbyObjects();
	}
};