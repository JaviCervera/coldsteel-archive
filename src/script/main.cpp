#include "script.h"

char     exeFilename[1024];
char     dllFilename[1024];

// Format of the functions found in the game dll
typedef const char* (*csGetApiVersionPtr)();
typedef int (*csGetApiPtr)(int);
typedef void (*csMainPtr)(int, int, int, float, float, float, const char*);

bool initDll()
{
#ifdef _WIN32
   // Load game dll
   dllHandle = LoadLibrary(dllFilename);
   if (!dllHandle)
      return false;

   // Get Api version checker
   csGetApiVersion = (csGetApiVersionPtr) GetProcAddress(dllHandle, "csGetApiVersion");
   if (!csGetApiVersion)
      return false;
   
   // Get Api def function
   csGetApi = (csGetApiPtr) GetProcAddress(dllHandle, "csGetApi");
   if (!csGetApi)
      return false;

   // Get main function
   csMain = (csMainPtr) GetProcAddress(dllHandle, "csMain");
   if (!csMain)
      return false;
#endif

   return true;
}

void finishDll()
{
#ifdef _WIN32
   FreeLibrary(dllHandle);
#endif
}

#ifdef _WIN32
int WINAPI WinMain(IN HINSTANCE hInstance, IN HINSTANCE hPrevInstance, IN LPSTR lpCmdLine, IN int nShowCmd)
#endif
{
   // Get exe filename
#ifdef _WIN32
   GetModuleFileName(NULL, exeFilename, sizeof(exeFilename));
#endif

   // Get dll filename
   if(strcmp(lpCmdLine, ""))  // If a file is specified (without extension), set as dll filename
   {
      strcpy(dllFilename, csFileStripExt(lpCmdLine));
   } else {                   // If no file is specified, use the exe filename
      strcpy(dllFilename, csFileStripExt(exeFilename));
   }
   strcat(dllFilename, ".dll");  // Add ".dll" extension

   // Init dll
   if (!initDll())
   {
      char errorMsg[1024];
      strcpy(errorMsg, "Could not load '");
      strcat(errorMsg, dllFilename);
      strcat(errorMsg, "'.");
#if defined(_WIN32)
      MessageBox(NULL, errorMsg, "Error", MB_OK | MB_ICONEXCLAMATION);
#elif defined(__APPLE__)
      NSRunCriticalAlertPanel(@"Error", errorMsg, @"Ok", 0, 0);
#endif
      return -1;
   }

   // Check dll version
   if (strcmp(csGetApiVersion(), VERSION_STRING))
   {
#ifdef _WIN32
      MessageBox(NULL, "Dll does not match engine version.", "Error", MB_OK | MB_ICONEXCLAMATION);
#endif
      return -1;
   }

   // Pass the engine functions to the dll
   csGetApi(ExportApi());

   // Init engine
   csCoreInit();

   // Loop
	bool must_exit = false;	// Tells if the engine has to finish
	int millisecs = 0;	    // Millisecs in the last frame;
	float frame_time = 0.0;	// Time elapsed since last frame, in seconds
   while (!must_exit)
   {
      // Process all events
      while (csEventPoll())
      {
         // Send current event to the script
         csMain(csEventId(), csEventFrom(), csEventTo(), csEventA(), csEventB(), csEventC(), csEventData());

         // If processed event was EV_FINISH, do not process any more events, we are done
         if (csEventId() == CSEV_FINISH)
         {
            must_exit = true;
            break;  // Breaks event-processing loop
         }
      }

      // Events for this frame processed, so send an EV_FRAME event
      frame_time = float(Device->getTimer()->getTime() - millisecs) / 1000.0f;
      millisecs = Device->getTimer()->getTime();
      csEventPost(CSEV_FRAME, 0, 0, frame_time, 0.0, 0.0, "");

      Device->run();
   }

   // Finish engine
   csCoreFinish();

   // Finish dll
   finishDll();

   return 0;
}