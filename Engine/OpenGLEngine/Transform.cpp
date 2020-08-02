#include "Transform.h"

Matrix4x4 Transform::GetModelMatrix()
{
	Matrix4x4 translate_m = Matrix4x4::Translate(position);
	Matrix4x4 rotation_m = Matrix4x4::Rotate(eulerAngle);
	Matrix4x4 scale_m = Matrix4x4::Scale(scale);
	_modelMatrix = translate_m * rotation_m * scale_m;
	return _modelMatrix;
}

