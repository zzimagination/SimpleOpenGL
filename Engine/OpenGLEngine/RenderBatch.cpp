#include "RenderBatch.h"
#include "BatchManager.h"

RenderBatch::RenderBatch(Shader* shader, unsigned int VAO, GLenum mode, GLsizei count):
	_shader(shader), _VAO(VAO), _glMode(mode), _glCount(count)
{

}

void RenderBatch::DrawCall()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	_shader->use();
	glBindVertexArray(_VAO);
	glDrawArrays(_glMode, glFirtst, _glCount);
}
