#ifndef __MATHZ_VECTOR3__
#define __MATHZ_VECTOR3__

#include "MathBase.h"
#include "Float2.h"

namespace SemperEngine {

	class Float3
	{
	public:

		const static Float3 right;

		const static Float3 up;

		const static Float3 forward;

	public:

		static Float3 Cross(const Float3 &a, const Float3 &b);

		static float Dot(const Float3 &a, const Float3 &b);

	public:

		float x;

		float y;

		float z;

	public:

		Float3();

		Float3(const float& x, const float& y, const float& z);

		Float3(const Float2& value);

		Float3 Normalize();

		float Length();

		Float3 ProjectionXZ();

	public:

		Float3 operator-();

		Float3 operator+(const Float3& b);

		Float3 operator-(const Float3& b);

		Float3 operator*(const float& right);

		Float3 operator/(const float& right);

		friend Float3 operator*(const float& left, const Float3& right);
	};
}
#endif // !MATH_VECTOR3

