/*
	BlamLib: .NET SDK for the Blam Engine

	See license\BlamLib\BlamLib for specific license information
*/
#pragma warning disable 1591 // "Missing XML comment for publicly visible type or member"
using System;
using System.IO;
using System.Xml;
using TI = BlamLib.TagInterface;

namespace BlamLib.Blam.Halo4.Tags
{
	public interface ITempToStreamInterface
	{
		void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner);
	};
	public interface ITempToXmlStreamInterface
	{
		void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner);
	};

	#region custom_app_globals
	partial class custom_app_globals_group : ITempToXmlStreamInterface
	{
		public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			s.WriteStartElement("capg");
			s.WriteAttributeString("name", tag.Name);
			{
				s.WriteStartElement("apps");
				foreach (var element in Apps)
				{
					s.WriteStartElement("entry");
					s.WriteAttributeString("name", element.Name.ToString());
					s.WriteAttributeString("icon", element.Icon.ToString());
					s.WriteEndElement();
				}
				s.WriteEndElement();
			}
			s.WriteEndElement();
		}
	};
	#endregion

	#region game_globals_ordnance_list
	partial class game_globals_ordnance_list_group : ITempToXmlStreamInterface
	{
		public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			s.WriteStartElement("ggol");
			s.WriteAttributeString("name", tag.Name);
			{
				s.WriteStartElement("types");
				foreach (var element in OrdnanceList)
				{
					s.WriteStartElement("entry");
					s.WriteAttributeString("name", element.Name.ToString());
					s.WriteAttributeString("lookupName", element.LookupName.ToString());
					s.WriteAttributeString("typeName", element.ObjectType.ToString());
					s.WriteEndElement();
				}
				s.WriteEndElement();

				s.WriteStartElement("sets");
				foreach (var element in OrdnanceSets)
				{
					s.WriteStartElement("entry");
					s.WriteAttributeString("name", element.Name.ToString());
					s.WriteAttributeString("lookupName", element.LookupName.ToString());
					s.WriteEndElement();
				}
				s.WriteEndElement();
			}
			s.WriteEndElement();
		}
	};
	#endregion

	#region game_medal_globals
	partial class game_medal_globals_group : ITempToStreamInterface, ITempToXmlStreamInterface
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

		public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			s.WriteStartElement("gmeg");
			s.WriteAttributeString("name", tag.Name);
			{
				s.WriteStartElement("medals");
				foreach (var element in Medals)
				{
					s.WriteStartElement("entry");
					s.WriteAttributeString("name", element.Name.ToString());
					s.WriteEndElement();
				}
				s.WriteEndElement();
			}
			s.WriteEndElement();
		}
	};
	#endregion

	#region incident_globals_definition
	partial class incident_globals_definition_group : ITempToStreamInterface, ITempToXmlStreamInterface
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

		public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			s.WriteStartElement("ingd");
			s.WriteAttributeString("name", tag.Name);
			{
				s.WriteStartElement("incidents");
				foreach (var element in Block0)
				{
					s.WriteStartElement("entry");
					if (!element.Name.Handle.IsNull)
						s.WriteAttributeString("name", element.Name.ToString());
					s.WriteEndElement();
				}
				s.WriteEndElement();
			}
			s.WriteEndElement();
		}
	};
	#endregion

	#region loadout_globals_definition
	partial class loadout_globals_definition_group : ITempToXmlStreamInterface
	{
		#region loadout_block
		partial class loadout_block
		{
			public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				s.WriteStartElement("entry");
				s.WriteAttributeString("name", Name.ToString());

				if (!AppSlot1.Handle.IsNull)
					s.WriteAttributeString("appSlot1", AppSlot1.ToString());
				if (!AppSlot2.Handle.IsNull)
					s.WriteAttributeString("appSlot2", AppSlot2.ToString());
				if (!PrimaryWeapon.Handle.IsNull)
					s.WriteAttributeString("primary", PrimaryWeapon.ToString());
				if (!SecondaryWeapon.Handle.IsNull)
					s.WriteAttributeString("secondary", SecondaryWeapon.ToString());
				if (!Equipment.Handle.IsNull)
					s.WriteAttributeString("equipment", Equipment.ToString());

				s.WriteEndElement();
			}
		}
		#endregion

		#region loadout_set_block
		partial class loadout_set_block
		{
			public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				var types = (owner as loadout_globals_definition_group).Loadouts;

				s.WriteStartElement("entry");
				s.WriteAttributeString("name", Name.ToString());

				s.WriteStartElement("loadouts");
				foreach (var element in Loadouts)
				{
					int index = element.LoadoutIndex.Value;
					string name = index >= 0 ? types[index].Name.ToString() : "NONE";

					s.WriteStartElement("entry");
					s.WriteAttributeString("typeName", name);
					s.WriteEndElement();
				}
				s.WriteEndElement();

				s.WriteEndElement();
			}
		}
		#endregion

		public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			s.WriteStartElement("lgtd");
			s.WriteAttributeString("name", tag.Name);
			{
				s.WriteStartElement("types");
				foreach (var element in Loadouts)
					element.ToStream(s, tag, this);
				s.WriteEndElement();

				s.WriteStartElement("sets");
				foreach (var element in LoadoutSets)
					element.ToStream(s, tag, this);
				s.WriteEndElement();

				s.WriteStartElement("names");
				foreach (var element in LoadoutNames)
				{
					s.WriteStartElement("entry");
					s.WriteAttributeString("name", element.Value.ToString());
					s.WriteEndElement();
				}
				s.WriteEndElement();

				s.WriteStartElement("defaults");
				foreach (var element in LoadoutDefaults)
					element.ToStream(s, tag, this);
				s.WriteEndElement();
			}
			s.WriteEndElement();
		}
	};
	#endregion

	#region megalogamengine_sounds
	partial class megalogamengine_sounds_group : ITempToStreamInterface, ITempToXmlStreamInterface
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

		public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			s.WriteStartElement("mgls");
			s.WriteAttributeString("name", tag.Name);
			{
				s.WriteStartElement("sounds");
				foreach (var element in Sounds)
				{
					s.WriteStartElement("entry");
					if (!element.Datum.IsNull)
						s.WriteAttributeString("tagName", element.GetTagPath());
					s.WriteEndElement();
				}
				s.WriteEndElement();
			}
			s.WriteEndElement();
		}
	};
	#endregion

	#region megalo_string_id_table
	partial class megalo_string_id_table_group : ITempToStreamInterface, ITempToXmlStreamInterface
	{
		#region megalo_string_id_table_C_block
		partial class megalo_string_id_table_C_block
		{
			public void ToStream(StreamWriter s, 
				Managers.TagManager tag, TI.Definition owner)
			{
				s.WriteLine("{0}\t{1}",
					Unknown0.Value.ToString("X8"), Unknown4.Value.ToString("X8"));
			}
		};
		#endregion

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

			s.WriteLine(k_ident+"BlockC");
			for (int x = 0; x < BlockC.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				BlockC[x].ToStream(s, tag, this);
			}
			s.WriteLine();
		}

		public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			s.WriteStartElement("msit");
			s.WriteAttributeString("name", tag.Name);
			{
				s.WriteStartElement("names");
				foreach (var element in Names)
				{
					s.WriteStartElement("entry");
					s.WriteAttributeString("name", element.Value.ToString());
					s.WriteEndElement();
				}
				s.WriteEndElement();
			}
			s.WriteEndElement();
		}
	};
	#endregion

	#region MultiplayerEffects
	partial class multiplayer_effects_group : ITempToStreamInterface, ITempToXmlStreamInterface
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

		public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			s.WriteStartElement("mgee");
			s.WriteAttributeString("name", tag.Name);
			{
				s.WriteStartElement("effects");
				foreach (var element in Effects)
				{
					s.WriteStartElement("entry");
					if (!element.Definition.Datum.IsNull)
						s.WriteAttributeString("tagName", element.Definition.GetTagPath());
					s.WriteEndElement();
				}
				s.WriteEndElement();
			}
			s.WriteEndElement();
		}
	};
	#endregion

	#region multiplayer_object_type_list
	partial class multiplayer_object_type_list_group : ITempToStreamInterface, ITempToXmlStreamInterface
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

			public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				s.WriteStartElement("entry");
				s.WriteAttributeString("name", Name.ToString());
				if (Definition.GroupTag != TI.TagGroup.Null)
				{
					s.WriteAttributeString("groupTag", Definition.GroupTag.TagToString());
					if (!Definition.Datum.IsNull)
						s.WriteAttributeString("tagName", Definition.GetTagPath());
				}
				s.WriteEndElement();
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

			public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				s.WriteStartElement("entry");
				int type_index = TypeIndex.Value;
				if (type_index >= 0)
				{
					var types = (owner as multiplayer_object_type_list_group).TypeList;

					s.WriteAttributeString("typeIndex", type_index.ToString());
					s.WriteAttributeString("typeName", types[type_index].Name.ToString());
				}
				if (!DescriptionText.Handle.IsNull) s.WriteAttributeString("desc", DescriptionText.ToString());
				if (!HeaderText.Handle.IsNull) s.WriteAttributeString("header", HeaderText.ToString());
				if (!HelpText.Handle.IsNull) s.WriteAttributeString("help", HelpText.ToString());
				if (!Icon.Handle.IsNull) s.WriteAttributeString("icon", Icon.ToString());
#if false
				if (Unknown10.Value > 0) s.WriteAttributeString("unk10", Unknown10.ToString());
				if (Unknown14.Value > 0) s.WriteAttributeString("unk14", Unknown14.ToString());
#endif
				s.WriteEndElement();
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

			public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				s.WriteStartElement("entry");
				s.WriteAttributeString("name", Name.ToString());
				s.WriteEndElement();
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

		public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			s.WriteStartElement("motl");
			s.WriteAttributeString("name", tag.Name);
			{
				s.WriteStartElement("types");
				foreach (var element in TypeList)
					element.ToStream(s, tag, this);
				s.WriteEndElement();

				s.WriteStartElement("weapons");
				foreach (var element in WeaponsList)
					element.ToStream(s, tag, this);
				s.WriteEndElement();

				s.WriteStartElement("vehicles");
				foreach (var element in VehiclesList)
					element.ToStream(s, tag, this);
				s.WriteEndElement();

				s.WriteStartElement("grenades");
				foreach (var element in GrenadesList)
					element.ToStream(s, tag, this);
				s.WriteEndElement();

				s.WriteStartElement("equipment");
				foreach (var element in EquipmentList)
					element.ToStream(s, tag, this);
				s.WriteEndElement();

				s.WriteStartElement("weaponSets");
				foreach (var element in WeaponSets)
					element.ToStream(s, tag, this);
				s.WriteEndElement();

				s.WriteStartElement("vehicleSets");
				foreach (var element in VehicleSets)
					element.ToStream(s, tag, this);
				s.WriteEndElement();

				s.WriteStartElement("equipmentSets");
				foreach (var element in EquipmentSets)
					element.ToStream(s, tag, this);
				s.WriteEndElement();
			}
			s.WriteEndElement();
		}
	};
	#endregion
}