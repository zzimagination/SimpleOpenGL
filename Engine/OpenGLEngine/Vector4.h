#ifndef MATH_VECTOR4
#define MATH_VECTOR4

struct Vector4
{
public:

	Vector4();

	Vector4(float x, float y, float z, float w);

public:

	float x = 0;

	float y = 0;

	float z = 0;

	float w = 0;

public:

	Vector4 operator-();

	Vector4 operator+(const Vector4& b);

	Vector4 operator-(const Vector4& b);

	float operator*(const Vector4& b);
};
#endif // !MATH_VECTOR4



