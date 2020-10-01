#ifndef MATH_VECTOR3
#define MATH_VECTOR3

namespace SemperEngine {

	class Vector3
	{
	public:

		static Vector3 left;

		static Vector3 up;

		static Vector3 forward;

	public:

		float x ;

		float y ;

		float z ;

	public:

		static Vector3 Cross(Vector3 a, Vector3 b);

		static float Dot(Vector3 a, Vector3 b);

	public:

		Vector3();

		Vector3(const Vector3& a);

		Vector3(float x, float y, float z);

		Vector3 Normalize();

	public:

		Vector3 operator-();

		Vector3 operator+(const Vector3& b);

		Vector3 operator-(const Vector3& b);

	};
}
#endif // !MATH_VECTOR3

