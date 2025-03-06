#include "engine.h"
#include <math.h>
#include <stdlib.h>

#define DEG2RAD (0.017453292f)
#define RAD2DEG	(57.29577951f)

//-----------------------------------------------
//  Math functions
//-----------------------------------------------

csFloat csMathFloor(float val)
{
	return floor(val);
}

//-----------------------------------------------

csFloat csMathCeil(float val)
{
	return ceil(val);
}

//-----------------------------------------------

csFloat csMathAbs(float val)
{
	return abs(val);
}

//-----------------------------------------------

csFloat csMathSqr(float val)
{
	return sqrt(val);
}

//-----------------------------------------------

csFloat csMathSin(float val)
{
	return sin(val * DEG2RAD);
}

//-----------------------------------------------

csFloat csMathCos(float val)
{
	return cos(val * DEG2RAD);
}

//-----------------------------------------------

csFloat csMathTan(float val)
{
	return tan(val * DEG2RAD);
}

//-----------------------------------------------

csFloat csMathASin(float val)
{
	return asin(val * RAD2DEG);
}

//-----------------------------------------------

csFloat csMathACos(float val)
{
	return acos(val * RAD2DEG);
}

//-----------------------------------------------

csFloat csMathATan(float val)
{
	return atan(val * RAD2DEG);
}

//-----------------------------------------------

csFloat csMathATan2(float x, float y)
{
	return atan2(x, y) * RAD2DEG;
}

//-----------------------------------------------

csFloat csMathExp(float val)
{
	return exp(val);
}

//-----------------------------------------------

csFloat csMathLog(float val)
{
	return log(val);
}

//-----------------------------------------------

csFloat csMathLog10(float val)
{
	return log10(val);
}

//-----------------------------------------------

csInt csMathRand(int min, int max)
{
	return (rand() % (max - min)) + min;
}

//-----------------------------------------------

csVoid csMathRandSeed(int seed)
{
	return srand(seed);
}
