/*
	BlamLib: .NET SDK for the Blam Engine

	See license\BlamLib\BlamLib for specific license information
*/
#pragma warning disable 1591 // "Missing XML comment for publicly visible type or member"
using System;
using System.IO;
using TI = BlamLib.TagInterface;

namespace BlamLib.Blam.Halo4.Tags
{
	public interface ITempToStreamInterface
	{
		void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner);
	};

	#region game_medal_globals
	partial class game_medal_globals_group : ITempToStreamInterface
	{
		#region game_medal_globals_category_block
		partial class game_medal_globals_category_block
		{
			public void ToStream(StreamWriter s, 
				Managers.TagManager tag, TI.Definition owner)
			{
				s.WriteLine("{0}\t{1}\t{2}\t{3}",
					Unknown8, Points, 
					Name, Unknown4);
			}
		};
		#endregion

		#region game_medal_globals_medals_block
		partial class game_medal_globals_medals_block
		{
			public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				s.WriteLine("{0}\t{1}\t{2}\t{3}\t{4}\t{5}",
					Name, 
					Unknown8.Value.ToString("X4"), UnknownA.Value.ToString("X2"), 
					CategoryIndex, UnknownC, Points);
			}
		};
		#endregion

		public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			const string k_ident = "\t";

			s.WriteLine(k_ident+"Categories");
			for (int x = 0; x < Categories.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				Categories[x].ToStream(s, tag, this);
			}
			s.WriteLine();

			s.WriteLine(k_ident+"Medals");
			for (int x = 0; x < Medals.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				Medals[x].ToStream(s, tag, this);
			}
			s.WriteLine();
		}
	};
	#endregion

	#region incident_globals_definition
	partial class incident_globals_definition_group : ITempToStreamInterface
	{
		#region incident_globals_definition_0_block
		partial class incident_globals_definition_0_block
		{
			public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				const string k_ident = "\t\t\t\t";

				s.WriteLine(Name);
				s.WriteLine(k_ident+
					"Block0C={0}\t" + "Block18={1}\t" + "Block24={2}\t" + 
					"Block30={3}\t" + "Block3C={4}",
					BlockC.Count, Block18.Count, Block24.Count, 
					Block30.Count, Block3C.Count);
			}
		};
		#endregion

		public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			const string k_ident = "\t";

			s.WriteLine(k_ident+"Incidents");
			for (int x = 0; x < Block0.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				Block0[x].ToStream(s, tag, this);
			}
			s.WriteLine();
		}
	};
	#endregion

	#region megalogamengine_sounds
	partial class megalogamengine_sounds_group : ITempToStreamInterface
	{
		public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			const string k_ident = "\t";

			for (int x = 0; x < Sounds.Length; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");

				var sound_ref = Sounds[x];
				if (sound_ref.GroupTag == TI.TagGroup.Null)
					s.WriteLine("NONE");
				else
					s.WriteLine(sound_ref);
			}
			s.WriteLine();
		}
	};
	#endregion

	#region megalo_string_id_table
	partial class megalo_string_id_table_group : ITempToStreamInterface
	{
		public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			const string k_ident = "\t";

			s.WriteLine(k_ident+"Names");
			for (int x = 0; x < Names.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				s.WriteLine(Names[x]);
			}
			s.WriteLine();
		}
	};
	#endregion

	#region MultiplayerEffects
	partial class multiplayer_effects_group : ITempToStreamInterface
	{
		#region multiplayer_effect_block
		partial class multiplayer_effect_block
		{
			internal void DefinitionToStream(StreamWriter s)
			{
				if (Definition.GroupTag == TI.TagGroup.Null)
					s.Write("NONE");
				else
				{
					s.Write(Definition.GroupTag.TagToString());
					if (!Definition.Datum.IsNull)
						s.Write(Definition.GetTagPath());
					else
						s.Write("NONE");
				}
			}
			public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				s.Write("{0}\t", Name);
				DefinitionToStream(s);
				s.WriteLine();
			}
		};
		#endregion

		public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			const string k_ident = "\t";

			s.WriteLine(k_ident+"Effects");
			for (int x = 0; x < Effects.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				Effects[x].ToStream(s, tag, this);
			}
			s.WriteLine();
		}
	};
	#endregion

	#region multiplayer_object_type_list
	partial class multiplayer_object_type_list_group : ITempToStreamInterface
	{
		#region multiplayer_object_type_block
		partial class multiplayer_object_type_block
		{
			internal void DefinitionToStream(StreamWriter s)
			{
				if (Definition.GroupTag == TI.TagGroup.Null)
					s.Write("NONE");
				else
				{
					s.Write(Definition.GroupTag.TagToString());
					s.Write(" ");
					if(!Definition.Datum.IsNull)
						s.Write(Definition.GetTagPath());
					else
						s.Write("NONE");
				}
			}
			public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				s.Write("{0}\t", Name);
				DefinitionToStream(s);
				s.WriteLine();
			}
		};
		#endregion

		#region multiplayer_object_type_mapping_block
		partial class multiplayer_object_type_mapping_block
		{
			public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				TI.StringId name = DescriptionText;
				if (name.Handle.IsNull) name = HeaderText;
				if (name.Handle.IsNull) name = HelpText;
				if (name.Handle.IsNull) name = Icon;

				string name_str = "<unknown>";
				if (!name.Handle.IsNull) name_str = name.ToString();

				s.Write("{0}\t", name_str);

				int type_index = TypeIndex.Value;
				if (type_index < 0)
					s.Write("NONE");
				else
				{
					var types = (owner as multiplayer_object_type_list_group).TypeList;
					if (type_index >= types.Count)
						s.Write("--INVALID--");
					else
						types[type_index].DefinitionToStream(s);
				}
				s.WriteLine();
			}
		};
		#endregion

		#region multiplayer_object_type_set_block
		partial class multiplayer_object_type_set_block
		{
			#region multiplayer_object_type_set_entry_block
			partial class multiplayer_object_type_set_entry_block
			{
				public void ToStream(StreamWriter s,
					Managers.TagManager tag, TI.Definition owner)
				{
					s.WriteLine("{0}\t{1}", 
						ObjectMappingIndex.Value.ToString("X4"), 
						Unknown0.Value.ToString("X8"));
				}
			};
			#endregion

			public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				const string k_ident = "\t\t";

				s.WriteLine(Name);
				for (int x = 0; x < Entries.Count; x++)
				{
					s.Write(k_ident);
					s.Write("\t");
					Entries[x].ToStream(s, tag, this);
				}
			}
		};
		#endregion

		public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			const string k_ident = "\t";

			s.WriteLine(k_ident+"TypeList");
			for (int x = 0; x < TypeList.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				TypeList[x].ToStream(s, tag, this);
			}
			s.WriteLine();

			#region Lists
			s.WriteLine(k_ident+"WeaponsList");
			for (int x = 0; x < WeaponsList.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				WeaponsList[x].ToStream(s, tag, this);
			}
			s.WriteLine();

			s.WriteLine(k_ident+"VehiclesList");
			for (int x = 0; x < VehiclesList.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				VehiclesList[x].ToStream(s, tag, this);
			}
			s.WriteLine();

			s.WriteLine(k_ident+"GrenadesList");
			for (int x = 0; x < GrenadesList.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				GrenadesList[x].ToStream(s, tag, this);
			}
			s.WriteLine();

			s.WriteLine(k_ident+"EquipmentList");
			for (int x = 0; x < EquipmentList.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				EquipmentList[x].ToStream(s, tag, this);
			}
			s.WriteLine();
			#endregion

			#region Sets
			s.WriteLine(k_ident+"WeaponSets");
			for (int x = 0; x < WeaponSets.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				WeaponSets[x].ToStream(s, tag, this);
			}
			s.WriteLine();

			s.WriteLine(k_ident+"VehicleSets");
			for (int x = 0; x < VehicleSets.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				VehicleSets[x].ToStream(s, tag, this);
			}
			s.WriteLine();

			s.WriteLine(k_ident+"EquipmentSets");
			for (int x = 0; x < EquipmentSets.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				EquipmentSets[x].ToStream(s, tag, this);
			}
			s.WriteLine();
			#endregion
		}
	};
	#endregion
}