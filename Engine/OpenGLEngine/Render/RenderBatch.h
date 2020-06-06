#pragma once
#include <vector>
#include <glad/glad.h>
#include "../Math/Mathz.h"
#include "shader.h"

using namespace glm;

class RenderBatch
{
public:

	mat4 modelMat;

	mat4 viewMat;

	mat4 projectionMat;

	std::vector<unsigned int> glTextures;

	void (*func_shader)(Shader* shader);

	RenderBatch(Shader* shader, unsigned int VAO, GLsizei count);

	void DrawCall();

private:

	Shader* _shader;

	unsigned int _VAO;

	int _glCount;
};

