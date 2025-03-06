#ifndef _ENGINE_H_
#define _ENGINE_H_

//-----------------------------------------------
//	Includes
//-----------------------------------------------

// Common header
#include "common.h"

//Include Windows header
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

// Include Cocoa header
//#ifdef __APPLE__
//#include <AppKit/AppKit.h>
//#endif

//Include IrrLicht
#include <irrlicht.h>
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

// Include IrrKlang
#include <irrKlang.h>
using namespace audio;

// Include plib stuff (used for joystick support)
#if defined(_WIN32) && !defined(__GNUC__)
#include "js.h"
#endif

// Include STL stuff
#include <string>
#include <vector>

// Include STDC stuff
#include <time.h>

//-----------------------------------------------
//	Defines
//-----------------------------------------------

// Display
#define CSDF_FULLSCREEN 1
#define CSDF_VSYNC      2
#define CSDF_ANTIALIAS  4
#define CSDF_OPENGL     65536

// Events
#define CSEV_INIT             101
#define CSEV_FINISH           102
#define CSEV_FRAME            103
#define CSEV_DISPLAY_OPEN     201
#define CSEV_KEY_HIT          301
#define CSEV_KEY_RELEASE      302
#define CSEV_MOUSE_MOVE       401
#define CSEV_MOUSE_HIT        402
#define CSEV_MOUSE_RELEASE    403
#define CSEV_GADGET_ACTION    501
#define CSEV_GADGET_ENTER     502
#define CSEV_GADGET_EXIT      503
#define CSEV_GADGET_LOSTFOCUS 504

// Gadget types
#define GT_BUTTON 1
#define GT_CHECKBOX 2
#define GT_COMBOBOX 3
#define GT_EDITBOX 4
#define GT_GROUP 5
#define GT_LISTBOX 6
#define GT_MENU 7
#define GT_SCROLLBAR 8
#define GT_TABBER 9
#define GT_TEXT 10
#define GT_TEXTURE 11
#define GT_TOOLBAR 12
#define GT_WINDOW 13

// Material flags
#define CSMF_FULLBRIGHT 1
#define CSMF_FLATSHADING 2
#define CSMF_FOG 4
#define CSMF_NOCULL 8
#define CSMF_WIREFRAME 16
#define CSMF_NOZDEPTH 32
#define CSMF_NOZWRITE 64
#define CSMF_ANISOTROPIC 128

// Material types
#define CSMT_MODULATE 1
#define CSMT_MODULATE2X 2
#define CSMT_MODULATE4X 3
#define CSMT_DETAIL 4
#define CSMT_ADD 5
#define CSMT_VERTEX_ALPHA 6
#define CSMT_ALPHA 7
#define CSMT_MASKED 8
#define CSMT_REFLECTION 9
#define CSMT_REFLECTION_ALPHA 10
#define CSMT_NORMAL 11
#define CSMT_PARALLAX 12

// Light types
#define CSLT_POINT         0
#define CSLT_DIRECTIONAL   1

// Node types
#define CSNT_EMPTY        0
#define CSNT_BILLBOARD    1
#define CSNT_BODY         2
#define CSNT_CAMERA       3
#define CSNT_EMITTER      4
#define CSNT_LIGHT        5
#define CSNT_MESH         6
#define CSNT_MESH_OCTREE  7
#define CSNT_TERRAIN      8
#define CSNT_WATER        9

// Body types
#define CSBT_NULL		0
#define CSBT_BOX		1
#define CSBT_SPHERE		2
#define CSBT_CONE		3
#define CSBT_CAPSULE	4
#define CSBT_CYLINDER	5

//-----------------------------------------------
//  Classes
//-----------------------------------------------

struct csMatrix;  // Forward declaration
struct csVector;  // Forward declaration

struct csAffector
{
	char type;  // 0=fade-out, 1=gravity
	int color;
	int time;
	float grav[3];
};

struct csEffectParam
{
	int type;
	std::string name;
	union {
		ITexture* tex;
		bool boolval;
		int intval;
		float floatval;
		csVector* vector;
		csMatrix* matrix;
	};
};

class csEffectCallBack;
struct csEffect
{
	int               mat_type;
	csEffectCallBack* callback;
};

class csEventReceiver : public IEventReceiver
{
	virtual bool OnEvent(const SEvent& event);
};

struct csEvent
{
	csEvent();
	void clear();
	int id;
	int from;
	int to;
	float a;
	float b;
	float c;
	std::string str;
};

struct csFile
{
	bool				isreader;
	IReadFile*	reader;
	IWriteFile*	writer;
};

struct csMaterialData
{
	static std::vector<csMaterialData*> list;

	std::string name;
	int type;
	int flags;
	std::string textures[2];
	int ambient;
	int diffuse;
	int emissive;
	int specular;
	float shininess;
	float param;

	csMaterialData(const char* name);
	~csMaterialData();

};

struct csMatrix
{
	float m[16];
};

struct csNodeProperty
{
	std::string name;
	std::string value;
};

struct csCameraData
{
	csCameraData();

	float vx1, vy1, vx2, vy2;
	ITexture*	rendertarget;
	int			clearflags;
	int			clearcolor;
};

struct csNodeData
{
	csNodeData(int type, ISceneNode* node);
	~csNodeData();
	
	int type;
	ISceneNode* node;

	// Physics information
	bool usephysics;
	int bodytype;
	void* body;
	
	std::vector<csNodeProperty> properties;
	
	void* data;	// Used for example to check if a mesh node has a shadow node, or to store specific camera information
};

struct csParticleData
{
	csParticleData(const char* name);
	~csParticleData();
	std::string				name;
	std::string				material;
	int						type;
	vector3df				box;
	vector3df				direction;
	int						rate[2];
	int						startColor[2];
	int						lifeTime[2];
	int						maxAngle;
	float					size[2];
	std::vector<csAffector>	affectors;
};

struct csShaderConstant
{
	int			type;		// Type of constant (one of the above)
	std::string	name;		// Name of the constant
	float*		data;		// Beginning of data to send
	int			size;		// Size of data to send
	int			start_reg;	// First register to set (only for LowLevel shaders)
};

class csShaderCallBack;
struct csShader
{
	int					mat_type;
	bool				low_level;
	csShaderCallBack*	callback;
};

struct csVector
{
	float x, y, z;
};

struct csXMLFile
{
	bool isreader;
	IXMLReader* reader;
	IXMLWriter* writer;
};

//-----------------------------------------------
//  Global variables
//-----------------------------------------------

// Core
#ifdef COLDSTEEL_DEMO
extern float demo_time;
#endif

// Audio
extern ISoundEngine* AudioDevice;

// Display
extern IrrlichtDevice* Device;
extern bool displayClosed;

// Dir
/*#ifndef COLDSTEEL_LITE
extern std::vector<std::string> zip_list;
#endif*/

// Draw
extern int vx, vy, vw, vh;

// Input
extern int mousex, mousey, mousexspeed, mouseyspeed;
extern bool mousehit[3], mousedown[3], mousebutton, mousereleased;
extern bool keyhit[KEY_KEY_CODES_COUNT], keydown[KEY_KEY_CODES_COUNT];
extern int key, keyreleased;

//-----------------------------------------------
//  Functions
//-----------------------------------------------

// Audio
csVoid csListenerUpdate(ISceneNode* node);
csVoid csSoundSetMasterVolume(float volume);
csFloat csSoundGetMasterVolume(float volume);
csInt csSoundLoad(const char* file);
csVoid csSoundFree(ISoundSource* sound);
csInt csSoundPlay2D(ISoundSource* sound, int loop);
csInt csSoundPlay3D(ISoundSource* sound, float x, float y, float z, int loop);
csInt csSoundIsPlaying(ISoundSource* sound);
csInt csChannelPaused(ISound* channel);
csInt csChannelFinished(ISound* channel);
csInt csChannelLooped(ISound* channel);
csFloat csChannelGetMinDistance(ISound* channel);
csFloat csChannelGetMaxDistance(ISound* channel);
csFloat csChannelGetPan(ISound* channel);
csInt csChannelGetPlayPosition(ISound* channel);
csFloat csChannelX(ISound* channel);
csFloat csChannelY(ISound* channel);
csFloat csChannelZ(ISound* channel);
csFloat csChannelGetVolume(ISound* channel);
csVoid csChannelPause(ISound* channel);
csVoid csChannelResume(ISound* channel);
csVoid csChannelSetDistance(ISound* channel, float min, float max);
csVoid csChannelSetPan(ISound* channel, float pan);
csVoid csChannelSetPosition(ISound* channel, float x, float y, float z);
csVoid csChannelSetVolume(ISound* channel, float volume);
csVoid csChannelStop(ISound* channel);

// Billboard
csInt csBillboardNode(ISceneNode* parent);
csVoid csBillboardResize(IBillboardSceneNode* n, float width, float height);
csFloat csBillboardWidth(IBillboardSceneNode* n);
csFloat csBillboardHeight(IBillboardSceneNode* n);

// Body
void InitPhysics();
void CleanPhysics();
void UpdatePhysics(float timestep);
void PhysicsGravity(float x, float y, float z);

// Camera
csInt csCameraNode(ISceneNode* parent);
csVoid csCameraViewport(ICameraSceneNode* cam, float x1, float y1, float x2, float y2);
csVoid csCameraRange(ICameraSceneNode* cam, float near_, float far_);
csVoid csCameraFov(ICameraSceneNode* cam, float fov);
csVoid csCameraAspectRatio(ICameraSceneNode* cam, float ratio);
csVoid csCameraProjection(ICameraSceneNode* cam, float width, float height, float near_, float far_, int ortho);
csVoid csCameraLine(ICameraSceneNode* cam, int x, int y, csVector* vec_line_a, csVector* vec_line_b);
csInt csCameraPickNode(ICameraSceneNode* cam, int x, int y, int group);
csVoid csCameraToScreen(ICameraSceneNode* cam, float x, float y, float z, csVector* vec_out);
csVoid csCameraRenderTarget(ICameraSceneNode* cam, ITexture* texture);
csVoid csCameraClearFlags(ICameraSceneNode* cam, int flags, int color);

// Collision
csVoid csCollisionSlide(ISceneNode* n, float pos_x, float pos_y, float pos_z, float dest_x, float dest_y, float dest_z, float rad_x, float rad_y, float rad_z, csVector* vec_pos, csVector* vec_tri1, csVector* vec_tri2, csVector* vec_tri3);
csInt csCollisionLinePick(ISceneNode* n, float pos_x, float pos_y, float pos_z, float dest_x, float dest_y, float dest_z, csVector* vec_pos, csVector* vec_tri1, csVector* vec_tri2, csVector* vec_tri3);
csInt csCollisionLineNode(float pos_x, float pos_y, float pos_z, float dest_x, float dest_y, float dest_z, int group);

// Core
csVoid csCoreInit();
csVoid csCoreFinish();
csVoid csCoreMessage(const char* msg, int error);
csInt csCoreTimer();

// Dir
csVoid csPackageAdd(const char* pak);
csInt csDirList(const char* dir);
csVoid csDirClose(IFileList* list);
csInt csDirFileCount(IFileList* list);
csString csDirFileName(IFileList* list, int index);
csInt csDirFileIsDir(IFileList* list, int index);

// Display
csVoid csDisplayOpen(int width, int height, int depth, int flags, int win);
csVoid csDisplayClose();
csVoid csDisplayCaption(const char* caption);
csInt csDisplayClosed();
csInt csDisplayWidth();
csInt csDisplayHeight();
csInt csDisplayFps();
csInt csDisplayFeature(int feature);
csVoid csDisplayResize(int width, int height);
csInt csDisplayActive();
csVoid csDisplayScreenshot(const char* file);

// Draw
csInt csGetColor(int red, int green, int blue, int alpha);
csInt csGetRed(int color);
csInt csGetGreen(int color);
csInt csGetBlue(int color);
csInt csGetAlpha(int color);
csVoid csSetColor(int color);
csVoid csViewport(int x, int y, int w, int h);
csVoid csDrawLine(int x, int y, int x1, int y1);
csVoid csDrawRect(int x, int y, int w, int h);
csVoid csDrawTexture(ITexture* tex, int x, int y);
csVoid csDrawTextureAdvanced(ITexture* tex, int x, int y, int width, int height, int rect_x, int rect_y, int rect_width, int rect_height, int color, int usealpha);
csVoid csDrawText(IGUIFont* font, const char* text, int x, int y);
csInt csTextWidth(IGUIFont* font, const char* text);
csInt csTextHeight(IGUIFont* font, const char* text);

// Effect
csInt csEffectRegister(const char* effect, int base_material);
csInt csEffectRegisterFile(const char* effect, int base_material);
csVoid csEffectSetTechnique(csEffect* eff, const char* name);
csVoid csEffectSetTexture(csEffect* eff, const char* name, ITexture* tex);
csVoid csEffectSetBool(csEffect* eff, const char* name, int boolval);
csVoid csEffectSetInt(csEffect* eff, const char* name, int intval);
csVoid csEffectSetFloat(csEffect* eff, const char* name, float floatval);
csVoid csEffectSetVector(csEffect* eff, const char* name, csVector* vector);
csVoid csEffectSetMatrix(csEffect* eff, const char* name, csMatrix* matrix);

// Emitter
csInt csEmitterNode(csParticleData* part, ISceneNode* parent);
csVoid csEmitterAddFadeOutAffector(IParticleSystemSceneNode* n, int color, int time);
csVoid csEmitterAddGravityAffector(IParticleSystemSceneNode* n, float grav_x, float grav_y, float grav_z, int time);
csVoid csEmitterRemoveAffectors(IParticleSystemSceneNode* n);
csVoid csEmitterGlobal(IParticleSystemSceneNode* n, int global);

// Event
void CleanEvents();
csInt csEventGet();
csInt csEventPoll();
csVoid csEventPost(int id, int from, int to, float a, float b, float c, const char* str);
csInt csEventId();
csInt csEventFrom();
csInt csEventTo();
csFloat csEventA();
csFloat csEventB();
csFloat csEventC();
csString csEventData();

// File System
csInt csFileRead(const char* file);
csInt csFileWrite(const char* file);
csVoid csFileClose(csFile* file);
csInt csFileSize(csFile* file);
csInt csFilePos(csFile* file);
csVoid csFileSeek(csFile* file, int pos, int relative);
csInt csFileReadByte(csFile* file);
csInt csFileReadShort(csFile* file);
csInt csFileReadInt(csFile* file);
csFloat csFileReadFloat(csFile* file);
csString csFileReadString(csFile* file);
csVoid csFileReadBytes(csFile* file, int buffer, int size);
csVoid csFileWriteByte(csFile* file, int val);
csVoid csFileWriteShort(csFile* file, int val);
csVoid csFileWriteInt(csFile* file, int val);
csVoid csFileWriteFloat(csFile* file, float val);
csVoid csFileWriteString(csFile* file, const char* str);
csVoid csFileWriteBytes(csFile* file, int buffer, int size);
csString csFileGetExt(const char* str);
csString csFileGetDir(const char* str);
csString csFileStripExt(const char* str);
csString csFileStripDir(const char* str);

// Font
csInt csFontLoad(const char* file);
csVoid csFontFree(IGUIFont* font);

// Gadget
csVoid csGadgetFree(IGUIElement* gadget);
csInt csGadgetType(IGUIElement* gadget);
csVoid csGadgetEnable(IGUIElement* gadget, int state);
csString csGadgetGetText(IGUIElement* gadget);
csVoid csGadgetSetText(IGUIElement* gadget, const char* text);
csVoid csGadgetShape(IGUIElement* gadget, int x, int y, int w, int h);
csVoid csGadgetVisible(IGUIElement* gadget, int state);
csInt csGadgetChildren(IGUIElement* gadget);
csInt csGadgetChild(IGUIElement* gadget, int index);
csInt csGadgetParent(IGUIElement* gadget);
csVoid csGadgetSetImage(IGUIElement* gadget, ITexture* img, int x, int y, int width, int height, int alpha);
csVoid csGadgetSetFont(IGUIElement* gadget, IGUIFont* font);
csVoid csGadgetSetColor(IGUIElement* gadget, int color, int override_);
csVoid csGadgetSetState(IGUIElement* gadget, int state);
csInt csGadgetGetState(IGUIElement* gadget);
csInt csGadgetAddItem(IGUIElement* gadget, const char* text, int id);
csInt csGadgetGetItemId(IGUIElement* gadget, int index);
csString csGadgetGetItemText(IGUIElement* gadget, int index);
csInt csGadgetSelectedItem(IGUIElement* gadget);
csVoid csGadgetSelectItem(IGUIElement* gadget, int index);
csInt csGadgetCountItems(IGUIElement* gadget);
csVoid csGadgetSetItemText(IGUIElement* gadget, int index, const char* text);
csVoid csGadgetEnableItem(IGUIElement* gadget, int index, int enable);
csVoid csGadgetRemoveItem(IGUIElement* gadget, int index);
csVoid csGadgetRemoveItems(IGUIElement* gadget);

// Gui
csInt csGuiButton(int x, int y, int w, int h, IGUIElement* parent);
csInt csGuiCheckBox(int x, int y, int w, int h, IGUIElement* parent);
csInt csGuiComboBox(int x, int y, int w, int h, IGUIElement* parent);
csInt csGuiContextMenu(int x, int y, int w, int h, IGUIElement* parent);
csInt csGuiEditBox(int x, int y, int w, int h, IGUIElement* parent, int maxchars, int border);
csInt csGuiGroup(int x, int y, int w, int h, IGUIElement* parent);
csInt csGuiListBox(int x, int y, int w, int h, IGUIElement* parent, int draw_background);
csInt csGuiMenu(IGUIElement* parent);
csInt csGuiMessageBox(IGUIElement* parent, const char* caption, const char* text, int flags);
csInt csGuiScrollBar(int x, int y, int w, int h, IGUIElement* parent, int horizontal, int max, int step);
csInt csGuiTabber(int x, int y, int w, int h, IGUIElement* parent, int flags);
csInt csGuiText(int x, int y, int w, int h, IGUIElement* parent, int flags);
csInt csGuiTexture(int x, int y, IGUIElement* parent, ITexture* tex, int use_alpha);
csInt csGuiToolbar(IGUIElement* parent);
csInt csGuiWindow(int x, int y, int w, int h, IGUIElement* parent, int modal);
csVoid csGuiDraw();

// Input
csVoid csMousePosition(int x, int y);
csVoid csMouseHide(int hide);
csInt csMouseX();
csInt csMouseY();
//csInt csMouseMoveX();
//csInt csMouseMoveY();
csInt csMouseHit(int button);
csInt csMouseDown(int button);
csInt csMouseGet();
csInt csMouseReleased();
csInt csKeyHit(int key);
csInt csKeyDown(int key);
csInt csKeyGet();
csInt csKeyReleased();

// Joystick
int csJoyInit(int id);
void csJoyFinish(int id);
csString csJoyName(int id);
csInt csJoyButton(int id, int button);
csFloat csJoyAxis(int id, int axis);
csInt csJoyNumAxes(int id);

// Light
csInt csLightNode(ISceneNode* parent);
csVoid csLightType(ILightSceneNode* n, int type);
csVoid csLightRadius(ILightSceneNode* n, float radius);
csVoid csLightAmbient(ILightSceneNode* n, int color);
csVoid csLightDiffuse(ILightSceneNode* n, int color);
csVoid csLightSpecular(ILightSceneNode* n, int color);

// Material
E_MATERIAL_TYPE getIrrLichtMaterialType(int type);
void setMaterialFlag(SMaterial* mat, int flag, int state);
csInt csMaterialCreate(const char* name);
csInt csMaterialFromData(csMaterialData* data);
csInt csMaterialToData(SMaterial* mat);
csVoid csMaterialFree(SMaterial* mat);
csVoid csMaterialSetType(SMaterial* mat, int newtype);
csVoid csMaterialSetFlags(SMaterial* mat, int flags);
csVoid csMaterialSetTexture(SMaterial* mat, ITexture* tex, int layer);
csVoid csMaterialSetAmbient(SMaterial* mat, int color);
csVoid csMaterialSetDiffuse(SMaterial* mat, int color);
csVoid csMaterialSetEmissive(SMaterial* mat, int color);
csVoid csMaterialSetSpecular(SMaterial* mat, int color);
csVoid csMaterialSetShininess(SMaterial* mat, float shininess);
csVoid csMaterialSetParam(SMaterial* mat, float param);
csString csMaterialGetName(SMaterial* mat);
csInt csMaterialGetType(SMaterial* mat);
csInt csMaterialGetFlags(SMaterial* mat);
csInt csMaterialGetTexture(SMaterial* mat, int layer);
csInt csMaterialGetAmbient(SMaterial* mat);
csInt csMaterialGetDiffuse(SMaterial* mat);
csInt csMaterialGetEmissive(SMaterial* mat);
csInt csMaterialGetSpecular(SMaterial* mat);
csFloat csMaterialGetShininess(SMaterial* mat);
csFloat csMaterialGetParam(SMaterial* mat);

// Material Data
void CleanMaterialDatas();
csInt csMaterialDataCreate(const char* name);
csInt csMaterialDataLoad(const char* file);
csVoid csMaterialDataSave(csMaterialData* mat, const char* file, const char* rel_path);
csVoid csMaterialDataFree(csMaterialData* mat);
csInt csMaterialDataFind(const char* name);
csVoid csMaterialDataSetType(csMaterialData* mat, int newtype);
csVoid csMaterialDataSetFlags(csMaterialData* mat, int flags);
csVoid csMaterialDataSetTexture(csMaterialData* mat, const char* name, int layer);
csVoid csMaterialDataSetAmbient(csMaterialData* mat, int color);
csVoid csMaterialDataSetDiffuse(csMaterialData* mat, int color);
csVoid csMaterialDataSetEmissive(csMaterialData* mat, int color);
csVoid csMaterialDataSetSpecular(csMaterialData* mat, int color);
csVoid csMaterialDataSetShininess(csMaterialData* mat, float shininess);
csVoid csMaterialDataSetParam(csMaterialData* mat, float param);
csString csMaterialDataGetName(csMaterialData* mat);
csInt csMaterialDataGetType(csMaterialData* mat);
csInt csMaterialDataGetFlags(csMaterialData* mat);
csString csMaterialDataGetTexture(csMaterialData* mat, int layer);
csInt csMaterialDataGetAmbient(csMaterialData* mat);
csInt csMaterialDataGetDiffuse(csMaterialData* mat);
csInt csMaterialDataGetEmissive(csMaterialData* mat);
csInt csMaterialDataGetSpecular(csMaterialData* mat);
csFloat csMaterialDataGetShininess(csMaterialData* mat);
csFloat csMaterialDataGetParam(csMaterialData* mat);

// Math
csFloat csMathFloor(float val);
csFloat csMathCeil(float val);
csFloat csMathAbs(float val);
csFloat csMathSqr(float val);
csFloat csMathSin(float val);
csFloat csMathCos(float val);
csFloat csMathTan(float val);
csFloat csMathASin(float val);
csFloat csMathACos(float val);
csFloat csMathATan(float val);
csFloat csMathATan2(float x, float y);
csFloat csMathExp(float val);
csFloat csMathLog(float val);
csFloat csMathLog10(float val);
csInt csMathRand(int min, int max);
csVoid csMathRandSeed(int seed);

// Matrix
void CleanMatrices();
csInt csMatrixCreate();
csVoid csMatrixFree(csMatrix* mat);
csVoid csMatrixAdd(csMatrix* mat, csMatrix* matrix2);
csVoid csMatrixCopy(csMatrix* mat, csMatrix* matrix2);
csVoid csMatrixDiv(csMatrix* mat, csMatrix* matrix2);
csFloat csMatrixElement(csMatrix* mat, int row, int column);
csInt csMatrixEqual(csMatrix* mat, csMatrix* matrix2);
csVoid csMatrixGetRotation(csMatrix* mat, csVector* vector);
csVoid csMatrixGetTranslation(csMatrix* mat, csVector* vector);
csVoid csMatrixIdentity(csMatrix* mat);
csVoid csMatrixInterpolate(csMatrix* mat, csMatrix* matrix2, float time);
csInt csMatrixInvert(csMatrix* mat);
csVoid csMatrixMul(csMatrix* mat, csMatrix* matrix2);
csVoid csMatrixSet(csMatrix* mat, int row, int column, float val);
csVoid csMatrixSetRotation(csMatrix* mat, csVector* vector);
csVoid csMatrixSetScale(csMatrix* mat, csVector* vector);
csVoid csMatrixSetTranslation(csMatrix* mat, csVector* vector);
csVoid csMatrixSub(csMatrix* mat, csMatrix* matrix2);
csVoid csMatrixTranspose(csMatrix* mat);

// Mesh
csInt csMeshLoad(const char* file);
csInt csMeshTerrainLoad(const char* heightmap);
csVoid csMeshFree(IAnimatedMesh* mesh);
csInt csMeshNode(IAnimatedMesh* mesh, ISceneNode* parent, int col_info, int tangent_mesh);
csInt csMeshOctreeNode(IAnimatedMesh* mesh, ISceneNode* parent, int col_info, int tangent_mesh);
csVoid csMeshScale(IAnimatedMesh* mesh, float sx, float sy, float sz);
csVoid csMeshFlip(IAnimatedMesh* mesh);
csVoid csMeshUpdateNormals(IAnimatedMesh* mesh);
csVoid csMeshVerticesColor(IAnimatedMesh* mesh, int color, int change_alpha);
csVoid csMeshPlanarMapping(IAnimatedMesh* mesh, float resolution);
csFloat csMeshWidth(IAnimatedMesh* mesh);
csFloat csMeshHeight(IAnimatedMesh* mesh);
csFloat csMeshDepth(IAnimatedMesh* mesh);

// Node
ISceneNode* NewNode(int type, ISceneNode* parent, const char* str = "", int data1 = 0, int data2 = 0);
csInt csNodeEmpty(ISceneNode* parent);
csVoid csNodeFree(ISceneNode* n);
csInt csNodeType(ISceneNode* n);
csVoid csNodePosition(ISceneNode* n, float x, float y, float z);
csVoid csNodeMove(ISceneNode* n, float x, float y, float z);
csVoid csNodeRotate(ISceneNode* n, float pitch, float yaw, float roll);
csVoid csNodeTurn(ISceneNode* n, float pitch, float yaw, float roll);
csVoid csNodeScale(ISceneNode* n, float x, float y, float z);
csFloat csNodeX(ISceneNode* n, int absolute);
csFloat csNodeY(ISceneNode* n, int absolute);
csFloat csNodeZ(ISceneNode* n, int absolute);
csFloat csNodePitch(ISceneNode* n);
csFloat csNodeYaw(ISceneNode* n);
csFloat csNodeRoll(ISceneNode* n);
csFloat csNodeScaleX(ISceneNode* n);
csFloat csNodeScaleY(ISceneNode* n);
csFloat csNodeScaleZ(ISceneNode* n);
csFloat csNodeWidth(ISceneNode* n);
csFloat csNodeHeight(ISceneNode* n);
csFloat csNodeDepth(ISceneNode* n);
csVoid csNodeCastShadow(ISceneNode* n, int shadow);
csVoid csNodeHide(ISceneNode* n, int state);
csInt csNodeMaterials(ISceneNode* n);
csInt csNodeGetMaterial(ISceneNode* n, int mat_index);
csVoid csNodeSetMaterial(ISceneNode* n, SMaterial* mat, int mat_index);
csVoid csNodeSetMaterialData(ISceneNode* n, csMaterialData* mat, int mat_index);
csVoid csNodeSetMaterialFast(ISceneNode* n, int index, int type, int flags, ITexture* tex1, ITexture* tex2);
csVoid csNodeSetMaterialFlag(ISceneNode* n, int index, int flag, int state);
csVoid csNodeSetName(ISceneNode* n, const char* name);
csString csNodeGetName(ISceneNode* n);
csVoid csNodeSetPickGroup(ISceneNode* n, int group);
csVoid csNodeSetProperty(ISceneNode* n, const char* name, const char* value);
csInt csNodeProperties(ISceneNode* n);
csInt csNodeFindProperty(ISceneNode* n, const char* name);
csString csNodePropertyName(ISceneNode* n, int index);
csString csNodePropertyValue(ISceneNode* n, int index);
csVoid csNodeRemoveProperty(ISceneNode* n, int index);
csVoid csNodeSetParent(ISceneNode* n, ISceneNode* parent);
csInt csNodeGetParent(ISceneNode* n);
csInt csNodeChildren(ISceneNode* n);
csInt csNodeChild(ISceneNode* n, int index);
csInt csNodeFindChild(ISceneNode* n, const char* name, int recursive);
csVoid csNodeSpeed(ISceneNode* n, float fps);
csVoid csNodeLoop(ISceneNode* n, int loop);
csVoid csNodeSetFrame(ISceneNode* n, int begin, int end);
csInt csNodeGetFrame(ISceneNode* n);
csVoid csNodeAttachToBone(ISceneNode* n, ISceneNode* n2, const char* bonename);
csVoid csNodeLookAt(ISceneNode* n, float posx, float posy, float posz);

// Node Physics
void SetBodyPosition(const void* body, float x, float y, float z);
void SetBodyRotation(const void* body, float pitch, float yaw, float roll);
void DeleteBody(void* body);
csVoid csNodeSetBodyType(ISceneNode* node, int type);
csVoid csNodeEnablePhysics(ISceneNode* node, int use);
csVoid csNodeSetMass(ISceneNode* node, float mass);

// Particle Data
void CleanParticleDatas();
csInt csParticleDataCreate(const char* name);
csInt csParticleDataLoad(const char* file);
csVoid csParticleDataSave(csParticleData* part, const char* file);
csVoid csParticleDataFree(csParticleData* part);
csInt csParticleDataFind(const char* name);
csVoid csParticleDataSetMaterial(csParticleData* part, const char* mat_name);
csVoid csParticleDataSetType(csParticleData* part, int type);
csVoid csParticleDataSetBox(csParticleData* part, float width, float height, float depth);
csVoid csParticleDataSetDirection(csParticleData* part, float x, float y, float z);
csVoid csParticleDataSetRate(csParticleData* part, int min, int max);
csVoid csParticleDataSetColor(csParticleData* part, int min, int max);
csVoid csParticleDataSetLifeTime(csParticleData* part, int min, int max);
csVoid csParticleDataSetMaxAngle(csParticleData* part, int angle);
csVoid csParticleDataSetSize(csParticleData* part, float width, float height);
csVoid csParticleDataAddFadeOutAffector(csParticleData* part, int color, int time);
csVoid csParticleDataAddGravityAffector(csParticleData* part, float grav_x, float grav_y, float grav_z, int time);
csString csParticleDataGetName(csParticleData* part);
csString csParticleDataGetMaterial(csParticleData* part);
csInt csParticleDataGetType(csParticleData* part);
csFloat csParticleDataGetBoxWidth(csParticleData* part);
csFloat csParticleDataGetBoxHeight(csParticleData* part);
csFloat csParticleDataGetBoxDepth(csParticleData* part);
csFloat csParticleDataGetDirectionX(csParticleData* part);
csFloat csParticleDataGetDirectionY(csParticleData* part);
csFloat csParticleDataGetDirectionZ(csParticleData* part);
csInt csParticleDataGetMinRate(csParticleData* part);
csInt csParticleDataGetMaxRate(csParticleData* part);
csInt csParticleDataGetMinColor(csParticleData* part);
csInt csParticleDataGetMaxColor(csParticleData* part);
csInt csParticleDataGetMinLifeTime(csParticleData* part);
csInt csParticleDataGetMaxLifeTime(csParticleData* part);
csInt csParticleDataGetMaxAngle(csParticleData* part);
csFloat csParticleDataGetWidth(csParticleData* part);
csFloat csParticleDataGetHeight(csParticleData* part);
csInt csParticleDataAffectors(csParticleData* part);
csInt csParticleDataGetAffectorType(csParticleData* part, int index);
csInt csParticleDataGetAffectorColor(csParticleData* part, int index);
csInt csParticleDataGetAffectorTime(csParticleData* part, int index);
csFloat csParticleDataGetAffectorGravityX(csParticleData* part, int index);
csFloat csParticleDataGetAffectorGravityY(csParticleData* part, int index);
csFloat csParticleDataGetAffectorGravityZ(csParticleData* part, int index);

// Scene
csVoid csSceneBegin();
csVoid csSceneEnd();
csVoid csSceneUpdate(float timestep);
csVoid csSceneRender(ICameraSceneNode* cam);
csVoid csSceneAmbient(int color);
csVoid csSceneShadow(int color);
csVoid csSceneFog(int color, float near_, float far_);
csVoid csSceneSkybox(ITexture* top, ITexture* bottom, ITexture* left, ITexture* right, ITexture* front, ITexture* back);
csVoid csSceneSkydome(ITexture* tex, float hres, float yres, float tex_percent, float sphere_percent);
csVoid csSceneTransformation(int state, csMatrix* matrix);
csVoid csSceneSetGravity(float x, float y, float z);

// Shader
csInt csShaderRegister(const char* pixel_shader, const char* pixel_entry, int pixel_type, const char* vertex_shader, const char* vertex_entry, int vertex_type, int base_material);
csInt csShaderRegisterFile(const char* pixel_file, const char* pixel_entry, int pixel_type, const char* vertex_file, const char* vertex_entry, int vertex_type, int base_material);
csInt csShaderAsmRegister(const char* pixel_shader, const char* vertex_shader, int base_material);
csInt csShaderAsmRegisterFile(const char* pixel_file, const char* vertex_file, int base_material);
csVoid csShaderPixelConstant(csShader* shader, const char* name, int start_register, int data, int count);
csVoid csShaderVertexConstant(csShader* shader, const char* name, int start_register, int data, int count);

// String
void stringToWstring(const char* string, wchar_t* wstring, int maxchars);
void wstringToString(const wchar_t* wstring, char* string, int maxchars);
const wchar_t* asWstring(const char* string);
const char* asString(const wchar_t* wstring);
csInt csStringToInt(const char* str);
csFloat csStringToFloat(const char* str);
csString csStringFromInt(int number);
csString csStringFromFloat(float number);
csString csStringLeft(const char* str, int num);
csString csStringRight(const char* str, int num);
csString csStringMid(const char* str, int pos, int num);
csString csStringReplace(const char* str, const char* find, const char* replace);
csInt csStringFind(const char* str, const char* find, int offset);
csString csStringUpper(const char* str);
csString csStringLower(const char* str);
csString csStringTrim(const char* str);
csString csStringChar(int ascii);
csInt csStringAscii(const char* str);
csInt csStringLen(const char* str);
csString csStringField(const char* str, const char* delimiter, int index);

// Terrain
csInt csTerrainNode(const char* heightmap, ISceneNode* parent, float width, float height, float depth, int col_info);
csVoid csTerrainScaleTexture(ITerrainSceneNode* n, float scale1, float scale2);

// Texture
csInt csTextureCreate(int width, int height);
csInt csTextureTargetCreate(int width, int height);
csInt csTextureLoad(const char* file, int mipmaps);
csVoid csTextureFree(ITexture* tex);
csString csTextureFile(ITexture* tex);
csInt csTextureWidth(ITexture* tex, int original);
csInt csTextureHeight(ITexture* tex, int original);
csInt csTextureLock(ITexture* tex);
csVoid csTextureUnlock(ITexture* tex);
csVoid csTextureColorKey(ITexture* tex, int color);
csVoid csTextureNormalize(ITexture* tex, float amplitude);
csInt csTextureHWPointer(ITexture* tex);

// Vector
void CleanVectors();
csInt csVectorCreate();
csVoid csVectorFree(csVector* vec);
csVoid csVectorAdd(csVector* vec, csVector* other_vector);
csVoid csVectorAddScale(csVector* vec, csVector* other_vector, float scale);
csInt csVectorBetween(csVector* vec, float x0, float y0, float z0, float x1, float y1, float z1);
csVoid csVectorCopy(csVector* vec, csVector* other_vector);
csVoid csVectorCrossProduct(csVector* vec, csVector* vector2);
csFloat csVectorDistance(csVector* vec, float x, float y, float z);
csFloat csVectorDistanceSquared(csVector* vec, float x, float y, float z);
csVoid csVectorDiv(csVector* vec, csVector* vector2);
csFloat csVectorDotProduct(csVector* vec, csVector* other_vector);
csInt csVectorEqual(csVector* vec, csVector* other_vector, float epsilon);
csVoid csVectorInterpolate(csVector* vec, csVector* vector2, float d);
csVoid csVectorInvert(csVector* vec);
csFloat csVectorLength(csVector* vec);
csFloat csVectorLengthSquared(csVector* vec);
csVoid csVectorMul(csVector* vec, csVector* vector2);
csVoid csVectorNormalize(csVector* vec);
csVoid csVectorScale(csVector* vec, float scale);
csVoid csVectorSet(csVector* vec, float x, float y, float z);
csVoid csVectorSub(csVector* vec, csVector* vector2);
csFloat csVectorX(csVector* vec);
csFloat csVectorY(csVector* vec);
csFloat csVectorZ(csVector* vec);

// XML
void xmlWriteSetting(csXMLFile* file, const char* name, const char* value);
csInt csXMLRead(const char* file);
csInt csXMLWrite(const char* file);
csVoid csXMLClose(csXMLFile* file);
csInt csXMLReadNode(csXMLFile* file);
csInt csXMLNodeType(csXMLFile* file);
csString csXMLNodeName(csXMLFile* file);
csString csXMLNodeData(csXMLFile* file);
csInt csXMLAttributeCount(csXMLFile* file);
csString csXMLAttributeName(csXMLFile* file, int index);
csString csXMLAttributeValue(csXMLFile* file, int index);
csVoid csXMLWriteHeader(csXMLFile* file);
csVoid csXMLWriteElement(csXMLFile* file, const char* name, const char* attributes, int empty);
csVoid csXMLWriteClosingTag(csXMLFile* file, const char* name);
csVoid csXMLWriteText(csXMLFile* file, const char* text);
csVoid csXMLWriteLineBreak(csXMLFile* file);

#endif  // _ENGINE_H_
