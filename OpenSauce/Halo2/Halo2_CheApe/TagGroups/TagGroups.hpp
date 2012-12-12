/*
    Yelo: Open Sauce SDK
		Halo 2 (Editing Kit) Edition

	See license\OpenSauce\Halo2_CheApe for specific license information
*/
#pragma once

#include <blamlib/Halo2/tag_files/tag_groups.hpp>

namespace Yelo
{
	namespace Enums
	{
		enum field_type
		{
			_field_string,
			_field_long_string,
			_field_string_id,
			_field_old_string_id,
			_field_char_integer,
			_field_short_integer,
			_field_long_integer,
			_field_angle,
			_field_tag,
			_field_char_enum,
			_field_enum,
			_field_long_enum,
			_field_long_flags,
			_field_word_flags,
			_field_byte_flags,
			_field_point_2d,
			_field_rectangle_2d,
			_field_rgb_color,
			_field_argb_color,
			_field_real,
			_field_real_fraction,
			_field_real_point_2d,
			_field_real_point_3d,
			_field_real_vector_2d,
			_field_real_vector_3d,
			_field_real_quaternion,
			_field_real_euler_angles_2d,
			_field_real_euler_angles_3d,
			_field_real_plane_2d,
			_field_real_plane_3d,
			_field_real_rgb_color,
			_field_real_argb_color,
			_field_real_hsv_color,
			_field_real_ahsv_color,
			_field_short_bounds,
			_field_angle_bounds,
			_field_real_bounds,
			_field_real_fraction_bounds,
			_field_tag_reference,
			_field_block,
			_field_long_block_flags,
			_field_word_block_flags,
			_field_byte_block_flags,
			_field_char_block_index1,
			_field_char_block_index2,
			_field_short_block_index1,
			_field_short_block_index2,
			_field_long_block_index1,
			_field_long_block_index2,
			_field_data,
			_field_vertex_buffer,
			_field_array_start,
			_field_array_end,
			_field_pad,
			_field_useless_pad,
			_field_skip,
			_field_explanation,
			_field_custom,
			_field_struct,
			_field_terminator,

			_field_type,
		};
	};

	namespace Flags
	{
		enum tag_field_flags
		{
			// the text editor is available for data blobs of this type
			_tag_data_flag_editable =	FLAG(0),
			// the sound board is available for data blobs of this type
			_tag_data_flag_playable =	FLAG(1),
			_tag_data_flag_3 =			FLAG(2),

			_tag_reference_flag_1 =				FLAG(0),
			// reference isn't automatically loaded. up to the code to 
			// perform any loading if it wants to
			_tag_reference_flag_non_resolving =	FLAG(1),

			_tag_block_flag_1 =	FLAG(0),

			_tag_group_flag_initialized =	FLAG(0),
			_tag_group_flag_2 =				FLAG(1),
			_tag_group_flag_3 =				FLAG(2),
			_tag_group_flag_4 =				FLAG(3),
		};

		enum tag_instance_flags {
			_tag_instance_flag_was_reloaded =	FLAG(0),
			_tag_instance_flag_marked_invalid =	FLAG(1),
		};

		enum tag_loading_flags {
			_tag_loading_flag_is_new =						FLAG(0),
			//_tag_loading_flag_ = FLAG(1),
			//_tag_loading_flag_ = FLAG(2), // print errors?
			_tag_loading_flag_ignore_invalid_field_data =	FLAG(3),
			_tag_loading_flag_dont_call_block_postprocess =	FLAG(4),
			_tag_loading_flag_byte_swap =					FLAG(5),
			_tag_loading_flag_dont_call_tag_postprocess =	FLAG(6),
			_tag_loading_flag_dont_call_handle_invalid =	FLAG(7),
		};
	};


	//////////////////////////////////////////////////////////////////////////
	// tag interface

	struct s_byteswap_definition
	{
		cstring name;
		uint32 size;
		int32* codes;
		tag signature;
		bool initialized;
		PAD24;
	};

	struct tag_field
	{
		_enum field_type; PAD16;
		cstring name;
		void* definition;
		tag group_tag;

		template<typename T> API_INLINE T* Definition() const { return CAST_PTR(T*, definition); }
	};

	struct s_tag_field_set_version_upgrade_arguments {
		int32 set_index;
		tag_field* set_fields;
		int32 set_count;
		uint32 set_size;
		void* address;
	};
	typedef bool (PLATFORM_API* proc_tag_field_set_version_upgrade)(
			s_tag_field_set_version_upgrade_arguments _old,
			s_tag_field_set_version_upgrade_arguments _new
		);
	struct s_tag_field_set_version
	{
		tag_field* fields;
		int32 index;
		proc_tag_field_set_version_upgrade proc_upgrade;
		PAD32;
		uint32 size_of; // set to -1 when unused, else set to a value to override the field-set's calculated size_of
	};
	struct s_tag_field_set_runtime_data
	{
		long_flags flags;
		tag_field* fields; // contains the combined (read: with any parents) tag fields
		uint32 runtime_size;
		uint32 total_useless_pad_size;
	};
	struct tag_field_set
	{
		s_tag_field_set_version version;
		uint32 size;					// 0x14
		uint32 alignment_bit;			// 0x18
		int32 parent_version_index;		// 0x1C
		tag_field* fields;				// 0x20
		cstring size_string;			// 0x24

		s_byteswap_definition byteswap;	// 0x28

		s_tag_field_set_runtime_data runtime_info;
	}; BOOST_STATIC_ASSERT( sizeof(tag_field_set) == 0x4C );

	typedef tag_block* (PLATFORM_API* proc_block_index_custom_search_get_block)(datum_index tag_index, 
		tag_field* block_index_field, void* block_index_address, 
		void* block_index_owner); // definition instance which contains the block_index
	typedef bool (PLATFORM_API* proc_block_index_custom_search_is_valid_source_block)(void* block_index_address, tag_block_definition* definition);
	struct block_index_custom_search_definition
	{
		proc_block_index_custom_search_get_block				get_block_proc;
		proc_block_index_custom_search_is_valid_source_block	is_valid_source_block_proc;
	};

	typedef bool (PLATFORM_API* proc_tag_block_postprocess)(datum_index owner_tag_index, void* block, bool is_new);
	typedef wcstring (PLATFORM_API* proc_tag_block_format)(datum_index tag_index, tag_block* block, int32 element, 
		wchar_t* formatted_buffer, uint32 formatted_buffer_size);
	typedef void (PLATFORM_API* proc_tag_bock_generate_default_block)(void* block);
	typedef void (PLATFORM_API* proc_tag_block_dispose_element)(tag_block* block, int32 element);
	// void? (PLATFORM_API* proc_tag_block_handle_invalid)(tag owner_group_tag, cstring owner_tag_name, long_flags flags, 
	// tag group_tag, cstring tag_name, datum_index& out_tag_index)
	struct tag_block_definition
	{
		cstring			display_name;
		cstring			name;
		long_flags		flags;
		int32			max_elements;
		cstring			max_elements_string;
		tag_field_set*	field_sets;
		int32			field_set_count;
		tag_field_set*	field_set_latest;
		PAD32;

		proc_tag_block_postprocess				postprocess_proc;
		proc_tag_block_format					format_proc;
		proc_tag_bock_generate_default_block	generate_default_proc;
		proc_tag_block_dispose_element			dispose_element_proc;
		PAD32; // proc handle invalid
	}; BOOST_STATIC_ASSERT( sizeof(tag_block_definition) == 0x38 );

	struct tag_struct_definition
	{
		cstring name;
		tag group_tag;
		cstring display_name;
		tag_block_definition* block_definition;
	}; BOOST_STATIC_ASSERT( sizeof(tag_struct_definition) == 0x10 );

	struct tag_data_definition
	{
		cstring name;
		long_flags flags;
		uint32 alignment_bit;
		uint32 max_size;
		cstring max_size_identifier;
		void* byte_swap_proc;
		void* copy_proc; // return_type? (? arg_0, ? arg_4, void* buffer, int buffer_size, int? arg_10)
	}; BOOST_STATIC_ASSERT( sizeof(tag_data_definition) == 0x1C );

	struct tag_reference_definition
	{
		long_flags flags;
		tag group_tag;
		tag* group_tags;
	}; BOOST_STATIC_ASSERT( sizeof(tag_reference_definition) == 0xC );

	typedef bool (PLATFORM_API* proc_tag_group_postprocess)(datum_index tag_index, bool is_new);
	typedef bool (PLATFORM_API* proc_tag_group_postprocess_for_sync)(datum_index tag_index, void* cache_file_writer);
	typedef void (PLATFORM_API* proc_tag_group_save_preprocess)(datum_index tag_index); // TODO: verify return type
	struct tag_group_definition
	{
		cstring name;
		long_flags flags;
		tag group_tag;
		tag parent_group_tag;
		int16 version;
		bool initialized; PAD8;

		proc_tag_group_postprocess			postprocess_proc;
		proc_tag_group_save_preprocess		save_preprocess_proc;
		proc_tag_group_postprocess_for_sync	postprocess_for_sync_proc;
		PAD32; // flags

		tag_block_definition* definition;
		tag child_group_tags[16];
		int16 childs_count; PAD16;
		cstring default_tag_path;
	}; BOOST_STATIC_ASSERT( sizeof(tag_group_definition) == 0x70 );

	struct tag_instance
	{
		int16 header;				// 0x0
		word_flags flags;			// 0x2
		char* filename;				// 0x4
		tag group_tag;				// 0x8
		tag parent_group_tags[2];	// 0xC 0x10
		bool is_new;				// 0x14
		bool is_orphan;				// 0x15
		bool is_read_only;			// 0x16
		bool null_definition;		// 0x17
		bool unknown18;				// 0x18, if true, tag_new will delete this and reuse this
		bool use_block_dispose_proc;// 0x19
		PAD8; PAD8;					// 0x1A
		uint32 checksum;			// 0x1C
		tag_block root_block;		// 0x20
		uint32 hash_key;			// 0x2C
	}; BOOST_STATIC_ASSERT( sizeof(tag_instance) == 0x30 );


	namespace TagGroups
	{
		void Initialize();
		void Dispose();
	};

	tag tag_get_group_tag(datum_index tag_index);
	tag_block* tag_get_root_block(datum_index tag_index);

	bool tag_file_exists(tag group_tag, cstring name);
	void tag_block_clear(tag_block* block, tag_block_definition* definition);

	void tag_reference_zero(tag_reference& reference);
	void tag_reference_move(tag_reference& dst, tag_reference& src);
	bool tag_references_compare(const tag_reference& lhs, const tag_reference& rhs);

	void tag_block_move(tag_block* to_block, tag_block* from_block);

	void tag_reference_copy(const tag_reference& src, tag_reference& dst);
	tag_group_definition* tag_group_get_next(tag_group_definition* start = NULL);
	void* tag_data_get_pointer(tag_data& data, uint32 offset);
	char* string_id_get_string(string_id id, string_id_value out_value);
	cstring string_id_get_value(string_id id);
	void tag_block_delete_all(tag_block* block);
	datum_index find_tag_instance(tag group_tag, cstring name, datum_index* out_index = NULL);


	// Get the group definition based on a four-character code
	tag_group_definition* tag_group_get(tag group_tag);
	template<typename T>
	tag_group_definition* tag_group_get()
	{
		return tag_group_get(T::k_group_tag);
	}
	
	void tag_orphan(datum_index tag_index);
	bool tag_rename(datum_index tag_index, cstring new_name);
	datum_index tag_loaded(tag group_tag, cstring name);
	bool tag_data_resize(tag_data& data, uint32 new_size);

	
	void* tag_block_get_element_with_size(tag_block* block, int32 element_index, size_t element_size);


	bool tag_reference_is_valid(const tag_reference& reference);
	bool duplicate_recursive_tag_block(const tag_block* src_block, const int32 src_index, tag_block* dst_block, int32 dst_index);
	datum_index tag_reload(tag group_tag, cstring name);

	void tag_load_children(datum_index tag_index);
	bool tag_block_copy(const tag_block* src_block, tag_block* dst_block);
	datum_index tag_copy_and_orphan(datum_index tag_index);
};