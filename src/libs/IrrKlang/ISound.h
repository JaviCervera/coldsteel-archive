// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __I_SOUND_H_INCLUDED__
#define __I_SOUND_H_INCLUDED__

#include "IVirtualUnknown.h"
#include "vector3d.h"

namespace irr
{

namespace audio
{
	class ISoundSource;

	//! Represents a sound which is currently played.
	/** You can stop the sound or change the volume or whatever using this interface.
	Creating sounds is done using ISoundEngine::play2D() or ISoundEngine::play3D(). 
	More informations about the source of a sound can be obtained from the ISoundSource
	interface. */
	class ISound : public virtual irr::IVirtualUnknown
	{
	public:

		//! returns source of the sound (with which you can get the filename or similar)
		virtual ISoundSource* getSoundSource() = 0;

		//! returns if the sound is paused
		virtual void setIsPaused( bool paused = true) = 0;

		//! returns if the sound is paused
		virtual bool getIsPaused() = 0;

		//! Will stop the sound and free its resources.
		/** If you just want to pause the sound, use setIsPaused().
		After calling stop(), isFinished() will usually return true. */
		virtual void stop() = 0;

		//! returns volume of the sound, a value between 0 (mute) and 1 (full volume).
		/** (this volume gets multiplied with the master volume of the sound engine
		and other parameters like distance to listener when played as 3d sound)  */
		virtual f32 getVolume() = 0;

		//! sets the volume of the sound, a value between 0 (mute) and 1 (full volume).
		/** This volume gets multiplied with the master volume of the sound engine
		and other parameters like distance to listener when played as 3d sound.  */
		virtual void setVolume(f32 volume) = 0;

		//! sets the pan of the sound. Takes a value between -1 and 1, 0 is center.
		virtual void setPan(f32 pan) = 0;

		//! returns the pan of the sound. Takes a value between -1 and 1, 0 is center.
		virtual f32 getPan() = 0;

		//! returns if the sound has been started to play looped
		virtual bool isLooped() = 0;

		//! returns if the sound has finished playing.
		/** Don't mix this up with isPaused(). isFinished() returns if the sound has been
		finished playing. If it has, is maybe already have been removed from the playing list of the
		sound engine and calls to any other of the methods of ISound will not have any result.
		If you call stop() to a playing sound will result that this function will return true
		when invoked. */
		virtual bool isFinished() = 0;

		//! Sets the minimal distance if this is a 3D sound.
		/** Specify the distances at which 3D sounds stop getting louder or quieter. This works
		like this: As a listener approaches a 3D sound source, the sound gets louder.
		Past a certain point, it is not reasonable for the volume to continue to increase.
		Either the maximum (zero) has been reached, or the nature of the sound source
		imposes a logical limit. This is the minimum distance for the sound source.
		Similarly, the maximum distance for a sound source is the distance beyond
		which the sound does not get any quieter.
		The default minimum distance is 1, the default max distance is a huge number nearly to infinite. */
		virtual void setMinDistance(f32 min) = 0;

		//! Returns the minimal distance if this is a 3D sound.
		/** See setMaxDistance() for details. */
		virtual f32 getMinDistance() = 0;

		//! Sets the maximal distance if this is a 3D sound.
		/** Specify the distances at which 3D sounds stop getting louder or quieter. This works
		like this: As a listener approaches a 3D sound source, the sound gets louder.
		Past a certain point, it is not reasonable for the volume to continue to increase.
		Either the maximum (zero) has been reached, or the nature of the sound source
		imposes a logical limit. This is the minimum distance for the sound source.
		Similarly, the maximum distance for a sound source is the distance beyond
		which the sound does not get any quieter.
		The default minimum distance is 1, the default max distance is a huge number nearly to infinite. */
		virtual void setMaxDistance(f32 max) = 0;

		//! Returns the maximal distance if this is a 3D sound.
		/** See setMaxDistance() for details. */
		virtual f32 getMaxDistance() = 0;

		//! sets the position of the sound in 3d space
		virtual void setPosition(core::vector3df position) = 0;

		//! returns the position of the sound in 3d space
		virtual core::vector3df getPosition() = 0;

		//! returns the current play position of the sound in milliseconds.
		/** Returns -1 if not implemented or possible for this sound for example
		because it already has been stopped and freed internally or similar. */
		virtual u32 getPlayPosition() = 0;

		//! returns the play length of the sound in milliseconds.
		/** Returns -1 if not known for this sound for example because its decoder
		does not support length reporting or it is a file stream of unknown size.
		Note: You can also use ISoundSource::getPlayLength() to get the length of 
		a sound without actually needing to play it. */
		virtual u32 getPlayLength() = 0;
	};

} // end namespace audio
} // end namespace irr


#endif
