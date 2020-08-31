#ifndef MATHZ
#define MATHZ

#include "MathBase.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

namespace SemperEngine {

	class  MathVector
	{
	public:

		static Vector3 Cross(Vector3 a, Vector3 b);

		static float Dot(Vector3 a, Vector3 b);

	};
}
#endif // !MATHZ
