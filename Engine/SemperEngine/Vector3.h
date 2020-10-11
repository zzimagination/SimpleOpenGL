#ifndef __MATHZ_VECTOR3__
#define __MATHZ_VECTOR3__

namespace SemperEngine {

	class Vector3
	{
	public:

		const static Vector3 right;

		const static Vector3 up;

		const static Vector3 forward;

	public:

		static Vector3 Cross(Vector3 a, Vector3 b);

		static float Dot(Vector3 a, Vector3 b);

	public:

		float x;

		float y;

		float z;

	public:

		Vector3();

		Vector3(const Vector3& a);

		Vector3(float x, float y, float z);

		Vector3 Normalize();

		float Length();

	public:

		Vector3 operator-();

		Vector3 operator+(const Vector3& b);

		Vector3 operator-(const Vector3& b);

		Vector3 operator*(const float& right);

		friend Vector3 operator*(const float& left, Vector3 right);
	};
}
#endif // !MATH_VECTOR3

