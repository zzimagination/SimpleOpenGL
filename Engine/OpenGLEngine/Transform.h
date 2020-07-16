#pragma once
#ifndef TRANSFORM
#define TRANSFORM
#include "Mathz.hpp"

using namespace glm;

class Transform
{
public:
	vec3 position;

	vec3 eulerAngle;

	quat rotation;

	vec3 scale;

	Matrix4x4 GetModelMatrix();
};
#endif // !TRANSFORM



