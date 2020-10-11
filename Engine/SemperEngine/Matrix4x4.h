#ifndef __MATHZ_MATRIX4X4__
#define __MATHZ_MATRIX4X4__

#include "Vector3.h"
#include "Vector4.h"

namespace SemperEngine {
	struct Matrix4x4
	{
	public:

		float x0, y0, z0, w0,
			  x1, y1, z1, w1,
			  x2, y2, z2, w2,
			  x3, y3, z3, w3;

	public:

		static Matrix4x4 Translate(Vector3 v);

		static Matrix4x4 Rotate(Vector3 v);

		static Matrix4x4 Scale(Vector3 v);

		static Matrix4x4 Identity();
			
	public:

		Matrix4x4();

		Matrix4x4(Vector4 r0, Vector4 r1, Vector4 r2, Vector4 r3);

		Matrix4x4(float r0c0, float r0c1, float r0c2, float r0c3,
			float r1c0, float r1c1, float r1c2, float r1c3,
			float r2c0, float r2c1, float r2c2, float r2c3,
			float r3c0, float r3c1, float r3c2, float r3c3);

		Vector4 GetRow(int i) const;

		Vector4 GetColumn(int i) const;

	public:

		Matrix4x4 operator*(const Matrix4x4 &b);

		Vector3 operator*(const Vector3 &right);

	};
}
#endif 

