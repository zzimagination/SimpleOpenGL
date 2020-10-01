#include "GraphicDraw.h"
#include "GraphicDataCenter.h"
#include "GraphicRenderDraw.h"
#include "GraphicShaderManager.h"
#include "CubeData.h"


#include <glad/glad.h>

namespace SemperEngine
{
	namespace Core
	{
		GraphicDraw::GraphicDraw(RenderBatch batch)
		{
			this->vertexData = GraphicDataCenter::vertexDatas[*batch.vertexData.graphicCenterID];
			this->modelMatrix = batch.modelMatrix;
			this->viewMatrix = batch.viewMatrix;
			this->projectionMatrix = batch.projectionMatrix;
			this->material = batch.material;
		}

		void GraphicDraw::Excute()
		{
			GraphicRenderDraw::SetCullFace(true, Back);
			GraphicRenderDraw::SetDepthTest(true);

			GraphicRenderDraw::SetVertexData(vertexData->graphicData);
			GraphicRenderDraw::SetTransform(modelMatrix, viewMatrix, projectionMatrix);
			GraphicRenderDraw::SetShader(material);
			GraphicRenderDraw::Draw();
		}
	}
}