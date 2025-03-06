#include "engine.h"

std::vector<csMaterial*> mat_list;

//-----------------------------------------------
//  Material functions
//-----------------------------------------------

csMaterial::csMaterial(const char* name)
{
	mat_list.push_back(this);
	//this->name = name;
	this->mat = new SMaterial;
	this->mat->Name = name;
	csMaterialSetType(this, CSMT_MODULATE);
	csMaterialSetFlags(this, 0);
}

//-----------------------------------------------

csMaterial::~csMaterial()
{
	for (int i = 0; i < mat_list.size(); i++)
		if (mat_list[i] == this)
		{
			mat_list.erase(mat_list.begin() + i);
			break;
		}
	delete this->mat;
}

//-----------------------------------------------

E_MATERIAL_TYPE getIrrLichtMaterialType(int type)
{
	switch (type)
	{
	case CSMT_MODULATE:
		return EMT_LIGHTMAP_LIGHTING;
	case CSMT_MODULATE2X:
		return  EMT_LIGHTMAP_LIGHTING_M2;
	case CSMT_MODULATE4X:
		return EMT_LIGHTMAP_LIGHTING_M4;
	case CSMT_DETAIL:
		return EMT_DETAIL_MAP;
	case CSMT_ADD:
		return EMT_TRANSPARENT_ADD_COLOR;
	case CSMT_VERTEX_ALPHA:
		return EMT_TRANSPARENT_VERTEX_ALPHA;
	case CSMT_ALPHA:
		return EMT_TRANSPARENT_ALPHA_CHANNEL;
	case CSMT_MASKED:
		return EMT_TRANSPARENT_ALPHA_CHANNEL_REF;
	case CSMT_REFLECTION:
		return EMT_REFLECTION_2_LAYER;
	case CSMT_REFLECTION_ALPHA:
		return EMT_TRANSPARENT_REFLECTION_2_LAYER;
#ifndef COLDSTEEL_LITE
	case CSMT_NORMAL:
		return EMT_NORMAL_MAP_SOLID;
	case CSMT_PARALLAX:
		return EMT_PARALLAX_MAP_SOLID;
	default:
		return (E_MATERIAL_TYPE)((csShader*)type)->mat_type;
#else
	default:
		return (E_MATERIAL_TYPE) -1;
#endif
	}
}

//-----------------------------------------------

int getColdSteelMaterialType(E_MATERIAL_TYPE type)
{
	switch (type)
	{
	case EMT_LIGHTMAP_LIGHTING:
		return CSMT_MODULATE;
	case EMT_LIGHTMAP_LIGHTING_M2:
		return CSMT_MODULATE2X;
	case EMT_LIGHTMAP_LIGHTING_M4:
		return CSMT_MODULATE4X;
	case EMT_DETAIL_MAP:
		return CSMT_DETAIL;
	case EMT_TRANSPARENT_ADD_COLOR:
		return CSMT_ADD;
	case EMT_TRANSPARENT_VERTEX_ALPHA:
		return CSMT_VERTEX_ALPHA;
	case EMT_TRANSPARENT_ALPHA_CHANNEL:
		return CSMT_ALPHA;
	case EMT_TRANSPARENT_ALPHA_CHANNEL_REF:
		return CSMT_MASKED;
	case EMT_REFLECTION_2_LAYER:
		return CSMT_REFLECTION;
	case EMT_TRANSPARENT_REFLECTION_2_LAYER:
		return CSMT_REFLECTION_ALPHA;
#ifndef COLDSTEEL_LITE
	case EMT_NORMAL_MAP_SOLID:
		return CSMT_NORMAL;
	case EMT_PARALLAX_MAP_SOLID:
		return CSMT_PARALLAX;
#endif
	default:
		return (int) type;
	}
}

//-----------------------------------------------

void setMaterialFlag(SMaterial* mat, int flag, int state)
{
	mat->setFlag(EMF_TRILINEAR_FILTER, true);
	if (flag == CSMF_FULLBRIGHT) mat->setFlag(EMF_LIGHTING, !state);
	if (flag == CSMF_FLATSHADING) mat->setFlag(EMF_GOURAUD_SHADING, !state);
	if (flag == CSMF_FOG) mat->setFlag(EMF_FOG_ENABLE, state);
	if (flag == CSMF_NOCULL) mat->setFlag(EMF_BACK_FACE_CULLING, !state);
	if (flag == CSMF_WIREFRAME) mat->setFlag(EMF_WIREFRAME, state);
	if (flag == CSMF_NOZDEPTH) mat->setFlag(EMF_ZBUFFER, !state);
	if (flag == CSMF_NOZWRITE) mat->setFlag(EMF_ZWRITE_ENABLE, !state);
	if (flag == CSMF_ANISOTROPIC) mat->setFlag(EMF_ANISOTROPIC_FILTER, state);
}

//-----------------------------------------------

csInt csMaterialCreate(const char* name)
{
	if (csMaterialFind(name)) return 0;
	return (int) new csMaterial(name);
}

//-----------------------------------------------

csInt csMaterialLoad(const char* file)
{
	csXMLFile* xml = (csXMLFile*) csXMLRead(file);
	if (xml)
	{
		bool isMaterial = false;
		std::string matName;
		std::string matType;
		std::string matFlags;
		std::string matTex[2];
		int matAmbient = csGetColor(255, 255, 255, 255);
		int matDiffuse = csGetColor(255, 255, 255, 255);
		int matEmissive = csGetColor(0, 0, 0, 255);
		int matSpecular = csGetColor(255, 255, 255, 255);
		float matShininess;
		float matParam;
		while (csXMLReadNode(xml))
		{
			if (csXMLNodeType(xml) == 1)  // An element
			{
				if (std::string(csXMLNodeName(xml)) == "material")  isMaterial = true;
				if (std::string(csXMLNodeName(xml)) == "name")
				{
					csXMLReadNode(xml);
					matName = csXMLNodeData(xml);
				}
				if (std::string(csXMLNodeName(xml)) == "type")
				{
					csXMLReadNode(xml);
					matType = csXMLNodeData(xml);
				}
				if (std::string(csXMLNodeName(xml)) == "flags")
				{
					csXMLReadNode(xml);
					matFlags = csXMLNodeData(xml);
				}
				if (std::string(csXMLNodeName(xml)) == "texture0")
				{
					csXMLReadNode(xml);
					matTex[0] = csXMLNodeData(xml);
				}
				if (std::string(csXMLNodeName(xml)) == "texture1")
				{
					csXMLReadNode(xml);
					matTex[1] = csXMLNodeData(xml);
				}
				if (std::string(csXMLNodeName(xml)) == "ambient")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					matAmbient = csGetColor(csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 1))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 2))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 3))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 4))));
				}
				if (std::string(csXMLNodeName(xml)) == "diffuse")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					matDiffuse = csGetColor(csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 1))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 2))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 3))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 4))));
				}
				if (std::string(csXMLNodeName(xml)) == "emissive")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					matEmissive = csGetColor(csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 1))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 2))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 3))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 4))));
				}
				if (std::string(csXMLNodeName(xml)) == "specular")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					matSpecular = csGetColor(csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 1))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 2))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 3))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 4))));
				}
				if (std::string(csXMLNodeName(xml)) == "shininess")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					matShininess = csStringToFloat(str.c_str());
				}
				if (std::string(csXMLNodeName(xml)) == "param")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					matParam = csStringToFloat(str.c_str());
				}
			}
		}
		csXMLClose(xml);

		if (!isMaterial)  return 0;
		if (csMaterialFind(matName.c_str())) return 0;

		csMaterial* mat = (csMaterial*) csMaterialCreate(matName.c_str());
		if (matType == "MT_MODULATE")         csMaterialSetType(mat, CSMT_MODULATE);
		if (matType == "MT_MODULATE2X")       csMaterialSetType(mat, CSMT_MODULATE2X);
		if (matType == "MT_MODULATE4X")       csMaterialSetType(mat, CSMT_MODULATE4X);
		if (matType == "MT_DETAIL")           csMaterialSetType(mat, CSMT_DETAIL);
		if (matType == "MT_ADD")              csMaterialSetType(mat, CSMT_ADD);
		if (matType == "MT_VERTEX_ALPHA")     csMaterialSetType(mat, CSMT_VERTEX_ALPHA);
		if (matType == "MT_ALPHA")            csMaterialSetType(mat, CSMT_ALPHA);
		if (matType == "MT_MASKED")           csMaterialSetType(mat, CSMT_MASKED);
		if (matType == "MT_REFLECTION")       csMaterialSetType(mat, CSMT_REFLECTION);
		if (matType == "MT_REFLECTION_ALPHA") csMaterialSetType(mat, CSMT_REFLECTION_ALPHA);
		if (matType == "MT_NORMAL")           csMaterialSetType(mat, CSMT_NORMAL);
		if (matType == "MT_PARALLAX")         csMaterialSetType(mat, CSMT_PARALLAX);
		int flags = 0;
		if (csStringFind(matFlags.c_str(), "MF_FULLBRIGHT", 1))   flags |= CSMF_FULLBRIGHT;
		if (csStringFind(matFlags.c_str(), "MF_FLATSHADING", 1))  flags |= CSMF_FLATSHADING;
		if (csStringFind(matFlags.c_str(), "MF_FOG", 1))          flags |= CSMF_FOG;
		if (csStringFind(matFlags.c_str(), "MF_NOCULL", 1))       flags |= CSMF_NOCULL;
		if (csStringFind(matFlags.c_str(), "MF_WIREFRAME", 1))    flags |= CSMF_WIREFRAME;
		if (csStringFind(matFlags.c_str(), "MF_NOZDEPTH", 1))     flags |= CSMF_NOZDEPTH;
		if (csStringFind(matFlags.c_str(), "MF_NOZWRITE", 1))     flags |= CSMF_NOZWRITE;
		if (csStringFind(matFlags.c_str(), "MF_ANISOTROPIC", 1))  flags |= CSMF_ANISOTROPIC;
		csMaterialSetFlags(mat, flags);
		if (matTex[0] != "")
		{
			ITexture* tex = (ITexture*) csTextureLoad(matTex[0].c_str(), true);
			csMaterialSetTexture(mat, tex, 0);
		}
		if (matTex[1] != "")
		{
			ITexture* tex = (ITexture*) csTextureLoad(matTex[1].c_str(), true);
			csMaterialSetTexture(mat, tex, 1);
		}
		csMaterialSetAmbient(mat, matAmbient);
		csMaterialSetDiffuse(mat, matDiffuse);
		csMaterialSetEmissive(mat, matEmissive);
		csMaterialSetSpecular(mat, matSpecular);
		csMaterialSetShininess(mat, matShininess);
		csMaterialSetParam(mat, matParam);
		return (int) mat;
	}
	return 0;
}

//-----------------------------------------------

csVoid csMaterialSave(csMaterial* mat, const char* file, const char* rel_path)
{
#ifndef COLDSTEEL_DEMO
	csXMLFile* xml = (csXMLFile*) csXMLWrite(file);
	if (xml)
	{
		csXMLWriteHeader(xml);
		csXMLWriteElement(xml, "material", "", false); csXMLWriteLineBreak(xml);

		xmlWriteSetting(xml, "name", csMaterialGetName(mat));
		switch (csMaterialGetType(mat))
		{
		case CSMT_MODULATE:
			xmlWriteSetting(xml, "type", "MT_MODULATE");
			break;
		case CSMT_MODULATE2X:
			xmlWriteSetting(xml, "type", "MT_MODULATE2X");
			break;
		case CSMT_MODULATE4X:
			xmlWriteSetting(xml, "type", "MT_MODULATE4X");
			break;
		case CSMT_DETAIL:
			xmlWriteSetting(xml, "type", "MT_DETAIL");
			break;
		case CSMT_ADD:
			xmlWriteSetting(xml, "type", "MT_ADD");
			break;
		case CSMT_VERTEX_ALPHA:
			xmlWriteSetting(xml, "type", "MT_VERTEX_ALPHA");
			break;
		case CSMT_ALPHA:
			xmlWriteSetting(xml, "type", "MT_ALPHA");
			break;
		case CSMT_MASKED:
			xmlWriteSetting(xml, "type", "MT_MASKED");
			break;
		case CSMT_REFLECTION:
			xmlWriteSetting(xml, "type", "MT_REFLECTION");
			break;
		case CSMT_REFLECTION_ALPHA:
			xmlWriteSetting(xml, "type", "MT_REFLECTION_ALPHA");
			break;
		case CSMT_NORMAL:
			xmlWriteSetting(xml, "type", "MT_NORMAL");
			break;
		case CSMT_PARALLAX:
			xmlWriteSetting(xml, "type", "MT_PARALLAX");
			break;
		}
		if (csMaterialGetFlags(mat) != 0)
		{
			int flags = csMaterialGetFlags(mat);
			if (flags)
			{
				std::string sflags = "";
				if ((flags & CSMF_FULLBRIGHT) == CSMF_FULLBRIGHT) sflags += "MF_FULLBRIGHT, ";
				if ((flags & CSMF_FLATSHADING) == CSMF_FLATSHADING) sflags += "MF_FLATSHADING, ";
				if ((flags & CSMF_FOG) == CSMF_FOG) sflags += "MF_FOG, ";
				if ((flags & CSMF_NOCULL) == CSMF_NOCULL) sflags += "MF_NOCULL, ";
				if ((flags & CSMF_WIREFRAME) == CSMF_WIREFRAME) sflags += "MF_WIREFRAME, ";
				if ((flags & CSMF_NOZDEPTH) == CSMF_NOZDEPTH) sflags += "MF_NOZDEPTH, ";
				if ((flags & CSMF_NOZWRITE) == CSMF_NOZWRITE) sflags += "MF_NOZWRITE, ";
				if ((flags & CSMF_ANISOTROPIC) == CSMF_ANISOTROPIC) sflags += "MF_ANISOTROPIC, ";
				sflags.resize(sflags.length() - 2);
				xmlWriteSetting(xml, "flags", sflags.c_str());
			}
		}
		if (mat->mat->Textures[0])
		{
			// JEDIVE:
			//std::string tex = mat->mat->Texture1->textureFile.c_str();
			std::string tex = mat->mat->Textures[0]->getName().c_str();
			if (std::string(rel_path) != "") tex = csStringReplace(tex.c_str(), rel_path, "");
			xmlWriteSetting(xml, "texture0", tex.c_str());
		}
		if (mat->mat->Textures[1])
		{
			// JEDIVE:
			//std::string tex = mat->mat->Texture2->textureFile.c_str();
			std::string tex = mat->mat->Textures[1]->getName().c_str();
			if (std::string(rel_path) != "") tex = csStringReplace(tex.c_str(), rel_path, "");
			xmlWriteSetting(xml, "texture1", tex.c_str());
		}

		char ambient[1024];
		sprintf(ambient, "%i, %i, %i", csGetRed(csMaterialGetAmbient(mat)), csGetGreen(csMaterialGetAmbient(mat)), csGetBlue(csMaterialGetAmbient(mat)));
		xmlWriteSetting(xml, "ambient", ambient);
		char diffuse[1024];
		sprintf(diffuse, "%i, %i, %i", csGetRed(csMaterialGetDiffuse(mat)), csGetGreen(csMaterialGetDiffuse(mat)), csGetBlue(csMaterialGetDiffuse(mat)));
		xmlWriteSetting(xml, "diffuse", diffuse);
		char emissive[1024];
		sprintf(emissive, "%i, %i, %i", csGetRed(csMaterialGetEmissive(mat)), csGetGreen(csMaterialGetEmissive(mat)), csGetBlue(csMaterialGetEmissive(mat)));
		xmlWriteSetting(xml, "emissive", emissive);
		char specular[1024];
		sprintf(specular, "%i, %i, %i", csGetRed(csMaterialGetSpecular(mat)), csGetGreen(csMaterialGetSpecular(mat)), csGetBlue(csMaterialGetSpecular(mat)));
		xmlWriteSetting(xml, "specular", specular);
		xmlWriteSetting(xml, "shininess", csStringFromFloat(csMaterialGetShininess(mat)));
		xmlWriteSetting(xml, "param", csStringFromFloat(csMaterialGetParam(mat)));

		csXMLWriteClosingTag(xml, "material");
		csXMLClose(xml);
	}
#endif
}

//-----------------------------------------------

csVoid csMaterialFree(csMaterial* mat)
{
	delete mat;
}

//-----------------------------------------------

csInt csMaterialFind(const char* name)
{
	if (std::string(name) == "") return 0;
	for (int i = 0; i < mat_list.size(); i++)
		if (mat_list[i]->mat->Name == name)
			return (int) mat_list[i];
	return 0;
}

//-----------------------------------------------

csVoid csMaterialSetType(csMaterial* mat, int newtype)
{
	mat->mat->MaterialType = getIrrLichtMaterialType(newtype);
}

//-----------------------------------------------

csVoid csMaterialSetFlags(csMaterial* mat, int flags)
{
	mat->mat->setFlag(EMF_TRILINEAR_FILTER, true);
	if ((flags & CSMF_FULLBRIGHT) == CSMF_FULLBRIGHT) mat->mat->setFlag(EMF_LIGHTING, false); else mat->mat->setFlag(EMF_LIGHTING, true);
	if ((flags & CSMF_FLATSHADING) == CSMF_FLATSHADING) mat->mat->setFlag(EMF_GOURAUD_SHADING, false); else mat->mat->setFlag(EMF_GOURAUD_SHADING, true);
	if ((flags & CSMF_FOG) == CSMF_FOG) mat->mat->setFlag(EMF_FOG_ENABLE, true); else mat->mat->setFlag(EMF_FOG_ENABLE, false);
	if ((flags & CSMF_NOCULL) == CSMF_NOCULL) mat->mat->setFlag(EMF_BACK_FACE_CULLING, false); else mat->mat->setFlag(EMF_BACK_FACE_CULLING, true);
	if ((flags & CSMF_WIREFRAME) == CSMF_WIREFRAME) mat->mat->setFlag(EMF_WIREFRAME, true); else mat->mat->setFlag(EMF_WIREFRAME, false);
	if ((flags & CSMF_NOZDEPTH) == CSMF_NOZDEPTH) mat->mat->setFlag(EMF_ZBUFFER, false); else mat->mat->setFlag(EMF_ZBUFFER, true);
	if ((flags & CSMF_NOZWRITE) == CSMF_NOZWRITE) mat->mat->setFlag(EMF_ZWRITE_ENABLE, false); else mat->mat->setFlag(EMF_ZWRITE_ENABLE, true);
	if ((flags & CSMF_ANISOTROPIC) == CSMF_ANISOTROPIC) mat->mat->setFlag(EMF_ANISOTROPIC_FILTER, true); else mat->mat->setFlag(EMF_ANISOTROPIC_FILTER, false);
}

//-----------------------------------------------

csVoid csMaterialSetTexture(csMaterial* mat, ITexture* tex, int layer)
{
	mat->mat->Textures[layer] = tex;
}

//-----------------------------------------------

csVoid csMaterialSetAmbient(csMaterial* mat, int color)
{
	mat->mat->AmbientColor.set(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color));
}

//-----------------------------------------------

csVoid csMaterialSetDiffuse(csMaterial* mat, int color)
{
	mat->mat->DiffuseColor.set(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color));
}

//-----------------------------------------------

csVoid csMaterialSetEmissive(csMaterial* mat, int color)
{
	mat->mat->EmissiveColor.set(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color));
}

//-----------------------------------------------

csVoid csMaterialSetSpecular(csMaterial* mat, int color)
{
	mat->mat->SpecularColor.set(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color));
}

//-----------------------------------------------

csVoid csMaterialSetShininess(csMaterial* mat, float shininess)
{
	mat->mat->Shininess = shininess;
}

//-----------------------------------------------

csVoid csMaterialSetParam(csMaterial* mat, float param)
{
	mat->mat->MaterialTypeParam = param;
}

//-----------------------------------------------

csString csMaterialGetName(csMaterial* mat)
{
	return mat->mat->Name.c_str();
}

//-----------------------------------------------

csInt csMaterialGetType(csMaterial* mat)
{
	return getColdSteelMaterialType(mat->mat->MaterialType);
}

//-----------------------------------------------

csInt csMaterialGetFlags(csMaterial* mat)
{
	int flags = 0;
	if (mat->mat->getFlag(EMF_LIGHTING) == false) flags |= CSMF_FULLBRIGHT;
	if (mat->mat->getFlag(EMF_GOURAUD_SHADING) == false) flags |= CSMF_FLATSHADING;
	if (mat->mat->getFlag(EMF_FOG_ENABLE) == true) flags |= CSMF_FOG;
	if (mat->mat->getFlag(EMF_BACK_FACE_CULLING) == false) flags |= CSMF_NOCULL;
	if (mat->mat->getFlag(EMF_WIREFRAME) == true) flags |= CSMF_WIREFRAME;
	if (mat->mat->getFlag(EMF_ZBUFFER) == false) flags |= CSMF_NOZDEPTH;
	if (mat->mat->getFlag(EMF_ZWRITE_ENABLE) == false) flags |= CSMF_NOZWRITE;
	if (mat->mat->getFlag(EMF_ANISOTROPIC_FILTER) == true) flags |= CSMF_ANISOTROPIC;
	return flags;
}

//-----------------------------------------------

csInt csMaterialGetTexture(csMaterial* mat, int layer)
{
	return (int)mat->mat->Textures[layer];
}

//-----------------------------------------------

csInt csMaterialGetAmbient(csMaterial* mat)
{
	return csGetColor(mat->mat->AmbientColor.getRed(), mat->mat->AmbientColor.getGreen(), mat->mat->AmbientColor.getBlue(), mat->mat->AmbientColor.getAlpha());
}

//-----------------------------------------------

csInt csMaterialGetDiffuse(csMaterial* mat)
{
	return csGetColor(mat->mat->DiffuseColor.getRed(), mat->mat->DiffuseColor.getGreen(), mat->mat->DiffuseColor.getBlue(), mat->mat->DiffuseColor.getAlpha());
}

//-----------------------------------------------

csInt csMaterialGetEmissive(csMaterial* mat)
{
	return csGetColor(mat->mat->EmissiveColor.getRed(), mat->mat->EmissiveColor.getGreen(), mat->mat->EmissiveColor.getBlue(), mat->mat->EmissiveColor.getAlpha());
}

//-----------------------------------------------

csInt csMaterialGetSpecular(csMaterial* mat)
{
	return csGetColor(mat->mat->SpecularColor.getRed(), mat->mat->SpecularColor.getGreen(), mat->mat->SpecularColor.getBlue(), mat->mat->SpecularColor.getAlpha());
}

//-----------------------------------------------

csFloat csMaterialGetShininess(csMaterial* mat)
{
	return mat->mat->Shininess;
}

//-----------------------------------------------

csFloat csMaterialGetParam(csMaterial* mat)
{
	return mat->mat->MaterialTypeParam;
}
