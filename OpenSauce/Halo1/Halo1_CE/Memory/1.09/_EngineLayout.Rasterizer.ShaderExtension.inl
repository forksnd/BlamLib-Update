/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/


//////////////////////////////////////////////////////////////////////////
// ShaderExtension.cpp
#if __EL_INCLUDE_FILE_ID == __EL_RASTERIZER_SHADEREXTENSION
	FUNC_PTR(RASTERIZER_MODEL_DRAW_INVERT_BACKFACE_NORMALS_CHECK_HOOK,			0x52E3C5, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_DRAW_INVERT_BACKFACE_NORMALS_CHECK_RETN,			0x52E3CB, FUNC_PTR_NULL);

	FUNC_PTR(RASTERIZER_DX9_SHADERS_EFFECT_SHADERS_INITIALIZE__SPRINTF_CALL,	0x533094, PTR_NULL);

	static cstring* K_VSH_COLLECTION_PATH_REFERENCES[] = {
		CAST_PTR(cstring*, 0x533AFE), CAST_PTR(cstring*, 0x533B99),
	};

	static void** K_PS_VERSION_ITERATOR_START[] = {
		CAST_PTR(void**, 0x533028), CAST_PTR(void**, 0x533552)
	};

#elif __EL_INCLUDE_FILE_ID == __EL_RASTERIZER_SHADEREXTENSION_MODEL
	static void** K_SHADER_USAGE_ID_ARRAY_REFERENCES[] = {
		CAST_PTR(void**, 0x52A17D), CAST_PTR(void**, 0x52A1F5), 
		CAST_PTR(void**, 0x52A274), CAST_PTR(void**, 0x52A2F4), 
		CAST_PTR(void**, 0x52A395), CAST_PTR(void**, 0x52A127)
	};

	ENGINE_PTR(int, RASTERIZER_MODEL_SHADER_LOAD_COUNT,				0x52A04E, PTR_NULL);
	ENGINE_PTR(int, RASTERIZER_MODEL_SHADER_LOAD_NO_INVERSE_COUNT,	0x52A053, PTR_NULL);

	FUNC_PTR(RASTERIZER_MODEL_ENVIRONMENT_NO_USAGE_ID_OFFSET_HOOK,	0x52A118, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_ENVIRONMENT_NO_USAGE_ID_OFFSET_RETN,	0x52A125, FUNC_PTR_NULL);

	FUNC_PTR(RASTERIZER_MODEL_NO_USAGE_ID_OFFSET_HOOK,				0x52A386, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_NO_USAGE_ID_OFFSET_RETN,				0x52A393, FUNC_PTR_NULL);


	static void** K_PIXEL_SHADER_REFERENCES_ENVIRONMENT_NO[] = {
		CAST_PTR(void**, 0x52A097), CAST_PTR(void**, 0x52A159)
	};
	static void** K_PIXEL_SHADER_REFERENCES_CHANGE_COLOR[] = {
		CAST_PTR(void**, 0x52A0B7), CAST_PTR(void**, 0x52A236)
	};
	static void** K_PIXEL_SHADER_REFERENCES_MULTIPURPOSE[] = {
		CAST_PTR(void**, 0x52A0C7), CAST_PTR(void**, 0x52A2B6)
	};
	static void** K_PIXEL_SHADER_REFERENCES_NO[] = {
		CAST_PTR(void**, 0x52A0ED), CAST_PTR(void**, 0x52A3C5)
	};
	static void** K_PIXEL_SHADER_REFERENCES_REFLECTION[] = {
		CAST_PTR(void**, 0x52A0D7), CAST_PTR(void**, 0x52A336)
	};
	static void** K_PIXEL_SHADER_REFERENCES_SELF_ILLUMINATION[] = {
		CAST_PTR(void**, 0x52A0A7), CAST_PTR(void**, 0x52A1B7)
	};


	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_ENVIRONMENT_NO_HOOK,			0x52B92A, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_ENVIRONMENT_NO_RETN,			0x52B931, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_ENVIRONMENT_NO_INV_HOOK,		0x52B91A, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_ENVIRONMENT_NO_INV_RETN,		0x52B921, FUNC_PTR_NULL);

	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_CHANGE_COLOR_HOOK,			0x52AD51, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_CHANGE_COLOR_RETN,			0x52AD58, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_CHANGE_COLOR_INV_HOOK,		0x52AD48, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_CHANGE_COLOR_INV_RETN,		0x52AD4F, FUNC_PTR_NULL);

	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_MULTIPURPOSE_HOOK,			0x52AD63, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_MULTIPURPOSE_RETN,			0x52AD6A, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_MULTIPURPOSE_INV_HOOK,		0x52AD5A, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_MULTIPURPOSE_INV_RETN,		0x52AD61, FUNC_PTR_NULL);

	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_NO_HOOK,						0x52AD1B, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_NO_RETN,						0x52AD22, FUNC_PTR_NULL);

	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_REFLECTION_HOOK,				0x52AD3F, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_REFLECTION_RETN,				0x52AD46, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_REFLECTION_INV_HOOK,			0x52AD36, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_REFLECTION_INV_RETN,			0x52AD3D, FUNC_PTR_NULL);

	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_SELF_ILLUMINATION_HOOK,		0x52AD2D, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_SELF_ILLUMINATION_RETN,		0x52AD34, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_SELF_ILLUMINATION_INV_HOOK,	0x52AD24, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_PS_INDEX_SELF_ILLUMINATION_INV_RETN,	0x52AD2B, FUNC_PTR_NULL);

#elif __EL_INCLUDE_FILE_ID == __EL_RASTERIZER_SHADEREXTENSION_ENVIRONMENT
#else
	#error Undefined engine layout include for: __EL_RASTERIZER_SHADEREXTENSION
#endif