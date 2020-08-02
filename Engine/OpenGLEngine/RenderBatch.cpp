#include "RenderBatch.h"
#include "RenderBatchManager.h"
#include "Camera.h"
#include "RenderDraw.h"

void RenderBatch::DrawCall(Camera* camera)
{
	RenderDraw::SetCullFace(CullFace::Front);
	RenderDraw::SetDepthTest(true);
	RenderDraw::SetTransform(*modelMatrix, camera->CalculateViewMatrix(), camera->CalculateProjectionMatrix());
	RenderDraw::SetShader(material);
	RenderDraw::SetVertexData(vertexData);
	RenderDraw::SetTextureData(textureData);
	RenderDraw::Draw();
}
