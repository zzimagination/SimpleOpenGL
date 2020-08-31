#ifndef TRANSFORM
#define TRANSFORM
#include "Mathz.h"

namespace SemperEngine {

	class Transform
	{
	public:

		Vector3 position;

		Vector3 eulerAngle;

		Vector3 scale;

	public:

		Transform();

		Matrix4x4 GetModelMatrix();

	private:

		Matrix4x4 _modelMatrix;
	};

}
#endif // !TRANSFORM



