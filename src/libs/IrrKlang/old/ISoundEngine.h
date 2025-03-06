// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __I_SOUND_ENGINE_H_INCLUDED__
#define __I_SOUND_ENGINE_H_INCLUDED__

#include "IUnknown.h"
#include "vector3d.h"
#include "ISoundSource.h"
#include "ISound.h"
#include "EStreamModes.h"
#include "IFileFactory.h"

namespace irr
{
namespace audio
{
	class IAudioStreamLoader;

	//! Interface to the sound engine, for playing 3d and 2d sound and music
	class ISoundEngine : public virtual irr::IUnknown
	{
	public:

		//! loads a sound source (if not loaded already) from a file and plays it.
		/** \param sourceFileName Filename of sound, like "sounds/test.wav" or "foobar.ogg".
		 \param playLooped plays the sound in loop mode. If set to 'false', the sound is played once, then stopped and deleted from the internal playing list. Calls to
		 ISound have no effect after such a non looped sound has been stopped automaticly.
		 \param startPaused starts the sound paused. This implies that track=true. Use this if you want to modify some of the playing
		 parameters before the sound actually plays. Usually you would set this parameter to true, then use the ISound interface to
		 modify some of the sound parameters and then call ISound::setPaused(false);
		 Note: You need to call ISound::drop() when setting this parameter to true and you don't need the ISound
		 object anymore. See 'return' for details.
		 \param track Makes it possible to track the sound. Causes the method to return an ISound interface. See 'return' for details.
		 \param streamMode Specifies if the file should be streamed or loaded completely into memory for playing.
		 ESM_AUTO_DETECT sets this to autodetection. Note: if the sound has been loaded or played before into the
		 engine, this parameter has no effect.
		 \return Only returns a pointer to an ISound if the parameters 'track' or 'startPaused' have been
		 set to true. Note: if this method returns an ISound as result, you HAVE to call ISound::drop()
		 after you don't need the ISound interface anymore. Otherwise this will cause memory waste or even
		 hardware buffer wastes. This method also may return 0 altough 'track' or 'startPaused' have been
		 set to true, if the sound could not be played.*/
		virtual ISound* play2D(const char* soundFileName, bool playLooped=false,
							   bool startPaused=false, bool track=false, E_STREAM_MODE streamMode=ESM_AUTO_DETECT) = 0;

		//! Plays a sound source as 2D sound with its default settings stored in ISoundSource.
		/** An ISoundSource object will be created internally when playing a sound the first time,
		or can be added with getSoundSource().
		\param source The sound source, specifiying sound file source and default settings for this file.
		Use the other ISoundEngine::play2D() overloads if you want to specify a filename string instead of this.
		\param playLooped plays the sound in loop mode. If set to 'false', the sound is played once, then stopped and deleted from the internal playing list. Calls to
		 ISound have no effect after such a non looped sound has been stopped automaticly.
		\param startPaused starts the sound paused. This implies that track=true. Use this if you want to modify some of the playing
		 parameters before the sound actually plays. Usually you would set this parameter to true, then use the ISound interface to
		 modify some of the sound parameters and then call ISound::setPaused(false);
		 Note: You need to call ISound::drop() when setting this parameter to true and you don't need the ISound
		 object anymore. See 'return' for details.
		 \param track Makes it possible to track the sound. Causes the method to return an ISound interface. See 'return' for details.
		 \return Only returns a pointer to an ISound if the parameters 'track' or 'startPaused' have been
		 set to true. Note: if this method returns an ISound as result, you HAVE to call ISound::drop()
		 after you don't need the ISound interface anymore. Otherwise this will cause memory waste or even
		 hardware buffer wastes. This method also may return 0 altough 'track' or 'startPaused' have been
		 set to true, if the sound could not be played.*/
		virtual ISound* play2D(ISoundSource* source, bool playLooped=false,
								bool startPaused=false, bool track=false) = 0;

		//! loads a sound source (if not loaded already) from a file and plays it as 3D sound.
		/** \param sourceFileName Filename of sound, like "sounds/test.wav" or "foobar.ogg".
		 \param pos Position of the 3D sound.
		 \param playLooped plays the sound in loop mode. If set to 'false', the sound is played once, then stopped and deleted from the internal playing list. Calls to
		 ISound have no effect after such a non looped sound has been stopped automaticly.
		 \param startPaused starts the sound paused. This implies that track=true. Use this if you want to modify some of the playing
		 parameters before the sound actually plays. Usually you would set this parameter to true, then use the ISound interface to
		 modify some of the sound parameters and then call ISound::setPaused(false);
		 Note: You need to call ISound::drop() when setting this parameter to true and you don't need the ISound
		 object anymore. See 'return' for details.
		 \param track Makes it possible to track the sound. Causes the method to return an ISound interface. See 'return' for details.
 		 \param streamMode Specifies if the file should be streamed or loaded completely into memory for playing.
		 ESM_AUTO_DETECT sets this to autodetection. Note: if the sound has been loaded or played before into the
		 engine, this parameter has no effect.
		 \return Only returns a pointer to an ISound if the parameters 'track' or 'startPaused' have been
		 set to true. Note: if this method returns an ISound as result, you HAVE to call ISound::drop()
		 after you don't need the ISound interface anymore. Otherwise this will cause memory waste or even
		 hardware buffer wastes. This method also may return 0 altough 'track' or 'startPaused' have been
		 set to true, if the sound could not be played.*/
		virtual ISound* play3D(const char* soundFileName, core::vector3df pos,
							   bool playLooped=false, bool startPaused=false,
							   bool track=false, E_STREAM_MODE streamMode=ESM_AUTO_DETECT) = 0;

		//! Plays a sound source as 2D sound with its default settings stored in ISoundSource.
		/** An ISoundSource object will be created internally when playing a sound the first time,
		or can be added with getSoundSource().
		\param source The sound source, specifiying sound file source and default settings for this file.
		Use the other ISoundEngine::play2D() overloads if you want to specify a filename string instead of this.
		\param pos Position of the 3D sound.
		\param playLooped plays the sound in loop mode. If set to 'false', the sound is played once, then stopped and deleted from the internal playing list. Calls to
		 ISound have no effect after such a non looped sound has been stopped automaticly.
		\param startPaused starts the sound paused. This implies that track=true. Use this if you want to modify some of the playing
		 parameters before the sound actually plays. Usually you would set this parameter to true, then use the ISound interface to
		 modify some of the sound parameters and then call ISound::setPaused(false);
		 Note: You need to call ISound::drop() when setting this parameter to true and you don't need the ISound
		 object anymore. See 'return' for details.
		 \param track Makes it possible to track the sound. Causes the method to return an ISound interface. See 'return' for details.
		 \return Only returns a pointer to an ISound if the parameters 'track' or 'startPaused' have been
		 set to true. Note: if this method returns an ISound as result, you HAVE to call ISound::drop()
		 after you don't need the ISound interface anymore. Otherwise this will cause memory waste or even
		 hardware buffer wastes. This method also may return 0 altough 'track' or 'startPaused' have been
		 set to true, if the sound could not be played.*/
		virtual ISound* play3D(ISoundSource* source, core::vector3df pos,
							   bool playLooped=false, bool startPaused=false, bool track=false) = 0;

		//! plays a sound source as music
		/** NOTE: Not implemented yet.
		\return Returns 0 if failed and a pointer to the playing sound if suceceeded. The returned pointer can
		 be ignored if not needed. */
		virtual ISound* playMusic(ISoundSource* source) = 0;

		//! stops all currently playing sounds
		virtual void stopAllSounds() = 0;

		//! Gets a sound source by sound name. Adds the sound source as file into the sound engine if not loaded already.
		/** Please note: For performance reasons most ISoundEngine implementations will
		not try to load the sound when calling this method, but only when play() is called
		with this sound source as parameter. */
		virtual ISoundSource* getSoundSource(const c8* soundName) = 0;

		//! returns a sound source by index.
		/** \param idx: Index of the loaded sound source, must by smaller than getSoundSourceCount() */
		virtual ISoundSource* getSoundSource(s32 index) = 0;

		//! returns amount of loaded sound sources
		virtual s32 getSoundSourceCount() = 0;

		//! Adds sound source into the sound engine as file.
		/** Please note: For performance reasons most ISoundEngine implementations will
		not try to load the sound file when calling this method, but only when play() is called
		with this sound source as parameter. 
		\param fileName Name of the sound file (e.g. "sounds/something.mp3"). You can also use this
		name when calling play3D() or play2D().
		\param mode Streaming mode for this sound source 
		\return Returns the pointer to the added sound source or 0 if not sucessful because for
		example a sound already existed with that name. If not successful, the reason will be printed
		into the log. */
		virtual ISoundSource* addSoundSource(const c8* fileName, E_STREAM_MODE mode=ESM_AUTO_DETECT) = 0;

		//! Adds sound source into the sound engine as memory source.
		/** \param memory Pointer to the memory to be treated as loaded sound file. 
		Note: The memory block pointed to should remain there as long as the sound engine exists.
		This will change with the the next release of the engine.
		\param sizeInBytes Size of the memory chunk, in bytes.
		\param soundName Name of the virtual sound file (e.g. "sounds/something.mp3"). You can also use this
		name when calling play3D() or play2D().
		\return Returns the pointer to the added sound source or 0 if not sucessful because for
		example a sound already existed with that name. If not successful, the reason will be printed
		into the log. */
		virtual ISoundSource* addSoundSource(void* memory, s32 sizeInBytes, const c8* soundName) = 0;

		//! returns current playing music sound, and 0 if no music played currently
		virtual ISound* getCurrentMusic() = 0;

		//! sets sound volume. This value is multiplied with all sounds played, but not with music.
		//! \param volume 0 (silent) to 1.0f (full volume)
		virtual void setSoundVolume(f32 volume) = 0;

		//! returns sound volume
		virtual f32 getSoundVolume() = 0;

		//! sets music volume
		//! \param volume 0 (silent) to 1.0f (full volume)
		virtual void setMusicVolume(f32 volume) = 0;

		//! returns music volume
		virtual f32 getMusicVolume() = 0;

		//! Sets the current listener 3d position.
		/** This method is being called by the scene manager automaticly if you are using one, so
		 you might want to ignore this. */
		virtual void setListenerPosition(const core::vector3df& pos,
			const core::vector3df& lookdir,
			const core::vector3df& velPerSecond = core::vector3df(0,0,0),
			const core::vector3df& upVector = core::vector3df(0,1,0)) = 0;

		//! Updates the audio engine. This should be called once per frame if irrKlang was started in single thread mode.
		/** This updates the 3d positions of the sounds as well as their volumes, effects,
		streams and other stuff. Call this once per frame if you specified irrKlang to run
		single threaded. Otherwise it is not necessary to use this method.
		This method is being called by the scene manager automaticly if you are using one, so
		you might want to ignore this. */
		virtual void update() = 0;

		//! Returns if a sound with the specified name is currently playing
		virtual bool isCurrentlyPlaying(const char* soundName) = 0;

		//! Returns if a sound with the specified source is currently playing
		virtual bool isCurrentlyPlaying(ISoundSource* source) = 0;

		//! Registers a new audio stream loader in the sound engine
		/** Use this to enhance the audio engine to support other or new file formats.
		To do this, implement your own IAudioStreamLoader interface and register it
		with this method*/
		virtual void registerAudioStreamLoader(IAudioStreamLoader* loader) = 0;

		//! Returns if irrKlang is running in the same thread as the application or is using multithreading.
		/** This basicly returns the flag set by the user when creating the sound engine.*/
		virtual bool isMultiThreaded() const = 0;

		//! Adds a file factory to the sound engine, making it possible to override file access of the sound engine.
		/** Derive your own class from IFileFactory, overwrite the createAndOpenFile()
		method and return your own implemented IReadFile to overwrite file access of irrKlang. */
		virtual void addFileFactory(io::IFileFactory* fileFactory) = 0;
	};


} // end namespace sound
} // end namespace irr


#endif
