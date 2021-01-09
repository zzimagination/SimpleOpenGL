#include "RenderBatchManager.h"
#include "GraphicRenderer.h"
#include "GraphicDataCenter.h"
#include "Camera.h"
#include "Graphic.h"

namespace SemperEngine {

	namespace Core
	{
		using namespace std;

		vector<RenderBatch> RenderBatchManager::_batchs;

		void RenderBatchManager::GenerateBatchs(CameraObject* camera, std::vector<RenderCustomObject*> objects)
		{
			for (size_t i = 0; i < objects.size(); i++)
			{
				auto object = objects[i];
				RenderBatch batch;
				batch.SetVertexType(RenderBatch::VertexType::Custom);
				batch.SetMesh(object->mesh);
				batch.SetMaterial(object->material);
				batch.SetModelMatrix(object->modelMat);
				batch.SetViewMatrix(camera->viewMatrix);
				batch.SetProjectionMatrix(camera->projectMatrix);

				_batchs.push_back(batch);
			}
		}

		void RenderBatchManager::GenerateBatchs(std::vector<RenderScreenObject*> objects)
		{
			for (size_t i = 0; i < objects.size(); i++)
			{
				auto object = objects[i];
				RenderBatch batch;
				batch.SetVertexType(RenderBatch::VertexType::Screen);
				batch.SetMaterial(object->material);
				_batchs.push_back(batch);
			}
		}

		void RenderBatchManager::Clear()
		{
			_batchs.clear();
		}

		void RenderBatchManager::GenerateGraphicCommands()
		{
			for (int i = 0; i < _batchs.size(); i++)
			{
				RenderBatch batch = _batchs[i];

				if (batch.GetVertexType() == RenderBatch::VertexType::Custom)
				{
					DrawCustom(batch);
				}
				else if (batch.GetVertexType() == RenderBatch::VertexType::Screen)
				{
					DrawScreen(batch);
				}
			}
		}

		void RenderBatchManager::DrawCustom(RenderBatch batch)
		{
			auto vertex = batch.GetGraphicVertexInfo();
			auto matrix = batch.GetRenderMatrix();

			auto material = batch.GetMaterial();
			auto operation = material->renderOperation;
			ShaderProperty sproperty = material->shaderProperty;
			auto textures = GetGraphicTextureInfos(material);

			GraphicRenderer::Render(vertex, operation, matrix, sproperty, textures);
		}

		void RenderBatchManager::DrawScreen(RenderBatch batch)
		{
			auto material = batch.GetMaterial();
			auto operation = material->renderOperation;
			ShaderProperty sproperty = material->shaderProperty;
			auto textures = GetGraphicTextureInfos(material);

			GraphicRenderer::RenderScreen(operation, sproperty, textures);
		}

		std::vector<GraphicTextureInfo> RenderBatchManager::GetGraphicTextureInfos(std::shared_ptr<Material> material)
		{
			vector<GraphicTextureInfo> textures;
			for (int j = 0; j < material->textures.size(); j++)
			{
				auto index = material->textures[j].index;
				auto info = material->textures[j].texture->GetObject()->graphicDataInfo;
				GraphicTextureInfo tmp;
				tmp.index = index;
				tmp.info = info;
				textures.push_back(tmp);
			}
			return textures;
		}

	}
}