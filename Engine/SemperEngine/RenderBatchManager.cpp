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
				auto robject = renderObjects[i];
				RenderBatch batch;
				batch.vertexData = robject->vertexData;
				batch.modelMatrix = robject->modelMatrix;
				batch.material = robject->material;
				batch.viewMatrix = camera->CalculateViewMatrix();
				batch.projectionMatrix = camera->CalculateProjectionMatrix();
				batchs.push_back(batch);
			}
		}

		void RenderBatchManager::GenerateGraphicCommands()
		{
			for (int i = 0; i < batchs.size(); i++)
			{
				GraphicCommandManager::Draw(batchs[i]);
			}
		}

		void RenderBatchManager::Clear()
		{
			batchs.clear();
		}

	}
}