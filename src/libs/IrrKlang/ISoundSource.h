// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __I_IRR_SOUND_SOURCE_H_INCLUDED__
#define __I_IRR_SOUND_SOURCE_H_INCLUDED__

#include "IUnknown.h"
#include "vector3d.h"
#include "EStreamModes.h"

namespace irr
{

namespace audio
{
	//! A sound source describes an input file (.ogg, .mp3 or .wav) and its default settings for volume, 3d or 2d etc.
	/** The sound source can have default settings (is it a 3d sound source, is is a stream, does it loop, etc). */
	class ISoundSource : public virtual irr::IUnknown
	{
	public:

		//! returns the name of the sound source (usually, this is the file name)
		virtual const c8* getName() = 0;

		//! returns the detected or set type of the sound with wich the sound will be played.
		/** Note: If the returned type is ESM_AUTO_DETECT, this mode will change after the
		sound has been played the first time. */
		virtual E_STREAM_MODE getStreamMode() = 0;

		//! returns the play length of the sound in milliseconds.
		/** Returns -1 if not known for this sound for example because its decoder
		does not support lenght reporting or it is a file stream of unknown size.
		Note: If the sound never has been played before, the sound engine will have to open
		the file and try to get the play lenght from there, so this call could take a bit depending
		on the type of file. */
		virtual u32 getPlayLength() = 0;

		//! Forces the sound to be reloaded at next replay.
		/** Sounds which are not played as streams are buffered to make it possible to
		replay them without much overhead. If the sound file is altered after the sound
		has been played the first time, the engine won't play the changed file then.
		Calling this method makes the engine reload the file before the file is played
		the next time.*/
		virtual void forceReloadAtNextUse() = 0;

		//! Sets the threshold size where irrKlang decides to force streaming a file independent of the user specified setting.
		/** When specifying ESM_NO_STREAMING for playing back a sound file, irrKlang will
		ignore this setting if the file is bigger than this threshold and stream the file
		anyway. Please note that if an audio format loader is not able to return the 
		size of a sound source and returns -1 as length, this will be ignored as well 
		and streaming has to be forced.
		\param threshold: New threshold. The value is specified in uncompressed bytes and its default value is 
		about one Megabyte. Set to 0 or a negative value to disable stream forcing. */
		virtual void setForcedStreamingThreshold(s32 thresholdBytes) = 0;

		//! Returns the threshold size where irrKlang decides to force streaming a file independent of the user specified setting.
		/** See setForcedStreamingThreshold() for details. */
		virtual s32 getForcedStreamingForceThreshold() = 0;
	};

} // end namespace sound
} // end namespace irr


#endif
