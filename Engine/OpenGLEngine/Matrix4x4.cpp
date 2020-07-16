#include "Matrix4x4.h"

Matrix4x4::Matrix4x4()
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			points[i][j] = 0;
		}
	}
}

Matrix4x4::Matrix4x4(Vector3& r0, Vector3& r1, Vector3& r2, Vector3& r3)
{
	row0 = r0;
	row1 = r1;
	row2 = r2;
	row3 = r3;

	points[0][0] = r0.x;
	points[0][1] = r0.y;
	points[0][2] = r0.z;
	points[0][3] = 0;

	points[1][0] = r1.x;
	points[1][1] = r1.y;
	points[1][2] = r1.z;
	points[1][3] = 0;

	points[2][0] = r2.x;
	points[2][1] = r2.y;
	points[2][2] = r2.z;
	points[2][3] = 0;

	points[3][0] = r3.x;
	points[3][1] = r3.y;
	points[3][2] = r3.z;
	points[3][3] = 0;
}

Matrix4x4::Matrix4x4(float r0c0, float r0c1, float r0c2, float r0c3, float r1c0, float r1c1, float r1c2, float r1c3, float r2c0, float r2c1, float r2c2, float r2c3, float r3c0, float r3c1, float r3c2, float r3c3)
{
	row0 = { r0c0,r0c1,r0c2 };
	row1 = { r1c0,r1c1,r1c2 };
	row2 = { r2c0,r2c1,r2c2 };
	row3 = { r3c0,r3c1,r3c2 };

	points[0][0] = r0c0;
	points[0][1] = r0c1;
	points[0][2] = r0c2;
	points[0][3] = r0c3;

	points[1][0] = r1c0;
	points[1][1] = r1c1;
	points[1][2] = r1c2;
	points[1][3] = r1c3;

	points[2][0] = r2c0;
	points[2][1] = r2c1;
	points[2][2] = r2c2;
	points[2][3] = r2c3;

	points[3][0] = r3c0;
	points[3][1] = r3c1;
	points[3][2] = r3c2;
	points[3][3] = r3c3;
}

float* Matrix4x4::operator[](int i)
{
	return points[i];
}

const float* Matrix4x4::operator[](int i) const
{
	return points[i];
}
