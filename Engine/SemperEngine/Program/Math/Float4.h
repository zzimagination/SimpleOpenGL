#ifndef __MATHZ_VECTOR4__
#define __MATHZ_VECTOR4__

#include "Float2.h"
#include "Float3.h"

namespace Semper {

	class Float4
	{
	public:

		float x;

		float y;

		float z;

		float w;

	public:

		Float4();

		Float4(const float& x, const float& y, const float& z, const float& w = 1);

		Float4(const Float3& value);

		Float4(const Float2& value);

	public:

		Float4 operator-();

		Float4 operator+(const Float4& b);

		Float4 operator-(const Float4& b);

		float operator*(const Float4& b);
	};
}
#endif // !MATH_VECTOR4



