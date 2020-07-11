#ifndef  MATH_VECTOR2
#define MATH_VECTOR2

struct Vector3;

struct Vector2
{
public:

	float x = 0;

	float y = 0;

public:

	Vector2();

	Vector2(float x, float y);

public:

	Vector2 operator-();

	Vector2 operator+(const Vector2 &b);

	Vector2 operator-(const Vector2 &b);

	operator Vector3();
};

#endif //  MATH_VECTOR2


