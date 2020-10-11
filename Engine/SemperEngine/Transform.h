#ifndef __TRANSFORM__
#define __TRANSFORM__
#include "Mathz.h"

namespace SemperEngine {

	class Transform
	{
	public:

		Vector3 position;

		Quaternion rotation;

		Vector3 scale;

	public:

		Transform();

		Vector3 EulerAngle();

		Matrix4x4 GetModelMatrix();

	private:

		Matrix4x4 _modelMatrix;
	};

}
#endif // !TRANSFORM



