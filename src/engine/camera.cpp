#include "engine.h"

//-----------------------------------------------
//	Camera Functions
//-----------------------------------------------

csCameraData::csCameraData()
{
	vx1 = 0.0;
	vy1 = 0.0;
	vx2 = 1.0;
	vy2 = 1.0;
	rendertarget = NULL;
	clearflags = 3;
	clearcolor = 0;
}

//-----------------------------------------------

csInt csCameraNode(ISceneNode* parent)
{
	return (int) NewNode(CSNT_CAMERA, parent);
}

//-----------------------------------------------

csVoid csCameraViewport(ICameraSceneNode* cam, float x1, float y1, float x2, float y2)
{
	csCameraData* c = (csCameraData*) ((csNodeData*)cam->UserData)->data;
	c->vx1 = x1;
	c->vy1 = y1;
	c->vx2 = x2;
	c->vy2 = y2;
}

//-----------------------------------------------

csVoid csCameraRange(ICameraSceneNode* cam, float near_, float far_)
{
	cam->setNearValue(near_);
	cam->setFarValue(far_);
}

//-----------------------------------------------

csVoid csCameraFov(ICameraSceneNode* cam, float fov)
{
	cam->setFOV(fov);
}

//-----------------------------------------------

csVoid csCameraAspectRatio(ICameraSceneNode* cam, float ratio)
{
	cam->setAspectRatio(ratio);
}

//-----------------------------------------------

csVoid csCameraProjection(ICameraSceneNode* cam, float width, float height, float near_, float far_, int ortho)
{
	matrix4 mat;
	if (ortho == 0)
		mat.buildProjectionMatrixPerspectiveLH(width, height, near_, far_);
	else if (ortho == 1)
		mat.buildProjectionMatrixOrthoLH(width, height, near_, far_);
	cam->setProjectionMatrix(mat);
}

//-----------------------------------------------

csVoid csCameraLine(ICameraSceneNode* cam, int x, int y, csVector* vec_line_a, csVector* vec_line_b)
{
	line3d<f32> ray = Device->getSceneManager()->getSceneCollisionManager()->getRayFromScreenCoordinates(position2d<s32>(x,y), cam);
	if (vec_line_a) { vec_line_a->x = ray.start.X; vec_line_a->y = ray.start.Y; vec_line_a->z = ray.start.Z; }
	if (vec_line_b) { vec_line_b->x = ray.end.X; vec_line_b->y = ray.end.Y; vec_line_b->z = ray.end.Z; }
}

//-----------------------------------------------

csInt csCameraPickNode(ICameraSceneNode* cam, int x, int y, int group)
{
	ISceneNode* n;
	if ((x < 0) || (y < 0))
	{
		n = Device->getSceneManager()->getSceneCollisionManager()->getSceneNodeFromCameraBB(cam, group);
	} else {
		ICameraSceneNode* c = Device->getSceneManager()->getActiveCamera();
		Device->getSceneManager()->setActiveCamera(cam);
		n = Device->getSceneManager()->getSceneCollisionManager()->getSceneNodeFromScreenCoordinatesBB(position2d<s32>(x,y), group);
		Device->getSceneManager()->setActiveCamera(c);
	}
	return (int) n;
}

//-----------------------------------------------

csVoid csCameraToScreen(ICameraSceneNode* cam, float x, float y, float z, csVector* vec_out)
{
	position2d<s32> pos = Device->getSceneManager()->getSceneCollisionManager()->getScreenCoordinatesFrom3DPosition(vector3df(x,y,z), cam);
	if (vec_out) { vec_out->x = pos.X; vec_out->y = pos.Y; }
}

//-----------------------------------------------

csVoid csCameraRenderTarget(ICameraSceneNode* cam, ITexture* texture)
{
	((csCameraData*)((csNodeData*)cam->UserData)->data)->rendertarget = texture;
}

//-----------------------------------------------

csVoid csCameraClearFlags(ICameraSceneNode* cam, int flags, int color)
{
	((csCameraData*)((csNodeData*)cam->UserData)->data)->clearflags = flags;
	((csCameraData*)((csNodeData*)cam->UserData)->data)->clearcolor = color;
}