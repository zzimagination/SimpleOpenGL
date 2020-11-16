#include "RenderBatchManager.h"
#include "GraphicRenderer.h"
#include "GraphicDataCenter.h"
#include "Camera.h"
#include "Graphic.h"

namespace SemperEngine {

	namespace Core
	{
		using namespace std;

		vector<RenderBatch> RenderBatchManager::batchs;

		void RenderBatchManager::GenerateBatchs(CameraObject* camera, vector<RenderObject*>  renderObjects)
		{
			for (int i = 0; i < renderObjects.size(); i++)
			{
				auto robject = renderObjects[i];
				RenderBatch batch;
				batch.vertexData = robject->vertexData;
				batch.modelMatrix = robject->modelMatrix;
				batch.material = robject->material;
				batch.viewMatrix = camera->viewMatrix;
				batch.projectionMatrix = camera->projectMatrix;
				batchs.push_back(batch);
			}
		}

		void RenderBatchManager::GenerateGraphicCommands()
		{
			for (int i = 0; i < batchs.size(); i++)
			{
				GraphicVertexInfo vertex = { GraphicVertexInfo::Type::custom, batchs[i].vertexData->Package().clerk->GetGDataInfo() };
				RenderMatrix matrix = { batchs[i].modelMatrix, batchs[i].viewMatrix,batchs[i].projectionMatrix };
				auto operation = batchs[i].material->renderOperation;
				auto sproperty = batchs[i].material->shaderProperty;

				vector<GraphicTextureInfo> textures;
				for (int i = 0; i < batchs[i].material->textures.size(); i++)
				{
					auto tex = batchs[i].material->textures[i];
					GraphicTextureInfo tmp = { tex.index, tex.texture->Package().clerk->GetGDataInfo() };
					textures.push_back(tmp);
				}

				GraphicRenderer::Render(vertex, operation, matrix, sproperty, textures);
			}
		}

		void RenderBatchManager::Clear()
		{
			batchs.clear();
		}

	}
}