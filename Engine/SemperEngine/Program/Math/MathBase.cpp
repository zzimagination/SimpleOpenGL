#include "MathBase.h"
#include <math.h>

namespace SemperEngine {

	const float Math::pi = 3.1415926f;		//3.14159265358979323846264338327950288

	float Math::Clamp(const float& min, const float& max, const float& value)
	{
		auto tmp = fmaxf(min, value);
		return fminf(max, tmp);
	}

	int Math::Floor(const float& f)
	{
		return int(f);
	}

	int Math::Ceil(const float& f)
	{
		return int(f) + 1;
	}

	float Math::Remainder(const float& a, const float& b)
	{
		return fmodf(a, b);
	}

	float Math::Max(const float& a, const float& b)
	{
		return fmaxf(a, b);
	}

	float Math::Min(const float& a, const float& b)
	{
		return fminf(a, b);
	}

	float Math::Abs(const float& a)
	{
		return fabsf(a);
	}

	float Math::Sqrt(const float& a)
	{
		return sqrtf(a);
	}

	float Math::Cos(const float& a)
	{
		return cosf(a * pi / 180);
	}

	float Math::CosR(const float& r)
	{
		return cosf(r);
	}

	float Math::Sin(const float& a)
	{
		return sinf(a * pi / 180);
	}

	float Math::SinR(const float& r)
	{
		return sinf(r);
	}

	float Math::Tan(const float& a)
	{
		return tanf(a * pi / 180);
	}

	float Math::TanR(const float& r)
	{
		return tanf(r);
	}

	float Math::Cot(const float& a)
	{
		float a1 = 90 - a;
		return tanf(a1 * pi / 180);
	}

	float Math::ArcCos(const float& a)
	{
		auto red = acosf(a);
		return red / pi * 180;
	}

	float Math::ArcSin(const float& a)
	{
		auto red = asinf(a);
		return red / pi * 180;
	}

	float Math::ArcTan(const float& a)
	{
		auto red = atanf(a);
		return red / pi * 180;
	}
}