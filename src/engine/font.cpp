#include "engine.h"

//-----------------------------------------------
//  Font functions
//-----------------------------------------------

csInt csFontLoad(const char* file)
{
	return (int)Device->getGUIEnvironment()->getFont(file);
}

//-----------------------------------------------

csVoid csFontFree(IGUIFont* font)
{
	font->drop();
}
