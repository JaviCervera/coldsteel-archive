#include "engine.h"

std::vector<csVector*> vectorlist;

//-----------------------------------------------
//  Vector functions
//-----------------------------------------------

void CleanVectors()
{
	while (!vectorlist.empty())
		vectorlist.erase(vectorlist.begin());
}

//-----------------------------------------------

csInt csVectorCreate()
{
	csVector* vec = new csVector;
	vectorlist.push_back(vec);
	return (int) vec;
}

//-----------------------------------------------

csVoid csVectorFree(csVector* vec)
{
	// Remove vector from list
	for (unsigned int i = 0; i < vectorlist.size(); i++)
		if (vectorlist[i] == vec)
		{
			vectorlist.erase(vectorlist.begin() + i);
			break;
		}

	delete vec;
}

//-----------------------------------------------

csVoid csVectorAdd(csVector* vec, csVector* other_vector)
{
	vec->x += other_vector->x;
	vec->y += other_vector->y;
	vec->z += other_vector->z;
}

//-----------------------------------------------

csVoid csVectorAddScale(csVector* vec, csVector* other_vector, float scale)
{
	vec->x += scale * other_vector->x;
	vec->y += scale * other_vector->y;
	vec->z += scale * other_vector->z;
}

//-----------------------------------------------

csInt csVectorBetween(csVector* vec, float x0, float y0, float z0, float x1, float y1, float z1)
{
	csVector vec2;
	float f;
	vec2.x = x1 / x0;
	vec2.y = y1 / y0;
	vec2.z = z1 / z0;
	f = csVectorLengthSquared(&vec2);
	return csVectorDistanceSquared(vec, x0, y0, z0) < f &&
		csVectorDistanceSquared(vec, x1, y1, z1) < f;
}

//-----------------------------------------------

csVoid csVectorCopy(csVector* vec, csVector* other_vector)
{
	vec->x = other_vector->x;
	vec->y = other_vector->y;
	vec->z = other_vector->z;
}

//-----------------------------------------------

csVoid csVectorCrossProduct(csVector* vec, csVector* vector2)
{
	vec->x = vec->y*vector2->z - vec->z*vector2->y;
	vec->y = vec->z*vector2->x - vec->x*vector2->z;
	vec->z = vec->x*vector2->y - vec->y*vector2->x;
}

//-----------------------------------------------

csFloat csVectorDistance(csVector* vec, float x, float y, float z)
{
	float vx = vec->x - x;
	float vy = vec->y - y;
	float vz = vec->z - z;
	return sqrt(vx*vx + vy*vy + vz*vz);
}

//-----------------------------------------------

csFloat csVectorDistanceSquared(csVector* vec, float x, float y, float z)
{
	float vx = vec->x - x;
	float vy = vec->y - y;
	float vz = vec->z - z;
	return (vx*vx + vy*vy + vz*vz);
}

//-----------------------------------------------

csVoid csVectorDiv(csVector* vec, csVector* vector2)
{
	vec->x /= vector2->x;
	vec->y /= vector2->y;
	vec->z /= vector2->z;
}

//-----------------------------------------------

csFloat csVectorDotProduct(csVector* vec, csVector* other_vector)
{
	return vec->x*other_vector->x + vec->y*other_vector->y + vec->z*other_vector->z;
}

//-----------------------------------------------

csInt csVectorEqual(csVector* vec, csVector* other_vector, float epsilon)
{
	return ((fabs(vec->x-other_vector->x) < epsilon) && 
		(fabs(vec->y-other_vector->y) < epsilon) && 
		(fabs(vec->z-other_vector->z) < epsilon));
}

//-----------------------------------------------

csVoid csVectorInterpolate(csVector* vec, csVector* vector2, float d)
{
	float inv = 1.0f - d;
	vec->x = vector2->x*inv + vec->x*d;
	vec->y = vector2->y*inv + vec->y*d;
	vec->z = vector2->z*inv + vec->z*d;
}

//-----------------------------------------------

csVoid csVectorInvert(csVector* vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	vec->z = -vec->z;
}

//-----------------------------------------------

csFloat csVectorLength(csVector* vec)
{
	return sqrt(vec->x*vec->x + vec->y*vec->y + vec->z*vec->z);
}

//-----------------------------------------------

csFloat csVectorLengthSquared(csVector* vec)
{
	return (vec->x*vec->x + vec->y*vec->y + vec->z*vec->z);
}

//-----------------------------------------------

csVoid csVectorMul(csVector* vec, csVector* vector2)
{
	vec->x *= vector2->x;
	vec->y *= vector2->y;
	vec->z *= vector2->z;
}

//-----------------------------------------------

csVoid csVectorNormalize(csVector* vec)
{
	float l = csVectorLength(vec);
	if (l == 0) return;
	l = (float)1.0 / l;
	vec->x *= l;
	vec->y *= l;
	vec->z *= l;
}

//-----------------------------------------------

csVoid csVectorScale(csVector* vec, float scale)
{
	vec->x *= scale;
	vec->y *= scale;
	vec->z *= scale;
}

//-----------------------------------------------

csVoid csVectorSet(csVector* vec, float x, float y, float z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

//-----------------------------------------------

csVoid csVectorSub(csVector* vec, csVector* vector2)
{
	vec->x -= vector2->x;
	vec->y -= vector2->y;
	vec->z -= vector2->z;
}

//-----------------------------------------------

csFloat csVectorX(csVector* vec)
{
	return vec->x;
}

//-----------------------------------------------

csFloat csVectorY(csVector* vec)
{
	return vec->y;
}

//-----------------------------------------------

csFloat csVectorZ(csVector* vec)
{
	return vec->z;
}
