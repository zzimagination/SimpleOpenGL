#pragma once
#ifndef MATHZ
#define MATHZ

#define MATH_GLM

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

class  Math
{
public:

	static const float pi;
	//3.14159265358979323846264338327950288

#ifdef  MATH_GLM
	static float CosF(float a);
	static float SinF(float a);
	static float TanF(float a);
	static Vector3 CrossF(Vector3 a, Vector3 b);
	static float DotF(Vector3 a, Vector3 b);
#define CosFloat(a) CosF(a)
#define SinFloat(a) SinF(a)
#define TanFloat(a) TanF(a)
#define CrossFloat(a,b) CrossF(a,b)
#define DotFloat(a,b) DotF(a,b)
#endif //  MATH_GLM
public:

	static float Cos(float a);

	static float Sin(float a);

	static float Tan(float a);

	static Vector3 Cross(Vector3 a, Vector3 b);

	static float Dot(Vector3 a, Vector3 b);

	static float Clamp(float min, float max, float value);

	static int Floor(float f);

	static int Ceil(float f);

	static float Remainder(float a, float b);
};
#endif // !MATHZ
