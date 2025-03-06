#include "engine.h"

//-----------------------------------------------
//  Node variables
//-----------------------------------------------

std::vector<csNode*> nodelist;

//-----------------------------------------------
//  Node functions
//-----------------------------------------------

csNode::csNode(int type_, csNode* parent, const char* str, int data1, int data2)
{
	// Add this node to the list
	nodelist.push_back(this);

	// Get parent pointer
	ISceneNode* p = NULL;
	if (parent) p = parent->ptr;

	// Set node data
	this->type = type_;
	switch (type)
	{
	case CSNT_EMPTY:
		this->ptr = Device->getSceneManager()->addEmptySceneNode(p);
		break;
	case CSNT_BILLBOARD:
		this->ptr = Device->getSceneManager()->addBillboardSceneNode(p, dimension2d<f32>(1,1));
		break;
	case CSNT_CAMERA:
		this->ptr = Device->getSceneManager()->addCameraSceneNode(p);
		this->data = new csCamera();
		break;
	case CSNT_EMITTER:
		this->ptr = Device->getSceneManager()->addParticleSystemSceneNode(false, p);
		break;
	case CSNT_LIGHT:
		this->ptr = Device->getSceneManager()->addLightSceneNode(p);
		break;
	case CSNT_MESH:
		if (data2)
		{
			IMesh* tmesh = Device->getSceneManager()->getMeshManipulator()->createMeshWithTangents(((IAnimatedMesh*) data1)->getMesh(0));
			this->ptr = Device->getSceneManager()->addMeshSceneNode(tmesh, p);
			tmesh->drop();
		} else {
			this->ptr = Device->getSceneManager()->addAnimatedMeshSceneNode((IAnimatedMesh*) data1, p);
			((IAnimatedMeshSceneNode*)this->ptr)->setAnimationSpeed(0);
			((IAnimatedMeshSceneNode*)this->ptr)->setCurrentFrame(0);
		}
		break;
	case CSNT_MESH_OCTREE:
		if (data2)
		{
			IMesh* tmesh = Device->getSceneManager()->getMeshManipulator()->createMeshWithTangents(((IAnimatedMesh*) data1)->getMesh(0));
			this->ptr = Device->getSceneManager()->addOctTreeSceneNode(tmesh, p);
			tmesh->drop();
		} else {
			this->ptr = Device->getSceneManager()->addOctTreeSceneNode(((IAnimatedMesh*) data1)->getMesh(0), p);
		}
		break;
	case CSNT_TERRAIN:
		this->ptr = Device->getSceneManager()->addTerrainSceneNode(str, p);
		break;
	}
	this->name = "";
	this->ptr->setID(0);
	this->ptr->setMaterialFlag(EMF_TRILINEAR_FILTER, true);
	this->parent = NULL;  // Starts without parent
	this->setParent(parent);
}

//-----------------------------------------------

csNode::~csNode()
{
	switch (this->type)
	{
		case CSNT_CAMERA:
			delete (csCamera*) this->data;
			break;
		case CSNT_MESH:
			if (this->data) ((IShadowVolumeSceneNode*)this->data)->remove();
			break;
	}
	if (this->parent) this->parent->removeNodeChild(this);
	this->ptr->remove();

	// Remove node from list
	for (unsigned int i = 0; i < nodelist.size(); i++)
		if (nodelist[i] == this)
		{
			nodelist.erase(nodelist.begin() + i);
			return;
		}
}

//-----------------------------------------------

void csNode::setParent(csNode* par)
{
	// Set IrrLicht ISceneNode of the parent
	ISceneNode* p;
	if (par)
		p = par->ptr;
	else
		p = Device->getSceneManager()->getRootSceneNode();
	this->ptr->setParent(p);

	// Remove child from old parent
	if (this->parent) this->parent->removeNodeChild(this);

	// Add child to new parent
	if (par) par->addNodeChild(this);

	// Set parent node
	this->parent = par;
}

//-----------------------------------------------

void csNode::removeNodeChild(csNode* child)
{
	for (int i = 0; i < this->children.size(); i++)
		if (this->children[i] == child)
			this->children.erase(this->children.begin() + i);
}

//-----------------------------------------------

void csNode::addNodeChild(csNode* child)
{
	this->removeNodeChild(child);	// If it's already a children, delete parenting
	this->children.push_back(child);
}

//-----------------------------------------------

csNode* GetNodeFromIrr(ISceneNode* irrn)
{
	for (unsigned int i = 0; i < nodelist.size(); i++)
		if (nodelist[i]->ptr == irrn)
			return nodelist[i];
	return NULL;
}

//-----------------------------------------------

int FindNodeProperty(csNode* n, const char* name)
{
	for (unsigned int i = 0; i < n->properties.size(); i++)
		if (n->properties[i].name == name)
			return i;
	return -1;
}

//-----------------------------------------------

csInt csNodeEmpty(csNode* parent)
{
	return (int) new csNode(CSNT_EMPTY, parent);
}

//-----------------------------------------------

csVoid csNodeFree(csNode* n)
{
	delete n;
}

//-----------------------------------------------

csInt csNodeType(csNode* n)
{
	return n->type;
}

//-----------------------------------------------

csVoid csNodePosition(csNode* n, float x, float y, float z)
{
	n->ptr->setPosition(vector3df(x,y,z));
}

//-----------------------------------------------

csVoid csNodeMove(csNode* n, float x, float y, float z)
{
	matrix4 matrix = n->ptr->getRelativeTransformation();
	vector3df dest(x,y,z);
	matrix.transformVect(dest);
	csNodePosition(n, dest.X, dest.Y, dest.Z);
}

//-----------------------------------------------

csVoid csNodeRotate(csNode* n, float pitch, float yaw, float roll)
{
	vector3df rot(pitch, yaw, roll);
		n->ptr->setRotation(rot);
}

//-----------------------------------------------

csVoid csNodeTurn(csNode* n, float pitch, float yaw, float roll)
{
	vector3df rot = n->ptr->getRotation();
	rot.X += pitch;
	rot.Y += yaw;
	rot.Z += roll;
	n->ptr->setRotation(rot);
}

//-----------------------------------------------

csVoid csNodeScale(csNode* n, float x, float y, float z)
{
	vector3df scale(x,y,z);
	n->ptr->setScale(scale);
}

//-----------------------------------------------

csFloat csNodeX(csNode* n, int absolute)
{
	if (absolute)
		return n->ptr->getAbsolutePosition().X;
	else
		return n->ptr->getPosition().X;
}

//-----------------------------------------------

csFloat csNodeY(csNode* n, int absolute)
{
	if (absolute)
		return n->ptr->getAbsolutePosition().Y;
	else
		return n->ptr->getPosition().Y;
}

//-----------------------------------------------

csFloat csNodeZ(csNode* n, int absolute)
{
	if (absolute)
		return n->ptr->getAbsolutePosition().Z;
	else
		return n->ptr->getPosition().Z;
}

//-----------------------------------------------

csFloat csNodePitch(csNode* n)
{
	return (n->ptr->getRotation().X);
}

//-----------------------------------------------

csFloat csNodeYaw(csNode* n)
{
	return (n->ptr->getRotation().Y);
}

//-----------------------------------------------

csFloat csNodeRoll(csNode* n)
{
	return (n->ptr->getRotation().Z);
}

//-----------------------------------------------

csFloat csNodeScaleX(csNode* n)
{
	return n->ptr->getScale().X;
}

//-----------------------------------------------

csFloat csNodeScaleY(csNode* n)
{
	return n->ptr->getScale().Y;
}

//-----------------------------------------------

csFloat csNodeScaleZ(csNode* n)
{
	return n->ptr->getScale().Z;
}

//-----------------------------------------------

csFloat csNodeWidth(csNode* n)
{
	return n->ptr->getBoundingBox().getExtent().X;
}

//-----------------------------------------------

csFloat csNodeHeight(csNode* n)
{
	return n->ptr->getBoundingBox().getExtent().Y;
}

//-----------------------------------------------

csFloat csNodeDepth(csNode* n)
{
	return n->ptr->getBoundingBox().getExtent().Z;
}

//-----------------------------------------------

csVoid csNodeCastShadow(csNode* n, int shadow)
{
#ifndef COLDSTEEL_LITE
	if (n->type == CSNT_LIGHT)
	{
		((ILightSceneNode*)n->ptr)->getLightData().CastShadows = (bool) shadow;
	} else if (n->type == CSNT_MESH) {
		IAnimatedMeshSceneNode* m = (IAnimatedMeshSceneNode*)n->ptr;
		IShadowVolumeSceneNode* s = (IShadowVolumeSceneNode*)n->data;
		if (shadow)
			n->data = (void*)m->addShadowVolumeSceneNode(-1, false);
		else if (n->data)
		{
			s->remove();
			n->data = 0;
		}
	}
#endif
}

//-----------------------------------------------

csVoid csNodeHide(csNode* n, int state)
{
	n->ptr->setVisible(!state);
}

//-----------------------------------------------

csInt csNodeMaterials(csNode* n)
{
	return n->ptr->getMaterialCount();
}

//-----------------------------------------------

csInt csNodeGetMaterial(csNode* n, int mat_index)
{ 
	/*
	// Find a matching material
	SMaterial irrmat = n->ptr->getMaterial(mat_index - 1);
	for (unsigned int i = 0; i < mat_list.size(); i++)
	{
		if ((irrmat.MaterialType == mat_list[i]->mat->MaterialType) &&
		// ****************************
		//(irrmat.Flags == mat_list[i]->mat->Flags) &&
		(irrmat.Textures[0] == mat_list[i]->mat->Textures[0]) &&
		(irrmat.Textures[1] == mat_list[i]->mat->Textures[1]) &&
		(irrmat.AmbientColor == mat_list[i]->mat->AmbientColor) &&
		(irrmat.DiffuseColor == mat_list[i]->mat->DiffuseColor) &&
		(irrmat.EmissiveColor == mat_list[i]->mat->EmissiveColor) &&
		(irrmat.SpecularColor == mat_list[i]->mat->SpecularColor) &&
		(irrmat.Shininess == mat_list[i]->mat->Shininess) &&
		(irrmat.MaterialTypeParam == mat_list[i]->mat->MaterialTypeParam))
		return (int) mat_list[i];
	}

	// If it does not exist, create a new one
	csMaterial* mat = (csMaterial*) csMaterialCreate(irrmat.Name.c_str());
	*mat->mat = irrmat;
	return (int) mat;
	*/
	return (int) new SMaterial(n->ptr->getMaterial(mat_index-1));
}

//-----------------------------------------------

csVoid csNodeSetMaterial(csNode* n, SMaterial* mat, int mat_index)
{
	if (mat_index == 0)
	{
		for (int i = 1; i <= csNodeMaterials(n); i++)
			csNodeSetMaterial(n, mat, i);
		return;
	}
	memcpy(&n->ptr->getMaterial(mat_index-1), mat, sizeof(SMaterial));
	/*
	n->ptr->getMaterial(mat_index - 1).Name = mat->mat->Name;
	n->ptr->getMaterial(mat_index - 1).MaterialType = mat->mat->MaterialType;
	for (int i = 0; i < EMF_MATERIAL_FLAG_COUNT; i++)
	{
		//n->ptr->getMaterial(mat_index - 1).Flags[i] = mat->mat->Flags[i];
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_WIREFRAME, mat->mat->getFlag(EMF_WIREFRAME));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_POINTCLOUD, mat->mat->getFlag(EMF_POINTCLOUD));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_GOURAUD_SHADING, mat->mat->getFlag(EMF_GOURAUD_SHADING));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_LIGHTING, mat->mat->getFlag(EMF_LIGHTING));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_ZBUFFER, mat->mat->getFlag(EMF_ZBUFFER));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_ZWRITE_ENABLE, mat->mat->getFlag(EMF_ZWRITE_ENABLE));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_BACK_FACE_CULLING, mat->mat->getFlag(EMF_BACK_FACE_CULLING));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_BILINEAR_FILTER, mat->mat->getFlag(EMF_BILINEAR_FILTER));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_TRILINEAR_FILTER, mat->mat->getFlag(EMF_TRILINEAR_FILTER));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_ANISOTROPIC_FILTER, mat->mat->getFlag(EMF_ANISOTROPIC_FILTER));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_FOG_ENABLE, mat->mat->getFlag(EMF_FOG_ENABLE));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_NORMALIZE_NORMALS, mat->mat->getFlag(EMF_NORMALIZE_NORMALS));
		n->ptr->getMaterial(mat_index - 1).setFlag(EMF_TEXTURE_WRAP, mat->mat->getFlag(EMF_TEXTURE_WRAP));
	}
	n->ptr->getMaterial(mat_index - 1).Textures[0] = mat->mat->Textures[0];
	n->ptr->getMaterial(mat_index - 1).Textures[1] = mat->mat->Textures[1];
	n->ptr->getMaterial(mat_index - 1).AmbientColor = mat->mat->AmbientColor;
	n->ptr->getMaterial(mat_index - 1).DiffuseColor = mat->mat->DiffuseColor;
	n->ptr->getMaterial(mat_index - 1).EmissiveColor = mat->mat->EmissiveColor;
	n->ptr->getMaterial(mat_index - 1).SpecularColor = mat->mat->SpecularColor;
	n->ptr->getMaterial(mat_index - 1).Shininess = mat->mat->Shininess;
	n->ptr->getMaterial(mat_index - 1).MaterialTypeParam = mat->mat->MaterialTypeParam;
	*/
}

//-----------------------------------------------

csVoid csNodeSetMaterialData(csNode* n, csMaterialData* mat, int mat_index)
{
	SMaterial* m = (SMaterial*) csMaterialFromData(mat);
	csNodeSetMaterial(n, m, mat_index);
	csMaterialFree(m);
}

//-----------------------------------------------

csVoid csNodeSetMaterialFast(csNode* n, int index, int type, int flags, ITexture* tex1, ITexture* tex2)
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

csVoid csNodeSetMaterialFlag(csNode* n, int index, int flag, int state)
{
	if (index == 0)
	{
		for (int i = 1; i <= csNodeMaterials(n); i++)
			csNodeSetMaterialFlag(n, i, flag, state);
		return;
	}
	setMaterialFlag(&n->ptr->getMaterial(index-1), flag, state);
}

//-----------------------------------------------

csVoid csNodeSetName(csNode* n, const char* name)
{
	n->name = name;
}

//-----------------------------------------------

csString csNodeGetName(csNode* n)
{
	return n->name.c_str();
}

//-----------------------------------------------

csVoid csNodeSetPickGroup(csNode* n, int group)
{
	if (group >= 0)
		n->ptr->setID(group);
}

//-----------------------------------------------

csVoid csNodeSetProperty(csNode* n, const char* name, const char* value)
{
	csNodeProperty p;
	p.name = name;
	p.value = value;

	// Search for property
	int id = FindNodeProperty(n, name);
	if (id != -1)
		n->properties[id].value = value;
	else
		n->properties.push_back(p);
}

//-----------------------------------------------

csInt csNodeProperties(csNode* n)
{
	return (int) n->properties.size();
}

//-----------------------------------------------

csInt csNodeFindProperty(csNode* n, const char* name)
{
	return FindNodeProperty(n, name) + 1;
}

//-----------------------------------------------

csString csNodePropertyName(csNode* n, int index)
{
	return n->properties[index-1].name.c_str();
}

//-----------------------------------------------

csString csNodePropertyValue(csNode* n, int index)
{
	return n->properties[index-1].value.c_str();
}

//-----------------------------------------------

csVoid csNodeRemoveProperty(csNode* n, int index)
{
	n->properties.erase(n->properties.begin() + (index-1));
}

//-----------------------------------------------

csVoid csNodeSetParent(csNode* n, csNode* parent)
{
	n->setParent(parent);
}

//-----------------------------------------------

csInt csNodeGetParent(csNode* n)
{
	return (int) n->parent;
}

//-----------------------------------------------

csInt csNodeChildren(csNode* n)
{
	return (int) n->children.size();
}

//-----------------------------------------------

csInt csNodeChild(csNode* n, int index)
{
	if (index > (int) n->children.size()) return 0;
	return (int) n->children[index-1];
}

//-----------------------------------------------

csInt csNodeFindChild(csNode* n, const char* name, int recursive)
{
	for (unsigned int i = 0; i < n->children.size(); i++)
		if (n->children[i]->name == name)
			return (int) n->children[i];
	if (recursive == 1)
		for (unsigned int i = 0; i < n->children.size(); i++)
		{
			int n_ = csNodeFindChild(n->children[i], name, recursive);
			if (n_ != 0) return n_;
		}
	return 0;
}

//-----------------------------------------------

csVoid csNodeSpeed(csNode* n, float fps)
{
	((IAnimatedMeshSceneNode*)n->ptr)->setAnimationSpeed(fps);
}

//-----------------------------------------------

csVoid csNodeLoop(csNode* n, int loop)
{
	((IAnimatedMeshSceneNode*)n->ptr)->setLoopMode((bool) loop);
}

//-----------------------------------------------

csVoid csNodeSetFrame(csNode* n, int begin, int end)
{
	if (!end)
		((IAnimatedMeshSceneNode*)n->ptr)->setCurrentFrame(begin);
	else
		((IAnimatedMeshSceneNode*)n->ptr)->setFrameLoop(begin, end);
}

//-----------------------------------------------

csInt csNodeGetFrame(csNode* n)
{
	return ((IAnimatedMeshSceneNode*)n->ptr)->getFrameNr();
}

//-----------------------------------------------

csVoid csNodeAttachToBone(csNode* n, csNode* n2, const char* bonename)
{
	// Attach "n" to the bone specified
	ISceneNode* bone = ((IAnimatedMeshSceneNode*)n2->ptr)->getB3DJointNode(bonename);
	if (!bone) bone = ((IAnimatedMeshSceneNode*)n2->ptr)->getMS3DJointNode(bonename);
	if (!bone) bone = ((IAnimatedMeshSceneNode*)n2->ptr)->getXJointNode(bonename);
	if (bone)
	{
		csNodeSetParent(n, n2);  // Set "n2" as parent of "n", as this is how it is done in ColdSteel, where bones are not nodes
		bone->addChild(n->ptr);
	}
}

//-----------------------------------------------

csVoid csNodeLookAt(csNode* n, float posx, float posy, float posz)
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
