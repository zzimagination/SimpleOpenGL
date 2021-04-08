#ifndef __MATHUTILITY__
#define __MATHUTILITY__

#include "MathBase.h"
#include "Float2.h"
#include "Float3.h"
#include "Float4.h"
#include "Color.h"
#include "Quaternion.h"
#include "Matrix4x4.h"

namespace SemperEngine
{
	constexpr int Left = 1;
	constexpr int Right = -1;

	class MathUtility
	{
	public:

		typedef int Direction;

	public:

		static Direction PointWithVectorDir(Float3 start, Float3 end, Float3 point)
		{
			auto v1 = end - start;
			auto v2 = point - start;
			return Float3::Cross(v1.ProjectionXZ(), v2.ProjectionXZ()).y > 0 ? Left : Right;
		}
	};
}

#endif // !__MATHUTILITY__