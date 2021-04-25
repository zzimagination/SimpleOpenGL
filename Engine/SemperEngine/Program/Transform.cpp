#include "Transform.h"

namespace Semper {

	Transform::Transform()
	{
		position = Float3();

		rotation = Quaternion();

		scale = Float3(1, 1, 1);
	}

	Float3 Transform::EulerAngle()
	{
		return Float3();
	}

	Matrix4x4 Transform::GetModelMatrix()
	{
		Matrix4x4 translate_m = Matrix4x4::Translate(position);
		Matrix4x4 rotation_m = rotation.ToMatrix(); 
		Matrix4x4 scale_m = Matrix4x4::Scale(scale);
		_modelMatrix = translate_m * rotation_m * scale_m;
		return _modelMatrix;
	}
}
