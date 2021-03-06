#ifndef __MATHZ_BASE__
#define __MATHZ_BASE__

#include "../Collection/Collection.h"

namespace Semper {

	class  Math
	{
	public:

		static const float pi;

	public:

		static float Cos(const float& a);

		static float CosR(const float& r);

		static float Sin(const float& a);

		static float SinR(const float& r);

		static float Tan(const float& a);

		static float TanR(const float& r);

		static float Cot(const float& a);

		static float ArcCos(const float& a);

		static float ArcSin(const float& a);

		static float ArcTan(const float& a);

		static float Clamp(const float& min, const float& max, const float& value);

		static int Floor(const float& f);

		static int Ceil(const float& f);

		static float Remainder(const float& a, const float& b);

		static float Max(const float& a, const float& b);

		static float Min(const float& a, const float& b);

		static float Abs(const float& a);

		static float Sqrt(const float& a);

	};
}

#endif // !MATH_BASE
