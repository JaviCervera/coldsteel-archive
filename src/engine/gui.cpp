#include "engine.h"

//-----------------------------------------------
//  Gui functions
//-----------------------------------------------

csInt csGuiButton(int x, int y, int w, int h, IGUIElement* parent)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	return (int) Device->getGUIEnvironment()->addButton(rect<s32>(x,y,x+w,y+h), parent);
}

//-----------------------------------------------

csInt csGuiCheckBox(int x, int y, int w, int h, IGUIElement* parent)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	return (int) Device->getGUIEnvironment()->addCheckBox(false, rect<s32>(x,y,x+w,y+h), parent);
}

//-----------------------------------------------

csInt csGuiComboBox(int x, int y, int w, int h, IGUIElement* parent)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	return (int) Device->getGUIEnvironment()->addComboBox(rect<s32>(x,y,x+w,y+h), parent);
}

//-----------------------------------------------

csInt csGuiContextMenu(int x, int y, int w, int h, IGUIElement* parent)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	return (int) Device->getGUIEnvironment()->addContextMenu(rect<s32>(x,y,x+w,y+h), parent);
}

//-----------------------------------------------

csInt csGuiEditBox(int x, int y, int w, int h, IGUIElement* parent, int maxchars, int border)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	IGUIEditBox* editbox = Device->getGUIEnvironment()->addEditBox(L"", rect<s32>(x,y,x+w,y+h), border, parent);
	editbox->setMax(maxchars);
	return (int) editbox;
}

//-----------------------------------------------

csInt csGuiGroup(int x, int y, int w, int h, IGUIElement* parent)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	return (int) Device->getGUIEnvironment()->addTab(rect<s32>(x,y,x+w,y+h), parent);
}

//-----------------------------------------------

csInt csGuiListBox(int x, int y, int w, int h, IGUIElement* parent, int draw_background)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	return (int) Device->getGUIEnvironment()->addListBox(rect<s32>(x,y,x+w,y+h), parent, -1, draw_background);
}

//-----------------------------------------------

csInt csGuiMenu(IGUIElement* parent)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	return (int) Device->getGUIEnvironment()->addMenu(parent);
}

//-----------------------------------------------

csInt csGuiMessageBox(IGUIElement* parent, const char* caption, const char* text, int flags)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	wchar_t wcaption[1024];
	wchar_t wtext[1024];
	stringToWstring(caption, wcaption, strlen(caption));
	stringToWstring(text, wtext, strlen(text));
	return (int) Device->getGUIEnvironment()->addMessageBox(wcaption, wtext, true, flags, parent);
}

//-----------------------------------------------

csInt csGuiScrollBar(int x, int y, int w, int h, IGUIElement* parent, int horizontal, int max, int step)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	IGUIScrollBar* scrollbar = Device->getGUIEnvironment()->addScrollBar(horizontal, rect<s32>(x,y,x+w,y+h), parent);
	scrollbar->setMax(max);
	scrollbar->setSmallStep(step);
	return (int) scrollbar;

}

//-----------------------------------------------

csInt csGuiTabber(int x, int y, int w, int h, IGUIElement* parent, int flags)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	bool border = false;
	bool fillback = false;
	if ((flags & 16) == 16) border = true;  // GF_BORDER
	if ((flags & 32) == 32) fillback = true; // GF_FILLBACK
	return (int) Device->getGUIEnvironment()->addTabControl(rect<s32>(x,y,x+w,y+h), parent, fillback, border);
}

//-----------------------------------------------

csInt csGuiText(int x, int y, int w, int h, IGUIElement* parent, int flags)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	bool border = false;
	bool wordwrap = false;
	bool fillback = false;
	if ((flags & 16) == 16) border = true;  // GF_BORDER
	if ((flags & 32) == 32) fillback = true; // GF_FILLBACK
	if ((flags & 64) == 64) wordwrap = true; // GF_WORDWRAP
	return (int) Device->getGUIEnvironment()->addStaticText(L"", rect<s32>(x,y,x+w,y+h), border, wordwrap, parent, -1, fillback);
}

//-----------------------------------------------

csInt csGuiTexture(int x, int y, IGUIElement* parent, ITexture* tex, int use_alpha)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	IGUIImage* img = Device->getGUIEnvironment()->addImage(tex, position2d<s32>(x, y), use_alpha, parent);
	img->setScaleImage(true);
	return (int) img;
}

//-----------------------------------------------

csInt csGuiToolbar(IGUIElement* parent)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	return (int) Device->getGUIEnvironment()->addToolBar(parent);
}

//-----------------------------------------------

csInt csGuiWindow(int x, int y, int w, int h, IGUIElement* parent, int modal)
{
	if (parent == 0) parent = Device->getGUIEnvironment()->getRootGUIElement();
	return (int) Device->getGUIEnvironment()->addWindow(rect<s32>(x,y,x+w,y+h), modal, L"", parent);
}

//-----------------------------------------------

csVoid csGuiDraw()
{
	Device->getGUIEnvironment()->drawAll();
}