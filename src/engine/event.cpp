#include "engine.h"

//-----------------------------------------------
//  Event variables
//-----------------------------------------------

std::vector<csEvent>  event_list;     // List of events to be executed
csEvent               current_event;  // Current event

//-----------------------------------------------
//  Event functions
//-----------------------------------------------

bool csEventReceiver::OnEvent(const SEvent& event)
{
	switch (event.EventType)
	{
	case EET_GUI_EVENT:
		switch (event.GUIEvent.EventType)
		{
		case EGET_ELEMENT_FOCUS_LOST:
			csEventPost(CSEV_GADGET_LOSTFOCUS, (int) event.GUIEvent.Caller, 0, 0.0, 0.0, 0.0, "");
			break;
		case EGET_ELEMENT_HOVERED:
			csEventPost(CSEV_GADGET_ENTER, (int) event.GUIEvent.Caller, 0, 0.0, 0.0, 0.0, "");
			break;
		case EGET_ELEMENT_LEFT:
			csEventPost(CSEV_GADGET_EXIT, (int) event.GUIEvent.Caller, 0, 0.0, 0.0, 0.0, "");
			break;
		case EGET_BUTTON_CLICKED:
			csEventPost(CSEV_GADGET_ACTION, (int) event.GUIEvent.Caller, 0, ((IGUIButton*)event.GUIEvent.Caller)->isPressed(), 0.0, 0.0, "");
			break;
		case EGET_SCROLL_BAR_CHANGED:
			csEventPost(CSEV_GADGET_ACTION, (int) event.GUIEvent.Caller, 0, ((IGUIScrollBar*)event.GUIEvent.Caller)->getPos(), 0.0, 0.0, "");
			break;
		case EGET_CHECKBOX_CHANGED:
			csEventPost(CSEV_GADGET_ACTION, (int) event.GUIEvent.Caller, 0, ((IGUICheckBox*)event.GUIEvent.Caller)->isChecked(), 0.0, 0.0, "");
			break;
		case EGET_LISTBOX_CHANGED:
			csEventPost(CSEV_GADGET_ACTION, (int) event.GUIEvent.Caller, 0, ((IGUIListBox*)event.GUIEvent.Caller)->getSelected(), 0.0, 0.0, "");
			break;
		case EGET_LISTBOX_SELECTED_AGAIN:
			csEventPost(CSEV_GADGET_ACTION, (int) event.GUIEvent.Caller, 0, ((IGUIListBox*)event.GUIEvent.Caller)->getSelected(), 0.0, 0.0, "");
			break;
		case EGET_TAB_CHANGED:
			csEventPost(CSEV_GADGET_ACTION, (int) event.GUIEvent.Caller, 0, ((IGUITabControl*)event.GUIEvent.Caller)->getActiveTab(), 0.0, 0.0, "");
			break;
		case EGET_EDITBOX_ENTER:
			csEventPost(CSEV_GADGET_ACTION, (int) event.GUIEvent.Caller, 0, 0.0, 0.0, 0.0, "");
			break;
		case EGET_MENU_ITEM_SELECTED:
			csEventPost(CSEV_GADGET_ACTION, (int) event.GUIEvent.Caller, 0, ((IGUIContextMenu*)event.GUIEvent.Caller)->getSelectedItem(), 0.0, 0.0, "");
			break;
		case EGET_COMBO_BOX_CHANGED:
			csEventPost(CSEV_GADGET_ACTION, (int) event.GUIEvent.Caller, 0, ((IGUIComboBox*)event.GUIEvent.Caller)->getSelected(), 0.0, 0.0, "");
			break;
		}
		break;
	case EET_MOUSE_INPUT_EVENT:
		switch (event.MouseInput.Event)
		{
		case EMIE_MOUSE_MOVED:
			mousexspeed = Device->getCursorControl()->getPosition().X - mousex;
			mouseyspeed = Device->getCursorControl()->getPosition().Y - mousey;
			mousex = Device->getCursorControl()->getPosition().X;
			mousey = Device->getCursorControl()->getPosition().Y;
			csEventPost(CSEV_MOUSE_MOVE, 0, 0, mousex, mousey, 0.0, "");
			break;
		case EMIE_LMOUSE_PRESSED_DOWN:
			mousehit[0] = true;
			mousedown[0] = true;
			mousebutton = 1;
			csEventPost(CSEV_MOUSE_HIT, 1, 0, 0.0, 0.0, 0.0, "");
			break;
		case EMIE_RMOUSE_PRESSED_DOWN:
			mousehit[1] = true;
			mousedown[1] = true;
			mousebutton = 2;
			csEventPost(CSEV_MOUSE_HIT, 2, 0, 0.0, 0.0, 0.0, "");
			break;
		case EMIE_MMOUSE_PRESSED_DOWN:
			mousehit[2] = true;
			mousedown[2] = true;
			mousebutton = 3;
			csEventPost(CSEV_MOUSE_HIT, 3, 0, 0.0, 0.0, 0.0, "");
			break;
		case EMIE_LMOUSE_LEFT_UP:
			mousedown[0] = false;
			mousereleased = 1;
			csEventPost(CSEV_MOUSE_RELEASE, 1, 0, 0.0, 0.0, 0.0, "");
			break;
		case EMIE_RMOUSE_LEFT_UP:
			mousedown[1] = false;
			mousereleased = 2;
			csEventPost(CSEV_MOUSE_RELEASE, 2, 0, 0.0, 0.0, 0.0, "");
			break;
		case EMIE_MMOUSE_LEFT_UP:
			mousedown[2] = false;
			mousereleased = 3;
			csEventPost(CSEV_MOUSE_RELEASE, 3, 0, 0.0, 0.0, 0.0, "");
			break;
		}
		break;
	case EET_KEY_INPUT_EVENT:
		switch (event.KeyInput.PressedDown)
		{
		case true:
			keyhit[event.KeyInput.Key] = true;
			keydown[event.KeyInput.Key] = true;
			key = event.KeyInput.Key;
			csEventPost(CSEV_KEY_HIT, key, 0, 0.0, 0.0, 0.0, "");
			break;
		case false:
			keydown[event.KeyInput.Key] = false;
			keyreleased = event.KeyInput.Key;
			csEventPost(CSEV_KEY_RELEASE, keyreleased, 0, 0.0, 0.0, 0.0, "");
			break;
		}
		break;
	}
	return false;
}

//-----------------------------------------------

csEvent::csEvent()
{
	this->clear();
}

//-----------------------------------------------

void csEvent::clear()
{
	this->id = 0;
	this->from = 0;
	this->to = 0;
	this->a = 0.0;
	this->b = 0.0;
	this->c = 0.0;
	this->str = "";
}

//-----------------------------------------------

void CleanEvents()
{
	current_event.clear();
	event_list.clear();
}

//-----------------------------------------------

csInt csEventGet()
{
	if (!event_list.empty())
		current_event = event_list[0];
	else
		current_event.clear();
	return current_event.id;
}

//-----------------------------------------------

csInt csEventPoll()
{
	if (!event_list.empty())
	{
		current_event = event_list[0];
		event_list.erase(event_list.begin());
	} else
		current_event.clear();
	return current_event.id;
}

//-----------------------------------------------

csVoid csEventPost(int id, int from, int to, float a, float b, float c, const char* str)
{
	csEvent ev;
	ev.id = id;
	ev.from = from;
	ev.to = to;
	ev.a = a;
	ev.b = b;
	ev.c = c;
	ev.str = str;
	event_list.push_back(ev);
}

//-----------------------------------------------

csInt csEventId()
{
	return current_event.id;
}

//-----------------------------------------------

csInt csEventFrom()
{
	return current_event.from;
}

//-----------------------------------------------

csInt csEventTo()
{
	return current_event.to;
}

//-----------------------------------------------

csFloat csEventA()
{
	return current_event.a;
}

//-----------------------------------------------

csFloat csEventB()
{
	return current_event.b;
}

//-----------------------------------------------

csFloat csEventC()
{
	return current_event.c;
}

//-----------------------------------------------

csString csEventData()
{
	return current_event.str.c_str();
}
