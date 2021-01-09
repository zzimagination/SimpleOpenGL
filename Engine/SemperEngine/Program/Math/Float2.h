#ifndef __MATHZ_VECTOR2__
#define __MATHZ_VECTOR2__

namespace SemperEngine 
{
	class Float2
	{
	public:

		float x ;

		float y ;

	public:

		static float Dot(const Float2 &a, const Float2 &b);

	public:

		Float2();

		Float2(const float& x, const float& y);

	public:

		Float2 operator-();

		Float2 operator+(const Float2 &b);

		Float2 operator-(const Float2 &b);

		Float2 operator*(const float& b);

		Float2 operator/(const float& b);

		friend Float2 operator*(const float& left, const Float2& right);
	};
}
#endif //  MATH_VECTOR2


