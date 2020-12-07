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
				GraphicVertexInfo vertex;
				vertex.info = batchs[i].vertexData->object->graphicDataInfo;
				RenderMatrix matrix;
				matrix.model = batchs[i].modelMatrix;
				matrix.projection = batchs[i].projectionMatrix;
				matrix.view = batchs[i].viewMatrix;
				auto material = batchs[i].material;
				auto operation = material->renderOperation;
				auto sproperty = material->shaderProperty;
				auto textures = GetGraphicTextureInfos(material);
				GraphicRenderer::Render(vertex, operation, matrix, sproperty, textures);
			}
		}

		void RenderBatchManager::Clear()
		{
			batchs.clear();
		}

		std::vector<GraphicTextureInfo> RenderBatchManager::GetGraphicTextureInfos(std::shared_ptr<Material> material)
		{
			vector<GraphicTextureInfo> textures;
			for (int j = 0; j < material->textures.size(); j++)
			{
				auto index = material->textures[j].index;
				auto info = material->textures[j].texture->object->graphicDataInfo;
				GraphicTextureInfo tmp;
				tmp.index = index;
				tmp.info = info;
				textures.push_back(tmp);
			}
			return textures;
		}

	}
}