#include "RenderBatch.h"
#include "RenderObject.h"
#include "Camera.h"
#include "RenderDraw.h"

RenderBatch::~RenderBatch()
{
	delete vertexData;
	delete textureData;
}

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

bool RenderBatch::IsBreak()
{
	for (int i = 0; i < renderObjects.size(); i++)
	{
		if (renderObjects[i]->IsBreakBatch())
		{
			return true;
		}
	}
	return false;
}

void RenderBatch::Break()
{
	for (int i = 0; i < renderObjects.size(); i++)
	{
		renderObjects[i]->SetRenderBatch(nullptr);
	}
}
