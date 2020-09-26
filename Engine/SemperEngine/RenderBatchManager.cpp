#include "RenderBatchManager.h"
#include "GraphicCommandManager.h"

namespace SemperEngine {

	namespace Core
	{
		using namespace std;


		vector<RenderBatch> RenderBatchManager::batchs;

		void RenderBatchManager::GenerateBatchs(Camera* camera, vector<RenderObject*>  renderObjects)
		{
			for (int i = 0; i < renderObjects.size(); i++)
			{
				RenderObject *object = renderObjects[i];
				RenderBatch batch;
				batch.vertexData = object->renderVertex;
				batch.modelMatrix = object->modelMatrix;
				batch.material = object->material;
				batch.viewMatrix = camera->CalculateViewMatrix();
				batch.projectionMatrix = camera->CalculateProjectionMatrix();

				batchs.push_back(batch);
			}
		}

		void RenderBatchManager::GenerateGraphicCommands()
		{
			for (int i = 0; i < batchs.size(); i++)
			{
				Core::GraphicCommandManager::Draw(batchs[i]);
			}
		}

		void RenderBatchManager::Clear()
		{
			batchs.clear();
		}

	}
}