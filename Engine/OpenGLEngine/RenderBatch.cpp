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
	_shader->setVec3("color", glm::vec3(1,0,0));
	glBindVertexArray(_VAO);
	//glDrawArrays(_glMode, glFirtst, _glCount);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
