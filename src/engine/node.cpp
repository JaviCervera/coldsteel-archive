#include "engine.h"

//-----------------------------------------------
//  Node functions
//-----------------------------------------------

csNodeData::csNodeData(int type, ISceneNode* node)
{
	this->type = type;
	this->node = node;
	this->usephysics = false;
	this->body = NULL;
}

//-----------------------------------------------

csNodeData::~csNodeData()
{
	switch (type)
	{
	case CSNT_CAMERA:
		delete (csCameraData*) data;
		break;
	case CSNT_MESH:
		if (data) ((IShadowVolumeSceneNode*)data)->remove();
		break;
	}
}

//-----------------------------------------------

/*
void DeleteNodeCallback(void* node)
{
	//char msg[32];
	//sprintf(msg, "%i", (int) ((ISceneNode*)node)->UserData);
	//csCoreMessage("DELETED", 0);
	delete (csNodeData*) ((ISceneNode*)node)->UserData;
}
*/

//-----------------------------------------------

ISceneNode* NewNode(int type, ISceneNode* parent, const char* str, int data1, int data2)
{
	ISceneNode* node;
	
	// Create IrrLicht ISceneNode depending on type
	switch (type)
	{
	case CSNT_EMPTY:
		node = Device->getSceneManager()->addEmptySceneNode(parent);
		break;
	case CSNT_BILLBOARD:
		node = Device->getSceneManager()->addBillboardSceneNode(parent, dimension2d<f32>(1,1));
		break;
	case CSNT_CAMERA:
		node = Device->getSceneManager()->addCameraSceneNode(parent);
		break;
	case CSNT_EMITTER:
		node = Device->getSceneManager()->addParticleSystemSceneNode(false, parent);
		break;
	case CSNT_LIGHT:
		node = Device->getSceneManager()->addLightSceneNode(parent);
		break;
	case CSNT_MESH:
		if (data2)
		{
			IMesh* tmesh = Device->getSceneManager()->getMeshManipulator()->createMeshWithTangents(((IAnimatedMesh*) data1)->getMesh(0));
			node = Device->getSceneManager()->addMeshSceneNode(tmesh, parent);
			tmesh->drop();
		} else {
			node = Device->getSceneManager()->addAnimatedMeshSceneNode((IAnimatedMesh*) data1, parent);
			((IAnimatedMeshSceneNode*)node)->setAnimationSpeed(0);
			((IAnimatedMeshSceneNode*)node)->setCurrentFrame(0);
		}
		break;
	case CSNT_MESH_OCTREE:
		if (data2)
		{
			IMesh* tmesh = Device->getSceneManager()->getMeshManipulator()->createMeshWithTangents(((IAnimatedMesh*) data1)->getMesh(0));
			node = Device->getSceneManager()->addOctTreeSceneNode(tmesh, parent);
			tmesh->drop();
		} else {
			node = Device->getSceneManager()->addOctTreeSceneNode(((IAnimatedMesh*) data1)->getMesh(0), parent);
		}
		break;
	case CSNT_TERRAIN:
		node = Device->getSceneManager()->addTerrainSceneNode(str, parent);
		break;
	}

	// Set other node settings
	node->setID(0);
	node->setMaterialFlag(EMF_TRILINEAR_FILTER, true);

	// Create user data
	csNodeData* data = new csNodeData(type, node);
	if (type == CSNT_CAMERA)
		data->data = new csCameraData();
	node->UserData = data;
	//node->userDataDeleteCallback = DeleteNodeCallback;

	return node;
}

//-----------------------------------------------

csInt csNodeEmpty(ISceneNode* parent)
{
	return (int) NewNode(CSNT_EMPTY, parent);
}

//-----------------------------------------------

csVoid csNodeFree(ISceneNode* n)
{
	if (((csNodeData*)n->UserData)->body)
		DeleteBody(((csNodeData*)n->UserData)->body);
	delete (csNodeData*) ((ISceneNode*)n)->UserData;
	n->remove();
}

//-----------------------------------------------

csInt csNodeType(ISceneNode* n)
{
	return ((csNodeData*)n->UserData)->type;
}

//-----------------------------------------------

csVoid csNodePosition(ISceneNode* n, float x, float y, float z)
{
	n->setPosition(vector3df(x,y,z));
	if (((csNodeData*)n->UserData)->body)
		SetBodyPosition(((csNodeData*)n->UserData)->body, x, y, z);
}

//-----------------------------------------------

csVoid csNodeMove(ISceneNode* n, float x, float y, float z)
{
	matrix4 matrix = n->getRelativeTransformation();
	vector3df dest(x,y,z);
	matrix.transformVect(dest);
	csNodePosition(n, dest.X, dest.Y, dest.Z);
}

//-----------------------------------------------

csVoid csNodeRotate(ISceneNode* n, float pitch, float yaw, float roll)
{
	vector3df rot(pitch, yaw, roll);
	n->setRotation(rot);
	if (((csNodeData*)n->UserData)->body)
		SetBodyRotation(((csNodeData*)n->UserData)->body, pitch, yaw, roll);
}

//-----------------------------------------------

csVoid csNodeTurn(ISceneNode* n, float pitch, float yaw, float roll)
{
	vector3df rot = n->getRotation();
	csNodeRotate(n, rot.X + pitch, rot.Y + yaw, rot.Z + roll);
	/*
	rot.X += pitch;
	rot.Y += yaw;
	rot.Z += roll;
	n->setRotation(rot);
	*/
}

//-----------------------------------------------

csVoid csNodeScale(ISceneNode* n, float x, float y, float z)
{
	vector3df scale(x,y,z);
	n->setScale(scale);
}

//-----------------------------------------------

csFloat csNodeX(ISceneNode* n, int absolute)
{
	if (absolute)
		return n->getAbsolutePosition().X;
	else
		return n->getPosition().X;
}

//-----------------------------------------------

csFloat csNodeY(ISceneNode* n, int absolute)
{
	if (absolute)
		return n->getAbsolutePosition().Y;
	else
		return n->getPosition().Y;
}

//-----------------------------------------------

csFloat csNodeZ(ISceneNode* n, int absolute)
{
	if (absolute)
		return n->getAbsolutePosition().Z;
	else
		return n->getPosition().Z;
}

//-----------------------------------------------

csFloat csNodePitch(ISceneNode* n)
{
	return (n->getRotation().X);
}

//-----------------------------------------------

csFloat csNodeYaw(ISceneNode* n)
{
	return (n->getRotation().Y);
}

//-----------------------------------------------

csFloat csNodeRoll(ISceneNode* n)
{
	return (n->getRotation().Z);
}

//-----------------------------------------------

csFloat csNodeScaleX(ISceneNode* n)
{
	return n->getScale().X;
}

//-----------------------------------------------

csFloat csNodeScaleY(ISceneNode* n)
{
	return n->getScale().Y;
}

//-----------------------------------------------

csFloat csNodeScaleZ(ISceneNode* n)
{
	return n->getScale().Z;
}

//-----------------------------------------------

csFloat csNodeWidth(ISceneNode* n)
{
	return n->getBoundingBox().getExtent().X;
}

//-----------------------------------------------

csFloat csNodeHeight(ISceneNode* n)
{
	return n->getBoundingBox().getExtent().Y;
}

//-----------------------------------------------

csFloat csNodeDepth(ISceneNode* n)
{
	return n->getBoundingBox().getExtent().Z;
}

//-----------------------------------------------

csVoid csNodeCastShadow(ISceneNode* n, int shadow)
{
#ifndef COLDSTEEL_LITE
	if (((csNodeData*)n->UserData)->type == CSNT_LIGHT)
	{
		((ILightSceneNode*)n)->getLightData().CastShadows = (bool) shadow;
	} else if (((csNodeData*)n->UserData)->type == CSNT_MESH) {
		IAnimatedMeshSceneNode* m = (IAnimatedMeshSceneNode*)n;
		IShadowVolumeSceneNode* s = (IShadowVolumeSceneNode*)((csNodeData*)n->UserData)->data;
		if (shadow)
			((csNodeData*)n->UserData)->data = (void*) m->addShadowVolumeSceneNode(-1, false);
		else if (s)
		{
			s->remove();
			((csNodeData*)n->UserData)->data = 0;
		}
	}
#endif
}

//-----------------------------------------------

csVoid csNodeHide(ISceneNode* n, int state)
{
	n->setVisible(!state);
}

//-----------------------------------------------

csInt csNodeMaterials(ISceneNode* n)
{
	return n->getMaterialCount();
}

//-----------------------------------------------

csInt csNodeGetMaterial(ISceneNode* n, int mat_index)
{
	return (int) new SMaterial(n->getMaterial(mat_index-1));
}

//-----------------------------------------------

csVoid csNodeSetMaterial(ISceneNode* n, SMaterial* mat, int mat_index)
{
	if (mat_index == 0)
	{
		for (int i = 1; i <= csNodeMaterials(n); i++)
			csNodeSetMaterial(n, mat, i);
		return;
	}
	memcpy(&n->getMaterial(mat_index-1), mat, sizeof(SMaterial));
}

//-----------------------------------------------

csVoid csNodeSetMaterialData(ISceneNode* n, csMaterialData* mat, int mat_index)
{
	SMaterial* m = (SMaterial*) csMaterialFromData(mat);
	csNodeSetMaterial(n, m, mat_index);
	csMaterialFree(m);
}

//-----------------------------------------------

csVoid csNodeSetMaterialFast(ISceneNode* n, int index, int type, int flags, ITexture* tex1, ITexture* tex2)
{
	SMaterial* mat = (SMaterial*) csMaterialCreate("");
	csMaterialSetType(mat, type);
	csMaterialSetFlags(mat, flags);
	csMaterialSetTexture(mat, tex1, 0);
	csMaterialSetTexture(mat, tex2, 1);
	csNodeSetMaterial(n, mat, index);
	csMaterialFree(mat);
}

//-----------------------------------------------

csVoid csNodeSetMaterialFlag(ISceneNode* n, int index, int flag, int state)
{
	if (index == 0)
	{
		for (int i = 1; i <= csNodeMaterials(n); i++)
			csNodeSetMaterialFlag(n, i, flag, state);
		return;
	}
	setMaterialFlag(&n->getMaterial(index-1), flag, state);
}

//-----------------------------------------------

csVoid csNodeSetName(ISceneNode* n, const char* name)
{
	n->setName(name);
}

//-----------------------------------------------

csString csNodeGetName(ISceneNode* n)
{
	return n->getName();
}

//-----------------------------------------------

csVoid csNodeSetPickGroup(ISceneNode* n, int group)
{
	if (group >= 0)
		n->setID(group);
}

//-----------------------------------------------

csVoid csNodeSetProperty(ISceneNode* n, const char* name, const char* value)
{
	csNodeProperty p;
	p.name = name;
	p.value = value;

	// Search for property
	int id = csNodeFindProperty(n, name);
	if (id != -1)
		((csNodeData*)n->UserData)->properties[id].value = value;
	else
		((csNodeData*)n->UserData)->properties.push_back(p);
}

//-----------------------------------------------

csInt csNodeProperties(ISceneNode* n)
{
	return (int) ((csNodeData*)n->UserData)->properties.size();
}

//-----------------------------------------------

csInt csNodeFindProperty(ISceneNode* n, const char* name)
{
	for (unsigned int i = 0; i < ((csNodeData*)n->UserData)->properties.size(); i++)
		if (((csNodeData*)n->UserData)->properties[i].name == name)
			return i+1;
	return 0;
}

//-----------------------------------------------

csString csNodePropertyName(ISceneNode* n, int index)
{
	return ((csNodeData*)n->UserData)->properties[index-1].name.c_str();
}

//-----------------------------------------------

csString csNodePropertyValue(ISceneNode* n, int index)
{
	return ((csNodeData*)n->UserData)->properties[index-1].value.c_str();
}

//-----------------------------------------------

csVoid csNodeRemoveProperty(ISceneNode* n, int index)
{
	((csNodeData*)n->UserData)->properties.erase(((csNodeData*)n->UserData)->properties.begin() + (index-1));
}

//-----------------------------------------------

csVoid csNodeSetParent(ISceneNode* n, ISceneNode* parent)
{
	n->setParent(parent);
}

//-----------------------------------------------

csInt csNodeGetParent(ISceneNode* n)
{
	return (int) n->getParent();
}

//-----------------------------------------------

csInt csNodeChildren(ISceneNode* n)
{
	return (int) n->getChildren().getSize();
}

//-----------------------------------------------

csInt csNodeChild(ISceneNode* n, int index)
{
	if (index > (int) n->getChildren().getSize()) return 0;
	return (int) *(n->getChildren().begin() + (index-1));
}

//-----------------------------------------------

csInt csNodeFindChild(ISceneNode* n, const char* name, int recursive)
{
	for (unsigned int i = 0; i < csNodeChildren(n); i++)
		if ((*(n->getChildren().begin()+i))->getName() == name)
			return (int) *(n->getChildren().begin()+i);
	if (recursive == 1)
		for (unsigned int i = 0; i < csNodeChildren(n); i++)
		{
			int n_ = csNodeFindChild(*(n->getChildren().begin()+i), name, recursive);
			if (n_ != 0) return n_;
		}
	return 0;
}

//-----------------------------------------------

csVoid csNodeSpeed(ISceneNode* n, float fps)
{
	((IAnimatedMeshSceneNode*)n)->setAnimationSpeed(fps);
}

//-----------------------------------------------

csVoid csNodeLoop(ISceneNode* n, int loop)
{
	((IAnimatedMeshSceneNode*)n)->setLoopMode((bool) loop);
}

//-----------------------------------------------

csVoid csNodeSetFrame(ISceneNode* n, int begin, int end)
{
	if (!end)
		((IAnimatedMeshSceneNode*)n)->setCurrentFrame(begin);
	else
		((IAnimatedMeshSceneNode*)n)->setFrameLoop(begin, end);
}

//-----------------------------------------------

csInt csNodeGetFrame(ISceneNode* n)
{
	return ((IAnimatedMeshSceneNode*)n)->getFrameNr();
}

//-----------------------------------------------

csVoid csNodeAttachToBone(ISceneNode* n, ISceneNode* n2, const char* bonename)
{
	// Attach "n" to the bone specified
	ISceneNode* bone = ((IAnimatedMeshSceneNode*)n2)->getJointNode(bonename);
	/*ISceneNode* bone = ((IAnimatedMeshSceneNode*)n2)->getB3DJointNode(bonename);
	if (!bone) bone = ((IAnimatedMeshSceneNode*)n2)->getMS3DJointNode(bonename);
	if (!bone) bone = ((IAnimatedMeshSceneNode*)n2)->getXJointNode(bonename);*/
	if (bone)
		n->setParent(bone);
}

//-----------------------------------------------

csVoid csNodeLookAt(ISceneNode* n, float posx, float posy, float posz)
{
	float xdiff = csNodeX(n, false) - posx;
	float ydiff = csNodeY(n, false) - posy;
	float zdiff = csNodeZ(n, false) - posz;

	float dist22 = csMathSqr(float(xdiff*xdiff) + float(zdiff*zdiff));
	float pitch = csMathATan2(ydiff, dist22);
	float yaw = csMathATan2(xdiff, -zdiff);
	float roll = csNodeRoll(n);

	csNodeRotate(n, pitch, yaw, roll);
}
