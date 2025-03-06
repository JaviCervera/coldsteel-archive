#include "angelscript.h"
#include "scriptstring.h"
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

void csCoreInit_ASWRAP(asIScriptGeneric* script)
{
	csCoreInit();
}

void csCoreFinish_ASWRAP(asIScriptGeneric* script)
{
	csCoreFinish();
}

void csCoreMessage_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int arg1 = (int) script->GetArgDWord(1);
	csCoreMessage(param0, param1);
}

void csBillboardNode_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csBillboardNode(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csBillboardResize_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	csBillboardResize(param0, param1, param2);
}

void csBillboardWidth_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csBillboardWidth(param0);
	script->SetReturnFloat(ret);
}

void csBillboardHeight_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csBillboardHeight(param0);
	script->SetReturnFloat(ret);
}

void csCameraNode_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csCameraNode(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csCameraViewport_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	float arg4 = (float) script->GetArgFloat(4);
	csCameraViewport(param0, param1, param2, param3, param4);
}

void csCameraRange_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	csCameraRange(param0, param1, param2);
}

void csCameraFov_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	csCameraFov(param0, param1);
}

void csCameraAspectRatio_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	csCameraAspectRatio(param0, param1);
}

void csCameraProjection_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	float arg4 = (float) script->GetArgFloat(4);
	int arg5 = (int) script->GetArgDWord(5);
	csCameraProjection(param0, param1, param2, param3, param4, param5);
}

void csCameraLine_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	int arg4 = (int) script->GetArgDWord(4);
	csCameraLine(param0, param1, param2, param3, param4);
}

void csCameraPickNode_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	int ret = csCameraPickNode(param0, param1, param2, param3);
	script->SetReturnDWord((asDWORD) ret);
}

void csCameraToScreen_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	int arg4 = (int) script->GetArgDWord(4);
	csCameraToScreen(param0, param1, param2, param3, param4);
}

void csCameraRenderTarget_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csCameraRenderTarget(param0, param1);
}

void csCollisionSlide_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	float arg4 = (float) script->GetArgFloat(4);
	float arg5 = (float) script->GetArgFloat(5);
	float arg6 = (float) script->GetArgFloat(6);
	float arg7 = (float) script->GetArgFloat(7);
	float arg8 = (float) script->GetArgFloat(8);
	float arg9 = (float) script->GetArgFloat(9);
	int arg10 = (int) script->GetArgDWord(10);
	int arg11 = (int) script->GetArgDWord(11);
	int arg12 = (int) script->GetArgDWord(12);
	int arg13 = (int) script->GetArgDWord(13);
	csCollisionSlide(param0, param1, param2, param3, param4, param5, param6, param7, param8, param9, param10, param11, param12, param13);
}

void csCollisionLinePick_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	float arg4 = (float) script->GetArgFloat(4);
	float arg5 = (float) script->GetArgFloat(5);
	float arg6 = (float) script->GetArgFloat(6);
	int arg7 = (int) script->GetArgDWord(7);
	int arg8 = (int) script->GetArgDWord(8);
	int arg9 = (int) script->GetArgDWord(9);
	int arg10 = (int) script->GetArgDWord(10);
	int ret = csCollisionLinePick(param0, param1, param2, param3, param4, param5, param6, param7, param8, param9, param10);
	script->SetReturnDWord((asDWORD) ret);
}

void csCollisionLineNode_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	float arg4 = (float) script->GetArgFloat(4);
	float arg5 = (float) script->GetArgFloat(5);
	int ret = csCollisionLineNode(param0, param1, param2, param3, param4, param5);
	script->SetReturnDWord((asDWORD) ret);
}

void csPackageAdd_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	csPackageAdd(param0);
}

void csDirList_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csDirList(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csDirClose_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csDirClose(param0);
}

void csDirFileCount_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csDirFileCount(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csDirFileName_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csDirFileName(param0, param1);
	script->SetReturnObject((void* )ret);
}

void csDirFileIsDir_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csDirFileIsDir(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csDisplayOpen_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	int arg4 = (int) script->GetArgDWord(4);
	csDisplayOpen(param0, param1, param2, param3, param4);
}

void csDisplayClose_ASWRAP(asIScriptGeneric* script)
{
	csDisplayClose();
}

void csDisplayCaption_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	csDisplayCaption(param0);
}

void csDisplayClosed_ASWRAP(asIScriptGeneric* script)
{
	int ret = csDisplayClosed();
	script->SetReturnDWord((asDWORD) ret);
}

void csDisplayWidth_ASWRAP(asIScriptGeneric* script)
{
	int ret = csDisplayWidth();
	script->SetReturnDWord((asDWORD) ret);
}

void csDisplayHeight_ASWRAP(asIScriptGeneric* script)
{
	int ret = csDisplayHeight();
	script->SetReturnDWord((asDWORD) ret);
}

void csDisplayFps_ASWRAP(asIScriptGeneric* script)
{
	int ret = csDisplayFps();
	script->SetReturnDWord((asDWORD) ret);
}

void csDisplayFeature_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csDisplayFeature(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csDisplayResize_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csDisplayResize(param0, param1);
}

void csDisplayActive_ASWRAP(asIScriptGeneric* script)
{
	int ret = csDisplayActive();
	script->SetReturnDWord((asDWORD) ret);
}

void csGetColor_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	int ret = csGetColor(param0, param1, param2, param3);
	script->SetReturnDWord((asDWORD) ret);
}

void csGetRed_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csGetRed(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csGetGreen_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csGetGreen(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csGetBlue_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csGetBlue(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csGetAlpha_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csGetAlpha(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csSetColor_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csSetColor(param0);
}

void csViewport_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	csViewport(param0, param1, param2, param3);
}

void csDrawLine_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	csDrawLine(param0, param1, param2, param3);
}

void csDrawRect_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	csDrawRect(param0, param1, param2, param3);
}

void csDrawTexture_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csDrawTexture(param0, param1, param2);
}

void csDrawText_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	csDrawText(param0, param1, param2, param3);
}

void csTextWidth_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int ret = csTextWidth(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csTextHeight_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int ret = csTextHeight(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csEffectRegister_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csEffectRegister(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csEffectRegisterFile_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csEffectRegisterFile(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csEffectSetTechnique_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	csEffectSetTechnique(param0, param1);
}

void csEffectSetTexture_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	csEffectSetTexture(param0, param1, param2);
}

void csEffectSetBool_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	csEffectSetBool(param0, param1, param2);
}

void csEffectSetInt_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	csEffectSetInt(param0, param1, param2);
}

void csEffectSetFloat_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	float arg2 = (float) script->GetArgFloat(2);
	csEffectSetFloat(param0, param1, param2);
}

void csEffectSetVector_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	csEffectSetVector(param0, param1, param2);
}

void csEffectSetMatrix_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	csEffectSetMatrix(param0, param1, param2);
}

void csEmitterNode_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csEmitterNode(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csEmitterAddFadeOutAffector_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csEmitterAddFadeOutAffector(param0, param1, param2);
}

void csEmitterAddGravityAffector_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	int arg4 = (int) script->GetArgDWord(4);
	csEmitterAddGravityAffector(param0, param1, param2, param3, param4);
}

void csEmitterRemoveAffectors_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csEmitterRemoveAffectors(param0);
}

void csEventGet_ASWRAP(asIScriptGeneric* script)
{
	int ret = csEventGet();
	script->SetReturnDWord((asDWORD) ret);
}

void csEventPoll_ASWRAP(asIScriptGeneric* script)
{
	int ret = csEventPoll();
	script->SetReturnDWord((asDWORD) ret);
}

void csEventPost_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	float arg3 = (float) script->GetArgFloat(3);
	float arg4 = (float) script->GetArgFloat(4);
	float arg5 = (float) script->GetArgFloat(5);
	std::string* arg6 = (std::string*) script->GetArgAddress(6);
	csEventPost(param0, param1, param2, param3, param4, param5, param6);
}

void csEventId_ASWRAP(asIScriptGeneric* script)
{
	int ret = csEventId();
	script->SetReturnDWord((asDWORD) ret);
}

void csEventFrom_ASWRAP(asIScriptGeneric* script)
{
	int ret = csEventFrom();
	script->SetReturnDWord((asDWORD) ret);
}

void csEventTo_ASWRAP(asIScriptGeneric* script)
{
	int ret = csEventTo();
	script->SetReturnDWord((asDWORD) ret);
}

void csEventA_ASWRAP(asIScriptGeneric* script)
{
	float ret = csEventA();
	script->SetReturnFloat(ret);
}

void csEventB_ASWRAP(asIScriptGeneric* script)
{
	float ret = csEventB();
	script->SetReturnFloat(ret);
}

void csEventC_ASWRAP(asIScriptGeneric* script)
{
	float ret = csEventC();
	script->SetReturnFloat(ret);
}

void csEventData_ASWRAP(asIScriptGeneric* script)
{
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csEventData();
	script->SetReturnObject((void* )ret);
}

void csFileRead_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csFileRead(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csFileWrite_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csFileWrite(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csFileClose_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csFileClose(param0);
}

void csFileSize_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csFileSize(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csFilePos_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csFilePos(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csFileSeek_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csFileSeek(param0, param1, param2);
}

void csFileReadByte_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csFileReadByte(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csFileReadShort_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csFileReadShort(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csFileReadInt_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csFileReadInt(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csFileReadFloat_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csFileReadFloat(param0);
	script->SetReturnFloat(ret);
}

void csFileReadString_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csFileReadString(param0);
	script->SetReturnObject((void* )ret);
}

void csFileReadBytes_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csFileReadBytes(param0, param1, param2);
}

void csFileWriteByte_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csFileWriteByte(param0, param1);
}

void csFileWriteShort_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csFileWriteShort(param0, param1);
}

void csFileWriteInt_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csFileWriteInt(param0, param1);
}

void csFileWriteFloat_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	csFileWriteFloat(param0, param1);
}

void csFileWriteString_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	csFileWriteString(param0, param1);
}

void csFileWriteBytes_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csFileWriteBytes(param0, param1, param2);
}

void csFileGetExt_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csFileGetExt(param0);
	script->SetReturnObject((void* )ret);
}

void csFileGetDir_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csFileGetDir(param0);
	script->SetReturnObject((void* )ret);
}

void csFileStripExt_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csFileStripExt(param0);
	script->SetReturnObject((void* )ret);
}

void csFileStripDir_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csFileStripDir(param0);
	script->SetReturnObject((void* )ret);
}

void csFontLoad_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csFontLoad(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csFontFree_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csFontFree(param0);
}

void csMousePosition_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMousePosition(param0, param1);
}

void csMouseHide_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csMouseHide(param0);
}

void csMouseX_ASWRAP(asIScriptGeneric* script)
{
	int ret = csMouseX();
	script->SetReturnDWord((asDWORD) ret);
}

void csMouseY_ASWRAP(asIScriptGeneric* script)
{
	int ret = csMouseY();
	script->SetReturnDWord((asDWORD) ret);
}

void csMouseHit_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csMouseHit(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMouseDown_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csMouseDown(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMouseGet_ASWRAP(asIScriptGeneric* script)
{
	int ret = csMouseGet();
	script->SetReturnDWord((asDWORD) ret);
}

void csMouseReleased_ASWRAP(asIScriptGeneric* script)
{
	int ret = csMouseReleased();
	script->SetReturnDWord((asDWORD) ret);
}

void csKeyHit_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csKeyHit(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csKeyDown_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csKeyDown(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csKeyGet_ASWRAP(asIScriptGeneric* script)
{
	int ret = csKeyGet();
	script->SetReturnDWord((asDWORD) ret);
}

void csKeyReleased_ASWRAP(asIScriptGeneric* script)
{
	int ret = csKeyReleased();
	script->SetReturnDWord((asDWORD) ret);
}

void csJoyName_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csJoyName(param0);
	script->SetReturnObject((void* )ret);
}

void csJoyButton_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csJoyButton(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csJoyAxis_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float ret = csJoyAxis(param0, param1);
	script->SetReturnFloat(ret);
}

void csJoyNumAxes_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csJoyNumAxes(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csLightNode_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csLightNode(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csLightRadius_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	csLightRadius(param0, param1);
}

void csLightAmbient_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csLightAmbient(param0, param1);
}

void csLightDiffuse_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csLightDiffuse(param0, param1);
}

void csLightSpecular_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csLightSpecular(param0, param1);
}

void csMaterialCreate_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csMaterialCreate(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMaterialLoad_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csMaterialLoad(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMaterialSave_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	std::string* arg2 = (std::string*) script->GetArgAddress(2);
	csMaterialSave(param0, param1, param2);
}

void csMaterialFree_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csMaterialFree(param0);
}

void csMaterialFind_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csMaterialFind(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMaterialSetType_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMaterialSetType(param0, param1);
}

void csMaterialSetFlags_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMaterialSetFlags(param0, param1);
}

void csMaterialSetTexture_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csMaterialSetTexture(param0, param1, param2);
}

void csMaterialSetAmbient_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMaterialSetAmbient(param0, param1);
}

void csMaterialSetDiffuse_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMaterialSetDiffuse(param0, param1);
}

void csMaterialSetEmissive_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMaterialSetEmissive(param0, param1);
}

void csMaterialSetSpecular_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMaterialSetSpecular(param0, param1);
}

void csMaterialSetShininess_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	csMaterialSetShininess(param0, param1);
}

void csMaterialSetParam_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	csMaterialSetParam(param0, param1);
}

void csMaterialGetName_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csMaterialGetName(param0);
	script->SetReturnObject((void* )ret);
}

void csMaterialGetType_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csMaterialGetType(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMaterialGetFlags_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csMaterialGetFlags(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMaterialGetTexture_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csMaterialGetTexture(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csMaterialGetAmbient_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csMaterialGetAmbient(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMaterialGetDiffuse_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csMaterialGetDiffuse(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMaterialGetEmissive_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csMaterialGetEmissive(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMaterialGetSpecular_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csMaterialGetSpecular(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMaterialGetShininess_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csMaterialGetShininess(param0);
	script->SetReturnFloat(ret);
}

void csMaterialGetParam_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csMaterialGetParam(param0);
	script->SetReturnFloat(ret);
}

void csMathFloor_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathFloor(param0);
	script->SetReturnFloat(ret);
}

void csMathCeil_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathCeil(param0);
	script->SetReturnFloat(ret);
}

void csMathAbs_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathAbs(param0);
	script->SetReturnFloat(ret);
}

void csMathSqr_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathSqr(param0);
	script->SetReturnFloat(ret);
}

void csMathSin_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathSin(param0);
	script->SetReturnFloat(ret);
}

void csMathCos_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathCos(param0);
	script->SetReturnFloat(ret);
}

void csMathTan_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathTan(param0);
	script->SetReturnFloat(ret);
}

void csMathASin_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathASin(param0);
	script->SetReturnFloat(ret);
}

void csMathACos_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathACos(param0);
	script->SetReturnFloat(ret);
}

void csMathATan_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathATan(param0);
	script->SetReturnFloat(ret);
}

void csMathATan2_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float arg1 = (float) script->GetArgFloat(1);
	float ret = csMathATan2(param0, param1);
	script->SetReturnFloat(ret);
}

void csMathExp_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathExp(param0);
	script->SetReturnFloat(ret);
}

void csMathLog_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathLog(param0);
	script->SetReturnFloat(ret);
}

void csMathLog10_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	float ret = csMathLog10(param0);
	script->SetReturnFloat(ret);
}

void csMathRand_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csMathRand(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csMathRandSeed_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csMathRandSeed(param0);
}

void csMatrixCreate_ASWRAP(asIScriptGeneric* script)
{
	int ret = csMatrixCreate();
	script->SetReturnDWord((asDWORD) ret);
}

void csMatrixFree_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csMatrixFree(param0);
}

void csMatrixAdd_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMatrixAdd(param0, param1);
}

void csMatrixCopy_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMatrixCopy(param0, param1);
}

void csMatrixDiv_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMatrixDiv(param0, param1);
}

void csMatrixElement_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	float ret = csMatrixElement(param0, param1, param2);
	script->SetReturnFloat(ret);
}

void csMatrixEqual_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csMatrixEqual(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csMatrixGetRotation_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMatrixGetRotation(param0, param1);
}

void csMatrixGetTranslation_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMatrixGetTranslation(param0, param1);
}

void csMatrixIdentity_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csMatrixIdentity(param0);
}

void csMatrixInterpolate_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float arg2 = (float) script->GetArgFloat(2);
	csMatrixInterpolate(param0, param1, param2);
}

void csMatrixInvert_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csMatrixInvert(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMatrixMul_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMatrixMul(param0, param1);
}

void csMatrixSet_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	float arg3 = (float) script->GetArgFloat(3);
	csMatrixSet(param0, param1, param2, param3);
}

void csMatrixSetRotation_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMatrixSetRotation(param0, param1);
}

void csMatrixSetScale_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMatrixSetScale(param0, param1);
}

void csMatrixSetTranslation_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMatrixSetTranslation(param0, param1);
}

void csMatrixSub_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csMatrixSub(param0, param1);
}

void csMatrixTranspose_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csMatrixTranspose(param0);
}

void csMeshLoad_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csMeshLoad(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMeshTerrainLoad_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csMeshTerrainLoad(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csMeshFree_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csMeshFree(param0);
}

void csMeshNode_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	int ret = csMeshNode(param0, param1, param2, param3);
	script->SetReturnDWord((asDWORD) ret);
}

void csMeshOctreeNode_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	int ret = csMeshOctreeNode(param0, param1, param2, param3);
	script->SetReturnDWord((asDWORD) ret);
}

void csMeshScale_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	csMeshScale(param0, param1, param2, param3);
}

void csMeshFlip_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csMeshFlip(param0);
}

void csMeshUpdateNormals_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csMeshUpdateNormals(param0);
}

void csMeshVerticesColor_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csMeshVerticesColor(param0, param1, param2);
}

void csMeshPlanarMapping_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	csMeshPlanarMapping(param0, param1);
}

void csMeshWidth_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csMeshWidth(param0);
	script->SetReturnFloat(ret);
}

void csMeshHeight_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csMeshHeight(param0);
	script->SetReturnFloat(ret);
}

void csMeshDepth_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csMeshDepth(param0);
	script->SetReturnFloat(ret);
}

void csNodeEmpty_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csNodeEmpty(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csNodeFree_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csNodeFree(param0);
}

void csNodeType_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csNodeType(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csNodeSetName_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	csNodeSetName(param0, param1);
}

void csNodeGetName_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csNodeGetName(param0);
	script->SetReturnObject((void* )ret);
}

void csNodePosition_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	csNodePosition(param0, param1, param2, param3);
}

void csNodeMove_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	csNodeMove(param0, param1, param2, param3);
}

void csNodeRotate_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	csNodeRotate(param0, param1, param2, param3);
}

void csNodeTurn_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	csNodeTurn(param0, param1, param2, param3);
}

void csNodeScale_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	csNodeScale(param0, param1, param2, param3);
}

void csNodeX_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float ret = csNodeX(param0, param1);
	script->SetReturnFloat(ret);
}

void csNodeY_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float ret = csNodeY(param0, param1);
	script->SetReturnFloat(ret);
}

void csNodeZ_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float ret = csNodeZ(param0, param1);
	script->SetReturnFloat(ret);
}

void csNodePitch_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csNodePitch(param0);
	script->SetReturnFloat(ret);
}

void csNodeYaw_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csNodeYaw(param0);
	script->SetReturnFloat(ret);
}

void csNodeRoll_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csNodeRoll(param0);
	script->SetReturnFloat(ret);
}

void csNodeScaleX_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csNodeScaleX(param0);
	script->SetReturnFloat(ret);
}

void csNodeScaleY_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csNodeScaleY(param0);
	script->SetReturnFloat(ret);
}

void csNodeScaleZ_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csNodeScaleZ(param0);
	script->SetReturnFloat(ret);
}

void csNodeWidth_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csNodeWidth(param0);
	script->SetReturnFloat(ret);
}

void csNodeHeight_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csNodeHeight(param0);
	script->SetReturnFloat(ret);
}

void csNodeDepth_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csNodeDepth(param0);
	script->SetReturnFloat(ret);
}

void csNodeCastShadow_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csNodeCastShadow(param0, param1);
}

void csNodeHide_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csNodeHide(param0, param1);
}

void csNodeMaterials_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csNodeMaterials(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csNodeGetMaterial_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csNodeGetMaterial(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csNodeSetMaterial_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csNodeSetMaterial(param0, param1, param2);
}

void csNodeSetMaterialFast_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	int arg4 = (int) script->GetArgDWord(4);
	int arg5 = (int) script->GetArgDWord(5);
	csNodeSetMaterialFast(param0, param1, param2, param3, param4, param5);
}

void csNodeSetPickGroup_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csNodeSetPickGroup(param0, param1);
}

void csNodeSetProperty_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	std::string* arg2 = (std::string*) script->GetArgAddress(2);
	csNodeSetProperty(param0, param1, param2);
}

void csNodeProperties_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csNodeProperties(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csNodeFindProperty_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int ret = csNodeFindProperty(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csNodePropertyName_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csNodePropertyName(param0, param1);
	script->SetReturnObject((void* )ret);
}

void csNodePropertyValue_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csNodePropertyValue(param0, param1);
	script->SetReturnObject((void* )ret);
}

void csNodeRemoveProperty_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csNodeRemoveProperty(param0, param1);
}

void csNodeSetParent_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csNodeSetParent(param0, param1);
}

void csNodeGetParent_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csNodeGetParent(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csNodeChildren_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csNodeChildren(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csNodeChild_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csNodeChild(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csNodeFindChild_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	int ret = csNodeFindChild(param0, param1, param2);
	script->SetReturnDWord((asDWORD) ret);
}

void csNodeSpeed_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csNodeSpeed(param0, param1);
}

void csNodeLoop_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csNodeLoop(param0, param1);
}

void csNodeSetFrame_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csNodeSetFrame(param0, param1, param2);
}

void csNodeGetFrame_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csNodeGetFrame(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csNodeAttachToBone_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	std::string* arg2 = (std::string*) script->GetArgAddress(2);
	csNodeAttachToBone(param0, param1, param2);
}

void csNodeLookAt_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	csNodeLookAt(param0, param1, param2, param3);
}

void csParticleDataCreate_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csParticleDataCreate(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataLoad_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csParticleDataLoad(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataSave_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	csParticleDataSave(param0, param1);
}

void csParticleDataFree_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csParticleDataFree(param0);
}

void csParticleDataFind_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csParticleDataFind(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataSetMaterial_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	csParticleDataSetMaterial(param0, param1);
}

void csParticleDataSetType_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csParticleDataSetType(param0, param1);
}

void csParticleDataSetBox_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	csParticleDataSetBox(param0, param1, param2, param3);
}

void csParticleDataSetDirection_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	csParticleDataSetDirection(param0, param1, param2, param3);
}

void csParticleDataSetRate_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csParticleDataSetRate(param0, param1, param2);
}

void csParticleDataSetColor_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csParticleDataSetColor(param0, param1, param2);
}

void csParticleDataSetLifeTime_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csParticleDataSetLifeTime(param0, param1, param2);
}

void csParticleDataSetMaxAngle_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csParticleDataSetMaxAngle(param0, param1);
}

void csParticleDataSetSize_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	csParticleDataSetSize(param0, param1, param2);
}

void csParticleDataAddFadeOutAffector_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	csParticleDataAddFadeOutAffector(param0, param1, param2);
}

void csParticleDataAddGravityAffector_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	int arg4 = (int) script->GetArgDWord(4);
	csParticleDataAddGravityAffector(param0, param1, param2, param3, param4);
}

void csParticleDataGetName_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csParticleDataGetName(param0);
	script->SetReturnObject((void* )ret);
}

void csParticleDataGetMaterial_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csParticleDataGetMaterial(param0);
	script->SetReturnObject((void* )ret);
}

void csParticleDataGetType_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csParticleDataGetType(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetBoxWidth_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csParticleDataGetBoxWidth(param0);
	script->SetReturnFloat(ret);
}

void csParticleDataGetBoxHeight_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csParticleDataGetBoxHeight(param0);
	script->SetReturnFloat(ret);
}

void csParticleDataGetBoxDepth_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csParticleDataGetBoxDepth(param0);
	script->SetReturnFloat(ret);
}

void csParticleDataGetDirectionX_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csParticleDataGetDirectionX(param0);
	script->SetReturnFloat(ret);
}

void csParticleDataGetDirectionY_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csParticleDataGetDirectionY(param0);
	script->SetReturnFloat(ret);
}

void csParticleDataGetDirectionZ_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csParticleDataGetDirectionZ(param0);
	script->SetReturnFloat(ret);
}

void csParticleDataGetMinRate_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csParticleDataGetMinRate(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetMaxRate_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csParticleDataGetMaxRate(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetMinColor_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csParticleDataGetMinColor(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetMaxColor_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csParticleDataGetMaxColor(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetMinLifeTime_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csParticleDataGetMinLifeTime(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetMaxLifeTime_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csParticleDataGetMaxLifeTime(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetMaxAngle_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csParticleDataGetMaxAngle(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetWidth_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csParticleDataGetWidth(param0);
	script->SetReturnFloat(ret);
}

void csParticleDataGetHeight_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csParticleDataGetHeight(param0);
	script->SetReturnFloat(ret);
}

void csParticleDataAffectors_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csParticleDataAffectors(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetAffectorType_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csParticleDataGetAffectorType(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetAffectorColor_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csParticleDataGetAffectorColor(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetAffectorTime_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csParticleDataGetAffectorTime(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csParticleDataGetAffectorGravityX_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float ret = csParticleDataGetAffectorGravityX(param0, param1);
	script->SetReturnFloat(ret);
}

void csParticleDataGetAffectorGravityY_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float ret = csParticleDataGetAffectorGravityY(param0, param1);
	script->SetReturnFloat(ret);
}

void csParticleDataGetAffectorGravityZ_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float ret = csParticleDataGetAffectorGravityZ(param0, param1);
	script->SetReturnFloat(ret);
}

void csSceneBegin_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csSceneBegin(param0, param1);
}

void csSceneEnd_ASWRAP(asIScriptGeneric* script)
{
	csSceneEnd();
}

void csSceneRender_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csSceneRender(param0);
}

void csSceneAmbient_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csSceneAmbient(param0);
}

void csSceneFog_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	csSceneFog(param0, param1, param2);
}

void csSceneSkybox_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	int arg4 = (int) script->GetArgDWord(4);
	int arg5 = (int) script->GetArgDWord(5);
	csSceneSkybox(param0, param1, param2, param3, param4, param5);
}

void csSceneTransformation_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csSceneTransformation(param0, param1);
}

void csShaderRegister_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	std::string* arg3 = (std::string*) script->GetArgAddress(3);
	std::string* arg4 = (std::string*) script->GetArgAddress(4);
	int arg5 = (int) script->GetArgDWord(5);
	int arg6 = (int) script->GetArgDWord(6);
	int ret = csShaderRegister(param0, param1, param2, param3, param4, param5, param6);
	script->SetReturnDWord((asDWORD) ret);
}

void csShaderRegisterFile_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	std::string* arg3 = (std::string*) script->GetArgAddress(3);
	std::string* arg4 = (std::string*) script->GetArgAddress(4);
	int arg5 = (int) script->GetArgDWord(5);
	int arg6 = (int) script->GetArgDWord(6);
	int ret = csShaderRegisterFile(param0, param1, param2, param3, param4, param5, param6);
	script->SetReturnDWord((asDWORD) ret);
}

void csShaderAsmRegister_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	int ret = csShaderAsmRegister(param0, param1, param2);
	script->SetReturnDWord((asDWORD) ret);
}

void csShaderAsmRegisterFile_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	int ret = csShaderAsmRegisterFile(param0, param1, param2);
	script->SetReturnDWord((asDWORD) ret);
}

void csShaderPixelConstant_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	int arg4 = (int) script->GetArgDWord(4);
	csShaderPixelConstant(param0, param1, param2, param3, param4);
}

void csShaderVertexConstant_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	int arg3 = (int) script->GetArgDWord(3);
	int arg4 = (int) script->GetArgDWord(4);
	csShaderVertexConstant(param0, param1, param2, param3, param4);
}

void csStringToInt_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csStringToInt(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csStringToFloat_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	float ret = csStringToFloat(param0);
	script->SetReturnFloat(ret);
}

void csStringFromInt_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csStringFromInt(param0);
	script->SetReturnObject((void* )ret);
}

void csStringFromFloat_ASWRAP(asIScriptGeneric* script)
{
	float arg0 = (float) script->GetArgFloat(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csStringFromFloat(param0);
	script->SetReturnObject((void* )ret);
}

void csStringLeft_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int arg1 = (int) script->GetArgDWord(1);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csStringLeft(param0, param1);
	script->SetReturnObject((void* )ret);
}

void csStringRight_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int arg1 = (int) script->GetArgDWord(1);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csStringRight(param0, param1);
	script->SetReturnObject((void* )ret);
}

void csStringMid_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int arg1 = (int) script->GetArgDWord(1);
	int arg2 = (int) script->GetArgDWord(2);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csStringMid(param0, param1, param2);
	script->SetReturnObject((void* )ret);
}

void csStringReplace_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	std::string* arg2 = (std::string*) script->GetArgAddress(2);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csStringReplace(param0, param1, param2);
	script->SetReturnObject((void* )ret);
}

void csStringFind_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	int ret = csStringFind(param0, param1, param2);
	script->SetReturnDWord((asDWORD) ret);
}

void csStringUpper_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csStringUpper(param0);
	script->SetReturnObject((void* )ret);
}

void csStringLower_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csStringLower(param0);
	script->SetReturnObject((void* )ret);
}

void csStringTrim_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csStringTrim(param0);
	script->SetReturnObject((void* )ret);
}

void csStringChar_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csStringChar(param0);
	script->SetReturnObject((void* )ret);
}

void csStringAscii_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csStringAscii(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csStringLen_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csStringLen(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csStringField_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	int arg2 = (int) script->GetArgDWord(2);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csStringField(param0, param1, param2);
	script->SetReturnObject((void* )ret);
}

void csTerrainNode_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int arg1 = (int) script->GetArgDWord(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	float arg4 = (float) script->GetArgFloat(4);
	int arg5 = (int) script->GetArgDWord(5);
	int ret = csTerrainNode(param0, param1, param2, param3, param4, param5);
	script->SetReturnDWord((asDWORD) ret);
}

void csTerrainScaleTexture_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	csTerrainScaleTexture(param0, param1, param2);
}

void csTextureCreate_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csTextureCreate(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csTextureTargetCreate_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csTextureTargetCreate(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csTextureLoad_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csTextureLoad(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csTextureFree_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csTextureFree(param0);
}

void csTextureFile_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csTextureFile(param0);
	script->SetReturnObject((void* )ret);
}

void csTextureWidth_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csTextureWidth(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csTextureHeight_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	int ret = csTextureHeight(param0, param1);
	script->SetReturnDWord((asDWORD) ret);
}

void csTextureLock_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csTextureLock(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csTextureUnlock_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csTextureUnlock(param0);
}

void csTextureColorKey_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csTextureColorKey(param0, param1);
}

void csTextureNormalize_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	csTextureNormalize(param0, param1);
}

void csTextureHWPointer_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csTextureHWPointer(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csVectorCreate_ASWRAP(asIScriptGeneric* script)
{
	int ret = csVectorCreate();
	script->SetReturnDWord((asDWORD) ret);
}

void csVectorFree_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csVectorFree(param0);
}

void csVectorAdd_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csVectorAdd(param0, param1);
}

void csVectorAddScale_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float arg2 = (float) script->GetArgFloat(2);
	csVectorAddScale(param0, param1, param2);
}

void csVectorBetween_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	float arg4 = (float) script->GetArgFloat(4);
	float arg5 = (float) script->GetArgFloat(5);
	float arg6 = (float) script->GetArgFloat(6);
	int ret = csVectorBetween(param0, param1, param2, param3, param4, param5, param6);
	script->SetReturnDWord((asDWORD) ret);
}

void csVectorCopy_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csVectorCopy(param0, param1);
}

void csVectorCrossProduct_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csVectorCrossProduct(param0, param1);
}

void csVectorDotProduct_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float ret = csVectorDotProduct(param0, param1);
	script->SetReturnFloat(ret);
}

void csVectorEqual_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float arg2 = (float) script->GetArgFloat(2);
	int ret = csVectorEqual(param0, param1, param2);
	script->SetReturnDWord((asDWORD) ret);
}

void csVectorDistance_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	float ret = csVectorDistance(param0, param1, param2, param3);
	script->SetReturnFloat(ret);
}

void csVectorDistanceSquared_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	float ret = csVectorDistanceSquared(param0, param1, param2, param3);
	script->SetReturnFloat(ret);
}

void csVectorDiv_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csVectorDiv(param0, param1);
}

void csVectorInterpolate_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	float arg2 = (float) script->GetArgFloat(2);
	csVectorInterpolate(param0, param1, param2);
}

void csVectorInvert_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csVectorInvert(param0);
}

void csVectorLength_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csVectorLength(param0);
	script->SetReturnFloat(ret);
}

void csVectorLengthSquared_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csVectorLengthSquared(param0);
	script->SetReturnFloat(ret);
}

void csVectorMul_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csVectorMul(param0, param1);
}

void csVectorNormalize_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csVectorNormalize(param0);
}

void csVectorScale_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	csVectorScale(param0, param1);
}

void csVectorSet_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float arg1 = (float) script->GetArgFloat(1);
	float arg2 = (float) script->GetArgFloat(2);
	float arg3 = (float) script->GetArgFloat(3);
	csVectorSet(param0, param1, param2, param3);
}

void csVectorSub_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	csVectorSub(param0, param1);
}

void csVectorX_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csVectorX(param0);
	script->SetReturnFloat(ret);
}

void csVectorY_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csVectorY(param0);
	script->SetReturnFloat(ret);
}

void csVectorZ_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	float ret = csVectorZ(param0);
	script->SetReturnFloat(ret);
}

void csXMLRead_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csXMLRead(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csXMLWrite_ASWRAP(asIScriptGeneric* script)
{
	std::string* arg0 = (std::string*) script->GetArgAddress(0);
	int ret = csXMLWrite(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csXMLClose_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csXMLClose(param0);
}

void csXMLReadNode_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csXMLReadNode(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csXMLNodeType_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csXMLNodeType(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csXMLNodeName_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csXMLNodeName(param0);
	script->SetReturnObject((void* )ret);
}

void csXMLNodeData_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csXMLNodeData(param0);
	script->SetReturnObject((void* )ret);
}

void csXMLAttributeCount_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int ret = csXMLAttributeCount(param0);
	script->SetReturnDWord((asDWORD) ret);
}

void csXMLAttributeName_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csXMLAttributeName(param0, param1);
	script->SetReturnObject((void* )ret);
}

void csXMLAttributeValue_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	int arg1 = (int) script->GetArgDWord(1);
	asCScriptString* ret = new asCScriptString();
	ret->buffer = csXMLAttributeValue(param0, param1);
	script->SetReturnObject((void* )ret);
}

void csXMLWriteHeader_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csXMLWriteHeader(param0);
}

void csXMLWriteElement_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	std::string* arg2 = (std::string*) script->GetArgAddress(2);
	int arg3 = (int) script->GetArgDWord(3);
	csXMLWriteElement(param0, param1, param2, param3);
}

void csXMLWriteClosingTag_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	csXMLWriteClosingTag(param0, param1);
}

void csXMLWriteText_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	std::string* arg1 = (std::string*) script->GetArgAddress(1);
	csXMLWriteText(param0, param1);
}

void csXMLWriteLineBreak_ASWRAP(asIScriptGeneric* script)
{
	int arg0 = (int) script->GetArgDWord(0);
	csXMLWriteLineBreak(param0);
}


bool asColdSteelRegister(asIScriptEngine* engine)
{
	if (engine->RegisterGlobalFunction("void CoreInit()", asFUNCTION(csCoreInit), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void CoreFinish()", asFUNCTION(csCoreFinish), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void CoreMessage(string &in msg_, int error_)", asFUNCTION(csCoreMessage), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int BillboardNode(int parent_)", asFUNCTION(csBillboardNode), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void BillboardResize(int billboard_, float width_, float height_)", asFUNCTION(csBillboardResize), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float BillboardWidth(int billboard_)", asFUNCTION(csBillboardWidth), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float BillboardHeight(int billboard_)", asFUNCTION(csBillboardHeight), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int CameraNode(int parent_)", asFUNCTION(csCameraNode), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void CameraViewport(int cam_, float x1_, float y1_, float x2_, float y2_)", asFUNCTION(csCameraViewport), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void CameraRange(int cam_, float near_, float far_)", asFUNCTION(csCameraRange), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void CameraFov(int cam_, float fov_)", asFUNCTION(csCameraFov), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void CameraAspectRatio(int cam_, float ratio_)", asFUNCTION(csCameraAspectRatio), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void CameraProjection(int cam_, float width_, float height_, float near_, float far_, int ortho_)", asFUNCTION(csCameraProjection), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void CameraLine(int cam_, int x_, int y_, int line_vec_start_, int line_vec_end_)", asFUNCTION(csCameraLine), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int CameraPickNode(int cam_, int x_, int y_, int group_)", asFUNCTION(csCameraPickNode), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void CameraToScreen(int cam_, float x_, float y_, float z_, int vec_out_)", asFUNCTION(csCameraToScreen), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void CameraRenderTarget(int cam_, int texture_)", asFUNCTION(csCameraRenderTarget), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void CollisionSlide(int node_, float pos_x_, float pos_y_, float pos_z_, float dest_x_, float dest_y_, float dest_z_, float rad_x_, float rad_y_, float rad_z_, int vec_pos_, int vec_tri_a_, int vec_tri_b_, int vec_tri_c_)", asFUNCTION(csCollisionSlide), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int CollisionLinePick(int node_, float pos_x_, float pos_y_, float pos_z_, float dest_x_, float dest_y_, float dest_z_, int vec_pos_, int vec_tri_a_, int vec_tri_b_, int vec_tri_c_)", asFUNCTION(csCollisionLinePick), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int CollisionLineNode(float pos_x_, float pos_y_, float pos_z_, float dest_x_, float dest_y_, float dest_z_)", asFUNCTION(csCollisionLineNode), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void PackageAdd(string &in pak_)", asFUNCTION(csPackageAdd), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int DirList(string &in dir_)", asFUNCTION(csDirList), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void DirClose(int dir_)", asFUNCTION(csDirClose), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int DirFileCount(int dir_)", asFUNCTION(csDirFileCount), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @DirFileName(int dir_, int index_)", asFUNCTION(csDirFileName), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int DirFileIsDir(int dir_, int index_)", asFUNCTION(csDirFileIsDir), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void DisplayOpen(int width_, int height_, int depth_, int flags_, int win_)", asFUNCTION(csDisplayOpen), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void DisplayClose()", asFUNCTION(csDisplayClose), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void DisplayCaption(string &in caption_)", asFUNCTION(csDisplayCaption), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int DisplayClosed()", asFUNCTION(csDisplayClosed), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int DisplayWidth()", asFUNCTION(csDisplayWidth), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int DisplayHeight()", asFUNCTION(csDisplayHeight), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int DisplayFps()", asFUNCTION(csDisplayFps), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int DisplayFeature(int feature_)", asFUNCTION(csDisplayFeature), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void DisplayResize(int width_, int height_)", asFUNCTION(csDisplayResize), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int DisplayActive()", asFUNCTION(csDisplayActive), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int GetColor(int red_, int green_, int blue_, int alpha_)", asFUNCTION(csGetColor), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int GetRed(int color_)", asFUNCTION(csGetRed), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int GetGreen(int color_)", asFUNCTION(csGetGreen), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int GetBlue(int color_)", asFUNCTION(csGetBlue), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int GetAlpha(int color_)", asFUNCTION(csGetAlpha), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void SetColor(int color_)", asFUNCTION(csSetColor), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void Viewport(int x_, int y_, int w_, int h_)", asFUNCTION(csViewport), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void DrawLine(int x_, int y_, int x1_, int y1_)", asFUNCTION(csDrawLine), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void DrawRect(int x_, int y_, int w_, int h_)", asFUNCTION(csDrawRect), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void DrawTexture(int tex_, int x_, int y_)", asFUNCTION(csDrawTexture), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void DrawText(int font_, string &in text_, int x_, int y_)", asFUNCTION(csDrawText), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int TextWidth(int font_, string &in text_)", asFUNCTION(csTextWidth), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int TextHeight(int font_, string &in text_)", asFUNCTION(csTextHeight), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int EffectRegister(string &in effect_, int base_mat_)", asFUNCTION(csEffectRegister), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int EffectRegisterFile(string &in effect_file_, int base_mat_)", asFUNCTION(csEffectRegisterFile), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void EffectSetTechnique(int effect_, string &in technique_)", asFUNCTION(csEffectSetTechnique), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void EffectSetTexture(int effect_, string &in var_name_, int texture_)", asFUNCTION(csEffectSetTexture), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void EffectSetBool(int effect_, string &in var_name_, int value_)", asFUNCTION(csEffectSetBool), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void EffectSetInt(int effect_, string &in var_name_, int value_)", asFUNCTION(csEffectSetInt), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void EffectSetFloat(int effect_, string &in var_name_, float value_)", asFUNCTION(csEffectSetFloat), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void EffectSetVector(int effect_, string &in var_name_, int vector_)", asFUNCTION(csEffectSetVector), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void EffectSetMatrix(int effect_, string &in var_name_, int matrix_)", asFUNCTION(csEffectSetMatrix), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int EmitterNode(int particle_data_, int parent_)", asFUNCTION(csEmitterNode), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void EmitterAddFadeOutAffector(int emitter_, int color_, int time_)", asFUNCTION(csEmitterAddFadeOutAffector), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void EmitterAddGravityAffector(int emitter_, float grav_x_, float grav_y_, float grav_z_, int time_)", asFUNCTION(csEmitterAddGravityAffector), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void EmitterRemoveAffectors(int emitter_)", asFUNCTION(csEmitterRemoveAffectors), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int EventGet()", asFUNCTION(csEventGet), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int EventPoll()", asFUNCTION(csEventPoll), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void EventPost(int id_, int from_, int to_, float a_, float b_, float c_, string &in str_)", asFUNCTION(csEventPost), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int EventId()", asFUNCTION(csEventId), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int EventFrom()", asFUNCTION(csEventFrom), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int EventTo()", asFUNCTION(csEventTo), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float EventA()", asFUNCTION(csEventA), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float EventB()", asFUNCTION(csEventB), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float EventC()", asFUNCTION(csEventC), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @EventData()", asFUNCTION(csEventData), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int FileRead(string &in file_)", asFUNCTION(csFileRead), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int FileWrite(string &in file_)", asFUNCTION(csFileWrite), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void FileClose(int file_)", asFUNCTION(csFileClose), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int FileSize(int file_)", asFUNCTION(csFileSize), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int FilePos(int file_)", asFUNCTION(csFilePos), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void FileSeek(int file_, int pos_, int relative_)", asFUNCTION(csFileSeek), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int FileReadByte(int file_)", asFUNCTION(csFileReadByte), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int FileReadShort(int file_)", asFUNCTION(csFileReadShort), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int FileReadInt(int file_)", asFUNCTION(csFileReadInt), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float FileReadFloat(int file_)", asFUNCTION(csFileReadFloat), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @FileReadString(int file_)", asFUNCTION(csFileReadString), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void FileReadBytes(int file_, int buf_, int size_)", asFUNCTION(csFileReadBytes), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void FileWriteByte(int file_, int value_)", asFUNCTION(csFileWriteByte), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void FileWriteShort(int file_, int value_)", asFUNCTION(csFileWriteShort), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void FileWriteInt(int file_, int value_)", asFUNCTION(csFileWriteInt), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void FileWriteFloat(int file_, float value_)", asFUNCTION(csFileWriteFloat), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void FileWriteString(int file_, string &in str_)", asFUNCTION(csFileWriteString), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void FileWriteBytes(int file_, int buf_, int size_)", asFUNCTION(csFileWriteBytes), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @FileGetExt(string &in filename_)", asFUNCTION(csFileGetExt), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @FileGetDir(string &in filename_)", asFUNCTION(csFileGetDir), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @FileStripExt(string &in filename_)", asFUNCTION(csFileStripExt), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @FileStripDir(string &in filename_)", asFUNCTION(csFileStripDir), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int FontLoad(string &in file_)", asFUNCTION(csFontLoad), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void FontFree(int font_)", asFUNCTION(csFontFree), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MousePosition(int x_, int y_)", asFUNCTION(csMousePosition), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MouseHide(int hide_)", asFUNCTION(csMouseHide), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MouseX()", asFUNCTION(csMouseX), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MouseY()", asFUNCTION(csMouseY), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MouseHit(int button_)", asFUNCTION(csMouseHit), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MouseDown(int button_)", asFUNCTION(csMouseDown), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MouseGet()", asFUNCTION(csMouseGet), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MouseReleased()", asFUNCTION(csMouseReleased), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int KeyHit(int key_)", asFUNCTION(csKeyHit), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int KeyDown(int key_)", asFUNCTION(csKeyDown), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int KeyGet()", asFUNCTION(csKeyGet), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int KeyReleased()", asFUNCTION(csKeyReleased), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @JoyName(int id_)", asFUNCTION(csJoyName), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int JoyButton(int id_, int button_)", asFUNCTION(csJoyButton), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float JoyAxis(int id_, int axis_)", asFUNCTION(csJoyAxis), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int JoyNumAxes(int id_)", asFUNCTION(csJoyNumAxes), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int LightNode(int parent_)", asFUNCTION(csLightNode), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void LightRadius(int light_, float radius_)", asFUNCTION(csLightRadius), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void LightAmbient(int light_, int color_)", asFUNCTION(csLightAmbient), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void LightDiffuse(int light_, int color_)", asFUNCTION(csLightDiffuse), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void LightSpecular(int light_, int color_)", asFUNCTION(csLightSpecular), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MaterialCreate(string &in name_)", asFUNCTION(csMaterialCreate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MaterialLoad(string &in file_)", asFUNCTION(csMaterialLoad), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MaterialSave(int mat_, string &in file_, string &in rel_path_)", asFUNCTION(csMaterialSave), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MaterialFree(int mat_)", asFUNCTION(csMaterialFree), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MaterialFind(string &in name_)", asFUNCTION(csMaterialFind), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MaterialSetType(int mat_, int newtype_)", asFUNCTION(csMaterialSetType), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MaterialSetFlags(int mat_, int flags_)", asFUNCTION(csMaterialSetFlags), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MaterialSetTexture(int mat_, int tex_, int layer_)", asFUNCTION(csMaterialSetTexture), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MaterialSetAmbient(int mat_, int color_)", asFUNCTION(csMaterialSetAmbient), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MaterialSetDiffuse(int mat_, int color_)", asFUNCTION(csMaterialSetDiffuse), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MaterialSetEmissive(int mat_, int color_)", asFUNCTION(csMaterialSetEmissive), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MaterialSetSpecular(int mat_, int color_)", asFUNCTION(csMaterialSetSpecular), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MaterialSetShininess(int mat_, float shininess_)", asFUNCTION(csMaterialSetShininess), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MaterialSetParam(int mat_, float param_)", asFUNCTION(csMaterialSetParam), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @MaterialGetName(int mat_)", asFUNCTION(csMaterialGetName), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MaterialGetType(int mat_)", asFUNCTION(csMaterialGetType), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MaterialGetFlags(int mat_)", asFUNCTION(csMaterialGetFlags), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MaterialGetTexture(int mat_, int layer_)", asFUNCTION(csMaterialGetTexture), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MaterialGetAmbient(int mat_)", asFUNCTION(csMaterialGetAmbient), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MaterialGetDiffuse(int mat_)", asFUNCTION(csMaterialGetDiffuse), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MaterialGetEmissive(int mat_)", asFUNCTION(csMaterialGetEmissive), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MaterialGetSpecular(int mat_)", asFUNCTION(csMaterialGetSpecular), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MaterialGetShininess(int mat_)", asFUNCTION(csMaterialGetShininess), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MaterialGetParam(int mat_)", asFUNCTION(csMaterialGetParam), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathFloor(float val_)", asFUNCTION(csMathFloor), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathCeil(float val_)", asFUNCTION(csMathCeil), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathAbs(float val_)", asFUNCTION(csMathAbs), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathSqr(float val_)", asFUNCTION(csMathSqr), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathSin(float val_)", asFUNCTION(csMathSin), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathCos(float val_)", asFUNCTION(csMathCos), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathTan(float val_)", asFUNCTION(csMathTan), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathASin(float val_)", asFUNCTION(csMathASin), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathACos(float val_)", asFUNCTION(csMathACos), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathATan(float val_)", asFUNCTION(csMathATan), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathATan2(float x_, float y_)", asFUNCTION(csMathATan2), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathExp(float val_)", asFUNCTION(csMathExp), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathLog(float val_)", asFUNCTION(csMathLog), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MathLog10(float val_)", asFUNCTION(csMathLog10), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MathRand(int min_, int max_)", asFUNCTION(csMathRand), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MathRandSeed(int seed_)", asFUNCTION(csMathRandSeed), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MatrixCreate()", asFUNCTION(csMatrixCreate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixFree(int matrix_)", asFUNCTION(csMatrixFree), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixAdd(int matrix_, int matrix2_)", asFUNCTION(csMatrixAdd), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixCopy(int matrix_, int matrix2_)", asFUNCTION(csMatrixCopy), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixDiv(int matrix_, int matrix2_)", asFUNCTION(csMatrixDiv), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MatrixElement(int matrix_, int row_, int column_)", asFUNCTION(csMatrixElement), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MatrixEqual(int matrix_, int matrix2_)", asFUNCTION(csMatrixEqual), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixGetRotation(int matrix_, int vector_)", asFUNCTION(csMatrixGetRotation), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixGetTranslation(int matrix_, int vector_)", asFUNCTION(csMatrixGetTranslation), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixIdentity(int matrix_)", asFUNCTION(csMatrixIdentity), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixInterpolate(int matrix_, int matrix2_, float time_)", asFUNCTION(csMatrixInterpolate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MatrixInvert(int matrix_)", asFUNCTION(csMatrixInvert), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixMul(int matrix_, int matrix2_)", asFUNCTION(csMatrixMul), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixSet(int matrix_, int row_, int column_, float val_)", asFUNCTION(csMatrixSet), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixSetRotation(int matrix_, int vector_)", asFUNCTION(csMatrixSetRotation), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixSetScale(int matrix_, int vector_)", asFUNCTION(csMatrixSetScale), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixSetTranslation(int matrix_, int vector_)", asFUNCTION(csMatrixSetTranslation), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixSub(int matrix_, int matrix2_)", asFUNCTION(csMatrixSub), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MatrixTranspose(int matrix_)", asFUNCTION(csMatrixTranspose), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MeshLoad(string &in file_)", asFUNCTION(csMeshLoad), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MeshTerrainLoad(string &in heightmap_)", asFUNCTION(csMeshTerrainLoad), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MeshFree(int mesh_)", asFUNCTION(csMeshFree), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MeshNode(int mesh_, int parent_, int col_info_, int tangent_mesh_)", asFUNCTION(csMeshNode), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int MeshOctreeNode(int mesh_, int parent_, int col_info_, int tangent_mesh_)", asFUNCTION(csMeshOctreeNode), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MeshScale(int mesh_, float sx_, float sy_, float sz_)", asFUNCTION(csMeshScale), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MeshFlip(int mesh_)", asFUNCTION(csMeshFlip), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MeshUpdateNormals(int mesh_)", asFUNCTION(csMeshUpdateNormals), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MeshVerticesColor(int mesh_, int color_, int change_alpha_)", asFUNCTION(csMeshVerticesColor), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void MeshPlanarMapping(int mesh_, float resolution_)", asFUNCTION(csMeshPlanarMapping), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MeshWidth(int mesh_)", asFUNCTION(csMeshWidth), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MeshHeight(int mesh_)", asFUNCTION(csMeshHeight), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float MeshDepth(int mesh_)", asFUNCTION(csMeshDepth), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int NodeEmpty(int parent_)", asFUNCTION(csNodeEmpty), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeFree(int node_)", asFUNCTION(csNodeFree), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int NodeType(int node_)", asFUNCTION(csNodeType), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeSetName(int node_, string &in name_)", asFUNCTION(csNodeSetName), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @NodeGetName(int node_)", asFUNCTION(csNodeGetName), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodePosition(int node_, float x_, float y_, float z_)", asFUNCTION(csNodePosition), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeMove(int node_, float x_, float y_, float z_)", asFUNCTION(csNodeMove), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeRotate(int node_, float pitch_, float yaw_, float roll_)", asFUNCTION(csNodeRotate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeTurn(int node_, float pitch_, float yaw_, float roll_)", asFUNCTION(csNodeTurn), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeScale(int node_, float x_, float y_, float z_)", asFUNCTION(csNodeScale), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodeX(int node_, int absolute_)", asFUNCTION(csNodeX), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodeY(int node_, int absolute_)", asFUNCTION(csNodeY), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodeZ(int node_, int absolute_)", asFUNCTION(csNodeZ), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodePitch(int node_)", asFUNCTION(csNodePitch), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodeYaw(int node_)", asFUNCTION(csNodeYaw), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodeRoll(int node_)", asFUNCTION(csNodeRoll), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodeScaleX(int node_)", asFUNCTION(csNodeScaleX), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodeScaleY(int node_)", asFUNCTION(csNodeScaleY), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodeScaleZ(int node_)", asFUNCTION(csNodeScaleZ), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodeWidth(int node_)", asFUNCTION(csNodeWidth), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodeHeight(int node_)", asFUNCTION(csNodeHeight), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float NodeDepth(int node_)", asFUNCTION(csNodeDepth), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeCastShadow(int node_, int cast_)", asFUNCTION(csNodeCastShadow), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeHide(int node_, int state_)", asFUNCTION(csNodeHide), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int NodeMaterials(int node_)", asFUNCTION(csNodeMaterials), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int NodeGetMaterial(int node_, int mat_index_)", asFUNCTION(csNodeGetMaterial), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeSetMaterial(int node_, int mat_, int mat_index_)", asFUNCTION(csNodeSetMaterial), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeSetMaterialFast(int node_, int index_, int type_, int flags_, int tex1_, int tex2_)", asFUNCTION(csNodeSetMaterialFast), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeSetPickGroup(int n_, int group_)", asFUNCTION(csNodeSetPickGroup), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeSetProperty(int node_, string &in name_, string &in value_)", asFUNCTION(csNodeSetProperty), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int NodeProperties(int node_)", asFUNCTION(csNodeProperties), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int NodeFindProperty(int node_, string &in name_)", asFUNCTION(csNodeFindProperty), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @NodePropertyName(int node_, int index_)", asFUNCTION(csNodePropertyName), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @NodePropertyValue(int node_, int index_)", asFUNCTION(csNodePropertyValue), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeRemoveProperty(int node_, int index_)", asFUNCTION(csNodeRemoveProperty), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeSetParent(int node_, int parent_)", asFUNCTION(csNodeSetParent), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int NodeGetParent(int node_)", asFUNCTION(csNodeGetParent), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int NodeChildren(int node_)", asFUNCTION(csNodeChildren), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int NodeChild(int node_, int index_)", asFUNCTION(csNodeChild), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int NodeFindChild(int node_, string &in name_, int recursive_)", asFUNCTION(csNodeFindChild), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeSpeed(int node_, int fps_)", asFUNCTION(csNodeSpeed), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeLoop(int node_, int loop_)", asFUNCTION(csNodeLoop), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeSetFrame(int node_, int start_, int finish_)", asFUNCTION(csNodeSetFrame), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int NodeGetFrame(int node_)", asFUNCTION(csNodeGetFrame), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeAttachToBone(int n_, int n2_, string &in bonename_)", asFUNCTION(csNodeAttachToBone), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void NodeLookAt(int node_, float x_, float y_, float z_)", asFUNCTION(csNodeLookAt), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataCreate(string &in name_)", asFUNCTION(csParticleDataCreate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataLoad(string &in file_)", asFUNCTION(csParticleDataLoad), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataSave(int part_data_, string &in file_)", asFUNCTION(csParticleDataSave), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataFree(int part_data_)", asFUNCTION(csParticleDataFree), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataFind(string &in name_)", asFUNCTION(csParticleDataFind), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataSetMaterial(int part_data_, string &in mat_name_)", asFUNCTION(csParticleDataSetMaterial), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataSetType(int part_data_, int type_)", asFUNCTION(csParticleDataSetType), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataSetBox(int part_data_, float width_, float height_, float depth_)", asFUNCTION(csParticleDataSetBox), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataSetDirection(int part_data_, float x_, float y_, float z_)", asFUNCTION(csParticleDataSetDirection), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataSetRate(int part_data_, int min_, int max_)", asFUNCTION(csParticleDataSetRate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataSetColor(int part_data_, int min_, int max_)", asFUNCTION(csParticleDataSetColor), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataSetLifeTime(int part_data_, int min_, int max_)", asFUNCTION(csParticleDataSetLifeTime), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataSetMaxAngle(int part_data_, int angle_)", asFUNCTION(csParticleDataSetMaxAngle), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataSetSize(int part_data_, float width_, float height_)", asFUNCTION(csParticleDataSetSize), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataAddFadeOutAffector(int part_data_, int color_, int time_)", asFUNCTION(csParticleDataAddFadeOutAffector), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ParticleDataAddGravityAffector(int part_data_, float grav_x_, float grav_y_, float grav_z_, int time_)", asFUNCTION(csParticleDataAddGravityAffector), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @ParticleDataGetName(int part_)", asFUNCTION(csParticleDataGetName), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @ParticleDataGetMaterial(int part_)", asFUNCTION(csParticleDataGetMaterial), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataGetType(int part_)", asFUNCTION(csParticleDataGetType), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float ParticleDataGetBoxWidth(int part_)", asFUNCTION(csParticleDataGetBoxWidth), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float ParticleDataGetBoxHeight(int part_)", asFUNCTION(csParticleDataGetBoxHeight), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float ParticleDataGetBoxDepth(int part_)", asFUNCTION(csParticleDataGetBoxDepth), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float ParticleDataGetDirectionX(int part_)", asFUNCTION(csParticleDataGetDirectionX), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float ParticleDataGetDirectionY(int part_)", asFUNCTION(csParticleDataGetDirectionY), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float ParticleDataGetDirectionZ(int part_)", asFUNCTION(csParticleDataGetDirectionZ), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataGetMinRate(int part_)", asFUNCTION(csParticleDataGetMinRate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataGetMaxRate(int part_)", asFUNCTION(csParticleDataGetMaxRate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataGetMinColor(int part_)", asFUNCTION(csParticleDataGetMinColor), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataGetMaxColor(int part_)", asFUNCTION(csParticleDataGetMaxColor), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataGetMinLifeTime(int part_)", asFUNCTION(csParticleDataGetMinLifeTime), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataGetMaxLifeTime(int part_)", asFUNCTION(csParticleDataGetMaxLifeTime), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataGetMaxAngle(int part_)", asFUNCTION(csParticleDataGetMaxAngle), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float ParticleDataGetWidth(int part_)", asFUNCTION(csParticleDataGetWidth), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float ParticleDataGetHeight(int part_)", asFUNCTION(csParticleDataGetHeight), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataAffectors(int part_)", asFUNCTION(csParticleDataAffectors), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataGetAffectorType(int part_, int index_)", asFUNCTION(csParticleDataGetAffectorType), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataGetAffectorColor(int part_, int index_)", asFUNCTION(csParticleDataGetAffectorColor), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ParticleDataGetAffectorTime(int part_, int index_)", asFUNCTION(csParticleDataGetAffectorTime), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float ParticleDataGetAffectorGravityX(int part_, int index_)", asFUNCTION(csParticleDataGetAffectorGravityX), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float ParticleDataGetAffectorGravityY(int part_, int index_)", asFUNCTION(csParticleDataGetAffectorGravityY), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float ParticleDataGetAffectorGravityZ(int part_, int index_)", asFUNCTION(csParticleDataGetAffectorGravityZ), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void SceneBegin(int clear_flags_, int color_)", asFUNCTION(csSceneBegin), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void SceneEnd()", asFUNCTION(csSceneEnd), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void SceneRender(int camera_)", asFUNCTION(csSceneRender), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void SceneAmbient(int color_)", asFUNCTION(csSceneAmbient), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void SceneFog(int color_, float near_, float far_)", asFUNCTION(csSceneFog), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void SceneSkybox(int top_, int bottom_, int left_, int right_, int front_, int back_)", asFUNCTION(csSceneSkybox), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void SceneTransformation(int state_, int matrix_)", asFUNCTION(csSceneTransformation), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ShaderRegister(string &in pixel_shader_, string &in pixel_entry_, int pixel_format_, string &in vertex_shader_, string &in vertex_entry_, int vertex_format_, int base_mat_)", asFUNCTION(csShaderRegister), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ShaderRegisterFile(string &in pixel_file_, string &in pixel_entry_, int pixel_format_, string &in vertex_file_, string &in vertex_entry_, int vertex_format_, int base_mat_)", asFUNCTION(csShaderRegisterFile), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ShaderAsmRegister(string &in pixel_shader_, string &in vertex_shader_, int base_material_)", asFUNCTION(csShaderAsmRegister), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int ShaderAsmRegisterFile(string &in pixel_file_, string &in vertex_file_, int base_mat_)", asFUNCTION(csShaderAsmRegisterFile), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ShaderPixelConstant(int shader_, string &in name_, int start_register_, int data_, int count_)", asFUNCTION(csShaderPixelConstant), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void ShaderVertexConstant(int shader_, string &in name_, int start_register_, int data_, int count_)", asFUNCTION(csShaderVertexConstant), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int StringToInt(string &in str_)", asFUNCTION(csStringToInt), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float StringToFloat(string &in str_)", asFUNCTION(csStringToFloat), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @StringFromInt(int number_)", asFUNCTION(csStringFromInt), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @StringFromFloat(float number_)", asFUNCTION(csStringFromFloat), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @StringLeft(string &in str_, int number_)", asFUNCTION(csStringLeft), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @StringRight(string &in str_, int num_)", asFUNCTION(csStringRight), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @StringMid(string &in str_, int pos_, int num_)", asFUNCTION(csStringMid), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @StringReplace(string &in str_, string &in find_, string &in replace_)", asFUNCTION(csStringReplace), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int StringFind(string &in str_, string &in find_, int offset_)", asFUNCTION(csStringFind), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @StringUpper(string &in str_)", asFUNCTION(csStringUpper), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @StringLower(string &in str_)", asFUNCTION(csStringLower), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @StringTrim(string &in str_)", asFUNCTION(csStringTrim), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @StringChar(int ascii_)", asFUNCTION(csStringChar), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int StringAscii(string &in str_)", asFUNCTION(csStringAscii), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int StringLen(string &in str_)", asFUNCTION(csStringLen), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @StringField(string &in str_, string &in delimiter_, int index_)", asFUNCTION(csStringField), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int TerrainNode(string &in heightmap_, int parent_, float width_, float height_, float depth_, int col_info_)", asFUNCTION(csTerrainNode), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void TerrainScaleTexture(int terrain_, float scale1_, float scale2_)", asFUNCTION(csTerrainScaleTexture), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int TextureCreate(int width_, int height_)", asFUNCTION(csTextureCreate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int TextureTargetCreate(int width_, int height_)", asFUNCTION(csTextureTargetCreate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int TextureLoad(string &in file_, int mipmaps_)", asFUNCTION(csTextureLoad), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void TextureFree(int tex_)", asFUNCTION(csTextureFree), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @TextureFile(int tex_)", asFUNCTION(csTextureFile), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int TextureWidth(int tex_, int original_)", asFUNCTION(csTextureWidth), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int TextureHeight(int tex_, int original_)", asFUNCTION(csTextureHeight), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int TextureLock(int tex_)", asFUNCTION(csTextureLock), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void TextureUnlock(int tex_)", asFUNCTION(csTextureUnlock), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void TextureColorKey(int tex_, int color_)", asFUNCTION(csTextureColorKey), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void TextureNormalize(int tex_, float amplitude_)", asFUNCTION(csTextureNormalize), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int TextureHWPointer(int tex_)", asFUNCTION(csTextureHWPointer), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int VectorCreate()", asFUNCTION(csVectorCreate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorFree(int vector_)", asFUNCTION(csVectorFree), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorAdd(int vector_, int vector2_)", asFUNCTION(csVectorAdd), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorAddScale(int vector_, int vector2_, float scale_)", asFUNCTION(csVectorAddScale), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int VectorBetween(int vector_, float x0_, float y0_, float z0_, float x1_, float y1_, float z1_)", asFUNCTION(csVectorBetween), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorCopy(int vector_, int other_vector_)", asFUNCTION(csVectorCopy), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorCrossProduct(int vector_, int vector2_)", asFUNCTION(csVectorCrossProduct), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float VectorDotProduct(int vector_, int other_vector_)", asFUNCTION(csVectorDotProduct), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int VectorEqual(int vector_, int other_vector_, float epsilon_)", asFUNCTION(csVectorEqual), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float VectorDistance(int vector_, float x_, float y_, float z_)", asFUNCTION(csVectorDistance), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float VectorDistanceSquared(int vector_, float x_, float y_, float z_)", asFUNCTION(csVectorDistanceSquared), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorDiv(int vector_, int vector2_)", asFUNCTION(csVectorDiv), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorInterpolate(int vector_, int vector2_, float d_)", asFUNCTION(csVectorInterpolate), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorInvert(int vector_)", asFUNCTION(csVectorInvert), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float VectorLength(int vector_)", asFUNCTION(csVectorLength), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float VectorLengthSquared(int vector_)", asFUNCTION(csVectorLengthSquared), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorMul(int vector_, int vector2_)", asFUNCTION(csVectorMul), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorNormalize(int vector_)", asFUNCTION(csVectorNormalize), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorScale(int vector_, float scale_)", asFUNCTION(csVectorScale), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorSet(int vector_, float x_, float y_, float z_)", asFUNCTION(csVectorSet), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void VectorSub(int vector_, int vector2_)", asFUNCTION(csVectorSub), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float VectorX(int vector_)", asFUNCTION(csVectorX), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float VectorY(int vector_)", asFUNCTION(csVectorY), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("float VectorZ(int vector_)", asFUNCTION(csVectorZ), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int XMLRead(string &in file_)", asFUNCTION(csXMLRead), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int XMLWrite(string &in file_)", asFUNCTION(csXMLWrite), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void XMLClose(int xml_)", asFUNCTION(csXMLClose), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int XMLReadNode(int xml_)", asFUNCTION(csXMLReadNode), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int XMLNodeType(int xml_)", asFUNCTION(csXMLNodeType), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @XMLNodeName(int xml_)", asFUNCTION(csXMLNodeName), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @XMLNodeData(int xml_)", asFUNCTION(csXMLNodeData), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("int XMLAttributeCount(int xml_)", asFUNCTION(csXMLAttributeCount), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @XMLAttributeName(int xml_, int index_)", asFUNCTION(csXMLAttributeName), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("string @XMLAttributeValue(int xml_, int index_)", asFUNCTION(csXMLAttributeValue), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void XMLWriteHeader(int xml_)", asFUNCTION(csXMLWriteHeader), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void XMLWriteElement(int xml_, string &in name_, string &in attributes_, int empty_)", asFUNCTION(csXMLWriteElement), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void XMLWriteClosingTag(int xml_, string &in name_)", asFUNCTION(csXMLWriteClosingTag), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void XMLWriteText(int xml_, string &in text_)", asFUNCTION(csXMLWriteText), asCALL_GENERIC) < 0) return false;
	if (engine->RegisterGlobalFunction("void XMLWriteLineBreak(int xml_)", asFUNCTION(csXMLWriteLineBreak), asCALL_GENERIC) < 0) return false;

	char* constants = (char*) malloc(6656);
	strcpy(constants, "");
	strcat(constants, "const int DFE_RENDERTOTEXTURE=0;\n");
	strcat(constants, "const int DFE_BILINEARFILTER=1;\n");
	strcat(constants, "const int DFE_HARDWARETNL=2;\n");
	strcat(constants, "const int DFE_MIPMAP=3;\n");
	strcat(constants, "const int DFE_STENCILBUFFER=4;\n");
	strcat(constants, "const int DFE_VERTEXSHADER11=5;\n");
	strcat(constants, "const int DFE_VERTEXSHADER20=6;\n");
	strcat(constants, "const int DFE_VERTEXSHADER30=7;\n");
	strcat(constants, "const int DFE_PIXELSHADER11=8;\n");
	strcat(constants, "const int DFE_PIXELSHADER12=9;\n");
	strcat(constants, "const int DFE_PIXELSHADER13=10;\n");
	strcat(constants, "const int DFE_PIXELSHADER14=11;\n");
	strcat(constants, "const int DFE_PIXELSHADER20=12;\n");
	strcat(constants, "const int DFE_PIXELSHADER30=13;\n");
	strcat(constants, "const int DFE_ARB_VERTEXPROGRAM1=14;\n");
	strcat(constants, "const int DFE_ARB_FRAGMENTPROGRAM1=15;\n");
	strcat(constants, "const int DF_FULLSCREEN=1;\n");
	strcat(constants, "const int DF_VSYNC=2;\n");
	strcat(constants, "const int DF_ANTIALIAS=4;\n");
	strcat(constants, "const int DF_OPENGL=65536;\n");
	strcat(constants, "const int EV_INIT=101;\n");
	strcat(constants, "const int EV_FINISH=102;\n");
	strcat(constants, "const int EV_FRAME=103;\n");
	strcat(constants, "const int EV_DISPLAY_OPEN=201;\n");
	strcat(constants, "const int EV_KEY_HIT=301;\n");
	strcat(constants, "const int EV_KEY_RELEASE=302;\n");
	strcat(constants, "const int EV_MOUSE_MOVE=401;\n");
	strcat(constants, "const int EV_MOUSE_HIT=402;\n");
	strcat(constants, "const int EV_MOUSE_RELEASE=403;\n");
	strcat(constants, "const int MB_LEFT=1;\n");
	strcat(constants, "const int MB_RIGHT=2;\n");
	strcat(constants, "const int MB_MIDDLE=3;\n");
	strcat(constants, "const int KEY_LBUTTON=0x01;\n");
	strcat(constants, "const int KEY_RBUTTON=0x02;\n");
	strcat(constants, "const int KEY_CANCEL=0x03;\n");
	strcat(constants, "const int KEY_MBUTTON=0x04;\n");
	strcat(constants, "const int KEY_XBUTTON1=0x05;\n");
	strcat(constants, "const int KEY_XBUTTON2=0x06;\n");
	strcat(constants, "const int KEY_BACK=0x08;\n");
	strcat(constants, "const int KEY_TAB=0x09;\n");
	strcat(constants, "const int KEY_CLEAR=0x0C;\n");
	strcat(constants, "const int KEY_RETURN=0x0D;\n");
	strcat(constants, "const int KEY_ENTER=0x0D;\n");
	strcat(constants, "const int KEY_SHIFT=0x10;\n");
	strcat(constants, "const int KEY_CONTROL=0x11;\n");
	strcat(constants, "const int KEY_MENU=0x12;\n");
	strcat(constants, "const int KEY_PAUSE=0x13;\n");
	strcat(constants, "const int KEY_CAPITAL=0x14;\n");
	strcat(constants, "const int KEY_KANA=0x15;\n");
	strcat(constants, "const int KEY_HANGUEL=0x15;\n");
	strcat(constants, "const int KEY_HANGUL=0x15;\n");
	strcat(constants, "const int KEY_JUNJA=0x17;\n");
	strcat(constants, "const int KEY_FINAL=0x18;\n");
	strcat(constants, "const int KEY_HANJA=0x19;\n");
	strcat(constants, "const int KEY_KANJI=0x19;\n");
	strcat(constants, "const int KEY_ESC=0x1B;\n");
	strcat(constants, "const int KEY_ESCAPE=0x1B;\n");
	strcat(constants, "const int KEY_CONVERT=0x1C;\n");
	strcat(constants, "const int KEY_NONCONVERT=0x1D;\n");
	strcat(constants, "const int KEY_ACCEPT=0x1E;\n");
	strcat(constants, "const int KEY_MODECHANGE=0x1F;\n");
	strcat(constants, "const int KEY_SPACE=0x20;\n");
	strcat(constants, "const int KEY_PRIOR=0x21;\n");
	strcat(constants, "const int KEY_NEXT=0x22;\n");
	strcat(constants, "const int KEY_END=0x23;\n");
	strcat(constants, "const int KEY_HOME=0x24;\n");
	strcat(constants, "const int KEY_LEFT=0x25;\n");
	strcat(constants, "const int KEY_UP=0x26;\n");
	strcat(constants, "const int KEY_RIGHT=0x27;\n");
	strcat(constants, "const int KEY_DOWN=0x28;\n");
	strcat(constants, "const int KEY_SELECT=0x29;\n");
	strcat(constants, "const int KEY_PRINT=0x2A;\n");
	strcat(constants, "const int KEY_EXECUT=0x2B;\n");
	strcat(constants, "const int KEY_SNAPSHOT=0x2C;\n");
	strcat(constants, "const int KEY_INSERT=0x2D;\n");
	strcat(constants, "const int KEY_DELETE=0x2E;\n");
	strcat(constants, "const int KEY_HELP=0x2F;\n");
	strcat(constants, "const int KEY_0=0x30;\n");
	strcat(constants, "const int KEY_1=0x31;\n");
	strcat(constants, "const int KEY_2=0x32;\n");
	strcat(constants, "const int KEY_3=0x33;\n");
	strcat(constants, "const int KEY_4=0x34;\n");
	strcat(constants, "const int KEY_5=0x35;\n");
	strcat(constants, "const int KEY_6=0x36;\n");
	strcat(constants, "const int KEY_7=0x37;\n");
	strcat(constants, "const int KEY_8=0x38;\n");
	strcat(constants, "const int KEY_9=0x39;\n");
	strcat(constants, "const int KEY_A=0x41;\n");
	strcat(constants, "const int KEY_B=0x42;\n");
	strcat(constants, "const int KEY_C=0x43;\n");
	strcat(constants, "const int KEY_D=0x44;\n");
	strcat(constants, "const int KEY_E=0x45;\n");
	strcat(constants, "const int KEY_F=0x46;\n");
	strcat(constants, "const int KEY_G=0x47;\n");
	strcat(constants, "const int KEY_H=0x48;\n");
	strcat(constants, "const int KEY_I=0x49;\n");
	strcat(constants, "const int KEY_J=0x4A;\n");
	strcat(constants, "const int KEY_K=0x4B;\n");
	strcat(constants, "const int KEY_L=0x4C;\n");
	strcat(constants, "const int KEY_M=0x4D;\n");
	strcat(constants, "const int KEY_N=0x4E;\n");
	strcat(constants, "const int KEY_O=0x4F;\n");
	strcat(constants, "const int KEY_P=0x50;\n");
	strcat(constants, "const int KEY_Q=0x51;\n");
	strcat(constants, "const int KEY_R=0x52;\n");
	strcat(constants, "const int KEY_S=0x53;\n");
	strcat(constants, "const int KEY_T=0x54;\n");
	strcat(constants, "const int KEY_U=0x55;\n");
	strcat(constants, "const int KEY_V=0x56;\n");
	strcat(constants, "const int KEY_W=0x57;\n");
	strcat(constants, "const int KEY_X=0x58;\n");
	strcat(constants, "const int KEY_Y=0x59;\n");
	strcat(constants, "const int KEY_Z=0x5A;\n");
	strcat(constants, "const int KEY_LWIN=0x5B;\n");
	strcat(constants, "const int KEY_RWIN=0x5C;\n");
	strcat(constants, "const int KEY_APPS=0x5D;\n");
	strcat(constants, "const int KEY_SLEEP=0x5F;\n");
	strcat(constants, "const int KEY_NUMPAD0=0x60;\n");
	strcat(constants, "const int KEY_NUMPAD1=0x61;\n");
	strcat(constants, "const int KEY_NUMPAD2=0x62;\n");
	strcat(constants, "const int KEY_NUMPAD3=0x63;\n");
	strcat(constants, "const int KEY_NUMPAD4=0x64;\n");
	strcat(constants, "const int KEY_NUMPAD5=0x65;\n");
	strcat(constants, "const int KEY_NUMPAD6=0x66;\n");
	strcat(constants, "const int KEY_NUMPAD7=0x67;\n");
	strcat(constants, "const int KEY_NUMPAD8=0x68;\n");
	strcat(constants, "const int KEY_NUMPAD9=0x69;\n");
	strcat(constants, "const int KEY_MULTIPLY=0x6A;\n");
	strcat(constants, "const int KEY_ADD=0x6B;\n");
	strcat(constants, "const int KEY_SEPARATOR=0x6C;\n");
	strcat(constants, "const int KEY_SUBTRACT=0x6D;\n");
	strcat(constants, "const int KEY_DECIMAL=0x6E;\n");
	strcat(constants, "const int KEY_DIVIDE=0x6F;\n");
	strcat(constants, "const int KEY_F1=0x70;\n");
	strcat(constants, "const int KEY_F2=0x71;\n");
	strcat(constants, "const int KEY_F3=0x72;\n");
	strcat(constants, "const int KEY_F4=0x73;\n");
	strcat(constants, "const int KEY_F5=0x74;\n");
	strcat(constants, "const int KEY_F6=0x75;\n");
	strcat(constants, "const int KEY_F7=0x76;\n");
	strcat(constants, "const int KEY_F8=0x77;\n");
	strcat(constants, "const int KEY_F9=0x78;\n");
	strcat(constants, "const int KEY_F10=0x79;\n");
	strcat(constants, "const int KEY_F11=0x7A;\n");
	strcat(constants, "const int KEY_F12=0x7B;\n");
	strcat(constants, "const int KEY_F13=0x7C;\n");
	strcat(constants, "const int KEY_F14=0x7D;\n");
	strcat(constants, "const int KEY_F15=0x7E;\n");
	strcat(constants, "const int KEY_F16=0x7F;\n");
	strcat(constants, "const int KEY_F17=0x80;\n");
	strcat(constants, "const int KEY_F18=0x81;\n");
	strcat(constants, "const int KEY_F19=0x82;\n");
	strcat(constants, "const int KEY_F20=0x83;\n");
	strcat(constants, "const int KEY_F21=0x84;\n");
	strcat(constants, "const int KEY_F22=0x85;\n");
	strcat(constants, "const int KEY_F23=0x86;\n");
	strcat(constants, "const int KEY_F24=0x87;\n");
	strcat(constants, "const int KEY_NUMLOCK=0x90;\n");
	strcat(constants, "const int KEY_SCROLL=0x91;\n");
	strcat(constants, "const int KEY_LSHIFT=0xA0;\n");
	strcat(constants, "const int KEY_RSHIFT=0xA1;\n");
	strcat(constants, "const int KEY_LCONTROL=0xA2;\n");
	strcat(constants, "const int KEY_RCONTROL=0xA3;\n");
	strcat(constants, "const int KEY_LMENU=0xA4;\n");
	strcat(constants, "const int KEY_RMENU=0xA5;\n");
	strcat(constants, "const int KEY_COMMA=0xBC;\n");
	strcat(constants, "const int KEY_PLUS=0xBB;\n");
	strcat(constants, "const int KEY_MINUS=0xBD;\n");
	strcat(constants, "const int KEY_PERIOD=0xBE;\n");
	strcat(constants, "const int KEY_ATTN=0xF6;\n");
	strcat(constants, "const int KEY_CRSEL=0xF7;\n");
	strcat(constants, "const int KEY_EXSEL=0xF8;\n");
	strcat(constants, "const int KEY_EREOF=0xF9;\n");
	strcat(constants, "const int KEY_PLAY=0xFA;\n");
	strcat(constants, "const int KEY_ZOOM=0xFB;\n");
	strcat(constants, "const int KEY_PA1=0xFD;\n");
	strcat(constants, "const int KEY_OEM_CLEAR=0xFE;\n");
	strcat(constants, "const int MF_FULLBRIGHT=1;\n");
	strcat(constants, "const int MF_FLATSHADING=2;\n");
	strcat(constants, "const int MF_FOG=4;\n");
	strcat(constants, "const int MF_NOCULL=8;\n");
	strcat(constants, "const int MF_WIREFRAME=16;\n");
	strcat(constants, "const int MF_NOZDEPTH=32;\n");
	strcat(constants, "const int MF_NOZWRITE=64;\n");
	strcat(constants, "const int MF_ANISOTROPIC=128;\n");
	strcat(constants, "const int MT_MODULATE=1;\n");
	strcat(constants, "const int MT_MODULATE2X=2;\n");
	strcat(constants, "const int MT_MODULATE4X=3;\n");
	strcat(constants, "const int MT_DETAIL=4;\n");
	strcat(constants, "const int MT_ADD=5;\n");
	strcat(constants, "const int MT_VERTEX_ALPHA=6;\n");
	strcat(constants, "const int MT_ALPHA=7;\n");
	strcat(constants, "const int MT_MASKED=8;\n");
	strcat(constants, "const int MT_REFLECTION=9;\n");
	strcat(constants, "const int MT_REFLECTION_ALPHA=10;\n");
	strcat(constants, "const int MT_NORMAL=11;\n");
	strcat(constants, "const int MT_PARALLAX=12;\n");
	strcat(constants, "const int CI_NULL=0;\n");
	strcat(constants, "const int CI_BBOX=1;\n");
	strcat(constants, "const int CI_TRIANGLES=2;\n");
	strcat(constants, "const int CI_OCTREE=3;\n");
	strcat(constants, "const int NT_EMPTY=0;\n");
	strcat(constants, "const int NT_BILLBOARD=1;\n");
	strcat(constants, "const int NT_BODY=2;\n");
	strcat(constants, "const int NT_CAMERA=3;\n");
	strcat(constants, "const int NT_EMITTER=4;\n");
	strcat(constants, "const int NT_LIGHT=5;\n");
	strcat(constants, "const int NT_MESH=6;\n");
	strcat(constants, "const int NT_MESH_OCTREE=7;\n");
	strcat(constants, "const int NT_TERRAIN=8;\n");
	strcat(constants, "const int NT_WATER=9;\n");
	strcat(constants, "const int PT_POINT=0;\n");
	strcat(constants, "const int PT_BOX=1;\n");
	strcat(constants, "const int CF_BACKBUFFER=1;\n");
	strcat(constants, "const int CF_ZBUFFER=2;\n");
	strcat(constants, "const int TS_VIEW=0;\n");
	strcat(constants, "const int TS_WORLD=1;\n");
	strcat(constants, "const int TS_PROJECTION=2;\n");
	strcat(constants, "const int PSF_11=0;\n");
	strcat(constants, "const int PSF_12=1;\n");
	strcat(constants, "const int PSF_13=2;\n");
	strcat(constants, "const int PSF_14=3;\n");
	strcat(constants, "const int PSF_20=4;\n");
	strcat(constants, "const int PSF_2A=5;\n");
	strcat(constants, "const int PSF_2B=6;\n");
	strcat(constants, "const int PSF_30=7;\n");
	strcat(constants, "const int VSF_11=0;\n");
	strcat(constants, "const int VSF_20=1;\n");
	strcat(constants, "const int VSF_2A=2;\n");
	strcat(constants, "const int VSF_30=3;\n");
	strcat(constants, "const int XML_NONE=0;\n");
	strcat(constants, "const int XML_ELEMENT=1;\n");
	strcat(constants, "const int XML_ELEMENTEND=2;\n");
	strcat(constants, "const int XML_TEXT=3;\n");
	strcat(constants, "const int XML_COMMENT=4;\n");
	strcat(constants, "const int XML_UNKNOWN=5;\n");
	engine->AddScriptSection("module", "constants", constants, strlen(constants), 0, true);
	free(constants);

	return true;
}
