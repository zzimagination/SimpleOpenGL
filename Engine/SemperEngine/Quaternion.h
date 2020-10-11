#pragma once
#ifndef __MATH_QUATERNION__
#define __MATH_QUATERNION__

#include "MathBase.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

namespace SemperEngine
{
	class Quaternion
	{
	public:

		static Quaternion AngleAxis(float angle, Vector3 axis);

	private:

		Vector4 _data;

	public:

		Quaternion();

		Quaternion(float x, float y, float z, float w);

		float X();

		float Y();

		float Z();

		float W();

		Quaternion inverse();

		Matrix4x4 ToMatrix();

		Quaternion& operator=(const Quaternion& right);

		Quaternion operator*(const Quaternion& right);

		Vector3 operator*(const Vector3& right);
	private:

	};
}

#endif // !__MATH_QUATERNION__
