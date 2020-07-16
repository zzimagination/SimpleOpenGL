#include "RenderBatch.h"
#include "BatchManager.h"
#include "Camera.h"

RenderBatch::RenderBatch(ShaderProgram* shader, unsigned int VAO, GLsizei count) :
	_shader(shader), _VAO(VAO), _glCount(count)
{

}

void RenderBatch::DrawCall()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	_shader->use();
	_shader->setMat4(MODEL_MATRIX, modelMat);
	_shader->setMat4(VIEW_MATRIX, viewMat);
	_shader->setMat4(PROJECTION_MARIX, projectionMat);

	for (auto i = vec3Map.begin(); i != vec3Map.end(); i++)
	{
		string name = i->first;
		vec3 val = i->second;
		_shader->setVec3(name, Vector3(val.x,val.y,val.z));
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
