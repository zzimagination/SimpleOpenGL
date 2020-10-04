#ifndef MATH_BASE
#define MATH_BASE

#define MATH_GLM

namespace SemperEngine {

	class  Math
	{
	public:

		static const float pi;
		//3.14159265358979323846264338327950288

	public:

		static float Cos(float a);

		static float Sin(float a);

		static float Tan(float a);

		static float Clamp(float min, float max, float value);

		static int Floor(float f);

		static int Ceil(float f);

		static float Remainder(float a, float b);

		static float Max(float a, float b);

		static float Min(float a, float b);

	};
}

#endif // !MATH_BASE
