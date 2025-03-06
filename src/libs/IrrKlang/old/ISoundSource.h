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
	};

} // end namespace sound
} // end namespace irr


#endif
