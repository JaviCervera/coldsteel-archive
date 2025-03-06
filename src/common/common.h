#ifndef _COMMON_H
#define _COMMON_H_

#define VERSION_STRING  "0.9.7"

// Return types
#ifdef COLDSTEEL_RUNTIME
#define csVoid     extern "C"	void _stdcall
#define csInt      extern "C"	int _stdcall
#define csFloat    extern "C"	float _stdcall
#define csString   extern "C"	const char * _stdcall
#else
#if defined(_WIN32) && !defined(__GNUC__) // On Visual-C++, functions are exported as a dll
#define csVoid     extern "C" _declspec(dllexport) void            _stdcall
#define csInt      extern "C" _declspec(dllexport) int             _stdcall
#define csFloat    extern "C" _declspec(dllexport) float           _stdcall
#define csString   extern "C" _declspec(dllexport) const char *    _stdcall
#else          // On other platforms, compile as static
#define csVoid     extern "C" void
#define csInt      extern "C" int
#define csFloat    extern "C" float
#define csString   extern "C" const char *
#endif
#endif

#endif  // _COMMON_H_
