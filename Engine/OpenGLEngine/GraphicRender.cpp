#include "GraphicRender.h"
#include "RenderBatchManager.h"
#include "RenderBatch.h"
#include "RenderDraw.h"
#include "RenderVertex.h"
#include "Texture.h"
#include "VertexDataList.h"
#include "TextureDataList.h"

void GraphicRender::Render()
{
	RenderDraw::SetClear(ClearMode::Color | ClearMode::Depth, Vector4(0.2f, 0.2f, 0.2f, 1));

	vector<RenderBatch>* batchs = RenderBatchManager::frontBatchs;
	if (batchs != nullptr)
	{
		for (int i = 0; i < batchs->size(); i++)
		{

			RenderBatch batch = (*batchs)[i];
			VertexData *vertexData = GetVertexData(batch.vertexData);
			vector<TextureData*> textureDatas = GetTextureData(batch.textureDatas);

			RenderDraw::SetCullFace(CullFace::Front);
			RenderDraw::SetDepthTest(true);
			RenderDraw::SetVertexData(vertexData);
			RenderDraw::SetTransform(batch.modelMatrix, batch.viewMatrix, batch.projectionMatrix);
			RenderDraw::SetShader(batch.shader, batch.floatProperty, batch.vector2Property, batch.vector3Property, batch.vector4Property, batch.matrixProperty);
			for (int i = 0; i < textureDatas.size(); i++)
			{
				RenderDraw::SetTextureData(textureDatas[i]);
			}
			RenderDraw::Draw();
		}
	}
}

VertexData * GraphicRender::GetVertexData(RenderVertex * v)
{
	return VertexDataList::GetVertexData(v);
}

vector<TextureData*> GraphicRender::GetTextureData(vector<Texture*> tex)
{
	vector<TextureData*> data;
	for (int i = 0; i < tex.size(); i++)
	{
		data.push_back(TextureDataList::GetData(tex[i]));
	}
	return data;
}
