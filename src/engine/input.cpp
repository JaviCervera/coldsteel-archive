#include "engine.h"

//-----------------------------------------------
//  Input variables
//-----------------------------------------------

int mousex = 0, mousey = 0, mousexspeed = 0, mouseyspeed = 0;
bool mousehit[3], mousedown[3], mousebutton, mousereleased;
bool keyhit[KEY_KEY_CODES_COUNT], keydown[KEY_KEY_CODES_COUNT];
int key, keyreleased;

//-----------------------------------------------
//  Input functions
//-----------------------------------------------

csVoid csMousePosition(int x, int y)
{
	Device->getCursorControl()->setPosition(position2d<s32>(x,y));
}

//-----------------------------------------------

csVoid csMouseHide(int hide)
{
	Device->getCursorControl()->setVisible(!hide);
}

//-----------------------------------------------

csInt csMouseX()
{
	return Device->getCursorControl()->getPosition().X;
}

//-----------------------------------------------

csInt csMouseY()
{
	return Device->getCursorControl()->getPosition().Y;
}

/*
//-----------------------------------------------

csInt csMouseMoveX()
{
	return mousexspeed;
}

//-----------------------------------------------

csInt csMouseMoveY()
{
	return mouseyspeed;
}
*/

//-----------------------------------------------

csInt csMouseHit(int button)
{
	int hit = mousehit[button - 1];
	mousehit[button - 1] = false;
	return hit;
}

//-----------------------------------------------

csInt csMouseDown(int button)
{
	return mousedown[button - 1];
}

//-----------------------------------------------

csInt csMouseGet()
{
	return mousebutton;
}

//-----------------------------------------------

csInt csMouseReleased()
{
	return mousereleased;
}

//-----------------------------------------------

csInt csKeyHit(int key)
{
	int k = keyhit[key];
	keyhit[key] = false;
	return k;
}

//-----------------------------------------------

csInt csKeyDown(int key)
{
	return keydown[key];
}

//-----------------------------------------------

csInt csKeyGet()
{
	return key;
}

//-----------------------------------------------

csInt csKeyReleased()
{
	return keyreleased;
}
