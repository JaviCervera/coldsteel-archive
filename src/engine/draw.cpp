#include "engine.h"

//-----------------------------------------------
// Drawing functions
//-----------------------------------------------

int vx, vy, vw, vh;
SColor drawingcolor(255,255,255,255);

//-----------------------------------------------

csInt csGetColor(int red, int green, int blue, int alpha)
{
	return (alpha << 24) + (red << 16) + (green << 8) + blue;
}

//-----------------------------------------------

csInt csGetRed(int color)
{
	return (color & 0x00FF0000) >> 16;
}

//-----------------------------------------------

csInt csGetGreen(int color)
{
	return (color & 0x0000FF00) >> 8;
}

//-----------------------------------------------

csInt csGetBlue(int color)
{
	return (color & 0x000000FF);
}

//-----------------------------------------------

csInt csGetAlpha(int color)
{
	return (color & 0xFF000000) >> 24;
}

//-----------------------------------------------

csVoid csSetColor(int color)
{
	drawingcolor.setRed(csGetRed(color));
	drawingcolor.setGreen(csGetGreen(color));
	drawingcolor.setBlue(csGetBlue(color));
	drawingcolor.setAlpha(csGetAlpha(color));
}

//-----------------------------------------------

csVoid csViewport(int x, int y, int w, int h)
{
	vx = x; vy = y; vw = w; vh = h;
	Device->getVideoDriver()->setViewPort(rect<s32>(vx,vy,vw,vh));
}

//-----------------------------------------------

csVoid csDrawLine(int x, int y, int x1, int y1)
{
	Device->getVideoDriver()->draw2DLine(position2d<s32>(x,y), position2d<s32>(x1,y1), drawingcolor);
}

//-----------------------------------------------

csVoid csDrawRect(int x, int y, int w, int h)
{
	Device->getVideoDriver()->draw2DRectangle(drawingcolor, rect<s32>(x,y,x+w,y+h));
}

//-----------------------------------------------

csVoid csDrawTexture(ITexture* tex, int x, int y)
{
	Device->getVideoDriver()->draw2DImage(tex, position2d<s32>(x,y));
}

//-----------------------------------------------

csVoid csDrawTextureAdvanced(ITexture* tex, int x, int y, int width, int height, int rect_x, int rect_y, int rect_width, int rect_height, int color, int usealpha)
{
	//Device->getVideoDriver()->draw2DImage(tex, position2d<s32>(), 
}

//-----------------------------------------------

csVoid csDrawText(IGUIFont* font, const char* text, int x, int y)
{
	if (font) {
		dimension2d<s32> size = font->getDimension(asWstring(text));
		font->draw(asWstring(text), rect<s32>(x,y,size.Width,size.Height), drawingcolor);
	} else {
		dimension2d<s32> size = Device->getGUIEnvironment()->getBuiltInFont()->getDimension(asWstring(text));
		Device->getGUIEnvironment()->getBuiltInFont()->draw(asWstring(text), rect<s32>(x,y,size.Width,size.Height), drawingcolor);
	}
}

//-----------------------------------------------

csInt csTextWidth(IGUIFont* font, const char* text)
{
	if (font)
		return font->getDimension(asWstring(text)).Width;
	else
		return Device->getGUIEnvironment()->getBuiltInFont()->getDimension(asWstring(text)).Width;
}

//-----------------------------------------------

csInt csTextHeight(IGUIFont* font, const char* text)
{
	if (font)
		return font->getDimension(asWstring(text)).Height;
	else
		return Device->getGUIEnvironment()->getBuiltInFont()->getDimension(asWstring(text)).Height;
}
