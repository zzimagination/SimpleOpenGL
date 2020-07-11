#include "Transform.h"

mat4 Transform::GetModelMatrix()
{
	mat4 model = mat4(1);
	model = glm::scale(model, scale);
	model = glm::rotate(model, radians(eulerAngle.x), vec3(1, 0, 0));
	model = glm::rotate(model, radians(eulerAngle.y), vec3(0, 1, 0));
	model = glm::rotate(model, radians(eulerAngle.z), vec3(0, 0, 1));
	model = glm::translate(model, position);
	return model;
}

