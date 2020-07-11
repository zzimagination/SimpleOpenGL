#ifndef MATH_MATRIX4X4
#define MATH_MATRIX4X4
#include "Vector3.h"

struct Matrix4x4
{
public:

	Matrix4x4();

	Matrix4x4(Vector3 r0, Vector3 r1, Vector3 r2, Vector3 r3);

	Matrix4x4(float r0c0, float r0c1, float r0c2, float r0c3,
		float r1c0, float r1c1, float r1c2, float r1c3,
		float r2c0, float r2c1, float r2c2, float r2c3,
		float r3c0, float r3c1, float r3c2, float r3c3);
public:

	Vector3 row0, row1, row2, row3;

private:

	float points[4][4];

public:

	float* operator[](int i);
};
#endif 

