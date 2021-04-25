#ifndef __MATHZ_MATRIX4X4__
#define __MATHZ_MATRIX4X4__

#include "MathBase.h"
#include "Float3.h"
#include "Float4.h"

namespace Semper
{
	/// <summary>
	/// ––æÿ’Û
	/// </summary>
	struct Matrix4x4
	{
	public:

		float x0, y0, z0, w0,
			x1, y1, z1, w1,
			x2, y2, z2, w2,
			x3, y3, z3, w3;

	public:

		static Matrix4x4 Translate(const Float3& v);

		static Matrix4x4 Rotate(const Float3& v);

		static Matrix4x4 Scale(const Float3& v);

		static Matrix4x4 Identity();

	public:

		Matrix4x4();

		Matrix4x4(const Float4& r0, const Float4& r1, const Float4& r2, const Float4& r3);

		Matrix4x4(const float& r0c0, const float& r0c1, const float& r0c2, const float& r0c3,
			const float& r1c0, const float& r1c1, const float& r1c2, const float& r1c3,
			const float& r2c0, const float& r2c1, const float& r2c2, const float& r2c3,
			const float& r3c0, const float& r3c1, const float& r3c2, const float& r3c3);

		Float4 GetRow(const int& i) const;

		Float4 GetColumn(const int& i) const;

	public:

		Matrix4x4 operator*(const Matrix4x4& b);

		Float3 operator*(const Float3& right);

	};
}
#endif 

