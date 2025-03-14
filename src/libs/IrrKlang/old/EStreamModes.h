// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __E_STREAM_MODES_H_INCLUDED__
#define __E_STREAM_MODES_H_INCLUDED__

namespace irr
{
namespace audio  
{
	//! An enumeration for all types of supported sound drivers
	enum E_STREAM_MODE
	{
		//! Autodetects the best stream mode for a specified audio data
		ESM_AUTO_DETECT = 0,

		//! Streams the audio data when needed
		ESM_STREAMING,

		//! Loads the whole audio data into the memory
		ESM_NO_STREAMING,

		//! This enumeration literal is never used, it only forces the compiler to 
		//! compile these enumeration values to 32 bit.
		ESM_FORCE_32_BIT = 0x7fffffff
	};

} // end namespace audio
} // end namespace irr


#endif

