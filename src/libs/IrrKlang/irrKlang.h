/* irrKlang.h -- interface of the 'irrKlang' library

  Copyright (C) 2002-2007 Nikolaus Gebhardt

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
*/

#ifndef __IRR_KLANG_H_INCLUDED__
#define __IRR_KLANG_H_INCLUDED__

#include "irrTypes.h"
#include "IUnknown.h"
#include "IVirtualUnknown.h"

#include "ESoundOutputDrivers.h"
#include "ESoundEngineOptions.h"
#include "EStreamModes.h"
#include "SAudioStreamFormat.h"
#include "ISoundEngine.h"
#include "ISoundSource.h"
#include "ISound.h"
#include "IAudioStream.h"
#include "IAudioStreamLoader.h"

//! irrKlang Version
#define IRR_KLANG_VERSION "0.7"

/*! \mainpage irrKlang 0.7 API documentation
 *
 * <div align="center"><img src="logobig.png" ></div>
 *
 * \section intro Introduction
 *
 * Welcome to the irrKlang API documentation.
 * Here you'll find any information you'll need to develop applications with
 * irrKlang. If you are looking for a tutorial on how to start, you'll
 * find some on the homepage of irrKlang at
 * <A HREF="http://www.ambiera.com/irrklang" >http://www.ambiera.com/irrklang</A>
 * or inside the SDK in the directory \examples.
 *
 * The irrKlang library is intended to be an easy-to-use 3d and 2d sound engine, so
 * this documentation is an important part of it. If you have any questions or
 * suggestions, just send a email to the author of the engine, Nikolaus Gebhardt
 * (niko (at) irrlicht3d.org).
 *
 *
 * \section links Links
 *
 * <A HREF="namespaces.html">Namespaces</A>: A very good place to start reading
 * the documentation.<BR>
 * <A HREF="annotated.html">Class list</A>: List of all classes with descriptions.<BR>
 * <A HREF="functions.html">Class members</A>: Good place to find forgotten features.<BR>
 *
 * \section irrexample Short example
 *
 * A simple application, starting up the sound engine and playing a .wav sound effect and
 * some streaming .ogg music file.
 *
 * \code
 * #include <iostream>
 * #include <irrKlang.h>
 * using namespace irr;
 * using namespace audio;
 *
 * #pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll
 *
 *
 * int main(int argc, const char** argv)
 * {
 * 	// start the sound engine with default parameters
 * 	ISoundEngine* engine = createIrrKlangDevice();
 *
 * 	if (!engine)
 * 		return 0; // error starting up the engine
 *
 * 	// play some sound stream, looped
 * 	engine->play2D("../../media/helltroopers.ogg", true);
 *
 * 	std::cout << "\nHello World!\n";
 *
 * 	char i = 0;
 *
 * 	while(i != 'q')
 * 	{
 * 		std::cout << "Press any key to play some sound, press 'q' to quit.\n";
 *
 * 		// play a single sound
 * 		engine->play2D("../../media/bell.wav");
 *
 * 		std::cin >> i; // wait for user to press some key
 * 	}
 *
 * 	engine->drop(); // delete engine
 * 	return 0;
 * }
 *
 * \endcode
 */

#if defined(IRRKLANG_STATIC)
    #define IRRKLANG_API
#else
    #if (defined(WIN32) || defined(WIN64) || defined(_MSC_VER))
        #ifdef IRRKLANG_EXPORTS
        #define IRRKLANG_API __declspec(dllexport)
        #else
        #define IRRKLANG_API __declspec(dllimport)
        #endif // IRRKLANG_EXPORT
    #else
        #define IRRKLANG_API __attribute__((visibility("default")))
    #endif // defined(WIN32) || defined(WIN64)
#endif // IRRKLANG_STATIC

#if defined(_STDCALL_SUPPORTED)
#define IRRKLANGCALLCONV __stdcall  // Declare the calling convention.
#else
#define IRRKLANGCALLCONV
#endif // STDCALL_SUPPORTED

//! Everything in the Irrlicht Engine can be found in this namespace.
namespace irr
{
namespace audio
{
	//! Creates an irrKlang device. The irrKlang device is the root object for using the sound engine.
	/** \param driver The sound output driver to be used for sound output. Use audio::ESOD_AUTO_DETECT
	to let irrKlang decide which driver will be best.
	\param options A combination of audio::E_SOUND_ENGINE_OPTIONS literals. Default value is ESEO_DEFAULT_OPTIONS.
	\param sdk_version_do_not_use Don't use or change this parameter. Always set it to
	IRRKLANG_SDK_VERSION, which is done by default. This is needed for sdk version checks.
	\return Returns pointer to the created irrKlang device or null if the
	device could not be created. If you don't need the device, use ISoundEngine::drop() to
	delete it. See IUnknown::drop() for details.
	*/
	IRRKLANG_API ISoundEngine* IRRKLANGCALLCONV createIrrKlangDevice(
		E_SOUND_OUTPUT_DRIVER driver = ESOD_AUTO_DETECT,
		int options = audio::ESEO_DEFAULT_OPTIONS,
		const char* sdk_version_do_not_use = IRR_KLANG_VERSION);
}

	// THE FOLLOWING IS AN EMPTY LIST OF ALL SUB NAMESPACES
	// EXISTING ONLY FOR THE DOCUMENTATION SOFTWARE DOXYGEN.

	//! In this namespace can be found basic classes like vectors, planes, arrays, lists and so on.
	namespace core
	{
	}

	//! This namespace provides interfaces for input/output: Reading and writing files, accessing zip archives, xml files, ...
	namespace io
	{
	}

	//! The video namespace contains classes for accessing the video driver. All 2d and 3d rendering is done here.
	namespace video
	{
	}

	//! Most of the irrKlang classes for sound output can be found here.
	namespace audio
	{
	}
}


/*! \file irrKlang.h
    \brief Main header file of the irrKlang sound library, the only file needed to include.
*/

#endif

