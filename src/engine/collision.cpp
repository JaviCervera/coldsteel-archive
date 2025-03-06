#include "engine.h"

//-----------------------------------------------
//  Collision functions
//-----------------------------------------------

csVoid csCollisionSlide(ISceneNode* n, float pos_x, float pos_y, float pos_z, float dest_x, float dest_y, float dest_z, float rad_x, float rad_y, float rad_z, csVector* vec_pos, csVector* vec_tri1, csVector* vec_tri2, csVector* vec_tri3)
{
	vector3df ellipPos(pos_x, pos_y, pos_z);
	vector3df ellipRad(rad_x, rad_y, rad_z);
	vector3df ellipVel(dest_x - pos_x, dest_y - pos_y, dest_z - pos_z);
	vector3df outPoint;
	triangle3df outTriangle;
	bool outFalling;
	outPoint = Device->getSceneManager()->getSceneCollisionManager()->getCollisionResultPosition(n->getTriangleSelector(), ellipPos, ellipRad, ellipVel, outTriangle, outFalling);
	if (vec_pos) { vec_pos->x = outPoint.X; vec_pos->y = outPoint.Y; vec_pos->z = outPoint.Z; }
	if (vec_tri1) { vec_tri1->x = outTriangle.pointA.X; vec_tri1->x = outTriangle.pointA.Y; vec_tri1->x = outTriangle.pointA.Z; }
	if (vec_tri2) { vec_tri2->x = outTriangle.pointB.X; vec_tri2->x = outTriangle.pointB.Y; vec_tri2->x = outTriangle.pointB.Z; }
	if (vec_tri3) { vec_tri3->x = outTriangle.pointC.X; vec_tri3->x = outTriangle.pointC.Y; vec_tri3->x = outTriangle.pointC.Z; }
}

//-----------------------------------------------

csInt csCollisionLinePick(ISceneNode* n, float pos_x, float pos_y, float pos_z, float dest_x, float dest_y, float dest_z, csVector* vec_pos, csVector* vec_tri1, csVector* vec_tri2, csVector* vec_tri3)
{
	line3d<f32> ray(pos_x, pos_y, pos_z, dest_x, dest_y, dest_z);
	vector3df outPoint;
	triangle3df outTriangle;
	bool ret = Device->getSceneManager()->getSceneCollisionManager()->getCollisionPoint(ray, n->getTriangleSelector(), outPoint, outTriangle);
	if (vec_pos) { vec_pos->x = outPoint.X; vec_pos->y = outPoint.Y; vec_pos->z = outPoint.Z; }
	if (vec_tri1) { vec_tri1->x = outTriangle.pointA.X; vec_tri1->x = outTriangle.pointA.Y; vec_tri1->x = outTriangle.pointA.Z; }
	if (vec_tri2) { vec_tri2->x = outTriangle.pointB.X; vec_tri2->x = outTriangle.pointB.Y; vec_tri2->x = outTriangle.pointB.Z; }
	if (vec_tri3) { vec_tri3->x = outTriangle.pointC.X; vec_tri3->x = outTriangle.pointC.Y; vec_tri3->x = outTriangle.pointC.Z; }
	return (int)ret;
}

//-----------------------------------------------

csInt csCollisionLineNode(float pos_x, float pos_y, float pos_z, float dest_x, float dest_y, float dest_z, int group)
{
	line3d<f32> ray(pos_x, pos_y, pos_z, dest_x, dest_y, dest_z);
	return (int) Device->getSceneManager()->getSceneCollisionManager()->getSceneNodeFromRayBB(ray, group);
	//return (int) GetNodeFromIrr(node);
}
