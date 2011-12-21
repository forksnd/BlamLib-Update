/*
	Yelo: Open Sauce SDK
		Halo 1 (Editing Kit) Edition

	See license\OpenSauce\Halo1_CheApe for specific license information
*/

//////////////////////////////////////////////////////////////////////////
// TagGroups.cpp
#if __EL_INCLUDE_FILE_ID == __EL_TAGGROUPS_TAG_GROUPS
	namespace TagGroups
	{
		ENGINE_DPTR(t_tag_instance_data, tag_instance_data,		0xAA57C0, 0xEB8A80, 0xBD5118);

		FUNC_PTR(TAG_FILES_OPEN,			0x439BB0, 0x444A60, 0x4FCB20);
	};

	FUNC_PTR(TAG_GET,						0x434DB0, 0x433340, 0x4F9E70);
	FUNC_PTR(TAG_GROUP_GET,					0x434B30, 0x433140, 0x4F9BF0);
	FUNC_PTR(TAG_RENAME,					0x434F4C, 0x4334D0, 0x4FA000);
	FUNC_PTR(TAG_BLOCK_INDEX_RESOLVE,		0x434FE0, 0x433570, 0x4FA0A0);
	FUNC_PTR(TAG_SIZE,						0x434FE0, 0x4335D0, 0x4FA160);

	FUNC_PTR(TAG_REFERENCE_SET,				0x4358C0, 0x433DF0, 0x4FA980);
	FUNC_PTR(TAG_BLOCK_SIZE,				0x433B40, 0x432340, 0x4F89B0);
	FUNC_PTR(TAG_BLOCK_GET_ELEMENT,			0x436310, 0x434840, 0x4FB3D0);
	FUNC_PTR(TAG_NEW,						0x436350, 0x434880, 0x4FB410);
	FUNC_PTR(TAG_SAVE,						0x436590, 0x434AC0, 0x4FB650);
	FUNC_PTR(TAG_BLOCK_DELETE_ELEMENT,		0x4366C0, 0x434BF0, 0x4FB780);
	FUNC_PTR(TAG_BLOCK_ADD_ELEMENT,			0x436980, 0x434EB0, 0x4FBA40);
	FUNC_PTR(TAG_UNLOAD,					0x436AE0, 0x435010, 0x4FBBA0);
	FUNC_PTR(TAG_BLOCK_RESIZE,				0x436B30, 0x435060, 0x4FBBF0);
	FUNC_PTR(TAG_BLOCK_INSERT_ELEMENT,		0x436BF0, 0x435120, 0x4FBCB0);
	FUNC_PTR(TAG_BLOCK_DUPLICATE_ELEMENT,	0x436F90, 0x435360, 0x4FC050);
	FUNC_PTR(TAG_LOAD,						0x437330, 0x435700, 0x4FC3F0);

	FUNC_PTR(TAG_ITERATOR_NEW,				FUNC_PTR_NULL, 0x432470, FUNC_PTR_NULL);
	FUNC_PTR(TAG_ITERATOR_NEXT,				FUNC_PTR_NULL, 0x432490, FUNC_PTR_NULL);


#else
	#error Undefined engine layout include for: __EL_INCLUDE_TAGGROUPS
#endif