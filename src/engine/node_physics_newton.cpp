#include "engine.h"

// Include Newton
#include <Newton.h>

//-----------------------------------------------
//  Node Physics variables
//-----------------------------------------------

NewtonWorld* dyWorld;

//-----------------------------------------------
//  Node Physics functions
//-----------------------------------------------

void InitPhysics()
{
	CleanPhysics();
	dyWorld = NewtonCreate(NULL, NULL);
}

//-----------------------------------------------

void CleanPhysics()
{
	if (dyWorld)
		NewtonDestroy(dyWorld);
	dyWorld = NULL;
}

//-----------------------------------------------

void UpdatePhysics(float timestep)
{
	NewtonUpdate(dyWorld, timestep);
}

//-----------------------------------------------

void BodyTransformCallback(const NewtonBody* body, const dFloat* matrix)
{
	// Copy the matrix into an Irrlicht matrix4
	matrix4 mat;
	//memcpy(mat.M, matrix, sizeof(float)*16);
	mat.setM(matrix);

	// Retreive the user data attached to the newton body
	ISceneNode* tmp = (ISceneNode*) NewtonBodyGetUserData(body);
	if (tmp)
	{
		// Position the node
		tmp->setPosition(mat.getTranslation());		// Set position
		tmp->setRotation(mat.getRotationDegrees());	// and rotation
	}
}

//-----------------------------------------------

csVoid csNodeSetBodyType(ISceneNode* node, int type)
{
	((csNodeData*)node->UserData)->bodytype = type;
}

//-----------------------------------------------

csVoid csNodeEnablePhysics(ISceneNode* node, int use)
{
	// Set new physics state
	((csNodeData*)node->UserData)->usephysics = (bool) use;

	// Delete old body if there was one
	if (((csNodeData*)node->UserData)->body != NULL) {
		NewtonDestroyBody(dyWorld, (NewtonBody*) ((csNodeData*)node->UserData)->body);
		((csNodeData*)node->UserData)->body = NULL;
	}

	// If physics are disabled, we are done
	if (use == 0)
		return;

	// Create collision model for the body
	NewtonCollision* coll;
	switch (((csNodeData*)node->UserData)->bodytype) {
		case CSBT_NULL:
			coll = NewtonCreateNull(dyWorld);
		case CSBT_BOX:
			coll = NewtonCreateBox(dyWorld, csNodeWidth(node), csNodeHeight(node), csNodeDepth(node), NULL);
		case CSBT_SPHERE:
			coll = NewtonCreateSphere(dyWorld, csNodeWidth(node)/2, csNodeHeight(node)/2, csNodeDepth(node)/2, NULL);
		case CSBT_CONE:
			if (csNodeWidth(node) > csNodeDepth(node))
				coll = NewtonCreateCone(dyWorld, csNodeWidth(node)/2, csNodeHeight(node), NULL);
			else
				coll = NewtonCreateCone(dyWorld, csNodeDepth(node)/2, csNodeHeight(node), NULL);
		case CSBT_CAPSULE:
			if (csNodeWidth(node) > csNodeDepth(node))
				coll = NewtonCreateCapsule(dyWorld, csNodeWidth(node)/2, csNodeHeight(node), NULL);
			else
				coll = NewtonCreateCapsule(dyWorld, csNodeDepth(node)/2, csNodeHeight(node), NULL);
		case CSBT_CYLINDER:
			if (csNodeWidth(node) > csNodeDepth(node))
				coll = NewtonCreateCylinder(dyWorld, csNodeWidth(node)/2, csNodeHeight(node), NULL);
			else
				coll = NewtonCreateCylinder(dyWorld, csNodeDepth(node)/2, csNodeHeight(node), NULL);
	}

	// Create body for the node
	((csNodeData*)node->UserData)->body = NewtonCreateBody(dyWorld, coll);
	NewtonReleaseCollision(dyWorld, coll);

	NewtonBodySetMassMatrix((NewtonBody*) ((csNodeData*)node->UserData)->body, 100, csNodeWidth(node), csNodeHeight(node), csNodeDepth(node));

	// Set body info
	NewtonBodySetUserData((NewtonBody*) ((csNodeData*)node->UserData)->body, node);
	NewtonBodySetTransformCallback((NewtonBody*) ((csNodeData*)node->UserData)->body, BodyTransformCallback);
}