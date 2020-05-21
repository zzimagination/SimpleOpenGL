#pragma once
#include <vector>
#include <glad/glad.h>
#include "shader.h"

class RenderBatch
{
public:

	RenderBatch(Shader* shader, unsigned int VAO, GLenum mode, GLsizei count);

	void DrawCall();

private:

	const int glFirtst = 0;

	Shader* _shader;

	unsigned int _VAO;
	//(GLenum mode, GLint first, GLsizei count);
	GLenum _glMode;

	GLsizei _glCount;
};

