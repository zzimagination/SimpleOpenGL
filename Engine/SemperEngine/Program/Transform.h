#ifndef __TRANSFORM__
#define __TRANSFORM__
#include "Common.h"

namespace Semper {

	class Transform
	{
	public:

		Float3 position;

		Quaternion rotation;

		Float3 scale;

	public:

		Transform();

		Float3 EulerAngle();

		Matrix4x4 GetModelMatrix();

	private:

		Matrix4x4 _modelMatrix;
	};

}
#endif // !TRANSFORM



