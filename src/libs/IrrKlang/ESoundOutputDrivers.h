// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __E_SOUND_OUTPUT_DRIVERS_H_INCLUDED__
#define __E_SOUND_OUTPUT_DRIVERS_H_INCLUDED__

namespace irr
{
namespace audio
{
	//! An enumeration for all types of supported sound drivers
	enum E_SOUND_OUTPUT_DRIVER
	{
		//! Autodetects the best sound driver for the system
		ESOD_AUTO_DETECT = 0,

		//! DirectSound sound output driver, windows only
		ESOD_DIRECT_SOUND,

		//! WinMM sound output driver, windows only
		ESOD_WIN_MM,

		//! ALSA sound output driver, linux only
		ESOD_ALSA,

		//! Null driver, creating no sound output
		ESOD_NULL,

		//! Amount of built-in sound output drivers
		ESOD_COUNT,

		//! This enumeration literal is never used, it only forces the compiler to
		//! compile these enumeration values to 32 bit.
		ESOD_FORCE_32_BIT = 0x7fffffff
	};

} // end namespace audio
} // end namespace irr


#endif

