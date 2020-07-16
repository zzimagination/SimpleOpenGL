#include "Transform.h"

Matrix4x4 Transform::GetModelMatrix()
{
	mat4 model = mat4(1);
	model = glm::scale(model, scale);
	model = glm::rotate(model, radians(eulerAngle.x), vec3(1, 0, 0));
	model = glm::rotate(model, radians(eulerAngle.y), vec3(0, 1, 0));
	model = glm::rotate(model, radians(eulerAngle.z), vec3(0, 0, 1));
	model = glm::translate(model, position);
	return Matrix4x4(
		model[0][0], model[1][0], model[2][0], model[3][0],
		model[0][1], model[1][1], model[2][1], model[3][1],
		model[0][2], model[1][2], model[2][2], model[3][2],
		model[0][3], model[1][3], model[2][3], model[3][3]
	);
}

