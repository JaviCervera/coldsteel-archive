#include "engine.h"

std::vector<csParticleData*> partdata_list;

//-----------------------------------------------
//  Particle Data functions
//-----------------------------------------------

void CleanParticleDatas()
{
   partdata_list.clear();
}

//-----------------------------------------------

csParticleData::csParticleData(const char* name)
{
	partdata_list.push_back(this);
	this->name = name;
	material = "";
	type = 0;
	box.set(1, 1, 1);
	direction.set(0, 1, 0);
	rate[0] = 1;
	rate[1] = 10;
	startColor[0] = csGetColor(0, 0, 0, 255);
	startColor[1] = csGetColor(255, 255, 255, 255);
	lifeTime[0] = 1000;
	lifeTime[1] = 5000;
	maxAngle = 0;
	size[0] = 1.0;
	size[1] = 1.0;
}

//-----------------------------------------------

csParticleData::~csParticleData()
{
	for (int i = 0; i < partdata_list.size(); i++)
	if (partdata_list[i] == this)
	{
		partdata_list.erase(partdata_list.begin() + i);
		break;
	}
}

//-----------------------------------------------

csInt csParticleDataCreate(const char* name)
{
#ifndef COLDSTEEL_LITE
	if (csParticleDataFind(name)) return 0;
		return (int) new csParticleData(name);
#else
	return 0;
#endif
}

//-----------------------------------------------

csInt csParticleDataLoad(const char* file)
{
#ifndef COLDSTEEL_LITE
	csXMLFile* xml = (csXMLFile*) csXMLRead(file);
	if (xml)
	{
		bool isParticle = false;
		std::string partName = "";
		std::string partMaterial = "";
		std::string partType = "PT_POINT";
		float partBox[3] = {1.0, 1.0, 1.0};
		float partDir[3] = {1.0, 1.0, 1.0};
		int partRate[2] = {1, 10};
		int partMinColor = csGetColor(0, 0, 0, 255);
		int partMaxColor = csGetColor(255, 255, 255, 255);
		int partLifeTime[2] = {1000, 5000};
		int partMaxAngle = 0;
		float partSize[2] = {1.0, 1.0};
		std::vector<csAffector> partAff;
		while (csXMLReadNode(xml))
		{
			if (csXMLNodeType(xml) == 1)  // An element
			{
				if (std::string(csXMLNodeName(xml)) == "particle_data")  isParticle = true;
				if (std::string(csXMLNodeName(xml)) == "name")
				{
					csXMLReadNode(xml);
					partName = csXMLNodeData(xml);
				}
				if (std::string(csXMLNodeName(xml)) == "material")
				{
					csXMLReadNode(xml);
					partMaterial = csXMLNodeData(xml);
				}
				if (std::string(csXMLNodeName(xml)) == "type")
				{
					csXMLReadNode(xml);
					partType = csXMLNodeData(xml);
				}
				if (std::string(csXMLNodeName(xml)) == "box")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					partBox[0] = csStringToFloat(csStringTrim(csStringField(str.c_str(), ",", 1)));
					partBox[1] = csStringToFloat(csStringTrim(csStringField(str.c_str(), ",", 2)));
					partBox[2] = csStringToFloat(csStringTrim(csStringField(str.c_str(), ",", 3)));
				}
				if (std::string(csXMLNodeName(xml)) == "direction")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					partDir[0] = csStringToFloat(csStringTrim(csStringField(str.c_str(), ",", 1)));
					partDir[1] = csStringToFloat(csStringTrim(csStringField(str.c_str(), ",", 2)));
					partDir[2] = csStringToFloat(csStringTrim(csStringField(str.c_str(), ",", 3)));
				}
				if (std::string(csXMLNodeName(xml)) == "rate")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					partRate[0] = csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 1)));
					partRate[1] = csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 2)));
				}
				if (std::string(csXMLNodeName(xml)) == "min_color")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					partMinColor = csGetColor(csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 1))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 2))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 3))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 4))));
				}
				if (std::string(csXMLNodeName(xml)) == "max_color")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					partMaxColor = csGetColor(csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 1))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 2))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 3))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 4))));
				}
				if (std::string(csXMLNodeName(xml)) == "life_time")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					partLifeTime[0] = csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 1)));
					partLifeTime[1] = csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 2)));
				}
				if (std::string(csXMLNodeName(xml)) == "max_angle")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					partMaxAngle = csStringToInt(str.c_str());
				}
				if (std::string(csXMLNodeName(xml)) == "size")
				{
					csXMLReadNode(xml);
					std::string str = csXMLNodeData(xml);
					partSize[0] = csStringToFloat(csStringTrim(csStringField(str.c_str(), ",", 1)));
					partSize[1] = csStringToFloat(csStringTrim(csStringField(str.c_str(), ",", 2)));
				}
				if (std::string(csXMLNodeName(xml)) == "fadeout_affector")
				{
					csAffector aff; aff.type = 0;
					for (int i = 1; i <= csXMLAttributeCount(xml); i++)
					{
						if (std::string(csXMLAttributeName(xml, i)) == "color")
						{
							std::string str = csXMLAttributeValue(xml, i);
							aff.color = csGetColor(csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 1))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 2))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 3))), csStringToInt(csStringTrim(csStringField(str.c_str(), ",", 4))));
						}
						if (std::string(csXMLAttributeName(xml, i)) == "time")
							aff.time = csStringToInt(csStringTrim(csXMLAttributeValue(xml, i)));
					}
					partAff.push_back(aff);
				}
				if (std::string(csXMLNodeName(xml)) == "gravity_affector")
				{
					csAffector aff; aff.type = 1;
					for (int i = 1; i <= csXMLAttributeCount(xml); i++)
					{
						if (std::string(csXMLAttributeName(xml, i)) == "gravity")
						{
							std::string str = csXMLAttributeValue(xml, i);
							aff.grav[0] = csStringToFloat(csStringTrim(csStringField(str.c_str(), ",", 1)));
							aff.grav[1] = csStringToFloat(csStringTrim(csStringField(str.c_str(), ",", 2)));
							aff.grav[2] = csStringToFloat(csStringTrim(csStringField(str.c_str(), ",", 3)));
						}
						if (std::string(csXMLAttributeName(xml, i)) == "time")
							aff.time = csStringToInt(csStringTrim(csXMLAttributeValue(xml, i)));
					}
					partAff.push_back(aff);
				}
			}
		}
		csXMLClose(xml);

		if (!isParticle) return 0;
		if (csParticleDataFind(partName.c_str())) return 0;

		csParticleData* part = (csParticleData*) csParticleDataCreate(partName.c_str());
		csParticleDataSetMaterial(part, partMaterial.c_str());
		if (partType == "PT_POINT") csParticleDataSetType(part, 0);
		if (partType == "PT_BOX")   csParticleDataSetType(part, 1);
		csParticleDataSetBox(part, partBox[0], partBox[1], partBox[2]);
		csParticleDataSetDirection(part, partDir[0], partDir[1], partDir[2]);
		csParticleDataSetRate(part, partRate[0], partRate[1]);
		csParticleDataSetColor(part, partMinColor, partMaxColor);
		csParticleDataSetLifeTime(part, partLifeTime[0], partLifeTime[1]);
		csParticleDataSetMaxAngle(part, partMaxAngle);
		csParticleDataSetSize(part, partSize[0], partSize[1]);

		// Add affectors
		for (int i = 0; i < partAff.size(); i++)
			if (partAff[i].type == 0)
				csParticleDataAddFadeOutAffector(part, partAff[i].color, partAff[i].time);
			else if (partAff[i].type == 1)
				csParticleDataAddGravityAffector(part, partAff[i].grav[0], partAff[i].grav[1], partAff[i].grav[2], partAff[i].time);

		return (int) part;
	}
#endif
	return 0;
}

//-----------------------------------------------

csVoid csParticleDataSave(csParticleData* part, const char* file)
{
#if !defined(COLDSTEEL_LITE) && !defined(COLDSTEEL_DEMO)
	csXMLFile* xml = (csXMLFile*) csXMLWrite(file);
	if (xml)
	{
		csXMLWriteHeader(xml);
		csXMLWriteElement(xml, "particle_data", "", false); csXMLWriteLineBreak(xml);
		xmlWriteSetting(xml, "name", part->name.c_str());
		xmlWriteSetting(xml, "material", part->material.c_str());
		switch (part->type)
		{
		case 0: // Point
			xmlWriteSetting(xml, "type", "PT_POINT");
			break;
		case 1: // Box
			xmlWriteSetting(xml, "type", "PT_BOX");
			break;
		}
		char box[1024];
		sprintf(box, "%f, %f, %f", part->box.X, part->box.Y, part->box.Z);
		xmlWriteSetting(xml, "box", box);
		char direction[1024];
		sprintf(direction, "%f, %f, %f", part->direction.X, part->direction.Y, part->direction.Z);
		xmlWriteSetting(xml, "direction", direction);
		char rate[1024];
		sprintf(rate, "%i, %i", part->rate[0], part->rate[1]);
		xmlWriteSetting(xml, "rate", rate);
		char color[1024];
		sprintf(color, "%i, %i, %i, %i", csGetRed(part->startColor[0]), csGetGreen(part->startColor[0]), csGetBlue(part->startColor[0]), csGetAlpha(part->startColor[0]));
		xmlWriteSetting(xml, "min_color", color);
		sprintf(color, "%i, %i, %i, %i", csGetRed(part->startColor[1]), csGetGreen(part->startColor[1]), csGetBlue(part->startColor[1]), csGetAlpha(part->startColor[1]));
		xmlWriteSetting(xml, "max_color", color);
		char lifetime[1024];
		sprintf(lifetime, "%i, %i", part->lifeTime[0], part->lifeTime[1]);
		xmlWriteSetting(xml, "life_time", lifetime);
		xmlWriteSetting(xml, "max_angle", csStringFromInt(part->maxAngle));
		char size[1024];
		sprintf(size, "%f, %f", part->size[0], part->size[1]);
		xmlWriteSetting(xml, "size", size);

		// Write affectors
		for (int i = 0; i < part->affectors.size(); i++)
			if (part->affectors[i].type == 0)
			{
				char aff[1024];
				sprintf(aff, "color|%i, %i, %i, %i|time|%i", csGetRed(part->affectors[i].color), csGetGreen(part->affectors[i].color), csGetBlue(part->affectors[i].color), csGetAlpha(part->affectors[i].color), part->affectors[i].time);
				csXMLWriteElement(xml, "fadeout_affector", aff, true); csXMLWriteLineBreak(xml);
			} else if (part->affectors[i].type == 1) {
				char aff[1024];
				sprintf(aff, "gravity|%f, %f, %f|time|%i", part->affectors[i].grav[0], part->affectors[i].grav[1], part->affectors[i].grav[2], part->affectors[i].time);
				csXMLWriteElement(xml, "gravity_affector", aff, true); csXMLWriteLineBreak(xml);
			}

		csXMLWriteClosingTag(xml, "particle_data");
		csXMLClose(xml);
	}
#endif
}

//-----------------------------------------------

csVoid csParticleDataFree(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	delete part;
#endif
}

//-----------------------------------------------

csInt csParticleDataFind(const char* name)
{
#ifndef COLDSTEEL_LITE
	if (std::string(name) == "") return 0;
	for (int i = 0; i < partdata_list.size(); i++)
		if (partdata_list[i]->name == name)
			return (int) partdata_list[i];
	return 0;
#else
	return 0;
#endif
}

//-----------------------------------------------

csVoid csParticleDataSetMaterial(csParticleData* part, const char* mat_name)
{
#ifndef COLDSTEEL_LITE
	part->material = mat_name;
#endif
}

//-----------------------------------------------

csVoid csParticleDataSetType(csParticleData* part, int type)
{
#ifndef COLDSTEEL_LITE
	part->type = type;
#endif
}

//-----------------------------------------------

csVoid csParticleDataSetBox(csParticleData* part, float width, float height, float depth)
{
#ifndef COLDSTEEL_LITE
	part->box.set(width, height, depth);
#endif
}

//-----------------------------------------------

csVoid csParticleDataSetDirection(csParticleData* part, float x, float y, float z)
{
#ifndef COLDSTEEL_LITE
	part->direction.set(x, y, z);
#endif
}

//-----------------------------------------------

csVoid csParticleDataSetRate(csParticleData* part, int min, int max)
{
#ifndef COLDSTEEL_LITE
	part->rate[0] = min;
	part->rate[1] = max;
#endif
}

//-----------------------------------------------

csVoid csParticleDataSetColor(csParticleData* part, int min, int max)
{
#ifndef COLDSTEEL_LITE
	part->startColor[0] = min;
	part->startColor[1] = max;
#endif
}

//-----------------------------------------------

csVoid csParticleDataSetLifeTime(csParticleData* part, int min, int max)
{
#ifndef COLDSTEEL_LITE
	part->lifeTime[0] = min;
	part->lifeTime[1] = max;
#endif
}

//-----------------------------------------------

csVoid csParticleDataSetMaxAngle(csParticleData* part, int angle)
{
#ifndef COLDSTEEL_LITE
	part->maxAngle = angle;
#endif
}

//-----------------------------------------------

csVoid csParticleDataSetSize(csParticleData* part, float width, float height)
{
#ifndef COLDSTEEL_LITE
	part->size[0] = width;
	part->size[1] = height;
#endif
}

//-----------------------------------------------

csVoid csParticleDataAddFadeOutAffector(csParticleData* part, int color, int time)
{
#ifndef COLDSTEEL_LITE
	csAffector aff;
	aff.type = 0;
	aff.color = color;
	aff.time = time;
	part->affectors.push_back(aff);
#endif
}

//-----------------------------------------------

csVoid csParticleDataAddGravityAffector(csParticleData* part, float grav_x, float grav_y, float grav_z, int time)
{
#ifndef COLDSTEEL_LITE
	csAffector aff;
	aff.type = 1;
	aff.grav[0] = grav_x;
	aff.grav[1] = grav_y;
	aff.grav[2] = grav_z;
	aff.time = time;
	part->affectors.push_back(aff);
#endif
}

//-----------------------------------------------

csString csParticleDataGetName(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->name.c_str();
#endif
}

//-----------------------------------------------

csString csParticleDataGetMaterial(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->material.c_str();
#endif
}

//-----------------------------------------------

csInt csParticleDataGetType(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->type;
#endif
}

//-----------------------------------------------

csFloat csParticleDataGetBoxWidth(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->box.X;
#endif
}

//-----------------------------------------------

csFloat csParticleDataGetBoxHeight(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->box.Y;
#endif
}

//-----------------------------------------------

csFloat csParticleDataGetBoxDepth(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->box.Z;
#endif
}

//-----------------------------------------------

csFloat csParticleDataGetDirectionX(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->direction.X;
#endif
}

//-----------------------------------------------

csFloat csParticleDataGetDirectionY(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->direction.Y;
#endif
}

//-----------------------------------------------

csFloat csParticleDataGetDirectionZ(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->direction.Z;
#endif
}

//-----------------------------------------------

csInt csParticleDataGetMinRate(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->rate[0];
#endif
}

//-----------------------------------------------

csInt csParticleDataGetMaxRate(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->rate[1];
#endif
}

//-----------------------------------------------

csInt csParticleDataGetMinColor(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->startColor[0];
#endif
}

//-----------------------------------------------

csInt csParticleDataGetMaxColor(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->startColor[1];
#endif
}

//-----------------------------------------------

csInt csParticleDataGetMinLifeTime(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->lifeTime[0];
#endif
}

//-----------------------------------------------

csInt csParticleDataGetMaxLifeTime(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->lifeTime[1];
#endif
}

//-----------------------------------------------

csInt csParticleDataGetMaxAngle(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->maxAngle;
#endif
}

//-----------------------------------------------

csFloat csParticleDataGetWidth(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->size[0];
#endif
}

//-----------------------------------------------

csFloat csParticleDataGetHeight(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->size[1];
#endif
}

//-----------------------------------------------

csInt csParticleDataAffectors(csParticleData* part)
{
#ifndef COLDSTEEL_LITE
	return part->affectors.size();
#endif
}

//-----------------------------------------------

csInt csParticleDataGetAffectorType(csParticleData* part, int index)
{
#ifndef COLDSTEEL_LITE
	return part->affectors[index-1].type;
#endif
}

//-----------------------------------------------

csInt csParticleDataGetAffectorColor(csParticleData* part, int index)
{
#ifndef COLDSTEEL_LITE
	return part->affectors[index-1].color;
#endif
}

//-----------------------------------------------

csInt csParticleDataGetAffectorTime(csParticleData* part, int index)
{
#ifndef COLDSTEEL_LITE
	return part->affectors[index-1].time;
#endif
}

//-----------------------------------------------

csFloat csParticleDataGetAffectorGravityX(csParticleData* part, int index)
{
#ifndef COLDSTEEL_LITE
	return part->affectors[index-1].grav[0];
#endif
}

//-----------------------------------------------

csFloat csParticleDataGetAffectorGravityY(csParticleData* part, int index)
{
#ifndef COLDSTEEL_LITE
	return part->affectors[index-1].grav[1];
#endif
}

//-----------------------------------------------

csFloat csParticleDataGetAffectorGravityZ(csParticleData* part, int index)
{
#ifndef COLDSTEEL_LITE
	return part->affectors[index-1].grav[2];
#endif
}
