#pragma once
#include "shader.h"
#include "MeshObject.h"
#include <glm/glm.hpp>

class RenderObject
{
public:

	unsigned int VAO, VBO, EBO;

	bool isDelete;

	std::vector<float> points;

	std::vector<unsigned int> indices;

	Shader* shader;

	unsigned int SetupGeometry();

	void ClearGeometry();
};

