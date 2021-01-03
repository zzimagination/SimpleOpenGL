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

		void RenderBatchManager::GenerateBatchs(CameraObject* camera, std::vector<RenderObject*> objects)
		{
			for (size_t i = 0; i < objects.size(); i++)
			{
				auto batch = GenerateBatch(objects[i], camera);
				_batchs.push_back(batch);
			}
		}

		void RenderBatchManager::GenerateBatchs(std::vector<RenderObject*> objects)
		{
			for (size_t i = 0; i < objects.size(); i++)
			{
				auto batch = GenerateBatch(objects[i], nullptr);
				_batchs.push_back(batch);
			}
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

		void RenderBatchManager::Clear()
		{
			_batchs.clear();
		}

		RenderBatch RenderBatchManager::GenerateBatch(RenderObject* object, CameraObject* camera)
		{
			RenderBatch batch;

			if (camera == nullptr)
			{
				batch.SetVertexType(RenderBatch::VertexType::Screen);
			}
			else
			{
				batch.SetVertexType(RenderBatch::VertexType::Custom);
			}

			if (object->hasMesh)
			{
				batch.SetMesh(object->GetMesh());
			}

			if (object->hasMaterial)
			{
				batch.SetMaterial(object->GetMaterial());
			}

			if (batch.GetVertexType() == RenderBatch::VertexType::Screen)
			{
				return batch;
			}

			if (camera != nullptr)
			{
				batch.SetModelMatrix(object->GetModelMat());
				batch.SetViewMatrix(camera->viewMatrix);
				batch.SetProjectionMatrix(camera->projectMatrix);
			}
			return batch;
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

	}
}