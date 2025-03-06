#include "engine.h"

enum
{
	SC_PIXEL,
	SC_VERTEX,
	SC_PIXEL_LOW,
	SC_VERTEX_LOW
};

//-----------------------------------------------
//  Shader functions
//-----------------------------------------------

class csShaderCallBack : public video::IShaderConstantSetCallBack
{
public: 
	virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
	{
		while (!constants.empty())
		{
			csShaderConstant constant = constants[0];
			constants.erase(constants.begin());
			switch (constant.type)
			{
			case SC_PIXEL:
				services->setPixelShaderConstant(constant.name.c_str(), constant.data, constant.size);
				break;
			case SC_VERTEX:
				services->setVertexShaderConstant(constant.name.c_str(), constant.data, constant.size);
				break;
			case SC_PIXEL_LOW:
				services->setPixelShaderConstant(constant.data, constant.start_reg, constant.size);
				break;
			case SC_VERTEX_LOW:
				services->setVertexShaderConstant(constant.data, constant.start_reg, constant.size);
				break;
			}
		}
	}

	void setPixelShaderConstant(const char* name, float* data, int start_register, int count)
	{
		csShaderConstant constant;
		if (strcmp(name, ""))	// Has a name, high-level shader
		{
			constant.type = SC_PIXEL;
		} else {
			constant.type = SC_PIXEL_LOW;
		}
		constant.name = name;
		constant.data = data;
		constant.size = count;
		constant.start_reg = start_register;
		constants.push_back(constant);
	}

	void setVertexShaderConstant(const char* name, float* data, int start_register, int count)
	{
		csShaderConstant constant;
		if (strcmp(name, ""))	// Has a name, high-level shader
			constant.type = SC_VERTEX;
		else
			constant.type = SC_VERTEX_LOW;
		constant.name = name;
		constant.data = data;
		constant.size = count;
		constant.start_reg = start_register;
		constants.push_back(constant);
	}

private:
	std::vector<csShaderConstant> constants;
};

//-----------------------------------------------

csInt csShaderRegister(const char* pixel_shader, const char* pixel_entry, int pixel_type, const char* vertex_shader, const char* vertex_entry, int vertex_type, int base_material)
{
#ifndef COLDSTEEL_LITE
	// Get real base material type
	base_material = (int) getIrrLichtMaterialType(base_material);

	// Create shader
	csShader* shader = new csShader;
	shader->low_level = false;
	shader->callback = new csShaderCallBack();
	shader->mat_type = Device->getVideoDriver()->getGPUProgrammingServices()->addHighLevelShaderMaterial(vertex_shader, vertex_entry, (E_VERTEX_SHADER_TYPE) vertex_type, pixel_shader, pixel_entry, (E_PIXEL_SHADER_TYPE) pixel_type, shader->callback, (E_MATERIAL_TYPE) base_material);

	// Return
	if (shader->mat_type == -1)
	{
		delete shader->callback;
		delete shader;
		return 0;
	} else {
		return (int) shader;
	}
#else
	return 0;
#endif
}

//-----------------------------------------------

csInt csShaderRegisterFile(const char* pixel_file, const char* pixel_entry, int pixel_type, const char* vertex_file, const char* vertex_entry, int vertex_type, int base_material)
{
#ifndef COLDSTEEL_LITE
	// Get real base material type
	base_material = (int) getIrrLichtMaterialType(base_material);

	// Create shader
	csShader* shader = new csShader;
	shader->low_level = false;
	shader->callback = new csShaderCallBack();
	shader->mat_type = Device->getVideoDriver()->getGPUProgrammingServices()->addHighLevelShaderMaterialFromFiles(vertex_file, vertex_entry, (E_VERTEX_SHADER_TYPE) vertex_type, pixel_file, pixel_entry, (E_PIXEL_SHADER_TYPE) pixel_type, shader->callback, (E_MATERIAL_TYPE) base_material);

	// Return
	if (shader->mat_type == -1)
	{
		delete shader->callback;
		delete shader;
		return 0;
	} else {
		return (int) shader;
	}
#else
	return 0;
#endif
}

//-----------------------------------------------

csInt csShaderAsmRegister(const char* pixel_shader, const char* vertex_shader, int base_material)
{
#ifndef COLDSTEEL_LITE
	// Get real base material type
	base_material = (int) getIrrLichtMaterialType(base_material);

	// Create shader
	csShader* shader = new csShader;
	shader->low_level = true;
	shader->callback = new csShaderCallBack();
	shader->mat_type = Device->getVideoDriver()->getGPUProgrammingServices()->addShaderMaterial(vertex_shader, pixel_shader, shader->callback, (E_MATERIAL_TYPE) base_material);

	// Return
	if (shader->mat_type == -1)
	{
		shader->callback->drop();
		delete shader;
		return 0;
	} else {
		shader->callback->drop();
		return (int) shader;
	}
#else
	return 0;
#endif
}

//-----------------------------------------------

csInt csShaderAsmRegisterFile(const char* pixel_file, const char* vertex_file, int base_material)
{
#ifndef COLDSTEEL_LITE
	// Get real base material type
	base_material = (int) getIrrLichtMaterialType(base_material);

	// Create shader
	csShader* shader = new csShader;
	shader->low_level = true;
	shader->callback = new csShaderCallBack();
	shader->mat_type = Device->getVideoDriver()->getGPUProgrammingServices()->addShaderMaterialFromFiles(vertex_file, pixel_file, shader->callback, (E_MATERIAL_TYPE) base_material);

	// Return
	if (shader->mat_type == -1)
	{
		delete shader->callback;
		delete shader;
		return 0;
	} else {
		return (int) shader;
	}
#else
	return 0;
#endif
}

//-----------------------------------------------

csVoid csShaderPixelConstant(csShader* shader, const char* name, int start_register, int data, int count)
{
#ifndef COLDSTEEL_LITE
	shader->callback->setPixelShaderConstant(name, (float*) data, start_register, count);
#endif
}

//-----------------------------------------------

csVoid csShaderVertexConstant(csShader* shader, const char* name, int start_register, int data, int count)
{
#ifndef COLDSTEEL_LITE
	shader->callback->setVertexShaderConstant(name, (float*) data, start_register, count);
#endif
}
