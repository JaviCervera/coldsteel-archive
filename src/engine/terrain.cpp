#include "engine.h"

//-----------------------------------------------	
//  Terrain functions
//-----------------------------------------------	

csInt csTerrainNode(const char* heightmap, ISceneNode* parent, float width, float height, float depth, int col_info)
{
#ifndef COLDSTEEL_LITE
	ITerrainSceneNode* n = (ITerrainSceneNode*) NewNode(CSNT_TERRAIN, parent, heightmap);

	// Scale the terrain
	n->setScale(vector3df(width / n->getBoundingBox().getExtent().X, height / n->getBoundingBox().getExtent().Y, depth / n->getBoundingBox().getExtent().Z));

	// Create collisions
	if (col_info == 1)
	{
		ITriangleSelector* selector = Device->getSceneManager()->createTerrainTriangleSelector(n);
		n->setTriangleSelector(selector);
		selector->drop();
	}

	return (int) n;
#else
	return csNodeEmpty(parent);
#endif
}

//-----------------------------------------------	

csVoid csTerrainScaleTexture(ITerrainSceneNode* n, float scale1, float scale2)
{
#ifndef COLDSTEEL_LITE
	n->scaleTexture(scale1, scale2);
#endif
}
