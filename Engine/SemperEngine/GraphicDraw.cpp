#include "GraphicDraw.h"
#include "GraphicDataCenter.h"
#include "GraphicRenderDraw.h"
#include "RenderBatch.h"

namespace SemperEngine
{
	namespace Core
	{
		GraphicDraw::GraphicDraw(RenderBatch  batch)
		{
			this->vertexData = batch.vertexData;
			this->modelMatrix = batch.modelMatrix;
			this->viewMatrix = batch.viewMatrix;
			this->projectionMatrix = batch.projectionMatrix;
			this->material = batch.material;
		}

		void GraphicDraw::Excute()
		{
			GraphicVertexData *gvdata = GraphicDataCenter::GetVertexData(vertexData);
			vector<GraphicTextureData*> texturesData = GraphicDataCenter::GetTexturesData(textureList);

			GraphicRenderDraw::SetCullFace(CullFace::Front);
			GraphicRenderDraw::SetDepthTest(true);
			GraphicRenderDraw::SetVertexData(gvdata);
			GraphicRenderDraw::SetTransform(modelMatrix, viewMatrix, projectionMatrix);
			GraphicRenderDraw::SetShader(material);
			for (int i = 0; i < texturesData.size(); i++)
			{
				GraphicRenderDraw::SetTextureData(texturesData[i]);
			}
			GraphicRenderDraw::Draw();
		}
	}
}