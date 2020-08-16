#ifndef TRANSFORM
#define TRANSFORM
#include "Mathz.h"

namespace SemperEngine {

	class Transform
	{
	public:

		Vector3 position = Vector3(0, 0, 0);

		Vector3 eulerAngle = Vector3(0, 0, 0);

		Vector3 scale = Vector3(1, 1, 1);

	public:

		Matrix4x4 GetModelMatrix();

	private:

		Matrix4x4 _modelMatrix;
	};

}
#endif // !TRANSFORM



