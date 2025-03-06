#include "engine.h"

//-----------------------------------------------
//  Audio variables
//-----------------------------------------------

ISoundEngine* AudioDevice = NULL;

//-----------------------------------------------
//  Audio functions
//-----------------------------------------------

csVoid csListenerUpdate(ISceneNode* node)
{
	core::matrix4 matrix = node->getAbsoluteTransformation();	// Get current node transformation
	core::vector3df lookat(0,0,1);									// This vector represents the lookat position of the node (1 step forward in the Z axis)
	matrix.transformVect(lookat);									// Get new transformation
	AudioDevice->setListenerPosition(node->getAbsolutePosition(), lookat);
}

csVoid csSoundSetMasterVolume(float volume)
{
	AudioDevice->setSoundVolume(volume);
}

csFloat csSoundGetMasterVolume(float volume)
{
	return AudioDevice->getSoundVolume();
}

csInt csSoundLoad(const char* file)
{
	return (int) AudioDevice->addSoundSource(file);
}

csVoid csSoundFree(ISoundSource* sound)
{
	sound->drop();
}

csInt csSoundPlay2D(ISoundSource* sound, int loop)
{
	return (int) AudioDevice->play2D(sound, (bool) loop, false, true);
}

csInt csSoundPlay3D(ISoundSource* sound, float x, float y, float z, int loop)
{
	return (int) AudioDevice->play3D(sound, vector3df(x,y,z), (bool) loop, false, true);
}

csInt csSoundIsPlaying(ISoundSource* sound)
{
	return (int) AudioDevice->isCurrentlyPlaying(sound);
}

csInt csChannelPaused(ISound* channel)
{
	return (int) channel->getIsPaused();
}

csInt csChannelFinished(ISound* channel)
{
	return (int) channel->isFinished();
}

csInt csChannelLooped(ISound* channel)
{
	return (int) channel->isLooped();
}

csFloat csChannelGetMinDistance(ISound* channel)
{
	return channel->getMinDistance();
}

csFloat csChannelGetMaxDistance(ISound* channel)
{
	return channel->getMaxDistance();
}

csFloat csChannelGetPan(ISound* channel)
{
	return channel->getPan();
}

csInt csChannelGetPlayPosition(ISound* channel)
{
	return channel->getPlayPosition();
}

csFloat csChannelX(ISound* channel)
{
	return channel->getPosition().X;
}

csFloat csChannelY(ISound* channel)
{
	return channel->getPosition().Y;
}

csFloat csChannelZ(ISound* channel)
{
	return channel->getPosition().Z;
}

csFloat csChannelGetVolume(ISound* channel)
{
	return channel->getVolume();
}

csVoid csChannelPause(ISound* channel)
{
	channel->setIsPaused(true);
}

csVoid csChannelResume(ISound* channel)
{
	channel->setIsPaused(false);
}

csVoid csChannelSetDistance(ISound* channel, float min, float max)
{
	channel->setMinDistance(min);
	channel->setMaxDistance(max);
}

csVoid csChannelSetPan(ISound* channel, float pan)
{
	channel->setPan(pan);
}

csVoid csChannelSetPosition(ISound* channel, float x, float y, float z)
{
	channel->setPosition(vector3df(x,y,z));
}

csVoid csChannelSetVolume(ISound* channel, float volume)
{
	channel->setVolume(volume);
}

csVoid csChannelStop(ISound* channel)
{
	channel->stop();
}