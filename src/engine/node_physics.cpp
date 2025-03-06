#include "engine.h"

// Include Bullet
#include <btBulletDynamicsCommon.h>

#define GRAD_PI (180.0 / 3.1415926535897932384626433832795)
#define GRAD_PI2 0.174532925f

//-----------------------------------------------
//  Node Physics variables
//-----------------------------------------------

btDynamicsWorld* dyWorld = NULL;

//-----------------------------------------------
//  Node Physics functions
//-----------------------------------------------

void QuaternionToEulerXYZ(const btQuaternion& quat, btVector3& euler)
{
	f32 w=quat.getW();	f32 x=quat.getX();	f32 y=quat.getY();	f32 z=quat.getZ();
	double sqw = w*w; double sqx = x*x; double sqy = y*y; double sqz = z*z; 
	euler.setZ((atan2(2.0 * (x*y + z*w),(sqx - sqy - sqz + sqw))));
	euler.setX((atan2(2.0 * (y*z + x*w),(-sqx - sqy + sqz + sqw))));
	euler.setY((asin(-2.0 * (x*z - y*w))));
	euler *= GRAD_PI;
}

//-----------------------------------------------

void EulerXYZToQuaternion(const btVector3& euler, btQuaternion& quat)
{	

	btMatrix3x3 mat;
	mat.setIdentity();
	mat.setEulerZYX(euler.getX(), euler.getY(), euler.getZ());
	mat.getRotation(quat);
}

//-----------------------------------------------

void SetBodyPosition(const void* body, float x, float y, float z)
{
	btTransform trans = ((btRigidBody*) body)->getWorldTransform();
	btVector3 pos(x, y, z);
	trans.setOrigin(pos);
	((btRigidBody*) body)->setWorldTransform(trans);
}

//-----------------------------------------------

void SetBodyRotation(const void* body, float pitch, float yaw, float roll)
{
	btTransform trans = ((btRigidBody*) body)->getWorldTransform();
	btQuaternion quat;
	EulerXYZToQuaternion(btVector3(pitch * GRAD_PI2, yaw * GRAD_PI2, roll * GRAD_PI2), quat);
	trans.setRotation(quat);
	((btRigidBody*) body)->setWorldTransform(trans);
}

//-----------------------------------------------

void DeleteBody(void* body)
{
	dyWorld->removeRigidBody((btRigidBody*) body);
	delete ((btRigidBody*) body)->getMotionState();
	delete ((btRigidBody*) body)->getCollisionShape();
	delete (btRigidBody*) body;
}

//-----------------------------------------------

void InitPhysics()
{
	CleanPhysics();
	btVector3 worldAabbMin(-10000,-10000,-10000);
	btVector3 worldAabbMax(10000,10000,10000);
   btCollisionConfiguration* colConfig = new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new btCollisionDispatcher(colConfig);
	//btBroadphaseInterface* broadphase = new btSimpleBroadphase();
	btBroadphaseInterface* broadphase = new btAxisSweep3(worldAabbMin, worldAabbMax);
   //btOverlappingPairCache* broadphase = new btAxisSweep3(worldAabbMin, worldAabbMax);
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver();
	//dyWorld = new btSimpleDynamicsWorld(dispatcher, broadphase, solver);
	dyWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, colConfig);
	csSceneSetGravity(0, -9.81f, 0);
}

//-----------------------------------------------

void CleanPhysics()
{
	if (dyWorld)
	{
		while (dyWorld->getNumCollisionObjects() > 0)
		{
			btRigidBody* body = btRigidBody::upcast(dyWorld->getCollisionObjectArray()[0]);
			if (body)
				DeleteBody(body);
		}

		delete dyWorld->getConstraintSolver();
		delete dyWorld->getBroadphase();
		delete dyWorld->getDispatcher();
		delete dyWorld;
		
		dyWorld = NULL;
	}
}

//-----------------------------------------------

void UpdatePhysics(float timestep)
{
	// Step physics simulation
	dyWorld->stepSimulation(timestep);
	dyWorld->updateAabbs();

	// For every object in the simulation
	for (int i = 0; i < dyWorld->getNumCollisionObjects(); i++) {
		// Get rigid body for the object
		btRigidBody* body = btRigidBody::upcast(dyWorld->getCollisionObjectArray()[i]);
		
		// If the body exist
		if (body) {
			// Get position & rotation for the body
			btVector3 bEuler;
			btPoint3 bPos = body->getCenterOfMassPosition();
			btQuaternion quat = body->getOrientation();
			QuaternionToEulerXYZ(quat, bEuler);

			// Convert Bullet data into IrrLicht data
			vector3df iPos(bPos.getX(), bPos.getY(), bPos.getZ());
			vector3df iEuler(bEuler.getX(), bEuler.getY(), bEuler.getZ());

			// Get Irrlicht scene node and apply tranformation
			ISceneNode* node = (ISceneNode*) body->getUserPointer();
			node->setPosition(iPos);
			node->setRotation(iEuler);

         //csCoreMessage("", 0);
		}
	}
}

//-----------------------------------------------

void PhysicsGravity(float x, float y, float z)
{
	dyWorld->setGravity(btVector3(x, y, z));
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
		DeleteBody((btRigidBody*) ((csNodeData*)node->UserData)->body);
		((csNodeData*)node->UserData)->body = NULL;
	}

	// If physics are disabled, we are done
	if (use == 0)
		return;

	// Create collision shape for the body
	btCollisionShape* shape;
	switch (((csNodeData*)node->UserData)->bodytype) {
		case CSBT_NULL:
			//shape = new btEmptyShape();
			break;
		case CSBT_BOX:
			shape = new btBoxShape(btVector3(csNodeWidth(node)/2, csNodeHeight(node)/2, csNodeDepth(node)/2));
			break;
		case CSBT_SPHERE:
			float rad;
			if (csNodeWidth(node) > csNodeHeight(node)) {
				if (csNodeWidth(node) > csNodeDepth(node))
					rad = csNodeWidth(node) / 2.0;
				else
					rad = csNodeDepth(node) / 2.0;
			} else {
				if (csNodeHeight(node) > csNodeDepth(node))
					rad = csNodeHeight(node) / 2.0;
				else
					rad = csNodeDepth(node) / 2.0;
			}
			shape = new btSphereShape(rad);
			break;
		case CSBT_CONE:
			if (csNodeWidth(node) > csNodeDepth(node))
				shape = new btConeShape(csNodeWidth(node)/2, csNodeHeight(node));
			else
				shape = new btConeShape(csNodeDepth(node)/2, csNodeHeight(node));
			break;
		case CSBT_CAPSULE:
			if (csNodeWidth(node) > csNodeDepth(node))
				shape = new btCapsuleShape(csNodeWidth(node)/2, csNodeHeight(node));
			else
				shape = new btCapsuleShape(csNodeDepth(node)/2, csNodeHeight(node));
			break;
		case CSBT_CYLINDER:
			shape = new btCylinderShape(btVector3(csNodeWidth(node), csNodeHeight(node), csNodeDepth(node)));
			break;
	}

	// Setup initial body transformation
	btTransform transform;
	transform.setIdentity();

	// Create body for the node
	btRigidBody* body = new btRigidBody(0, new btDefaultMotionState(transform), shape);
	dyWorld->addRigidBody(body);

	// Position and rotate
	SetBodyPosition(body, csNodeX(node, 0), csNodeY(node, 0), csNodeZ(node, 0));
	SetBodyRotation(body, csNodePitch(node), csNodeYaw(node), csNodeRoll(node));

	/*
	// Set CCD
	float ccd = 0;
	vector3df ext = node->getBoundingBox().getExtent();
	if (ext.X > ccd) ccd = ext.X;
	if (ext.Y > ccd) ccd = ext.Y;
	if (ext.Z > ccd) ccd = ext.Z;
	body->setCcdSquareMotionThreshold(ccd);
	body->setCcdSweptSphereRadius(0.2 * ccd);
	*/

	// Attach body to node and viceversa
	body->setUserPointer((void*) node);
	((csNodeData*)node->UserData)->body = (void*) body;
}

//-----------------------------------------------

csVoid csNodeSetMass(ISceneNode* node, float mass)
{
	btRigidBody* body = (btRigidBody*) ((csNodeData*)node->UserData)->body;
	btVector3 inertia;
	body->getCollisionShape()->calculateLocalInertia(mass, inertia);
	body->setMassProps(mass, inertia);
}
