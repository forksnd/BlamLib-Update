/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#if !PLATFORM_IS_DEDI
#include "Rasterizer/PostProcessing/ShaderSources/c_shader_data_base.hpp"
#include <Blam/Halo1/shader_postprocess_definitions.hpp>

namespace Yelo
{
	namespace Rasterizer { namespace PostProcessing
	{
		class c_shader_data_postprocess_definition : public c_shader_data_base
		{
			const char* m_shader_name;
			TagGroups::s_shader_postprocess_definition* m_shader_definition;

		public:
			void SetShaderName(const char* shader_name) { m_shader_name = shader_name; }
			void SetShaderDefinition(TagGroups::s_shader_postprocess_definition* definition) { m_shader_definition = definition; }

			void Ctor()
			{
				m_shader_definition = NULL;
			}
			void Dtor()
			{
				m_shader_definition = NULL;
			}

			const char* DataSourceID();
			const void* GetData(uint32& data_size);
			void Dispose() {}
			const bool IsBinary() { return true; }
			const char* GetIncludePath() { return NULL; }
			const D3DXMACRO* GetMacros() { return NULL; }
		};
	};};
};
#endif