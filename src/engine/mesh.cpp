#include "engine.h"
#include "IMeshCache.h"

//-----------------------------------------------	
//  Mesh functions
//-----------------------------------------------	

csInt csMeshLoad(const char* file)
{
	return (int) Device->getSceneManager()->getMesh(file);
}

//-----------------------------------------------	

csInt csMeshTerrainLoad(const char* heightmap)
{
	IImage* img = Device->getVideoDriver()->createImageFromFile(heightmap);
	return (int) Device->getSceneManager()->addTerrainMesh("*", img, img, dimension2d<f32>(1,1), 1.0f);
}

//-----------------------------------------------	

csVoid csMeshFree(IAnimatedMesh* mesh)
{
	Device->getSceneManager()->getMeshCache()->removeMesh(mesh);
}

//-----------------------------------------------	

csInt csMeshNode(IAnimatedMesh* mesh, ISceneNode* parent, int col_info, int tangent_mesh)
{
	ISceneNode* n = NewNode(CSNT_MESH, parent, "", (int) mesh, tangent_mesh);
	ITriangleSelector* selector = NULL;
	if (col_info == 1)
		selector = Device->getSceneManager()->createTriangleSelectorFromBoundingBox(n);
	else if (col_info == 2)
		selector = Device->getSceneManager()->createTriangleSelector(mesh->getMesh(0), n);
	else if (col_info == 3)
#ifndef COLDSTEEL_LITE
		selector = Device->getSceneManager()->createOctTreeTriangleSelector(mesh->getMesh(0), n);
#else
		selector = Device->getSceneManager()->createTriangleSelector(mesh->getMesh(0), n);
#endif
	if (col_info)
	{
		n->setTriangleSelector(selector);
		selector->drop();
	}

	return (int) n;
}

//-----------------------------------------------	

csInt csMeshOctreeNode(IAnimatedMesh* mesh, ISceneNode* parent, int col_info, int tangent_mesh)
{
#ifndef COLDSTEEL_LITE
	ISceneNode* n = NewNode(CSNT_MESH_OCTREE, parent, "", (int) mesh, tangent_mesh);
	ITriangleSelector* selector = NULL;
	if (col_info == 1)
		selector = Device->getSceneManager()->createTriangleSelectorFromBoundingBox(n);
	else if (col_info == 2)
		selector = Device->getSceneManager()->createTriangleSelector(mesh->getMesh(0), n);
	else if (col_info == 3)
		selector = Device->getSceneManager()->createOctTreeTriangleSelector(mesh->getMesh(0), n);
	if (col_info) {
		n->setTriangleSelector(selector);
		selector->drop();
	}

	return (int) n;
#else
	return csMeshNode(mesh, parent, col_info, tangent_mesh);
#endif
}

//-----------------------------------------------

csVoid csMeshScale(IAnimatedMesh* mesh, float sx, float sy, float sz)
{
	Device->getSceneManager()->getMeshManipulator()->scaleMesh(mesh->getMesh(0), vector3df(sx,sy,sz));
}

//-----------------------------------------------

csVoid csMeshFlip(IAnimatedMesh* mesh)
{
	Device->getSceneManager()->getMeshManipulator()->flipSurfaces(mesh->getMesh(0));
}

//-----------------------------------------------

csVoid csMeshUpdateNormals(IAnimatedMesh* mesh)
{
	Device->getSceneManager()->getMeshManipulator()->recalculateNormals(mesh->getMesh(0));
}

//-----------------------------------------------

csVoid csMeshVerticesColor(IAnimatedMesh* mesh, int color, int change_alpha)
{
	Device->getSceneManager()->getMeshManipulator()->setVertexColors(mesh->getMesh(0), SColor(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color)));
	if (change_alpha == 1) Device->getSceneManager()->getMeshManipulator()->setVertexColorAlpha(mesh->getMesh(0), csGetAlpha(color));
}

//-----------------------------------------------

csVoid csMeshPlanarMapping(IAnimatedMesh* mesh, float resolution)
{
	Device->getSceneManager()->getMeshManipulator()->makePlanarTextureMapping(mesh->getMesh(0), resolution);
}

//-----------------------------------------------

csFloat csMeshWidth(IAnimatedMesh* mesh)
{
	return mesh->getBoundingBox().getExtent().X;
}

//-----------------------------------------------

csFloat csMeshHeight(IAnimatedMesh* mesh)
{
	return mesh->getBoundingBox().getExtent().Y;
}

//-----------------------------------------------

csFloat csMeshDepth(IAnimatedMesh* mesh)
{
	return mesh->getBoundingBox().getExtent().Z;
}
