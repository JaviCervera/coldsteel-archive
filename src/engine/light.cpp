#include "engine.h"

//-----------------------------------------------
//  Light functions
//-----------------------------------------------

csInt csLightNode(ISceneNode* parent)
{
	return (int) NewNode(CSNT_LIGHT, parent);
}

//-----------------------------------------------

csVoid csLightType(ILightSceneNode* n, int type)
{
	n->getLightData().Type = (E_LIGHT_TYPE) type;
}

//-----------------------------------------------

csVoid csLightRadius(ILightSceneNode* n, float radius)
{
	n->getLightData().Radius = radius;
}

//-----------------------------------------------

csVoid csLightAmbient(ILightSceneNode* n, int color)
{
	n->getLightData().AmbientColor.set(csGetRed(color)/255.0f,csGetGreen(color)/255.0f,csGetBlue(color)/255.0f);
}

//-----------------------------------------------

csVoid csLightDiffuse(ILightSceneNode* n, int color)
{
	n->getLightData().DiffuseColor.set(csGetRed(color)/255.0f,csGetGreen(color)/255.0f,csGetBlue(color)/255.0f);
}

//-----------------------------------------------

csVoid csLightSpecular(ILightSceneNode* n, int color)
{
	n->getLightData().SpecularColor.set(csGetRed(color)/255.0f,csGetGreen(color)/255.0f,csGetBlue(color)/255.0f);
}
