#include "engine.h"

//-----------------------------------------------
//  Joystick variables
//-----------------------------------------------

#if defined(_WIN32) && !defined(__GNUC__)
jsJoystick* joysticks[2];
#endif

//-----------------------------------------------
//  Joystick functions
//-----------------------------------------------

int csJoyInit(int id)
{
#if defined(_WIN32) && !defined(__GNUC__)
	if ((id < 0) || (id > 1)) return 0;
	if (joysticks[id])        return -1;
	joysticks[id] = new jsJoystick(id);
	if (joysticks[id]->notWorking())
	{
		delete joysticks[id];
		joysticks[id] = NULL;
		return 0;
	}
	return 1;
#else
	return 0;
#endif
}

//-----------------------------------------------

void csJoyFinish(int id)
{
#if defined(_WIN32) && !defined(__GNUC__)
	if ((id < 0) || (id > 1)) return;
	if (!joysticks[id])       return;
	delete joysticks[id];
	joysticks[id] = NULL;
#endif
}

//-----------------------------------------------

csString csJoyName(int id)
{
#if defined(_WIN32) && !defined(__GNUC__)
	if ((id < 0) || (id > 1)) return "";
	if (!joysticks[id])       return "";
	return joysticks[id]->getName();
#else
	return "";
#endif
}

//-----------------------------------------------

csInt csJoyButton(int id, int button)
{
#if defined(_WIN32) && !defined(__GNUC__)
	int buttons;
	float axes[_JS_MAX_AXES];
	if ((id < 0) || (id > 1))     return 0;
	if (button > _JS_MAX_BUTTONS) return 0;
	if (!joysticks[id])           return 0;
	joysticks[id]->read(&buttons, axes);
	if (buttons & (1 << (button-1))) return 1;
#endif
	return 0;
}

//-----------------------------------------------

csFloat csJoyAxis(int id, int axis)
{
#if defined(_WIN32) && !defined(__GNUC__)
	int buttons;
	float axes[_JS_MAX_AXES];
	if ((id < 0) || (id > 1))     return 0;
	if (axis > _JS_MAX_AXES)      return 0;
	if (!joysticks[id])           return 0;
	joysticks[id]->read(&buttons, axes);
	return axes[axis-1];
#else
	return 0.0f;
#endif
}

//-----------------------------------------------

csInt csJoyNumAxes(int id)
{
#if defined(_WIN32) && !defined(__GNUC__)
	if ((id < 0) || (id > 1)) return 0;
	if (!joysticks[id])       return 0;
	return joysticks[id]->getNumAxes();
#else
	return 0;
#endif
}
