#include "engine.h"

//-----------------------------------------------
//  Display variables
//-----------------------------------------------

bool displayClosed;
IrrlichtDevice* Device = NULL;

#if defined(COLDSTEEL_LITE) || defined(COLDSTEEL_DEMO)
ITexture* watermark = NULL;
extern "C" {
	extern int watermarkWidth;
	extern int watermarkHeight;
	extern unsigned char watermarkData[];
}
#endif

//-----------------------------------------------
//  Display functions
//-----------------------------------------------

csVoid csDisplayOpen(int width, int height, int depth, int flags, int win)
{
	#if defined(_WIN32) && !defined(__GNUC__)
	E_DRIVER_TYPE driver = EDT_DIRECT3D9;
	#else
	E_DRIVER_TYPE driver = EDT_OPENGL;
	#endif
	bool fullscreen = false;
	bool vsync = false;
	bool antialias = true;

	displayClosed = false;

	// Close previous display
	Device->closeDevice();

	// Parse flags
	if ((flags & CSDF_FULLSCREEN) == CSDF_FULLSCREEN) fullscreen = true;
	if ((flags & CSDF_VSYNC) == CSDF_VSYNC) vsync = true;
	if ((flags & CSDF_ANTIALIAS) == CSDF_ANTIALIAS) antialias = true;
	if ((flags & CSDF_OPENGL) == CSDF_OPENGL) driver = EDT_OPENGL;

	// Check software mode
	if ((width < 0) || (height < 0))
	{
		driver = EDT_BURNINGSVIDEO;
		if (width < 0) width = -width;
		if (height < 0) height = -height;
	}

	/*
	// Lite version only supports DX9, max 1024x768, 16 bit mode,
	// no stencil, no antialias, and cannot draw on an external window
	#ifdef COLDSTEEL_LITE
	driver = EDT_DIRECTX9;
	if (width > 1024) width		= 1024;
	if (height > 768) height	= 768;
	depth = 16;
	stencil = false;
	antialias = false;
	win = 0;
	#endif
	*/
	
	// Set device creation parameters
	SIrrlichtCreationParameters param;
	param.AntiAlias = antialias;
	param.Bits = depth;
	param.DriverType = driver;
	param.EventReceiver = new csEventReceiver;
	param.Fullscreen = fullscreen;
	param.Stencilbuffer = true;
	param.Vsync = vsync;
	param.WindowId = (void*) win;
	param.WindowSize.Width = width;
	param.WindowSize.Height = height;
	Device = createDeviceEx(param);

	// Add packed media file to the resource manager
	/*#ifndef COLDSTEEL_LITE
	// Adds list of zips
	for (int i = 0; i < zip_list.size(); i++)
		Device->getFileSystem()->addZipFileArchive(zip_list[i].c_str());
	#endif*/

	// Video driver settings
	vx = 0; vy = 0;
	vw = Device->getVideoDriver()->getScreenSize().Width;
	vh = Device->getVideoDriver()->getScreenSize().Height;

	// Create watermark for Lite and SDK demo versions
	#if defined(CODSTEEL_LITE) || defined(COLDSTEEL_DEMO)
	IImage* img = Device->getVideoDriver()->createImageFromData(ECF_A8R8G8B8, dimension2d<s32>(watermarkWidth, watermarkHeight), watermarkData, false);
	watermark = Device->getVideoDriver()->addTexture("*", img);
	Device->getVideoDriver()->makeColorKeyTexture(watermark, SColor(255, 0, 0, 0));
	img->drop();
	#endif

	// Init physics
	InitPhysics();

	csEventPost(CSEV_DISPLAY_OPEN, 0, 0, 0.0, 0.0, 0.0, "");
}

//-----------------------------------------------

csVoid csDisplayClose()
{
	//while (!mat_list.empty())
	//  csMaterialFree(mat_list[0]);

	//while (!partdata_list.empty())
	//  csParticleDataFree(partdata_list[0]);

	// Delete other stuff (nodes, textures, etc)
	//...

	// Clean physics
	CleanPhysics();

	if (Device)
		Device->closeDevice();
	Device = createDevice(EDT_NULL);
	displayClosed = true;
}

//-----------------------------------------------

csVoid csDisplayCaption(const char* caption)
{
	Device->setWindowCaption(asWstring(caption));
}

//-----------------------------------------------

csInt csDisplayClosed()
{
	if (displayClosed)
		return 1;
	return 0;
}

//-----------------------------------------------

csInt csDisplayWidth()
{
	return Device->getVideoDriver()->getScreenSize().Width;
}

//-----------------------------------------------

csInt csDisplayHeight()
{
	return Device->getVideoDriver()->getScreenSize().Height;
}

//-----------------------------------------------

csInt csDisplayFps()
{
	return Device->getVideoDriver()->getFPS();	
}

//-----------------------------------------------

csInt csDisplayFeature(int feature)
{
	return Device->getVideoDriver()->queryFeature((E_VIDEO_DRIVER_FEATURE)feature);
}

//-----------------------------------------------

csVoid csDisplayResize(int width, int height)
{
	Device->getVideoDriver()->OnResize(dimension2d<s32>(width, height));
}

//-----------------------------------------------

csInt csDisplayActive()
{
	return (int) Device->isWindowActive();
}

//-----------------------------------------------

csVoid csDisplayScreenshot(const char* file)
{
	IImage* img = Device->getVideoDriver()->createScreenShot();
	Device->getVideoDriver()->writeImageToFile(img, file);
	img->drop();
}