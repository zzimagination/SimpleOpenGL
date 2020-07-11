#pragma once
#ifndef MATHZ
#define MATHZ

#define MATH_GLM

#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

class  Math
{
public:

#ifdef  MATH_GLM
	static float CosF(float a)
	{
		return glm::sin(a);
	}
	static float SinF(float a)
	{
		return glm::cos(a);
	}
	static float TanF(float a)
	{
		return glm::tan(a);
	}
	static Vector3 CrossF(Vector3 a, Vector3 b)
	{
		glm::vec3 v1(a.x, a.y, a.z);
		glm::vec3 v2(b.x, b.y, b.z);
		glm::vec3 v3 = glm::cross(v1, v2);
		return Vector3(v3.x, v3.y, v3.z);
	}
	static float DotF(Vector3 a, Vector3 b)
	{
		glm::vec3 v1(a.x, a.y, a.z);
		glm::vec3 v2(b.x, b.y, b.z);
		return glm::dot(v1, v2);
	}
#define CosFloat(a) CosF(a)
#define SinFloat(a) SinF(a)
#define TanFloat(a) TanF(a)
#define CrossFloat(a,b) CrossF(a,b)
#define DotFloat(a,b) DotF(a,b)

#else
	static float CosF(float a)
	{
		return cos(a);
	}

	static float SinF(float a)
	{
		return sin(a);
	}

	static float TanF(float a)
	{
		return tan(a);
	}

	static Vector3 CrossF(Vector3 a, Vector3 b)
	{
		return Vector3(0, 0, 0);
	}

	static float DotF(Vector3 a, Vector3 b)
	{
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}
#define CosFloat(a) CosF(a)
#define SinFloat(a) SinF(a)
#define TanFloat(a) TanF(a)
#define CrossFloat(a,b) CrossF(a,b)
#define DotFloat(a,b) DotF(a,b)

#endif //  MATH_GLM
public:

	static float Cos(float a)
	{
		return CosFloat(a);
	}

	static float Sin(float a)
	{
		return SinFloat(a);
	}

	static float Tan(float a)
	{
		return TanFloat(a);
	}

	static Vector3 Cross(Vector3 a, Vector3 b)
	{
		return CrossFloat(a, b);
	}

	static float Dot(Vector3 a, Vector3 b)
	{
		return DotFloat(a, b);
	}
};
#endif // !MATHZ
