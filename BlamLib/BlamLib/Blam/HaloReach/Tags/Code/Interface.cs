/*
	BlamLib: .NET SDK for the Blam Engine

	See license\BlamLib\BlamLib for specific license information
*/
#pragma warning disable 1591 // "Missing XML comment for publicly visible type or member"
using System;
using System.IO;
using System.Xml;
using TI = BlamLib.TagInterface;

namespace BlamLib.Blam.HaloReach.Tags
{
	#region multiplayer_variant_settings_interface_definition
	partial class multiplayer_variant_settings_interface_definition_group : ITempToStreamInterface, ITempToXmlStreamInterface
	{
		#region multiplayer_variant_settings_interface_definition_0_block
		partial class multiplayer_variant_settings_interface_definition_0_block
		{
			#region unknown_4_block
			partial class unknown_4_block
			{
				static void ReferenceToStream(StreamWriter s, TI.TagReference tr)
				{
					if (tr.GroupTag == TI.TagGroup.Null)
						s.Write("NONE");
					else
					{
						s.Write(tr.GroupTag.TagToString());
						s.Write(" ");
						if (!tr.Datum.IsNull)
							s.Write(tr.GetTagPath());
						else
							s.Write("NONE");
					}
				}

				public void ToStream(StreamWriter s,
					Managers.TagManager tag, TI.Definition owner)
				{
					const string k_ident = "\t\t\t\t";

					if(Unknown20 != 0)
						s.Write("{0}\t", Unknown20.Value.ToString("X8"));
					if (!Title.Handle.IsNull)
						s.Write("{0}", Title);
					s.WriteLine();
					if (!Settings.Datum.IsNull)
					{
						s.Write(k_ident+"\tSettings\t"); ReferenceToStream(s, Settings);
						s.WriteLine();
					}
					if (!Template.Datum.IsNull)
					{
						s.Write(k_ident+"\tTemplate\t"); ReferenceToStream(s, Template);
						s.WriteLine();
					}
					if (!ValuePairs.Datum.IsNull)
					{
						s.Write(k_ident+"\tValuePairs\t"); ReferenceToStream(s, ValuePairs);
						s.WriteLine();
					}
				}

				public void ToStream(XmlWriter s,
					Managers.TagManager tag, TI.Definition owner)
				{
					s.WriteStartElement("entry");

					if (!Title.Handle.IsNull)
						s.WriteAttributeString("titleId", Title.ToString());
					if (!Description.Handle.IsNull)
						s.WriteAttributeString("descId", Description.ToString());
					if (Unknown20 != 0)
						s.WriteAttributeString("settingCategory", Unknown20.ToString());

					if (!Settings.Datum.IsNull)
						s.WriteElementString("settings", Settings.GetTagPath());
					if (!Template.Datum.IsNull)
						s.WriteElementString("template", Template.GetTagPath());
					if (!ValuePairs.Datum.IsNull)
						s.WriteElementString("values", ValuePairs.GetTagPath());

					s.WriteEndElement();
				}
			};
			#endregion

			public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				const string k_ident = "\t\t\t";

				s.WriteLine("{0}\t{1}", SettingCategory.Value.ToString("X8"), Name);
				s.WriteLine(k_ident+"Options");
				for (int x = 0; x < Options.Count; x++)
				{
					s.Write(k_ident+"\t");
					s.Write(x.ToString("X4"));
					s.Write("\t");
					Options[x].ToStream(s, tag, this);
				}
				s.WriteLine();
			}

			public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				s.WriteStartElement("entry");
				s.WriteAttributeString("settingCategory", SettingCategory.Value.ToString());
				s.WriteAttributeString("name", Name.ToString());

				s.WriteStartElement("options");
				foreach (var opt in Options)
					opt.ToStream(s, tag, this);
				s.WriteEndElement();

				s.WriteEndElement();
			}
		};
		#endregion

		public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			const string k_ident = "\t";

			if (Unknown0.Value != 0)
				System.Diagnostics.Debugger.Break();
			s.WriteLine(k_ident+"Unknown0={0}", Unknown0.Value.ToString("X8"));
			s.WriteLine(k_ident+"Categories");
			for (int x = 0; x < Categories.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				Categories[x].ToStream(s, tag, this);
			}
			s.WriteLine();
		}

		public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			s.WriteStartElement("goof");
			s.WriteAttributeString("name", tag.Name);
			{
				s.WriteStartElement("categories");
				foreach (var cat in Categories)
					cat.ToStream(s, tag, this);
				s.WriteEndElement();
			}
			s.WriteEndElement();
		}
	};
	#endregion

	#region text_value_pair_definition_group
	partial class text_value_pair_definition_group : ITempToStreamInterface, ITempToXmlStreamInterface
	{
		#region text_value_pair_reference_block
		partial class text_value_pair_reference_block
		{
			public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				const string k_ident = "\t\t\t\t";

				s.WriteLine(Name);
				s.WriteLine(k_ident+
					"Type={0}\t" + "Integer={1}\t" + "StringId={2}\t" + "Flags={3}\t",
					Type, Integer.Value.ToString("X8"), StringId, Flags);
			}

			public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
			{
				s.WriteStartElement("entry");

				//s.WriteAttributeString("type", Type.ToString());
				s.WriteAttributeString("labelId", Name.ToString());
				if (!Description.Handle.IsNull) s.WriteAttributeString("descId", Description.ToString());
				switch (Type.Value)
				{
					case 0: s.WriteAttributeString("int", Integer.Value.ToString()); break;
					case 1: s.WriteAttributeString("stringId", StringId.ToString()); break;
				}
				if(Flags.Value != 0)
					s.WriteAttributeString("flags", Flags.ToString());

				s.WriteEndElement();
			}
		};
		#endregion

		public void ToStream(StreamWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			const string k_ident = "\t";

			s.WriteLine(k_ident+"Title={0}", Title);
			s.WriteLine(k_ident+"Values");
			for (int x = 0; x < Values.Count; x++)
			{
				s.Write(k_ident+"\t");
				s.Write(x.ToString("X4"));
				s.Write("\t");
				Values[x].ToStream(s, tag, this);
			}
			s.WriteLine();
		}

		public void ToStream(XmlWriter s,
				Managers.TagManager tag, TI.Definition owner)
		{
			s.WriteStartElement("sily");
			s.WriteAttributeString("name", tag.Name);
			{
				s.WriteAttributeString("titleId", Title.ToString());
				if(!Description.Handle.IsNull) s.WriteAttributeString("descId", Description.ToString());

				s.WriteStartElement("values");
				s.WriteAttributeString("type", Values[0].Type.ToString());
				foreach (var vp in Values)
					vp.ToStream(s, tag, this);
				s.WriteEndElement();
			}
			s.WriteEndElement();
		}
	};
	#endregion
}