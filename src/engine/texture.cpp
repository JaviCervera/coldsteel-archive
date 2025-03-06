#if defined(_WIN32) && !defined(__GNUC__)
#include "CD3D9Texture.h"
#endif
#include "COpenGLTexture.h"
#include "engine.h"

//-----------------------------------------------
//  Texture functions
//-----------------------------------------------

csInt csTextureCreate(int width, int height)
{
	return (int) Device->getVideoDriver()->addTexture(dimension2d<s32>(width, height), "*", ECF_A8R8G8B8);;
}

//-----------------------------------------------

csInt csTextureTargetCreate(int width, int height)
{
	return (int) Device->getVideoDriver()->createRenderTargetTexture(dimension2d<s32>(width, height));
}

//-----------------------------------------------

csInt csTextureLoad(const char* file, int mipmaps)
{
	int ret;
	if (mipmaps == 0) Device->getVideoDriver()->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, false);
	ret = (int) Device->getVideoDriver()->getTexture(file);
	if (mipmaps == 0) Device->getVideoDriver()->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, true);
	return ret;
}

//-----------------------------------------------

csVoid csTextureFree(ITexture* tex)
{
	Device->getVideoDriver()->removeTexture(tex);
}

//-----------------------------------------------

csString csTextureFile(ITexture* tex)
{
	// JEDIVE:
	//return tex->textureFile.c_str();
	return tex->getName().c_str();
}

//-----------------------------------------------

csInt csTextureWidth(ITexture* tex, int original)
{
	if (!original)
		return tex->getSize().Width;
	else
		return tex->getOriginalSize().Width;
}

//-----------------------------------------------

csInt csTextureHeight(ITexture* tex, int original)
{
	if (!original)
		return tex->getSize().Height;
	else
		return tex->getOriginalSize().Height;
}

//-----------------------------------------------

csInt csTextureLock(ITexture* tex)
{
	return (int)tex->lock();
}

//-----------------------------------------------

csVoid csTextureUnlock(ITexture* tex)
{
	tex->unlock();
}

//-----------------------------------------------

csVoid csTextureColorKey(ITexture* tex, int color)
{
	Device->getVideoDriver()->makeColorKeyTexture(tex, SColor(csGetAlpha(color),csGetRed(color),csGetGreen(color),csGetBlue(color)));
}

//-----------------------------------------------

csVoid csTextureNormalize(ITexture* tex, float amplitude)
{
	Device->getVideoDriver()->makeNormalMapTexture(tex, amplitude);
}

//-----------------------------------------------

csInt csTextureHWPointer(ITexture* tex)
{
#if defined(_WIN32) && !defined(__GNUC__)
	if (tex->getDriverType() == EDT_DIRECT3D9)  return (int) ((CD3D9Texture*)tex)->getDX9Texture();
#endif
	if (tex->getDriverType() == EDT_OPENGL)     return (int) ((COpenGLTexture*)tex)->getOpenGLTextureName();
	return 0;
}
