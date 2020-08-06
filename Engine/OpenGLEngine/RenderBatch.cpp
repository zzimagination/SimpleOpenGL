#include "RenderBatch.h"
#include "RenderObject.h"
#include "Camera.h"
#include "RenderDraw.h"

RenderBatch::~RenderBatch()
{
}

void RenderBatch::DrawCall(Camera* camera)
{
	RenderDraw::SetCullFace(CullFace::Front);
	RenderDraw::SetDepthTest(true);
	RenderDraw::SetVertexData(vertexData);
	RenderDraw::SetTransform(modelMatrix, camera->CalculateViewMatrix(), camera->CalculateProjectionMatrix());
	RenderDraw::SetShader(shader, floatProperty, vector2Property, vector3Property, vector4Property, matrixProperty);
	for (int i = 0; i < textureDatas.size(); i++)
	{
		RenderDraw::SetTextureData(textureDatas[i]);
	}
	RenderDraw::Draw();
}
