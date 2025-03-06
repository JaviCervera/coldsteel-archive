#include "engine.h"

//-----------------------------------------------
//  Gadget functions
//-----------------------------------------------

csVoid csGadgetFree(IGUIElement* gadget)
{
	gadget->remove();
}

//-----------------------------------------------

csInt csGadgetType(IGUIElement* gadget)
{
	switch (gadget->getType())
	{
	case EGUIET_BUTTON:
		return GT_BUTTON;
	case EGUIET_CHECK_BOX:
		return GT_CHECKBOX;
	case EGUIET_COMBO_BOX:
		return GT_COMBOBOX;
	case EGUIET_EDIT_BOX:
		return GT_EDITBOX;
	case EGUIET_TAB:
		return GT_GROUP;
	case EGUIET_LIST_BOX:
		return GT_LISTBOX;
	case EGUIET_MENU:
	case EGUIET_CONTEXT_MENU:
		return GT_MENU;
	case EGUIET_SCROLL_BAR:
		return GT_SCROLLBAR;
	case EGUIET_TAB_CONTROL:
		return GT_TABBER;
	case EGUIET_STATIC_TEXT:
		return GT_TEXT;
	case EGUIET_IMAGE:
		return GT_TEXTURE;
	case EGUIET_TOOL_BAR:
		return GT_TOOLBAR;
	case EGUIET_WINDOW:
		return GT_WINDOW;
	}
	return 0;
}

//-----------------------------------------------

csVoid csGadgetEnable(IGUIElement* gadget, int state)
{
	gadget->setEnabled((bool) state);
}

//-----------------------------------------------

csString csGadgetGetText(IGUIElement* gadget)
{
	return asString(gadget->getText());
}


//-----------------------------------------------

csVoid csGadgetSetText(IGUIElement* gadget, const char* text)
{
	gadget->setText(asWstring(text));
}

//-----------------------------------------------

csVoid csGadgetShape(IGUIElement* gadget, int x, int y, int w, int h)
{
	gadget->setRelativePosition(rect<s32>(x,y,x+w,y+h));
}

//-----------------------------------------------

csVoid csGadgetVisible(IGUIElement* gadget, int state)
{
	gadget->setVisible((bool) state);
}

//-----------------------------------------------

csInt csGadgetChildren(IGUIElement* gadget)
{
	return gadget->getChildren().getSize();
}

//-----------------------------------------------

csInt csGadgetChild(IGUIElement* gadget, int index)
{
	if (index > (int) gadget->getChildren().getSize()) return 0;
	return (int) *(gadget->getChildren().begin() + (index-1));
}

//-----------------------------------------------

csInt csGadgetParent(IGUIElement* gadget)
{
	return (int) gadget->getParent();
}

//-----------------------------------------------

csVoid csGadgetSetImage(IGUIElement* gadget, ITexture* img, int x, int y, int width, int height, int alpha)
{
	switch (csGadgetType(gadget))
	{
	case GT_BUTTON:
		((IGUIButton*)gadget)->setImage(img, rect<s32>(x, y, x+width, y+height));
		((IGUIButton*)gadget)->setUseAlphaChannel((bool) alpha);
		break;
	case GT_TEXTURE:
		((IGUIImage*)gadget)->setImage(img);
		((IGUIImage*)gadget)->setUseAlphaChannel((bool) alpha);
		break;
	}
}

//-----------------------------------------------

csVoid csGadgetSetFont(IGUIElement* gadget, IGUIFont* font)
{
	switch (csGadgetType(gadget))
	{
	case GT_BUTTON:
		((IGUIButton*)gadget)->setOverrideFont(font);
		break;
	case GT_EDITBOX:
		((IGUIEditBox*)gadget)->setOverrideFont(font);
		break;
	case GT_TEXT:
		((IGUIStaticText*)gadget)->setOverrideFont(font);
		break;
	}
}

//-----------------------------------------------

csVoid csGadgetSetColor(IGUIElement* gadget, int color, int override_)
{
	switch (csGadgetType(gadget))
	{
	case GT_EDITBOX:
		((IGUIEditBox*)gadget)->setOverrideColor(SColor(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color)));
		((IGUIEditBox*)gadget)->enableOverrideColor((bool) override_);
		break;
	case GT_TEXT:
		((IGUIStaticText*)gadget)->setOverrideColor(SColor(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color)));
		((IGUIStaticText*)gadget)->enableOverrideColor((bool) override_);
	}
}

//-----------------------------------------------

csVoid csGadgetSetState(IGUIElement* gadget, int state)
{
	switch (csGadgetType(gadget))
	{
	case GT_BUTTON:
		((IGUIButton*)gadget)->setPressed((bool) state);
		break;
	case GT_CHECKBOX:
		((IGUICheckBox*)gadget)->setChecked((bool) state);
		break;
	case GT_SCROLLBAR:
		((IGUIScrollBar*)gadget)->setPos(state);
	}
}

//-----------------------------------------------

csInt csGadgetGetState(IGUIElement* gadget)
{
	switch (csGadgetType(gadget))
	{
	case GT_BUTTON:
		return (int) ((IGUIButton*)gadget)->isPressed();
	case GT_CHECKBOX:
		return (int) ((IGUICheckBox*)gadget)->isChecked();
	case GT_SCROLLBAR:
		return (int) ((IGUIScrollBar*)gadget)->getPos();
	}
	return 0;
}

//-----------------------------------------------

csInt csGadgetAddItem(IGUIElement* gadget, const char* text, int id)
{
	switch (csGadgetType(gadget))
	{
	case GT_COMBOBOX:
		return ((IGUIComboBox*)gadget)->addItem(asWstring(text))+1;
	case GT_MENU:
		return ((IGUIContextMenu*)gadget)->addItem(asWstring(text), id)+1;
	case GT_LISTBOX:
		return ((IGUIListBox*)gadget)->addItem(asWstring(text))+1;
	case GT_TABBER:
		return ((IGUITabControl*)gadget)->addTab(asWstring(text))->getID()+1;
	case GT_TOOLBAR:
		return (int) ((IGUIToolBar*)gadget)->addButton(-1, asWstring(text), 0, (ITexture*) id);
	}
	return 0;
}

//-----------------------------------------------

csInt csGadgetGetItemId(IGUIElement* gadget, int index)
{
	switch (csGadgetType(gadget))
	{
	case GT_MENU:
		return ((IGUIContextMenu*)gadget)->getItemCommandId(index-1);
	}
	return -1;
}

//-----------------------------------------------

csString csGadgetGetItemText(IGUIElement* gadget, int index)
{
	switch (csGadgetType(gadget))
	{
	case GT_COMBOBOX:
		return asString(((IGUIComboBox*)gadget)->getItem(index-1));
	case GT_MENU:
		return asString(((IGUIContextMenu*)gadget)->getItemText(index-1));
	}
	return "";
}

//-----------------------------------------------

csInt csGadgetSelectedItem(IGUIElement* gadget)
{
	switch (csGadgetType(gadget))
	{
	case GT_COMBOBOX:
		return ((IGUIComboBox*)gadget)->getSelected()+1;
	case GT_MENU:
		return ((IGUIContextMenu*)gadget)->getSelectedItem()+1;
	case GT_LISTBOX:
		return ((IGUIListBox*)gadget)->getSelected()+1;
	case GT_TABBER:
		return ((IGUIListBox*)gadget)->getSelected()+1;
	}
	return 0;
}

//-----------------------------------------------

csVoid csGadgetSelectItem(IGUIElement* gadget, int index)
{
	switch (csGadgetType(gadget))
	{
	case GT_COMBOBOX:
		((IGUIComboBox*)gadget)->setSelected(index-1);
		break;
	case GT_LISTBOX:
		((IGUIListBox*)gadget)->setSelected(index-1);
		break;
	case GT_TABBER:
		((IGUITabControl*)gadget)->setActiveTab(index-1);
		break;
	}
}

//-----------------------------------------------

csInt csGadgetCountItems(IGUIElement* gadget)
{
	switch (csGadgetType(gadget))
	{
	case GT_COMBOBOX:
		return ((IGUIComboBox*)gadget)->getItemCount();
	case GT_MENU:
		return ((IGUIContextMenu*)gadget)->getItemCount();
	case GT_LISTBOX:
		return ((IGUIListBox*)gadget)->getItemCount();
	case GT_TABBER:
		return ((IGUITabControl*)gadget)->getTabCount();
	}
	return 0;
}

//-----------------------------------------------

csVoid csGadgetSetItemText(IGUIElement* gadget, int index, const char* text)
{
	switch (csGadgetType(gadget))
	{
	case GT_MENU:
		((IGUIContextMenu*)gadget)->setItemText(index-1, asWstring(text));
		break;
	}
}

//-----------------------------------------------

csVoid csGadgetEnableItem(IGUIElement* gadget, int index, int enable)
{
	switch (csGadgetType(gadget))
	{
	case GT_MENU:
		((IGUIContextMenu*)gadget)->setItemEnabled(index-1, (bool) enable);
		break;
	}
}

//-----------------------------------------------

csVoid csGadgetRemoveItem(IGUIElement* gadget, int index)
{
	switch (csGadgetType(gadget))
	{
	case GT_MENU:
		((IGUIContextMenu*)gadget)->removeItem(index-1);
		break;
	case GT_LISTBOX:
		((IGUIListBox*)gadget)->removeItem(index-1);
		break;
	}
}

//-----------------------------------------------

csVoid csGadgetRemoveItems(IGUIElement* gadget)
{
	switch (csGadgetType(gadget))
	{
	case GT_COMBOBOX:
		((IGUIComboBox*)gadget)->clear();
		break;
	case GT_MENU:
		((IGUIContextMenu*)gadget)->removeAllItems();
		break;
	case GT_LISTBOX:
		((IGUIListBox*)gadget)->clear();
		break;
	}
}