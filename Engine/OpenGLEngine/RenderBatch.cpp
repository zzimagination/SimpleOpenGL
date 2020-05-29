#include "RenderBatch.h"
#include "BatchManager.h"
#include "Camera.h"

RenderBatch::RenderBatch(Shader* shader, unsigned int VAO, GLsizei count) :
	_shader(shader), _VAO(VAO), _glCount(count)
{

}

void RenderBatch::DrawCall()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	_shader->use();
	if (func_shader != nullptr)
	{
		func_shader(_shader);
	}
	for (int i = 0; i < glTextures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, glTextures[i]);
	}

	glBindVertexArray(_VAO);
	glDrawElements(GL_TRIANGLES, _glCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
