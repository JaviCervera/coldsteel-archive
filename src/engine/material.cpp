#include "engine.h"

//-----------------------------------------------
//  Material functions
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
	SMaterial* mat = new SMaterial;
	mat->Name = name;
	csMaterialSetType(mat, CSMT_MODULATE);
	csMaterialSetFlags(mat, 0);
	return (int) mat;
}

//-----------------------------------------------

csInt csMaterialFromData(csMaterialData* data)
{
	SMaterial* mat = (SMaterial*) csMaterialCreate(data->name.c_str());
	csMaterialSetType(mat, data->type);
	csMaterialSetFlags(mat, data->flags);
	csMaterialSetTexture(mat, (ITexture*) csTextureLoad(data->textures[0].c_str(), 1), 0);
	csMaterialSetTexture(mat, (ITexture*) csTextureLoad(data->textures[1].c_str(), 1), 1);
	csMaterialSetAmbient(mat, data->ambient);
	csMaterialSetDiffuse(mat, data->diffuse);
	csMaterialSetEmissive(mat, data->emissive);
	csMaterialSetSpecular(mat, data->specular);
	csMaterialSetShininess(mat, data->shininess);
	csMaterialSetParam(mat, data->param);
	return (int) mat;
}

//-----------------------------------------------

csInt csMaterialToData(SMaterial* mat)
{
	if (csMaterialDataFind(csMaterialGetName(mat)))
		return 0;
	csMaterialData* data = new csMaterialData(csMaterialGetName(mat));
	csMaterialDataSetType(data, csMaterialGetType(mat));
	csMaterialDataSetFlags(data, csMaterialGetFlags(mat));
	if (csTextureFile((ITexture*) csMaterialGetTexture(mat, 0)))
		csMaterialDataSetTexture(data, csTextureFile((ITexture*) csMaterialGetTexture(mat, 0)), 0);
	if (csTextureFile((ITexture*) csMaterialGetTexture(mat, 1)))
		csMaterialDataSetTexture(data, csTextureFile((ITexture*) csMaterialGetTexture(mat, 1)), 1);
	csMaterialDataSetAmbient(data, csMaterialGetAmbient(mat));
	csMaterialDataSetDiffuse(data, csMaterialGetDiffuse(mat));
	csMaterialDataSetEmissive(data, csMaterialGetEmissive(mat));
	csMaterialDataSetSpecular(data, csMaterialGetSpecular(mat));
	csMaterialDataSetShininess(data, csMaterialGetShininess(mat));
	csMaterialDataSetParam(data, csMaterialGetParam(mat));
	return (int) data;
}

//-----------------------------------------------

csVoid csMaterialFree(SMaterial* mat)
{
	delete mat;
}

//-----------------------------------------------

csVoid csMaterialSetType(SMaterial* mat, int newtype)
{
	mat->MaterialType = getIrrLichtMaterialType(newtype);
}

//-----------------------------------------------

csVoid csMaterialSetFlags(SMaterial* mat, int flags)
{
	mat->setFlag(EMF_TRILINEAR_FILTER, true);
	if ((flags & CSMF_FULLBRIGHT) == CSMF_FULLBRIGHT) mat->setFlag(EMF_LIGHTING, false); else mat->setFlag(EMF_LIGHTING, true);
	if ((flags & CSMF_FLATSHADING) == CSMF_FLATSHADING) mat->setFlag(EMF_GOURAUD_SHADING, false); else mat->setFlag(EMF_GOURAUD_SHADING, true);
	if ((flags & CSMF_FOG) == CSMF_FOG) mat->setFlag(EMF_FOG_ENABLE, true); else mat->setFlag(EMF_FOG_ENABLE, false);
	if ((flags & CSMF_NOCULL) == CSMF_NOCULL) mat->setFlag(EMF_BACK_FACE_CULLING, false); else mat->setFlag(EMF_BACK_FACE_CULLING, true);
	if ((flags & CSMF_WIREFRAME) == CSMF_WIREFRAME) mat->setFlag(EMF_WIREFRAME, true); else mat->setFlag(EMF_WIREFRAME, false);
	if ((flags & CSMF_NOZDEPTH) == CSMF_NOZDEPTH) mat->setFlag(EMF_ZBUFFER, false); else mat->setFlag(EMF_ZBUFFER, true);
	if ((flags & CSMF_NOZWRITE) == CSMF_NOZWRITE) mat->setFlag(EMF_ZWRITE_ENABLE, false); else mat->setFlag(EMF_ZWRITE_ENABLE, true);
	if ((flags & CSMF_ANISOTROPIC) == CSMF_ANISOTROPIC) mat->setFlag(EMF_ANISOTROPIC_FILTER, true); else mat->setFlag(EMF_ANISOTROPIC_FILTER, false);
}

//-----------------------------------------------

csVoid csMaterialSetTexture(SMaterial* mat, ITexture* tex, int layer)
{
	mat->TextureLayer[layer].Texture = tex;
}

//-----------------------------------------------

csVoid csMaterialSetAmbient(SMaterial* mat, int color)
{
	mat->AmbientColor.set(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color));
}

//-----------------------------------------------

csVoid csMaterialSetDiffuse(SMaterial* mat, int color)
{
	mat->DiffuseColor.set(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color));
}

//-----------------------------------------------

csVoid csMaterialSetEmissive(SMaterial* mat, int color)
{
	mat->EmissiveColor.set(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color));
}

//-----------------------------------------------

csVoid csMaterialSetSpecular(SMaterial* mat, int color)
{
	mat->SpecularColor.set(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color));
}

//-----------------------------------------------

csVoid csMaterialSetShininess(SMaterial* mat, float shininess)
{
	mat->Shininess = shininess;
}

//-----------------------------------------------

csVoid csMaterialSetParam(SMaterial* mat, float param)
{
	mat->MaterialTypeParam = param;
}

//-----------------------------------------------

csString csMaterialGetName(SMaterial* mat)
{
	return mat->Name.c_str();
}

//-----------------------------------------------

csInt csMaterialGetType(SMaterial* mat)
{
	return getColdSteelMaterialType(mat->MaterialType);
}

//-----------------------------------------------

csInt csMaterialGetFlags(SMaterial* mat)
{
	int flags = 0;
	if (mat->getFlag(EMF_LIGHTING) == false) flags |= CSMF_FULLBRIGHT;
	if (mat->getFlag(EMF_GOURAUD_SHADING) == false) flags |= CSMF_FLATSHADING;
	if (mat->getFlag(EMF_FOG_ENABLE) == true) flags |= CSMF_FOG;
	if (mat->getFlag(EMF_BACK_FACE_CULLING) == false) flags |= CSMF_NOCULL;
	if (mat->getFlag(EMF_WIREFRAME) == true) flags |= CSMF_WIREFRAME;
	if (mat->getFlag(EMF_ZBUFFER) == false) flags |= CSMF_NOZDEPTH;
	if (mat->getFlag(EMF_ZWRITE_ENABLE) == false) flags |= CSMF_NOZWRITE;
	if (mat->getFlag(EMF_ANISOTROPIC_FILTER) == true) flags |= CSMF_ANISOTROPIC;
	return flags;
}

//-----------------------------------------------

csInt csMaterialGetTexture(SMaterial* mat, int layer)
{
	return (int)mat->TextureLayer[layer].Texture;
}

//-----------------------------------------------

csInt csMaterialGetAmbient(SMaterial* mat)
{
	return csGetColor(mat->AmbientColor.getRed(), mat->AmbientColor.getGreen(), mat->AmbientColor.getBlue(), mat->AmbientColor.getAlpha());
}

//-----------------------------------------------

csInt csMaterialGetDiffuse(SMaterial* mat)
{
	return csGetColor(mat->DiffuseColor.getRed(), mat->DiffuseColor.getGreen(), mat->DiffuseColor.getBlue(), mat->DiffuseColor.getAlpha());
}

//-----------------------------------------------

csInt csMaterialGetEmissive(SMaterial* mat)
{
	return csGetColor(mat->EmissiveColor.getRed(), mat->EmissiveColor.getGreen(), mat->EmissiveColor.getBlue(), mat->EmissiveColor.getAlpha());
}

//-----------------------------------------------

csInt csMaterialGetSpecular(SMaterial* mat)
{
	return csGetColor(mat->SpecularColor.getRed(), mat->SpecularColor.getGreen(), mat->SpecularColor.getBlue(), mat->SpecularColor.getAlpha());
}

//-----------------------------------------------

csFloat csMaterialGetShininess(SMaterial* mat)
{
	return mat->Shininess;
}

//-----------------------------------------------

csFloat csMaterialGetParam(SMaterial* mat)
{
	return mat->MaterialTypeParam;
}
