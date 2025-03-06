#include "common.h"
#include <memory.h>

csFloat csSoundGetMasterVolume(float volume_);
csFloat csChannelGetMinDistance(int channel_);
csFloat csChannelGetMaxDistance(int channel_);
csFloat csChannelGetPan(int channel_);
csFloat csChannelX(int channel_);
csFloat csChannelY(int channel_);
csFloat csChannelZ(int channel_);
csFloat csChannelGetVolume(int channel_);
csFloat csBillboardWidth(int billboard_);
csFloat csBillboardHeight(int billboard_);
csFloat csEventA();
csFloat csEventB();
csFloat csEventC();
csFloat csFileReadFloat(int file_);
csFloat csJoyAxis(int id_, int axis_);
csFloat csMaterialGetShininess(int mat_);
csFloat csMaterialGetParam(int mat_);
csFloat csMaterialDataGetShininess(int mat_);
csFloat csMaterialDataGetParam(int mat_);
csFloat csMathFloor(float val_);
csFloat csMathCeil(float val_);
csFloat csMathAbs(float val_);
csFloat csMathSqr(float val_);
csFloat csMathSin(float val_);
csFloat csMathCos(float val_);
csFloat csMathTan(float val_);
csFloat csMathASin(float val_);
csFloat csMathACos(float val_);
csFloat csMathATan(float val_);
csFloat csMathATan2(float x_, float y_);
csFloat csMathExp(float val_);
csFloat csMathLog(float val_);
csFloat csMathLog10(float val_);
csFloat csMatrixElement(int matrix_, int row_, int column_);
csFloat csMeshWidth(int mesh_);
csFloat csMeshHeight(int mesh_);
csFloat csMeshDepth(int mesh_);
csFloat csNodeX(int node_, int absolute_);
csFloat csNodeY(int node_, int absolute_);
csFloat csNodeZ(int node_, int absolute_);
csFloat csNodePitch(int node_);
csFloat csNodeYaw(int node_);
csFloat csNodeRoll(int node_);
csFloat csNodeScaleX(int node_);
csFloat csNodeScaleY(int node_);
csFloat csNodeScaleZ(int node_);
csFloat csNodeWidth(int node_);
csFloat csNodeHeight(int node_);
csFloat csNodeDepth(int node_);
csFloat csParticleDataGetBoxWidth(int part_);
csFloat csParticleDataGetBoxHeight(int part_);
csFloat csParticleDataGetBoxDepth(int part_);
csFloat csParticleDataGetDirectionX(int part_);
csFloat csParticleDataGetDirectionY(int part_);
csFloat csParticleDataGetDirectionZ(int part_);
csFloat csParticleDataGetWidth(int part_);
csFloat csParticleDataGetHeight(int part_);
csFloat csParticleDataGetAffectorGravityX(int part_, int index_);
csFloat csParticleDataGetAffectorGravityY(int part_, int index_);
csFloat csParticleDataGetAffectorGravityZ(int part_, int index_);
csFloat csStringToFloat(const char* str_);
csFloat csVectorDotProduct(int vector_, int other_vector_);
csFloat csVectorDistance(int vector_, float x_, float y_, float z_);
csFloat csVectorDistanceSquared(int vector_, float x_, float y_, float z_);
csFloat csVectorLength(int vector_);
csFloat csVectorLengthSquared(int vector_);
csFloat csVectorX(int vector_);
csFloat csVectorY(int vector_);
csFloat csVectorZ(int vector_);

csInt csSoundGetMasterVolume_FWRAP(float volume_)
{
	int i;
	float f = csSoundGetMasterVolume(volume_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csChannelGetMinDistance_FWRAP(int channel_)
{
	int i;
	float f = csChannelGetMinDistance(channel_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csChannelGetMaxDistance_FWRAP(int channel_)
{
	int i;
	float f = csChannelGetMaxDistance(channel_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csChannelGetPan_FWRAP(int channel_)
{
	int i;
	float f = csChannelGetPan(channel_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csChannelX_FWRAP(int channel_)
{
	int i;
	float f = csChannelX(channel_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csChannelY_FWRAP(int channel_)
{
	int i;
	float f = csChannelY(channel_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csChannelZ_FWRAP(int channel_)
{
	int i;
	float f = csChannelZ(channel_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csChannelGetVolume_FWRAP(int channel_)
{
	int i;
	float f = csChannelGetVolume(channel_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csBillboardWidth_FWRAP(int billboard_)
{
	int i;
	float f = csBillboardWidth(billboard_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csBillboardHeight_FWRAP(int billboard_)
{
	int i;
	float f = csBillboardHeight(billboard_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csEventA_FWRAP()
{
	int i;
	float f = csEventA();
	memcpy(&i, &f, 4);
	return i;
}

csInt csEventB_FWRAP()
{
	int i;
	float f = csEventB();
	memcpy(&i, &f, 4);
	return i;
}

csInt csEventC_FWRAP()
{
	int i;
	float f = csEventC();
	memcpy(&i, &f, 4);
	return i;
}

csInt csFileReadFloat_FWRAP(int file_)
{
	int i;
	float f = csFileReadFloat(file_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csJoyAxis_FWRAP(int id_, int axis_)
{
	int i;
	float f = csJoyAxis(id_, axis_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMaterialGetShininess_FWRAP(int mat_)
{
	int i;
	float f = csMaterialGetShininess(mat_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMaterialGetParam_FWRAP(int mat_)
{
	int i;
	float f = csMaterialGetParam(mat_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMaterialDataGetShininess_FWRAP(int mat_)
{
	int i;
	float f = csMaterialDataGetShininess(mat_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMaterialDataGetParam_FWRAP(int mat_)
{
	int i;
	float f = csMaterialDataGetParam(mat_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathFloor_FWRAP(float val_)
{
	int i;
	float f = csMathFloor(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathCeil_FWRAP(float val_)
{
	int i;
	float f = csMathCeil(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathAbs_FWRAP(float val_)
{
	int i;
	float f = csMathAbs(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathSqr_FWRAP(float val_)
{
	int i;
	float f = csMathSqr(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathSin_FWRAP(float val_)
{
	int i;
	float f = csMathSin(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathCos_FWRAP(float val_)
{
	int i;
	float f = csMathCos(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathTan_FWRAP(float val_)
{
	int i;
	float f = csMathTan(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathASin_FWRAP(float val_)
{
	int i;
	float f = csMathASin(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathACos_FWRAP(float val_)
{
	int i;
	float f = csMathACos(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathATan_FWRAP(float val_)
{
	int i;
	float f = csMathATan(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathATan2_FWRAP(float x_, float y_)
{
	int i;
	float f = csMathATan2(x_, y_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathExp_FWRAP(float val_)
{
	int i;
	float f = csMathExp(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathLog_FWRAP(float val_)
{
	int i;
	float f = csMathLog(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMathLog10_FWRAP(float val_)
{
	int i;
	float f = csMathLog10(val_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMatrixElement_FWRAP(int matrix_, int row_, int column_)
{
	int i;
	float f = csMatrixElement(matrix_, row_, column_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMeshWidth_FWRAP(int mesh_)
{
	int i;
	float f = csMeshWidth(mesh_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMeshHeight_FWRAP(int mesh_)
{
	int i;
	float f = csMeshHeight(mesh_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csMeshDepth_FWRAP(int mesh_)
{
	int i;
	float f = csMeshDepth(mesh_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodeX_FWRAP(int node_, int absolute_)
{
	int i;
	float f = csNodeX(node_, absolute_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodeY_FWRAP(int node_, int absolute_)
{
	int i;
	float f = csNodeY(node_, absolute_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodeZ_FWRAP(int node_, int absolute_)
{
	int i;
	float f = csNodeZ(node_, absolute_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodePitch_FWRAP(int node_)
{
	int i;
	float f = csNodePitch(node_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodeYaw_FWRAP(int node_)
{
	int i;
	float f = csNodeYaw(node_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodeRoll_FWRAP(int node_)
{
	int i;
	float f = csNodeRoll(node_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodeScaleX_FWRAP(int node_)
{
	int i;
	float f = csNodeScaleX(node_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodeScaleY_FWRAP(int node_)
{
	int i;
	float f = csNodeScaleY(node_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodeScaleZ_FWRAP(int node_)
{
	int i;
	float f = csNodeScaleZ(node_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodeWidth_FWRAP(int node_)
{
	int i;
	float f = csNodeWidth(node_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodeHeight_FWRAP(int node_)
{
	int i;
	float f = csNodeHeight(node_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csNodeDepth_FWRAP(int node_)
{
	int i;
	float f = csNodeDepth(node_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csParticleDataGetBoxWidth_FWRAP(int part_)
{
	int i;
	float f = csParticleDataGetBoxWidth(part_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csParticleDataGetBoxHeight_FWRAP(int part_)
{
	int i;
	float f = csParticleDataGetBoxHeight(part_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csParticleDataGetBoxDepth_FWRAP(int part_)
{
	int i;
	float f = csParticleDataGetBoxDepth(part_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csParticleDataGetDirectionX_FWRAP(int part_)
{
	int i;
	float f = csParticleDataGetDirectionX(part_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csParticleDataGetDirectionY_FWRAP(int part_)
{
	int i;
	float f = csParticleDataGetDirectionY(part_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csParticleDataGetDirectionZ_FWRAP(int part_)
{
	int i;
	float f = csParticleDataGetDirectionZ(part_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csParticleDataGetWidth_FWRAP(int part_)
{
	int i;
	float f = csParticleDataGetWidth(part_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csParticleDataGetHeight_FWRAP(int part_)
{
	int i;
	float f = csParticleDataGetHeight(part_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csParticleDataGetAffectorGravityX_FWRAP(int part_, int index_)
{
	int i;
	float f = csParticleDataGetAffectorGravityX(part_, index_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csParticleDataGetAffectorGravityY_FWRAP(int part_, int index_)
{
	int i;
	float f = csParticleDataGetAffectorGravityY(part_, index_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csParticleDataGetAffectorGravityZ_FWRAP(int part_, int index_)
{
	int i;
	float f = csParticleDataGetAffectorGravityZ(part_, index_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csStringToFloat_FWRAP(const char* str_)
{
	int i;
	float f = csStringToFloat(str_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csVectorDotProduct_FWRAP(int vector_, int other_vector_)
{
	int i;
	float f = csVectorDotProduct(vector_, other_vector_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csVectorDistance_FWRAP(int vector_, float x_, float y_, float z_)
{
	int i;
	float f = csVectorDistance(vector_, x_, y_, z_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csVectorDistanceSquared_FWRAP(int vector_, float x_, float y_, float z_)
{
	int i;
	float f = csVectorDistanceSquared(vector_, x_, y_, z_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csVectorLength_FWRAP(int vector_)
{
	int i;
	float f = csVectorLength(vector_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csVectorLengthSquared_FWRAP(int vector_)
{
	int i;
	float f = csVectorLengthSquared(vector_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csVectorX_FWRAP(int vector_)
{
	int i;
	float f = csVectorX(vector_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csVectorY_FWRAP(int vector_)
{
	int i;
	float f = csVectorY(vector_);
	memcpy(&i, &f, 4);
	return i;
}

csInt csVectorZ_FWRAP(int vector_)
{
	int i;
	float f = csVectorZ(vector_);
	memcpy(&i, &f, 4);
	return i;
}


csInt csSoundGetMasterVolume_FPTR(float volume_)
{
	static float f;
	f = csSoundGetMasterVolume(volume_);
	return (int)&f;
}

csInt csChannelGetMinDistance_FPTR(int channel_)
{
	static float f;
	f = csChannelGetMinDistance(channel_);
	return (int)&f;
}

csInt csChannelGetMaxDistance_FPTR(int channel_)
{
	static float f;
	f = csChannelGetMaxDistance(channel_);
	return (int)&f;
}

csInt csChannelGetPan_FPTR(int channel_)
{
	static float f;
	f = csChannelGetPan(channel_);
	return (int)&f;
}

csInt csChannelX_FPTR(int channel_)
{
	static float f;
	f = csChannelX(channel_);
	return (int)&f;
}

csInt csChannelY_FPTR(int channel_)
{
	static float f;
	f = csChannelY(channel_);
	return (int)&f;
}

csInt csChannelZ_FPTR(int channel_)
{
	static float f;
	f = csChannelZ(channel_);
	return (int)&f;
}

csInt csChannelGetVolume_FPTR(int channel_)
{
	static float f;
	f = csChannelGetVolume(channel_);
	return (int)&f;
}

csInt csBillboardWidth_FPTR(int billboard_)
{
	static float f;
	f = csBillboardWidth(billboard_);
	return (int)&f;
}

csInt csBillboardHeight_FPTR(int billboard_)
{
	static float f;
	f = csBillboardHeight(billboard_);
	return (int)&f;
}

csInt csEventA_FPTR()
{
	static float f;
	f = csEventA();
	return (int)&f;
}

csInt csEventB_FPTR()
{
	static float f;
	f = csEventB();
	return (int)&f;
}

csInt csEventC_FPTR()
{
	static float f;
	f = csEventC();
	return (int)&f;
}

csInt csFileReadFloat_FPTR(int file_)
{
	static float f;
	f = csFileReadFloat(file_);
	return (int)&f;
}

csInt csJoyAxis_FPTR(int id_, int axis_)
{
	static float f;
	f = csJoyAxis(id_, axis_);
	return (int)&f;
}

csInt csMaterialGetShininess_FPTR(int mat_)
{
	static float f;
	f = csMaterialGetShininess(mat_);
	return (int)&f;
}

csInt csMaterialGetParam_FPTR(int mat_)
{
	static float f;
	f = csMaterialGetParam(mat_);
	return (int)&f;
}

csInt csMaterialDataGetShininess_FPTR(int mat_)
{
	static float f;
	f = csMaterialDataGetShininess(mat_);
	return (int)&f;
}

csInt csMaterialDataGetParam_FPTR(int mat_)
{
	static float f;
	f = csMaterialDataGetParam(mat_);
	return (int)&f;
}

csInt csMathFloor_FPTR(float val_)
{
	static float f;
	f = csMathFloor(val_);
	return (int)&f;
}

csInt csMathCeil_FPTR(float val_)
{
	static float f;
	f = csMathCeil(val_);
	return (int)&f;
}

csInt csMathAbs_FPTR(float val_)
{
	static float f;
	f = csMathAbs(val_);
	return (int)&f;
}

csInt csMathSqr_FPTR(float val_)
{
	static float f;
	f = csMathSqr(val_);
	return (int)&f;
}

csInt csMathSin_FPTR(float val_)
{
	static float f;
	f = csMathSin(val_);
	return (int)&f;
}

csInt csMathCos_FPTR(float val_)
{
	static float f;
	f = csMathCos(val_);
	return (int)&f;
}

csInt csMathTan_FPTR(float val_)
{
	static float f;
	f = csMathTan(val_);
	return (int)&f;
}

csInt csMathASin_FPTR(float val_)
{
	static float f;
	f = csMathASin(val_);
	return (int)&f;
}

csInt csMathACos_FPTR(float val_)
{
	static float f;
	f = csMathACos(val_);
	return (int)&f;
}

csInt csMathATan_FPTR(float val_)
{
	static float f;
	f = csMathATan(val_);
	return (int)&f;
}

csInt csMathATan2_FPTR(float x_, float y_)
{
	static float f;
	f = csMathATan2(x_, y_);
	return (int)&f;
}

csInt csMathExp_FPTR(float val_)
{
	static float f;
	f = csMathExp(val_);
	return (int)&f;
}

csInt csMathLog_FPTR(float val_)
{
	static float f;
	f = csMathLog(val_);
	return (int)&f;
}

csInt csMathLog10_FPTR(float val_)
{
	static float f;
	f = csMathLog10(val_);
	return (int)&f;
}

csInt csMatrixElement_FPTR(int matrix_, int row_, int column_)
{
	static float f;
	f = csMatrixElement(matrix_, row_, column_);
	return (int)&f;
}

csInt csMeshWidth_FPTR(int mesh_)
{
	static float f;
	f = csMeshWidth(mesh_);
	return (int)&f;
}

csInt csMeshHeight_FPTR(int mesh_)
{
	static float f;
	f = csMeshHeight(mesh_);
	return (int)&f;
}

csInt csMeshDepth_FPTR(int mesh_)
{
	static float f;
	f = csMeshDepth(mesh_);
	return (int)&f;
}

csInt csNodeX_FPTR(int node_, int absolute_)
{
	static float f;
	f = csNodeX(node_, absolute_);
	return (int)&f;
}

csInt csNodeY_FPTR(int node_, int absolute_)
{
	static float f;
	f = csNodeY(node_, absolute_);
	return (int)&f;
}

csInt csNodeZ_FPTR(int node_, int absolute_)
{
	static float f;
	f = csNodeZ(node_, absolute_);
	return (int)&f;
}

csInt csNodePitch_FPTR(int node_)
{
	static float f;
	f = csNodePitch(node_);
	return (int)&f;
}

csInt csNodeYaw_FPTR(int node_)
{
	static float f;
	f = csNodeYaw(node_);
	return (int)&f;
}

csInt csNodeRoll_FPTR(int node_)
{
	static float f;
	f = csNodeRoll(node_);
	return (int)&f;
}

csInt csNodeScaleX_FPTR(int node_)
{
	static float f;
	f = csNodeScaleX(node_);
	return (int)&f;
}

csInt csNodeScaleY_FPTR(int node_)
{
	static float f;
	f = csNodeScaleY(node_);
	return (int)&f;
}

csInt csNodeScaleZ_FPTR(int node_)
{
	static float f;
	f = csNodeScaleZ(node_);
	return (int)&f;
}

csInt csNodeWidth_FPTR(int node_)
{
	static float f;
	f = csNodeWidth(node_);
	return (int)&f;
}

csInt csNodeHeight_FPTR(int node_)
{
	static float f;
	f = csNodeHeight(node_);
	return (int)&f;
}

csInt csNodeDepth_FPTR(int node_)
{
	static float f;
	f = csNodeDepth(node_);
	return (int)&f;
}

csInt csParticleDataGetBoxWidth_FPTR(int part_)
{
	static float f;
	f = csParticleDataGetBoxWidth(part_);
	return (int)&f;
}

csInt csParticleDataGetBoxHeight_FPTR(int part_)
{
	static float f;
	f = csParticleDataGetBoxHeight(part_);
	return (int)&f;
}

csInt csParticleDataGetBoxDepth_FPTR(int part_)
{
	static float f;
	f = csParticleDataGetBoxDepth(part_);
	return (int)&f;
}

csInt csParticleDataGetDirectionX_FPTR(int part_)
{
	static float f;
	f = csParticleDataGetDirectionX(part_);
	return (int)&f;
}

csInt csParticleDataGetDirectionY_FPTR(int part_)
{
	static float f;
	f = csParticleDataGetDirectionY(part_);
	return (int)&f;
}

csInt csParticleDataGetDirectionZ_FPTR(int part_)
{
	static float f;
	f = csParticleDataGetDirectionZ(part_);
	return (int)&f;
}

csInt csParticleDataGetWidth_FPTR(int part_)
{
	static float f;
	f = csParticleDataGetWidth(part_);
	return (int)&f;
}

csInt csParticleDataGetHeight_FPTR(int part_)
{
	static float f;
	f = csParticleDataGetHeight(part_);
	return (int)&f;
}

csInt csParticleDataGetAffectorGravityX_FPTR(int part_, int index_)
{
	static float f;
	f = csParticleDataGetAffectorGravityX(part_, index_);
	return (int)&f;
}

csInt csParticleDataGetAffectorGravityY_FPTR(int part_, int index_)
{
	static float f;
	f = csParticleDataGetAffectorGravityY(part_, index_);
	return (int)&f;
}

csInt csParticleDataGetAffectorGravityZ_FPTR(int part_, int index_)
{
	static float f;
	f = csParticleDataGetAffectorGravityZ(part_, index_);
	return (int)&f;
}

csInt csStringToFloat_FPTR(const char* str_)
{
	static float f;
	f = csStringToFloat(str_);
	return (int)&f;
}

csInt csVectorDotProduct_FPTR(int vector_, int other_vector_)
{
	static float f;
	f = csVectorDotProduct(vector_, other_vector_);
	return (int)&f;
}

csInt csVectorDistance_FPTR(int vector_, float x_, float y_, float z_)
{
	static float f;
	f = csVectorDistance(vector_, x_, y_, z_);
	return (int)&f;
}

csInt csVectorDistanceSquared_FPTR(int vector_, float x_, float y_, float z_)
{
	static float f;
	f = csVectorDistanceSquared(vector_, x_, y_, z_);
	return (int)&f;
}

csInt csVectorLength_FPTR(int vector_)
{
	static float f;
	f = csVectorLength(vector_);
	return (int)&f;
}

csInt csVectorLengthSquared_FPTR(int vector_)
{
	static float f;
	f = csVectorLengthSquared(vector_);
	return (int)&f;
}

csInt csVectorX_FPTR(int vector_)
{
	static float f;
	f = csVectorX(vector_);
	return (int)&f;
}

csInt csVectorY_FPTR(int vector_)
{
	static float f;
	f = csVectorY(vector_);
	return (int)&f;
}

csInt csVectorZ_FPTR(int vector_)
{
	static float f;
	f = csVectorZ(vector_);
	return (int)&f;
}


