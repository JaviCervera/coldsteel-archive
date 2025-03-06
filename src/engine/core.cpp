#include "engine.h"

//-----------------------------------------------
//  Core variables
//-----------------------------------------------

#ifdef COLDSTEEL_DEMO
float demo_time = 0;
#endif

//-----------------------------------------------
//  Core functions
//-----------------------------------------------

csVoid csCoreInit()
{
	// Finish Core if it were previously initialized
	csCoreFinish();

	// Indicates that the display is not closed (as csCoreFinish() puts it in that state)
	displayClosed = false;

	// Create IrrKlang Device
	AudioDevice = createIrrKlangDevice();

	// Start demo timer
	#ifdef COLDSTEEL_DEMO
	if (!demo_time) demo_time = (float) clock() / CLOCKS_PER_SEC;
	#endif

	// Init joystick library
#if defined(_WIN32) && !defined(__GNUC__)
	jsInit();
	csJoyInit(0);
	csJoyInit(1);
#endif

	// Send init event
	csEventPost(CSEV_INIT, 0, 0, 0.0, 0.0, 0.0, "");
}

//-----------------------------------------------

csVoid csCoreFinish()
{
	// Shutdown joystick library
	#if defined(_WIN32) && !defined(__GNUC__)
	csJoyFinish(0);
	csJoyFinish(1);
	#endif

	// Close display
	csDisplayClose();

	// Close audio engine
	if (AudioDevice)
	{
		AudioDevice->stopAllSounds();
		AudioDevice->drop();
		AudioDevice = NULL;
	}

	// Delete all stuff (vectors, etc)
	CleanEvents();
	CleanMatrices();
	CleanVectors();
	CleanMaterialDatas();
	CleanParticleDatas();
   // CleanZipList(); //********************
}

//-----------------------------------------------

csVoid csCoreMessage(const char* msg, int error)
{
	#if defined(_WIN32) && !defined(__GNUC__)
	int flags = MB_OK;
	if (error) flags |= MB_ICONEXCLAMATION;
	MessageBox(NULL, msg, "ColdSteel Engine", flags);
	#endif
}

//-----------------------------------------------

csInt csCoreTimer()
{
	return (int) Device->getTimer()->getRealTime();
}