// Copyright (C) 2002-2005 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_EFFECT_CALLBACK_H_INCLUDED__
#define __I_EFFECT_CALLBACK_H_INCLUDED__

#include "IReferenceCounted.h"

namespace irr
{
namespace video  
{
	class IMaterialRendererServices;

//! Interface making it possible to set constants for gpu programs every frame. 
/* Implement this interface in an own class and pass a pointer to it to one of the methods in
 IGPUProgrammingServices when creating a shader. The OnSetConstants method will be called
 every frame now. */
class IEffectCallBack : public IReferenceCounted
{
public:

	//! Destructor.
	virtual ~IEffectCallBack() {}

  virtual void OnSetParameters(IMaterialRendererServices* services, s32 userData) = 0;
};


} // end namespace video
} // end namespace irr

#endif


