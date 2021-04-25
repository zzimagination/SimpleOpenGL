#pragma once
#ifndef __MATH_QUATERNION__
#define __MATH_QUATERNION__

#include "MathBase.h"
#include "Float3.h"
#include "Float4.h"
#include "Matrix4x4.h"

namespace Semper
{
	class Quaternion
	{
	public:

		static Quaternion AngleAxis(const float &angle, const Float3 &axis);

	private:

		Float4 _data;

	public:

		Quaternion();

		Quaternion(const float &x, const float &y,const float &z,const float &w);

		float X();

		float Y();

		float Z();

		float W();

		Quaternion inverse();

		Matrix4x4 ToMatrix();

		Quaternion& operator=(const Quaternion& right);

		Quaternion operator*(const Quaternion& right);

		Float3 operator*(const Float3& right);
	};
}

#endif // !__MATH_QUATERNION__
