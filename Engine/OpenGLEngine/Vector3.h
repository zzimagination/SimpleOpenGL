#ifndef MATH_VECTOR3
#define MATH_VECTOR3

struct Vector3
{
public:

	static Vector3 left;

	static Vector3 up;

	static Vector3 forward;

public:

	float x = 0;

	float y = 0;

	float z = 0;

public:

	Vector3();

	Vector3(const Vector3& a);

	Vector3(float x, float y, float z);

public:
	
	Vector3 operator-();

	Vector3 operator+(const Vector3& b);

	Vector3 operator-(const Vector3& b);

};
#endif // !MATH_VECTOR3

