#include "engine.h"

//-----------------------------------------------
//  Emitter functions
//-----------------------------------------------

csInt csEmitterNode(csParticleData* part, ISceneNode* parent)
{
#ifndef COLDSTEEL_LITE
	IParticleEmitter* iem = NULL;
	IParticleSystemSceneNode* n = (IParticleSystemSceneNode*) NewNode(CSNT_EMITTER, parent);

	// Configure particles to emit
	if (part->type == 0)
	{
		iem = n->createPointEmitter(
			part->direction,										// Direction
			part->rate[0], part->rate[1],					// Particles per second
			SColor(														// Min start color
				csGetAlpha(part->startColor[0]),
				csGetRed(part->startColor[0]),
				csGetGreen(part->startColor[0]),
				csGetBlue(part->startColor[0])),
			SColor(														// Max start color
				csGetAlpha(part->startColor[1]),
				csGetRed(part->startColor[1]),
				csGetGreen(part->startColor[1]),
				csGetBlue(part->startColor[1])),
			part->lifeTime[0], part->lifeTime[1],	// Lifetime
			part->maxAngle											// Max angle
		);
	} else if (part->type == 1) {
		iem = n->createBoxEmitter(
			aabbox3d<f32>(-part->box.X/2, -part->box.Y/2, -part->box.Z/2, part->box.X/2, part->box.Y/2, part->box.Z/2),
			part->direction,										// Direction
			part->rate[0], part->rate[1],					// Particles per second
			SColor(														// Min start color
				csGetAlpha(part->startColor[0]),
				csGetRed(part->startColor[0]),
				csGetGreen(part->startColor[0]),
				csGetBlue(part->startColor[0])),
			SColor(														// Max start color
				csGetAlpha(part->startColor[1]),
				csGetRed(part->startColor[1]),
				csGetGreen(part->startColor[1]),
				csGetBlue(part->startColor[1])),
			part->lifeTime[0], part->lifeTime[1],	// Lifetime
			part->maxAngle											// Max angle
		);
	}
	n->setEmitter(iem);
	n->setParticleSize(dimension2d<f32>(part->size[0], part->size[1]));
	iem->drop();

	// Add affectors
	for (int i = 0; i < part->affectors.size(); i++)
		if (part->affectors[i].type == 0)
			csEmitterAddFadeOutAffector(n, part->affectors[i].color, part->affectors[i].time);
		else if (part->affectors[i].type == 1)
			csEmitterAddGravityAffector(n, part->affectors[i].grav[0], part->affectors[i].grav[1], part->affectors[i].grav[2], part->affectors[i].time);

	// Set material
	if (csMaterialDataFind(part->material.c_str()))
		csNodeSetMaterialData(n, (csMaterialData*) csMaterialDataFind(part->material.c_str()), 0);

	return (int) n;
#else
	return csNodeEmpty(parent);
#endif
}

//-----------------------------------------------

csVoid csEmitterAddFadeOutAffector(IParticleSystemSceneNode* n, int color, int time)
{
#ifndef COLDSTEEL_LITE
	IParticleAffector* aff = n->createFadeOutParticleAffector(SColor(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color)), time);
	n->addAffector(aff);
	aff->drop();
#endif
}

//-----------------------------------------------

csVoid csEmitterAddGravityAffector(IParticleSystemSceneNode* n, float grav_x, float grav_y, float grav_z, int time)
{
#ifndef COLDSTEEL_LITE
	IParticleAffector* aff = n->createGravityAffector(vector3df(grav_x, grav_y, grav_z), time);
	n->addAffector(aff);
	aff->drop();
#endif
}

//-----------------------------------------------

csVoid csEmitterRemoveAffectors(IParticleSystemSceneNode* n)
{
#ifndef COLDSTEEL_LITE
	n->removeAllAffectors();
#endif
}

//-----------------------------------------------

csVoid csEmitterGlobal(IParticleSystemSceneNode* n, int global)
{
#ifndef COLDSTEEL_LITE
	n->setParticlesAreGlobal(global);
#endif
}
