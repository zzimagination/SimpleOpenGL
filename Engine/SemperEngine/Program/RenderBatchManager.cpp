#include "RenderBatchManager.h"
#include "GraphicRenderer.h"
#include "GraphicResource.h"
#include "ResourceInternal.h"
#include "Camera.h"
#include "Graphic.h"
#include <type_traits>

namespace SemperEngine {

	namespace Core
	{
		using namespace std;

		std::vector<std::shared_ptr<RenderBatch>> RenderBatchManager::batchList;

		vector<RenderBatch> RenderBatchManager::_batchs;

		void RenderBatchManager::AddBatch(std::shared_ptr<RenderBatch> batch)
		{
			batchList.push_back(batch);
		}

		void RenderBatchManager::ExecuteBatchs()
		{
			for (auto b = batchList.begin(); b < batchList.end(); b++)
			{
				b->get()->GenerateGraphicResource();
				b->get()->RenderGraphicObject();
			}
		}

		void RenderBatchManager::GenerateBatchs(CameraObject* camera, std::vector<RenderCustomObject*> objects)
		{
			for (size_t i = 0; i < objects.size(); i++)
			{
				auto object = objects[i];

				BindResource(object);

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

				BindResource(object);

				RenderBatch batch;
				batch.SetVertexType(RenderBatch::VertexType::Screen);
				batch.SetMesh(ResourceInternal::ScreenMesh());
				batch.SetMaterial(object->material);
				_batchs.push_back(batch);
			}
		}

		void RenderBatchManager::GenerateBatch(RenderScreenObject* object)
		{
			BindResource(object);

			RenderBatch batch;
			batch.SetVertexType(RenderBatch::VertexType::Screen);
			batch.SetMesh(ResourceInternal::ScreenMesh());
			batch.SetMaterial(object->material);
			_batchs.push_back(batch);
		}

		void RenderBatchManager::Clear()
		{
			_batchs.clear();
			batchList.clear();
		}

		void RenderBatchManager::BindResource(RenderCustomObject* obj)
		{
			obj->mesh->GetObject()->CreateGraphicResource();

			auto textures = obj->material->GetTextures();
			for (size_t i = 0; i < textures.size(); i++)
			{
				textures[i]->GetObject()->CreateGraphicResource();
			}
		}

		void RenderBatchManager::BindResource(RenderScreenObject* obj)
		{
			auto textures = obj->material->GetTextures();
			for (size_t i = 0; i < textures.size(); i++)
			{
				textures[i]->GetObject()->CreateGraphicResource();
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

		void RenderBatchManager::DrawCustom(RenderBatch batch)
		{
			auto vertex = batch.GetGraphicVertexInfo();
			auto matrix = batch.GetRenderMatrix();
			auto operation = batch.GetMaterial()->GetObject()->renderOperation;
			ShaderProperty sproperty = batch.GetMaterial()->GetObject()->shaderProperty;
			auto textures = batch.GetGraphicTextureInfos();

			GraphicRenderer::Render(vertex, operation, matrix, sproperty, textures);
		}

		void RenderBatchManager::DrawScreen(RenderBatch batch)
		{
			auto vertex = batch.GetGraphicVertexInfo();
			auto operation = batch.GetMaterial()->GetObject()->renderOperation;
			ShaderProperty sproperty = batch.GetMaterial()->GetObject()->shaderProperty;
			auto textures = batch.GetGraphicTextureInfos();
			GraphicRenderer::RenderScreen(vertex, operation, sproperty, textures);
		}
	}
}