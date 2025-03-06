#include "engine.h"
#include <time.h>

#if defined(COLDSTEEL_LITE) || defined(COLDSTEEL_DEMO)
extern ITexture* watermark;
#endif

ISceneNode* skybox = NULL;
ISceneNode* skydome = NULL;

//-----------------------------------------------
//  Scene functions
//-----------------------------------------------

csVoid csSceneBegin()
{
#ifndef COLDSTEEL_RUNTIME
	if (!Device->run()) {
		csDisplayClose();
		return;
	}
#endif
	Device->getVideoDriver()->setViewPort(rect<s32>(0, 0, Device->getVideoDriver()->getScreenSize().Width, Device->getVideoDriver()->getScreenSize().Height));
	Device->getVideoDriver()->beginScene(false, false, SColor());
	Device->getVideoDriver()->setViewPort(rect<s32>(vx,vy,vw,vh));
}

//-----------------------------------------------

csVoid csSceneEnd()
{
	#if defined(COLDSTEEL_LITE) || defined(COLDSTEEL_DEMO)
	Device->getVideoDriver()->draw2DImage(watermark, position2d<s32>(Device->getVideoDriver()->getScreenSize().Width - watermark->getOriginalSize().Width, Device->getVideoDriver()->getScreenSize().Height - watermark->getOriginalSize().Height), rect<s32>(0, 0, watermark->getOriginalSize().Width, watermark->getOriginalSize().Height), NULL, SColor(64, 255, 255, 255), true);
	#endif

	Device->getVideoDriver()->endScene();
}

//-----------------------------------------------

csVoid csSceneUpdate(float timestep)
{
	UpdatePhysics(timestep);
}

//-----------------------------------------------

csVoid csSceneRender(ICameraSceneNode* cam)
{
	// Only runs for 5 minutes if in demo version
#ifdef COLDSTEEL_DEMO
	if (((float) clock() / CLOCKS_PER_SEC) >= demo_time + 300) return;
#endif

	csCameraData* camdata = (csCameraData*) ((csNodeData*)cam->UserData)->data;

	bool backbuffer = false;
	bool zbuffer = false;
	if ((camdata->clearflags & 1) == 1) backbuffer = true;
	if ((camdata->clearflags & 2) == 2) zbuffer = true;
	Device->getVideoDriver()->setRenderTarget(camdata->rendertarget, backbuffer, zbuffer, camdata->clearcolor);

	// Check if it has to do Render to Texture
	if (camdata->rendertarget != 0)
		Device->getVideoDriver()->setViewPort(rect<s32>(0, 0, csTextureWidth(camdata->rendertarget, 1), csTextureHeight(camdata->rendertarget, 1)));
	else
		Device->getVideoDriver()->setViewPort(rect<s32>(camdata->vx1 * Device->getVideoDriver()->getScreenSize().Width, camdata->vy1 * Device->getVideoDriver()->getScreenSize().Height, camdata->vx2 * Device->getVideoDriver()->getScreenSize().Width, camdata->vy2 * Device->getVideoDriver()->getScreenSize().Height));

	Device->getSceneManager()->setActiveCamera(cam);
	Device->getSceneManager()->drawAll();
	Device->getVideoDriver()->setViewPort(rect<s32>(vx,vy,vw,vh));
}

//-----------------------------------------------

csVoid csSceneAmbient(int color)
{
	Device->getSceneManager()->setAmbientLight(SColorf(csGetRed(color)/255.0f,csGetGreen(color)/255.0f,csGetBlue(color)/255.0f));
}

//-----------------------------------------------

csVoid csSceneShadow(int color)
{
	Device->getSceneManager()->setShadowColor(SColor(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color)));
}

//-----------------------------------------------

csVoid csSceneFog(int color, float near_, float far_)
{
	Device->getVideoDriver()->setFog(SColor(csGetAlpha(color), csGetRed(color), csGetGreen(color), csGetBlue(color)), true, near_, far_);
}

//-----------------------------------------------

csVoid csSceneSkybox(ITexture* top, ITexture* bottom, ITexture* left, ITexture* right, ITexture* front, ITexture* back)
{
	if (skybox)
		skybox->remove();
	if (top)
	{
		skybox = Device->getSceneManager()->addSkyBoxSceneNode(top, bottom, left, right, front, back);
		skybox->setMaterialFlag(EMF_TRILINEAR_FILTER, true);
		skybox->setMaterialFlag(EMF_TEXTURE_WRAP, false);
	}
}

//-----------------------------------------------

csVoid csSceneSkydome(ITexture* tex, float hres, float yres, float tex_percent, float sphere_percent)
{
	if (skydome)
		skydome->remove();
	if (tex)
	{
		skydome = Device->getSceneManager()->addSkyDomeSceneNode(tex, hres, yres, tex_percent, sphere_percent);
		skydome->setMaterialFlag(EMF_TRILINEAR_FILTER, true);
	}
}

//-----------------------------------------------

csVoid csSceneTransformation(int state, csMatrix* matrix)
{
	matrix4 mat = Device->getVideoDriver()->getTransform((E_TRANSFORMATION_STATE) state);
	for (int i = 0; i < 16; i++)
		matrix->m[i] = mat.pointer()[i];
}

//-----------------------------------------------

csVoid csSceneSetGravity(float x, float y, float z)
{
	PhysicsGravity(x, y, z);
}