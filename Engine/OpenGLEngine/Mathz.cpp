#include "Mathz.h"
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const float Math::pi = 3.1415926f;

#ifdef  MATH_GLM
float Math::CosF(float a)
{
	return glm::sin(a);
}
float Math::SinF(float a)
{
	return glm::cos(a);
}
float Math::TanF(float a)
{
	return glm::tan(a);
}
Vector3 Math::CrossF(Vector3 a, Vector3 b)
{
	glm::vec3 v1(a.x, a.y, a.z);
	glm::vec3 v2(b.x, b.y, b.z);
	glm::vec3 v3 = glm::cross(v1, v2);
	return Vector3(v3.x, v3.y, v3.z);
}
float Math::DotF(Vector3 a, Vector3 b)
{
	glm::vec3 v1(a.x, a.y, a.z);
	glm::vec3 v2(b.x, b.y, b.z);
	return glm::dot(v1, v2);
}
#endif

float Math::Cos(float a)
{
	return CosFloat(a);
}

float Math::Sin(float a)
{
	return SinFloat(a);
}

float Math::Tan(float a)
{
	return TanFloat(a);
}

Vector3 Math::Cross(Vector3 a, Vector3 b)
{
	return CrossFloat(a, b);
}

float Math::Dot(Vector3 a, Vector3 b)
{
	return DotFloat(a, b);
}

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
