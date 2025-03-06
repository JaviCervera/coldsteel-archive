#include "engine.h"

std::vector<csMaterialData*> csMaterialData::list;

//-----------------------------------------------
//  Material functions
//-----------------------------------------------

void CleanMaterialDatas()
{
   csMaterialData::list.clear();
}

//-----------------------------------------------

csMaterialData::csMaterialData(const char* name)
{
	list.push_back(this);
	this->name = name;
}

//-----------------------------------------------

csMaterialData::~csMaterialData()
{
	for (int i = 0; i < list.size(); i++)
		if (list[i] == this)
		{
			list.erase(list.begin() + i);
			break;
		}
}

//-----------------------------------------------

csInt csMaterialDataCreate(const char* name)
{
	if (csMaterialDataFind(name)) return 0;
	return (int) new csMaterialData(name);
}

//-----------------------------------------------

csInt csMaterialDataLoad(const char* file)
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
		if (csMaterialDataFind(matName.c_str())) return 0;

		csMaterialData* mat = (csMaterialData*) csMaterialDataCreate(matName.c_str());
		if (matType == "MT_MODULATE")         csMaterialDataSetType(mat, CSMT_MODULATE);
		if (matType == "MT_MODULATE2X")       csMaterialDataSetType(mat, CSMT_MODULATE2X);
		if (matType == "MT_MODULATE4X")       csMaterialDataSetType(mat, CSMT_MODULATE4X);
		if (matType == "MT_DETAIL")           csMaterialDataSetType(mat, CSMT_DETAIL);
		if (matType == "MT_ADD")              csMaterialDataSetType(mat, CSMT_ADD);
		if (matType == "MT_VERTEX_ALPHA")     csMaterialDataSetType(mat, CSMT_VERTEX_ALPHA);
		if (matType == "MT_ALPHA")            csMaterialDataSetType(mat, CSMT_ALPHA);
		if (matType == "MT_MASKED")           csMaterialDataSetType(mat, CSMT_MASKED);
		if (matType == "MT_REFLECTION")       csMaterialDataSetType(mat, CSMT_REFLECTION);
		if (matType == "MT_REFLECTION_ALPHA") csMaterialDataSetType(mat, CSMT_REFLECTION_ALPHA);
		if (matType == "MT_NORMAL")           csMaterialDataSetType(mat, CSMT_NORMAL);
		if (matType == "MT_PARALLAX")         csMaterialDataSetType(mat, CSMT_PARALLAX);
		int flags = 0;
		if (csStringFind(matFlags.c_str(), "MF_FULLBRIGHT", 1))   flags |= CSMF_FULLBRIGHT;
		if (csStringFind(matFlags.c_str(), "MF_FLATSHADING", 1))  flags |= CSMF_FLATSHADING;
		if (csStringFind(matFlags.c_str(), "MF_FOG", 1))          flags |= CSMF_FOG;
		if (csStringFind(matFlags.c_str(), "MF_NOCULL", 1))       flags |= CSMF_NOCULL;
		if (csStringFind(matFlags.c_str(), "MF_WIREFRAME", 1))    flags |= CSMF_WIREFRAME;
		if (csStringFind(matFlags.c_str(), "MF_NOZDEPTH", 1))     flags |= CSMF_NOZDEPTH;
		if (csStringFind(matFlags.c_str(), "MF_NOZWRITE", 1))     flags |= CSMF_NOZWRITE;
		if (csStringFind(matFlags.c_str(), "MF_ANISOTROPIC", 1))  flags |= CSMF_ANISOTROPIC;
		csMaterialDataSetFlags(mat, flags);
		csMaterialDataSetTexture(mat, matTex[0].c_str(), 0);
		csMaterialDataSetTexture(mat, matTex[1].c_str(), 1);
		csMaterialDataSetAmbient(mat, matAmbient);
		csMaterialDataSetDiffuse(mat, matDiffuse);
		csMaterialDataSetEmissive(mat, matEmissive);
		csMaterialDataSetSpecular(mat, matSpecular);
		csMaterialDataSetShininess(mat, matShininess);
		csMaterialDataSetParam(mat, matParam);
		return (int) mat;
	}
	return 0;
}

//-----------------------------------------------

csVoid csMaterialDataSave(csMaterialData* mat, const char* file, const char* rel_path)
{
#ifndef COLDSTEEL_DEMO
	csXMLFile* xml = (csXMLFile*) csXMLWrite(file);
	if (xml)
	{
		csXMLWriteHeader(xml);
		csXMLWriteElement(xml, "material", "", false); csXMLWriteLineBreak(xml);

		xmlWriteSetting(xml, "name", csMaterialDataGetName(mat));
		switch (csMaterialDataGetType(mat))
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
		if (csMaterialDataGetFlags(mat) != 0)
		{
			int flags = csMaterialDataGetFlags(mat);
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
		if (csMaterialDataGetTexture(mat, 0))
		{
			std::string tex = csMaterialDataGetTexture(mat, 0);
			if (std::string(rel_path) != "") tex = csStringReplace(tex.c_str(), rel_path, "");
			xmlWriteSetting(xml, "texture0", tex.c_str());
		}
		if (csMaterialDataGetTexture(mat, 1))
		{
			std::string tex = csMaterialDataGetTexture(mat, 1);
			if (std::string(rel_path) != "") tex = csStringReplace(tex.c_str(), rel_path, "");
			xmlWriteSetting(xml, "texture1", tex.c_str());
		}

		char ambient[1024];
		sprintf(ambient, "%i, %i, %i", csGetRed(csMaterialDataGetAmbient(mat)), csGetGreen(csMaterialDataGetAmbient(mat)), csGetBlue(csMaterialDataGetAmbient(mat)));
		xmlWriteSetting(xml, "ambient", ambient);
		char diffuse[1024];
		sprintf(diffuse, "%i, %i, %i", csGetRed(csMaterialDataGetDiffuse(mat)), csGetGreen(csMaterialDataGetDiffuse(mat)), csGetBlue(csMaterialDataGetDiffuse(mat)));
		xmlWriteSetting(xml, "diffuse", diffuse);
		char emissive[1024];
		sprintf(emissive, "%i, %i, %i", csGetRed(csMaterialDataGetEmissive(mat)), csGetGreen(csMaterialDataGetEmissive(mat)), csGetBlue(csMaterialDataGetEmissive(mat)));
		xmlWriteSetting(xml, "emissive", emissive);
		char specular[1024];
		sprintf(specular, "%i, %i, %i", csGetRed(csMaterialDataGetSpecular(mat)), csGetGreen(csMaterialDataGetSpecular(mat)), csGetBlue(csMaterialDataGetSpecular(mat)));
		xmlWriteSetting(xml, "specular", specular);
		xmlWriteSetting(xml, "shininess", csStringFromFloat(csMaterialDataGetShininess(mat)));
		xmlWriteSetting(xml, "param", csStringFromFloat(csMaterialDataGetParam(mat)));

		csXMLWriteClosingTag(xml, "material");
		csXMLClose(xml);
	}
#endif
}

//-----------------------------------------------

csVoid csMaterialDataFree(csMaterialData* mat)
{
	delete mat;
}

//-----------------------------------------------

csInt csMaterialDataFind(const char* name)
{
	if (std::string(name) == "") return 0;
	for (int i = 0; i < csMaterialData::list.size(); i++)
		if (csMaterialData::list[i]->name == name)
			return (int) csMaterialData::list[i];
	return 0;
}

//-----------------------------------------------

csVoid csMaterialDataSetType(csMaterialData* mat, int newtype)
{
	mat->type = getIrrLichtMaterialType(newtype);
}

//-----------------------------------------------

csVoid csMaterialDataSetFlags(csMaterialData* mat, int flags)
{
	mat->flags = flags;
}

//-----------------------------------------------

csVoid csMaterialDataSetTexture(csMaterialData* mat, const char* name, int layer)
{
	mat->textures[layer] = name;
}

//-----------------------------------------------

csVoid csMaterialDataSetAmbient(csMaterialData* mat, int color)
{
	mat->ambient = color;
}

//-----------------------------------------------

csVoid csMaterialDataSetDiffuse(csMaterialData* mat, int color)
{
	mat->diffuse = color;
}

//-----------------------------------------------

csVoid csMaterialDataSetEmissive(csMaterialData* mat, int color)
{
	mat->emissive = color;
}

//-----------------------------------------------

csVoid csMaterialDataSetSpecular(csMaterialData* mat, int color)
{
	mat->specular = color;
}

//-----------------------------------------------

csVoid csMaterialDataSetShininess(csMaterialData* mat, float shininess)
{
	mat->shininess = shininess;
}

//-----------------------------------------------

csVoid csMaterialDataSetParam(csMaterialData* mat, float param)
{
	mat->param = param;
}

//-----------------------------------------------

csString csMaterialDataGetName(csMaterialData* mat)
{
	return mat->name.c_str();
}

//-----------------------------------------------

csInt csMaterialDataGetType(csMaterialData* mat)
{
	return mat->type;
}

//-----------------------------------------------

csInt csMaterialDataGetFlags(csMaterialData* mat)
{
	return mat->flags;
}

//-----------------------------------------------

csString csMaterialDataGetTexture(csMaterialData* mat, int layer)
{
	return mat->textures[layer].c_str();
}

//-----------------------------------------------

csInt csMaterialDataGetAmbient(csMaterialData* mat)
{
	return mat->ambient;
}

//-----------------------------------------------

csInt csMaterialDataGetDiffuse(csMaterialData* mat)
{
	return mat->diffuse;
}

//-----------------------------------------------

csInt csMaterialDataGetEmissive(csMaterialData* mat)
{
	return mat->emissive;
}

//-----------------------------------------------

csInt csMaterialDataGetSpecular(csMaterialData* mat)
{
	return mat->specular;
}

//-----------------------------------------------

csFloat csMaterialDataGetShininess(csMaterialData* mat)
{
	return mat->shininess;
}

//-----------------------------------------------

csFloat csMaterialDataGetParam(csMaterialData* mat)
{
	return mat->param;
}
