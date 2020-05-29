#pragma once
#include <vector>
#include <glad/glad.h>
#include "shader.h"

class RenderBatch
{
public:

	std::vector<unsigned int> glTextures;

	void (*func_shader)(Shader* shader);

	RenderBatch(Shader* shader, unsigned int VAO, GLsizei count);

	void DrawCall();

private:

	Shader* _shader;

	unsigned int _VAO;

	int _glCount;
};

