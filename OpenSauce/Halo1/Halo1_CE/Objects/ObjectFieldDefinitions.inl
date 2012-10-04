/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

static s_object_field_definition g_object_real_fields[] = {
	FIELD_ENTRY(object, real, real, function_out, false, true),

	FIELD_ENTRY(object, real, vector, position,					true),
	FIELD_ENTRY(object, real, vector, transitional_velocity,	true),
	FIELD_ENTRY(object, real, vector, forward,					true),
	FIELD_ENTRY(object, real, vector, up,						true),
	FIELD_ENTRY(object, real, vector, angular_velocity,			true),

	FIELD_ENTRY(unit, real, vector, desired_facing,				true),
	FIELD_ENTRY(unit, real, vector, desired_aiming),
	FIELD_ENTRY(unit, real, vector, aiming),
	FIELD_ENTRY(unit, real, vector, aiming_velocity),
	FIELD_ENTRY(unit, real, vector, looking),
	FIELD_ENTRY(unit, real, vector, looking_angles),
	FIELD_ENTRY(unit, real, vector, looking_velocity),
};


static s_object_field_definition g_weapon_real_fields[] = {
	FIELD_ENTRY(weapon, real, real, heat),
	FIELD_ENTRY(weapon, real, real, age,			true),
	FIELD_ENTRY(weapon, real, real, light_power),
};

static s_object_field_definition g_weapon_tag_real_trigger_fields[] = {
	FIELD_ENTRY2(weapon_tag, real, real, trigger_spew_time,			"spew_time"),
	FIELD_ENTRY2(weapon_tag, real, real, trigger_rounds_per_second,	"rounds_per_second"),
};


static s_object_field_definition g_unit_object_index_fields[] = {
	FIELD_ENTRY( unit, weapon,		object_index, weapon,									true,  true),
	FIELD_ENTRY2(unit, unit,		object_index, recent_damage_unit, "recent_damage.unit",	false, true),
};


// We use bool for byte-size fields as hs_type doesn't have an 8-bit integer
static s_object_field_definition g_unit_integer_fields[] = {
	FIELD_ENTRY2(unit, bool, integer, total_grenade_count_frag,		"total_grenade_count[frag]",	true),
	FIELD_ENTRY2(unit, bool, integer, total_grenade_count_plasma,	"total_grenade_count[plasma]",	true),
	FIELD_ENTRY2(unit, bool, integer, total_grenade_count_custom2,	"total_grenade_count[custom2]",	true),
	FIELD_ENTRY2(unit, bool, integer, total_grenade_count_custom3,	"total_grenade_count[custom3]",	true),

	FIELD_ENTRY(unit, bool, integer, current_grenade_index,	false, true),
	FIELD_ENTRY(unit, bool, integer, zoom_level,			false, true),
	FIELD_ENTRY(unit, bool, integer, desired_zoom_level,	true),

	FIELD_ENTRY(unit, short, integer, vehicle_seat_index,	false, true),
	FIELD_ENTRY(unit, short, integer, current_weapon_index,	true,  true),
	FIELD_ENTRY(unit, short, integer, feign_death_timer),
};


static s_object_field_definition g_unit_real_fields[] = {
	FIELD_ENTRY(unit, real, real, camo_power),
	FIELD_ENTRY(unit, real, real, driver_power),
	FIELD_ENTRY(unit, real, real, gunner_power),
};