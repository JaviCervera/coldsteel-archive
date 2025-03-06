#include "engine.h"

//-----------------------------------------------
//  Effect functions
//-----------------------------------------------

#if defined(_WIN32) && !defined(__GNUC__)

// Effect parameter types
enum
{
	EP_TECHNIQUE,
	EP_TEXTURE,
	EP_BOOL,
	EP_INT,
	EP_FLOAT,
	EP_VECTOR,
	EP_MATRIX
};

class csEffectCallBack : public IEffectCallBack
{
public:
	virtual void OnSetParameters(IMaterialRendererServices* services, s32 userData)
	{
		vector3df vector;
		matrix4 matrix;
		while (!params.empty())
		{
			csEffectParam param = params[0];
			switch (param.type)
			{
			case EP_TECHNIQUE:
				services->setEffectTechnique(param.name.c_str());
				break;
			case EP_TEXTURE:
				services->setEffectTexture(param.name.c_str(), param.tex);
				break;
			case EP_BOOL:
				services->setEffectBool(param.name.c_str(), param.boolval);
				break;
			case EP_INT:
				services->setEffectInt(param.name.c_str(), param.intval);
				break;
			case EP_FLOAT:
				services->setEffectFloat(param.name.c_str(), param.floatval);
				break;
			case EP_VECTOR:
				vector.set(param.vector->x, param.vector->y, param.vector->z);
				services->setEffectVector(param.name.c_str(), vector);
				csVectorFree(param.vector);
				break;
			case EP_MATRIX:
				for (int i = 0; i < 16; ++i)
					matrix.pointer()[i] = param.matrix->m[i];
				services->setEffectMatrix(param.name.c_str(), matrix);
				csMatrixFree(param.matrix);
				break;
			}
			params.erase(params.begin());
		}
	}

	void setTechnique(const char* name)
	{
		csEffectParam param;
		param.type = EP_TECHNIQUE;
		param.name = name;
		params.push_back(param);
	}

	void setTexture(const char* name, ITexture* tex)
	{
		csEffectParam param;
		param.type = EP_TEXTURE;
		param.name = name;
		param.tex = tex;
		params.push_back(param);
	}

	void setBool(const char* name, int boolval)
	{
		csEffectParam param;
		param.type = EP_BOOL;
		param.name = name;
		param.boolval = boolval;
		params.push_back(param);
	}

	void setInt(const char* name, int intval)
	{
		csEffectParam param;
		param.type = EP_INT;
		param.name = name;
		param.intval = intval;
		params.push_back(param);
	}

	void setFloat(const char* name, float floatval)
	{
		csEffectParam param;
		param.type = EP_FLOAT;
		param.name = name;
		param.floatval = floatval;
		params.push_back(param);
	}

	void setVector(const char* name, csVector* vector)
	{
		csVector* vec = (csVector*) csVectorCreate();
		csVectorCopy(vec, vector);
		csEffectParam param;
		param.type = EP_VECTOR;
		param.name = name;
		param.vector = vec;
		params.push_back(param);
	}

	void setMatrix(const char* name, csMatrix* matrix)
	{
		csMatrix* mat = (csMatrix*) csMatrixCreate();
		csMatrixCopy(mat, matrix);
		csEffectParam param;
		param.type = EP_MATRIX;
		param.name = name;
		param.matrix = mat;
		params.push_back(param);
	}

private:
	std::vector<csEffectParam> params;
};

#endif // _WIN32

//-----------------------------------------------

csInt csEffectRegister(const char* effect, int base_material)
{
#if defined(_WIN32) && !defined(__GNUC__) && !defined(COLDSTEEL_LITE)
	// Get real base material type
	base_material = (int) getIrrLichtMaterialType(base_material);

	// Create shader
	csEffect* ef = new csEffect;
	ef->callback = new csEffectCallBack;
	ef->mat_type = Device->getVideoDriver()->getGPUProgrammingServices()->addEffectMaterial(effect, ef->callback, (E_MATERIAL_TYPE) base_material);

	// Return
	if (ef->mat_type == -1)
	{
		delete ef->callback;
		delete ef;
		return 0;
	} else {
		return (int) ef;
	}
#else
  return 0;
#endif
}

//-----------------------------------------------

csInt csEffectRegisterFile(const char* effect, int base_material)
{
#if defined(_WIN32) && !defined(__GNUC__) && !defined(COLDSTEEL_LITE)
	// Get real base material type
	base_material = (int) getIrrLichtMaterialType(base_material);

	// Create shader
	csEffect* ef = new csEffect;
	ef->callback = new csEffectCallBack();
	ef->mat_type = Device->getVideoDriver()->getGPUProgrammingServices()->addEffectMaterialFromFile(effect, ef->callback, (E_MATERIAL_TYPE) base_material);

	// Return
	if (ef->mat_type == -1)
	{
		delete ef->callback;
		delete ef;
		return 0;
	} else {
		return (int) ef;
	}
#else
  return 0;
#endif
}

//-----------------------------------------------

csVoid csEffectSetTechnique(csEffect* eff, const char* name)
{
#if defined(_WIN32) && !defined(__GNUC__) && !defined(COLDSTEEL_LITE)
	eff->callback->setTechnique(name);
#endif
}

//-----------------------------------------------

csVoid csEffectSetTexture(csEffect* eff, const char* name, ITexture* tex)
{
#if defined(_WIN32) && !defined(__GNUC__) && !defined(COLDSTEEL_LITE)
	eff->callback->setTexture(name, tex);
#endif
}

//-----------------------------------------------

csVoid csEffectSetBool(csEffect* eff, const char* name, int boolval)
{
#if defined(_WIN32) && !defined(__GNUC__) && !defined(COLDSTEEL_LITE)
	eff->callback->setBool(name, boolval);
#endif
}

//-----------------------------------------------

csVoid csEffectSetInt(csEffect* eff, const char* name, int intval)
{
#if defined(_WIN32) && !defined(__GNUC__) && !defined(COLDSTEEL_LITE)
	eff->callback->setInt(name, intval);
#endif
}

//-----------------------------------------------

csVoid csEffectSetFloat(csEffect* eff, const char* name, float floatval)
{
#if defined(_WIN32) && !defined(__GNUC__) && !defined(COLDSTEEL_LITE)
	eff->callback->setFloat(name, floatval);
#endif
}

//-----------------------------------------------

csVoid csEffectSetVector(csEffect* eff, const char* name, csVector* vector)
{
#if defined(_WIN32) && !defined(__GNUC__) && !defined(COLDSTEEL_LITE)
	eff->callback->setVector(name, vector);
#endif
}

//-----------------------------------------------

csVoid csEffectSetMatrix(csEffect* eff, const char* name, csMatrix* matrix)
{
#if defined(_WIN32) && !defined(__GNUC__) && !defined(COLDSTEEL_LITE)
	eff->callback->setMatrix(name, matrix);
#endif
}
