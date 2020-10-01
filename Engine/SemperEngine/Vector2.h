#ifndef MATH_VECTOR2
#define MATH_VECTOR2
namespace SemperEngine {

	class Vector2
	{
	public:

		float x ;

		float y ;

	public:

		static float Dot(Vector2 a, Vector2 b);

	public:

		Vector2();

		Vector2(float x, float y);

	public:

		Vector2 operator-();

		Vector2 operator+(const Vector2 &b);

		Vector2 operator-(const Vector2 &b);

	};
}
#endif //  MATH_VECTOR2


