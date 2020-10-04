#include "MathBase.h"
#include <math.h>

#ifdef  MATH_GLM
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#endif

namespace SemperEngine {

	const float Math::pi = 3.1415926f;

	float Math::Clamp(float min, float max, float value)
	{
		value = fmax(min, value);
		value = fmin(max, value);
		return value;
	}

	int Math::Floor(float f)
	{
		return int(f);
	}

	int Math::Ceil(float f)
	{
		return int(f) + 1;
	}

	float Math::Remainder(float a, float b)
	{
		return fmod(a, b);
	}

	float Math::Max(float a, float b)
	{
		return std::fmaxf(a, b);
	}

	float Math::Min(float a, float b)
	{
		return std::fminf(a, b);
	}

	float Math::Cos(float a)
	{
		return cosf(a*pi / 180);
	}

	float Math::Sin(float a)
	{
		return sinf(a*pi / 180);
	}

	float Math::Tan(float a)
	{
		return tanf(a*pi / 180);
	}

}