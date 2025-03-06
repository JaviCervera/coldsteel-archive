#include "engine.h"

#define GRAD_PI (180.0 / 3.1415926535897932384626433832795)

std::vector<csMatrix*> matrixlist;

//-----------------------------------------------
//  Matrix functions
//-----------------------------------------------

void CleanMatrices()
{
	while (!matrixlist.empty())
		matrixlist.erase(matrixlist.begin());
}

//-----------------------------------------------

csInt csMatrixCreate()
{
	csMatrix* mat = new csMatrix;
	matrixlist.push_back(mat);
	return (int) mat;
}

//-----------------------------------------------

csVoid csMatrixFree(csMatrix* mat)
{
	// Remove matrix from list
	for (unsigned int i = 0; i < matrixlist.size(); i++)
		if (matrixlist[i] == mat)
		{
			matrixlist.erase(matrixlist.begin() + i);
			break;
		}

	delete mat;
}

//-----------------------------------------------

csVoid csMatrixAdd(csMatrix* mat, csMatrix* matrix2)
{
	for (int i = 0; i < 16; i++)
		mat->m[i] += matrix2->m[i];
}

//-----------------------------------------------

csVoid csMatrixCopy(csMatrix* mat, csMatrix* matrix2)
{
	for (int i = 0; i < 16; i++)
		mat->m[i] = matrix2->m[i];
}

//-----------------------------------------------

csVoid csMatrixDiv(csMatrix* mat, csMatrix* matrix2)
{
	for (int i = 0; i < 16; i++)
		mat->m[i] /= matrix2->m[i];
}

//-----------------------------------------------

csFloat csMatrixElement(csMatrix* mat, int row, int column)
{
	return mat->m[column*4 + row];
}

//-----------------------------------------------

csInt csMatrixEqual(csMatrix* mat, csMatrix* matrix2)
{
	for (int i = 0; i < 16; i++)
		if (mat->m[i] != matrix2->m[i])
			return false;
	return true;
}

//-----------------------------------------------

csVoid csMatrixGetRotation(csMatrix* mat, csVector* vector)
{
	double Y = -asin(csMatrixElement(mat, 2, 0));
	double D = Y;
	double C = cos(Y);
	Y *= GRAD_PI;

	double rotx, roty, X, Z;

	if (fabs(C) > 0.0005f)
	{
		rotx = csMatrixElement(mat, 2, 2) / C;
		roty = csMatrixElement(mat, 2, 1)  / C;
		X = atan2(roty, rotx) * GRAD_PI;
		rotx = csMatrixElement(mat, 0, 0) / C;
		roty = csMatrixElement(mat, 1, 0) / C;
		Z = atan2( roty, rotx ) * GRAD_PI;
	} else {
		X  = 0.0f;
		rotx = csMatrixElement(mat, 1, 1);
		roty = -csMatrixElement(mat, 0, 1);
		Z  = atan2( roty, rotx ) * (float)GRAD_PI;
	}

	// fix values that get below zero
	// before it would set (!) values to 360
	// that where above 360:
	if (X < 0.00) X += 360.00;
	if (Y < 0.00) Y += 360.00;
	if (Z < 0.00) Z += 360.00;

    vector->x = (float)X;
    vector->y = (float)Y;
    vector->z = (float)Z;
}

//-----------------------------------------------

csVoid csMatrixGetTranslation(csMatrix* mat, csVector* vector)
{
	vector->x = mat->m[12];
	vector->y = mat->m[13];
	vector->z = mat->m[14];
}

//-----------------------------------------------

csVoid csMatrixIdentity(csMatrix* mat)
{
	for (int i = 0; i < 16; i++)
		mat->m[i] = 0.0f;
	mat->m[0] = mat->m[5] = mat->m[10] = mat->m[15] = 1;
}

//-----------------------------------------------

csVoid csMatrixInterpolate(csMatrix* mat, csMatrix* matrix2, float time)
{
	float ntime = 1.0f - time;
	for (int i = 0; i < 16; ++i)
		mat->m[i] = mat->m[i]*ntime + matrix2->m[i]*time;
}

//-----------------------------------------------

bool getInverseMatrix(csMatrix* m, csMatrix* out)
{
	float d = (csMatrixElement(m, 0, 0) * csMatrixElement(m, 1, 1) - csMatrixElement(m, 1, 0) * csMatrixElement(m, 0, 1)) * (csMatrixElement(m, 2, 2) * csMatrixElement(m, 3, 3) - csMatrixElement(m, 3, 2) * csMatrixElement(m, 2, 3)) - (csMatrixElement(m, 0, 0) * csMatrixElement(m, 2, 1) - csMatrixElement(m, 2, 0) * csMatrixElement(m, 0, 1)) * (csMatrixElement(m, 1, 2) * csMatrixElement(m, 3, 3) - csMatrixElement(m, 3, 2) * csMatrixElement(m, 1, 3))
			+ (csMatrixElement(m, 0, 0) * csMatrixElement(m, 3, 1) - csMatrixElement(m, 3, 0) * csMatrixElement(m, 0, 1)) * (csMatrixElement(m, 1, 2) * csMatrixElement(m, 2, 3) - csMatrixElement(m, 2, 2) * csMatrixElement(m, 1, 3)) + (csMatrixElement(m, 1, 0) * csMatrixElement(m, 2, 1) - csMatrixElement(m, 2, 0) * csMatrixElement(m, 1, 1)) * (csMatrixElement(m, 0, 2) * csMatrixElement(m, 3, 3) - csMatrixElement(m, 3, 2) * csMatrixElement(m, 0, 3))
			- (csMatrixElement(m, 1, 0) * csMatrixElement(m, 3, 1) - csMatrixElement(m, 3, 0) * csMatrixElement(m, 1, 1)) * (csMatrixElement(m, 0, 2) * csMatrixElement(m, 2, 3) - csMatrixElement(m, 2, 2) * csMatrixElement(m, 0, 3)) + (csMatrixElement(m, 2, 0) * csMatrixElement(m, 3, 1) - csMatrixElement(m, 3, 0) * csMatrixElement(m, 2, 1)) * (csMatrixElement(m, 0, 2) * csMatrixElement(m, 1, 3) - csMatrixElement(m, 1, 2) * csMatrixElement(m, 0, 3));
	if (d == 0.f) return false;
	d = 1.f / d;
	csMatrixSet(out, 0, 0, d * (csMatrixElement(m, 1, 1) * (csMatrixElement(m, 2, 2) * csMatrixElement(m, 3, 3) - csMatrixElement(m, 3, 2) * csMatrixElement(m, 2, 3)) + csMatrixElement(m, 2, 1) * (csMatrixElement(m, 3, 2) * csMatrixElement(m, 1, 3) - csMatrixElement(m, 1, 2) * csMatrixElement(m, 3, 3)) + csMatrixElement(m, 3, 1) * (csMatrixElement(m, 1, 2) * csMatrixElement(m, 2, 3) - csMatrixElement(m, 2, 2) * csMatrixElement(m, 1, 3))));
	csMatrixSet(out, 1, 0, d * (csMatrixElement(m, 1, 2) * (csMatrixElement(m, 2, 0) * csMatrixElement(m, 3, 3) - csMatrixElement(m, 3, 0) * csMatrixElement(m, 2, 3)) + csMatrixElement(m, 2, 2) * (csMatrixElement(m, 3, 0) * csMatrixElement(m, 1, 3) - csMatrixElement(m, 1, 0) * csMatrixElement(m, 3, 3)) + csMatrixElement(m, 3, 2) * (csMatrixElement(m, 1, 0) * csMatrixElement(m, 2, 3) - csMatrixElement(m, 2, 0) * csMatrixElement(m, 1, 3))));
	csMatrixSet(out, 2, 0, d * (csMatrixElement(m, 1, 3) * (csMatrixElement(m, 2, 0) * csMatrixElement(m, 3, 1) - csMatrixElement(m, 3, 0) * csMatrixElement(m, 2, 1)) + csMatrixElement(m, 2, 3) * (csMatrixElement(m, 3, 0) * csMatrixElement(m, 1, 1) - csMatrixElement(m, 1, 0) * csMatrixElement(m, 3, 1)) + csMatrixElement(m, 3, 3) * (csMatrixElement(m, 1, 0) * csMatrixElement(m, 2, 1) - csMatrixElement(m, 2, 0) * csMatrixElement(m, 1, 1))));
	csMatrixSet(out, 3, 0, d * (csMatrixElement(m, 1, 0) * (csMatrixElement(m, 3, 1) * csMatrixElement(m, 2, 2) - csMatrixElement(m, 2, 1) * csMatrixElement(m, 3, 2)) + csMatrixElement(m, 2, 0) * (csMatrixElement(m, 1, 1) * csMatrixElement(m, 3, 2) - csMatrixElement(m, 3, 1) * csMatrixElement(m, 1, 2)) + csMatrixElement(m, 3, 0) * (csMatrixElement(m, 2, 1) * csMatrixElement(m, 1, 2) - csMatrixElement(m, 1, 1) * csMatrixElement(m, 2, 2))));
	csMatrixSet(out, 0, 1, d * (csMatrixElement(m, 2, 1) * (csMatrixElement(m, 0, 2) * csMatrixElement(m, 3, 3) - csMatrixElement(m, 3, 2) * csMatrixElement(m, 0, 3)) + csMatrixElement(m, 3, 1) * (csMatrixElement(m, 2, 2) * csMatrixElement(m, 0, 3) - csMatrixElement(m, 0, 2) * csMatrixElement(m, 2, 3)) + csMatrixElement(m, 0, 1) * (csMatrixElement(m, 3, 2) * csMatrixElement(m, 2, 3) - csMatrixElement(m, 2, 2) * csMatrixElement(m, 3, 3))));
	csMatrixSet(out, 1, 1, d * (csMatrixElement(m, 2, 2) * (csMatrixElement(m, 0, 0) * csMatrixElement(m, 3, 3) - csMatrixElement(m, 3, 0) * csMatrixElement(m, 0, 3)) + csMatrixElement(m, 3, 2) * (csMatrixElement(m, 2, 0) * csMatrixElement(m, 0, 3) - csMatrixElement(m, 0, 0) * csMatrixElement(m, 2, 3)) + csMatrixElement(m, 0, 2) * (csMatrixElement(m, 3, 0) * csMatrixElement(m, 2, 3) - csMatrixElement(m, 2, 0) * csMatrixElement(m, 3, 3))));
	csMatrixSet(out, 2, 1, d * (csMatrixElement(m, 2, 3) * (csMatrixElement(m, 0, 0) * csMatrixElement(m, 3, 1) - csMatrixElement(m, 3, 0) * csMatrixElement(m, 0, 1)) + csMatrixElement(m, 3, 3) * (csMatrixElement(m, 2, 0) * csMatrixElement(m, 0, 1) - csMatrixElement(m, 0, 0) * csMatrixElement(m, 2, 1)) + csMatrixElement(m, 0, 3) * (csMatrixElement(m, 3, 0) * csMatrixElement(m, 2, 1) - csMatrixElement(m, 2, 0) * csMatrixElement(m, 3, 1))));
	csMatrixSet(out, 3, 1, d * (csMatrixElement(m, 2, 0) * (csMatrixElement(m, 3, 1) * csMatrixElement(m, 0, 2) - csMatrixElement(m, 0, 1) * csMatrixElement(m, 3, 2)) + csMatrixElement(m, 3, 0) * (csMatrixElement(m, 0, 1) * csMatrixElement(m, 2, 2) - csMatrixElement(m, 2, 1) * csMatrixElement(m, 0, 2)) + csMatrixElement(m, 0, 0) * (csMatrixElement(m, 2, 1) * csMatrixElement(m, 3, 2) - csMatrixElement(m, 3, 1) * csMatrixElement(m, 2, 2))));
	csMatrixSet(out, 0, 2, d * (csMatrixElement(m, 3, 1) * (csMatrixElement(m, 0, 2) * csMatrixElement(m, 1, 3) - csMatrixElement(m, 1, 2) * csMatrixElement(m, 0, 3)) + csMatrixElement(m, 0, 1) * (csMatrixElement(m, 1, 2) * csMatrixElement(m, 3, 3) - csMatrixElement(m, 3, 2) * csMatrixElement(m, 1, 3)) + csMatrixElement(m, 1, 1) * (csMatrixElement(m, 3, 2) * csMatrixElement(m, 0, 3) - csMatrixElement(m, 0, 2) * csMatrixElement(m, 3, 3))));
	csMatrixSet(out, 1, 2, d * (csMatrixElement(m, 3, 2) * (csMatrixElement(m, 0, 0) * csMatrixElement(m, 1, 3) - csMatrixElement(m, 1, 0) * csMatrixElement(m, 0, 3)) + csMatrixElement(m, 0, 2) * (csMatrixElement(m, 1, 0) * csMatrixElement(m, 3, 3) - csMatrixElement(m, 3, 0) * csMatrixElement(m, 1, 3)) + csMatrixElement(m, 1, 2) * (csMatrixElement(m, 3, 0) * csMatrixElement(m, 0, 3) - csMatrixElement(m, 0, 0) * csMatrixElement(m, 3, 3))));
	csMatrixSet(out, 2, 2, d * (csMatrixElement(m, 3, 3) * (csMatrixElement(m, 0, 0) * csMatrixElement(m, 1, 1) - csMatrixElement(m, 1, 0) * csMatrixElement(m, 0, 1)) + csMatrixElement(m, 0, 3) * (csMatrixElement(m, 1, 0) * csMatrixElement(m, 3, 1) - csMatrixElement(m, 3, 0) * csMatrixElement(m, 1, 1)) + csMatrixElement(m, 1, 3) * (csMatrixElement(m, 3, 0) * csMatrixElement(m, 0, 1) - csMatrixElement(m, 0, 0) * csMatrixElement(m, 3, 1))));
	csMatrixSet(out, 3, 2, d * (csMatrixElement(m, 3, 0) * (csMatrixElement(m, 1, 1) * csMatrixElement(m, 0, 2) - csMatrixElement(m, 0, 1) * csMatrixElement(m, 1, 2)) + csMatrixElement(m, 0, 0) * (csMatrixElement(m, 3, 1) * csMatrixElement(m, 1, 2) - csMatrixElement(m, 1, 1) * csMatrixElement(m, 3, 2)) + csMatrixElement(m, 1, 0) * (csMatrixElement(m, 0, 1) * csMatrixElement(m, 3, 2) - csMatrixElement(m, 3, 1) * csMatrixElement(m, 0, 2))));
	csMatrixSet(out, 0, 3, d * (csMatrixElement(m, 0, 1) * (csMatrixElement(m, 2, 2) * csMatrixElement(m, 1, 3) - csMatrixElement(m, 1, 2) * csMatrixElement(m, 2, 3)) + csMatrixElement(m, 1, 1) * (csMatrixElement(m, 0, 2) * csMatrixElement(m, 2, 3) - csMatrixElement(m, 2, 2) * csMatrixElement(m, 0, 3)) + csMatrixElement(m, 2, 1) * (csMatrixElement(m, 1, 2) * csMatrixElement(m, 0, 3) - csMatrixElement(m, 0, 2) * csMatrixElement(m, 1, 3))));
	csMatrixSet(out, 1, 3, d * (csMatrixElement(m, 0, 2) * (csMatrixElement(m, 2, 0) * csMatrixElement(m, 1, 3) - csMatrixElement(m, 1, 0) * csMatrixElement(m, 2, 3)) + csMatrixElement(m, 1, 2) * (csMatrixElement(m, 0, 0) * csMatrixElement(m, 2, 3) - csMatrixElement(m, 2, 0) * csMatrixElement(m, 0, 3)) + csMatrixElement(m, 2, 2) * (csMatrixElement(m, 1, 0) * csMatrixElement(m, 0, 3) - csMatrixElement(m, 0, 0) * csMatrixElement(m, 1, 3))));
	csMatrixSet(out, 2, 3, d * (csMatrixElement(m, 0, 3) * (csMatrixElement(m, 2, 0) * csMatrixElement(m, 1, 1) - csMatrixElement(m, 1, 0) * csMatrixElement(m, 2, 1)) + csMatrixElement(m, 1, 3) * (csMatrixElement(m, 0, 0) * csMatrixElement(m, 2, 1) - csMatrixElement(m, 2, 0) * csMatrixElement(m, 0, 1)) + csMatrixElement(m, 2, 3) * (csMatrixElement(m, 1, 0) * csMatrixElement(m, 0, 1) - csMatrixElement(m, 0, 0) * csMatrixElement(m, 1, 1))));
	csMatrixSet(out, 3, 3, d * (csMatrixElement(m, 0, 0) * (csMatrixElement(m, 1, 1) * csMatrixElement(m, 2, 2) - csMatrixElement(m, 2, 1) * csMatrixElement(m, 1, 2)) + csMatrixElement(m, 1, 0) * (csMatrixElement(m, 2, 1) * csMatrixElement(m, 0, 2) - csMatrixElement(m, 0, 1) * csMatrixElement(m, 2, 2)) + csMatrixElement(m, 2, 0) * (csMatrixElement(m, 0, 1) * csMatrixElement(m, 1, 2) - csMatrixElement(m, 1, 1) * csMatrixElement(m, 0, 2))));
	return true;
}

csInt csMatrixInvert(csMatrix* mat)
{
	csMatrix temp;
	if (getInverseMatrix(mat, &temp))
	{
		csMatrixCopy(mat, &temp);
		return true;
	}
	return false;
}

//-----------------------------------------------

csVoid csMatrixMul(csMatrix* mat, csMatrix* matrix2)
{
	int i;
	float a0, a1, a2, a3;
	for (i=0; i<4; i++)
	{
		a0 = mat->m[i];
		a1 = mat->m[4+i];
		a2 = mat->m[8+i];
		a3 = mat->m[12+i];
		mat->m[i]    = a0*matrix2->m[0]  + a1*matrix2->m[1]  + a2*matrix2->m[2]  + a3*matrix2->m[3];
		mat->m[4+i]  = a0*matrix2->m[4]  + a1*matrix2->m[5]  + a2*matrix2->m[6]  + a3*matrix2->m[7];
		mat->m[8+i]	= a0*matrix2->m[8]  + a1*matrix2->m[9]  + a2*matrix2->m[10] + a3*matrix2->m[11];
		mat->m[12+i] = a0*matrix2->m[12] + a1*matrix2->m[13] + a2*matrix2->m[14] + a3*matrix2->m[15];
	}
}

//-----------------------------------------------

csVoid csMatrixSet(csMatrix* mat, int row, int column, float val)
{
	mat->m[column*4 + row] = val;
}

//-----------------------------------------------

csVoid csMatrixSetRotation(csMatrix* mat, csVector* vector)
{
	double cr = cos(vector->x * 3.1415926535897932384626433832795 / 180.0);
	double sr = sin(vector->x * 3.1415926535897932384626433832795 / 180.0);
	double cp = cos(vector->y * 3.1415926535897932384626433832795 / 180.0);
	double sp = sin(vector->y * 3.1415926535897932384626433832795 / 180.0);
	double cy = cos(vector->z * 3.1415926535897932384626433832795 / 180.0);
	double sy = sin(vector->z * 3.1415926535897932384626433832795 / 180.0);

	mat->m[0] = (float)(cp*cy);
	mat->m[1] = (float)(cp*sy);
	mat->m[2] = (float)(-sp);

	double srsp = sr*sp;
	double crsp = cr*sp;

	mat->m[4] = (float)(srsp*cy-cr*sy);
	mat->m[5] = (float)(srsp*sy+cr*cy);
	mat->m[6] = (float)(sr*cp);

	mat->m[8] = (float)(crsp*cy+sr*sy);
	mat->m[9] = (float)(crsp*sy-sr*cy);
	mat->m[10] = (float)(cr*cp);
}

//-----------------------------------------------

csVoid csMatrixSetScale(csMatrix* mat, csVector* vector)
{
	mat->m[0] = vector->x;
	mat->m[5] = vector->y;
	mat->m[10] = vector->z;
}

//-----------------------------------------------

csVoid csMatrixSetTranslation(csMatrix* mat, csVector* vector)
{
	mat->m[12] = vector->x;
	mat->m[13] = vector->y;
	mat->m[14] = vector->z;
}

//-----------------------------------------------

csVoid csMatrixSub(csMatrix* mat, csMatrix* matrix2)
{
	for (int i = 0; i < 16; i++)
		mat->m[i] -= matrix2->m[i];
}

//-----------------------------------------------

csVoid csMatrixTranspose(csMatrix* mat)
{
	csMatrix m;
	for (int r = 0; r < 4; r++)
		for (int c = 0; c < 4; c++)
			csMatrixSet(&m, r, c, csMatrixElement(mat, c, r));
	csMatrixCopy(mat, &m);
}
