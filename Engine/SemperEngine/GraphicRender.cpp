#include "GraphicRender.h"
#include "RenderBatchManager.h"
#include "RenderBatch.h"
#include "GraphicRenderDraw.h"
#include "RenderVertexData.h"
#include "Texture.h"
#include "GraphicDataCenter.h"

namespace SemperEngine {

	void GraphicRender::Render()
	{
		GraphicRenderDraw::SetClear(ClearMode::Color | ClearMode::Depth, Vector4(0.0f, 0.0f, 0.0f, 1));

		vector<RenderBatch>* batchs = RenderBatchManager::frontBatchs;
		if (batchs != nullptr)
		{
			for (int i = 0; i < batchs->size(); i++)
			{
				RenderBatch batch = (*batchs)[i];
				GraphicVertexData *vertexData = GetVertexData(batch.vertexData);
				vector<GraphicTextureData*> textureDatas = GetTextureData(batch.textureDatas);

				GraphicRenderDraw::SetCullFace(CullFace::Front);
				GraphicRenderDraw::SetDepthTest(true);
				GraphicRenderDraw::SetVertexData(vertexData);
				GraphicRenderDraw::SetTransform(batch.modelMatrix, batch.viewMatrix, batch.projectionMatrix);
				GraphicRenderDraw::SetShader(batch.shader, batch.floatProperty, batch.vector2Property, batch.vector3Property, batch.vector4Property, batch.matrixProperty);
				for (int i = 0; i < textureDatas.size(); i++)
				{
					GraphicRenderDraw::SetTextureData(textureDatas[i]);
				}
				GraphicRenderDraw::Draw();
			}
		}
	}

	GraphicVertexData * GraphicRender::GetVertexData(RenderVertexData * v)
	{
		return GraphicDataCenter::GetVertexData(v);
	}

	vector<GraphicTextureData*> GraphicRender::GetTextureData(vector<Texture*> tex)
	{
		vector<GraphicTextureData*> data;
		for (int i = 0; i < tex.size(); i++)
		{
			data.push_back(GraphicDataCenter::GetTextureData(tex[i]));
		}
		return data;
	}
}