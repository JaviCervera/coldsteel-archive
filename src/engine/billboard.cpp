#include "engine.h"

//-----------------------------------------------	
//  Billboard functions
//-----------------------------------------------	

csInt csBillboardNode(ISceneNode* parent)
{
	return (int) NewNode(CSNT_BILLBOARD, parent);
}

//-----------------------------------------------	

csVoid csBillboardResize(IBillboardSceneNode* n, float width, float height)
{
	n->setSize(dimension2d<f32>(width, height));
}

//-----------------------------------------------	

csFloat csBillboardWidth(IBillboardSceneNode* n)
{
	return n->getSize().Width;
}

//-----------------------------------------------	

csFloat csBillboardHeight(IBillboardSceneNode* n)
{
	return n->getSize().Height;
}
