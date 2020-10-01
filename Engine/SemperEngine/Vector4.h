#ifndef MATH_VECTOR4
#define MATH_VECTOR4

namespace SemperEngine {

	class Vector4
	{
	public:

		float x;

		float y;

		float z;

		float w;

	public:

		Vector4();

		Vector4(float x, float y, float z, float w);

	public:

		Vector4 operator-();

		Vector4 operator+(const Vector4& b);

		Vector4 operator-(const Vector4& b);

		float operator*(const Vector4& b);
	};
}
#endif // !MATH_VECTOR4



