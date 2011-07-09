/*
    BlamLib: .NET SDK for the Blam Engine

    Copyright (C) 2005-2010  Kornner Studios (http://kornner.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
using System;
using System.ComponentModel;
using System.Xml;
using System.Xml.Serialization;
using System.Collections.Generic;
using BlamLib.Render.COLLADA.Validation;

namespace BlamLib.Render.COLLADA.Fx
{
	[SerializableAttribute()]
	[XmlTypeAttribute(AnonymousType = true)]
	public partial class ColladaEffect : ColladaElement
	{
		#region Fields
		ColladaObjectAttribute<string> _id;
		ColladaObjectAttribute<string> _name;
		ColladaObjectElement<Core.ColladaAsset> _asset;
		ColladaObjectElementList<ColladaAnnotate> _annotate;
		ColladaObjectElementList<ColladaImage> _image;
		ColladaObjectElementList<ColladaNewparam> _newparam;
		ColladaObjectElementList<ColladaProfileCOMMON> _profileCOMMON;
		ColladaObjectElementList<Core.ColladaExtra> _extra;
		#endregion

		#region Attributes
		[XmlAttribute("id"), ColladaID("effect-{0}")]
		public string ID
		{ get { return _id.Value; } set { _id.Value = value; } }

		[XmlAttribute("name"), DefaultValue("")]
		public string Name
		{ get { return _name.Value; } set { _name.Value = value; } }
		#endregion

		#region Children
		[XmlElement("asset")]
		public Core.ColladaAsset Asset
		{ get { return _asset.Value; } set { _asset.Value = value; } }

		[XmlElement("annotate")]
		public List<ColladaAnnotate> Annotate
		{ get { return _annotate.Value; } set { _annotate.Value = value; } }

		[XmlElement("image")]
		public List<ColladaImage> Image
		{ get { return _image.Value; } set { _image.Value = value; } }

		[XmlElement("newparam")]
		public List<ColladaNewparam> Newparam
		{ get { return _newparam.Value; } set { _newparam.Value = value; } }

		[XmlElement("profile_COMMON")]
		public List<ColladaProfileCOMMON> ProfileCOMMON
		{ get { return _profileCOMMON.Value; } set { _profileCOMMON.Value = value; } }

		[XmlElement("extra")]
		public List<Core.ColladaExtra> Extra
		{ get { return _extra.Value; } set { _extra.Value = value; } }
		#endregion

		public ColladaEffect() : base(Enums.ColladaElementType.Fx_Effect)
		{
			Fields.Add(_id = new ColladaObjectAttribute<string>(""));
			Fields.Add(_name = new ColladaObjectAttribute<string>(""));
			Fields.Add(_asset = new ColladaObjectElement<Core.ColladaAsset>());
			Fields.Add(_annotate = new ColladaObjectElementList<ColladaAnnotate>());
			Fields.Add(_image = new ColladaObjectElementList<ColladaImage>());
			Fields.Add(_newparam = new ColladaObjectElementList<ColladaNewparam>());
			Fields.Add(_profileCOMMON = new ColladaObjectElementList<ColladaProfileCOMMON>());
			Fields.Add(_extra = new ColladaObjectElementList<Core.ColladaExtra>());

			ValidationTests.Add(new ColladaIsNull(Enums.ColladaElementType.All, _id));
			ValidationTests.Add(new ColladaEmptyString(Enums.ColladaElementType.All, _id));
			ValidationTests.Add(new ColladaIsNull(Enums.ColladaElementType.All, _profileCOMMON));
			ValidationTests.Add(new ColladaListMinCount<ColladaProfileCOMMON>(Enums.ColladaElementType.All, _profileCOMMON, 1));
		}
	}
}