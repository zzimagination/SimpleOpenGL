#include "BatchManager.h"
#include "RenderObjectManager.h"

std::vector<RenderBatch> BatchManager::batchList;

void BatchManager::GenerateBatchs()
{
	if (batchList.size() > 0)
	{
		batchList.clear();
	}
	for (size_t i = 0; i < RenderObjectManager::renderObjects.size(); i++)
	{
		RenderObject* ptr = RenderObjectManager::renderObjects[i];
		int count = (int)ptr->indices.size();
		RenderBatch batch(ptr->shader, ptr->VAO, count);
		batch.modelMat = ptr->modelMatrix;
		batch.viewMat = ptr->viewMatrix;
		batch.projectionMat = ptr->projectionMatrix;
		batch.vec3Map = ptr->vec3Map;
		batchList.push_back(batch);
	}
}

void BatchManager::DrawBatchs()
{
	for (int i = 0; i < batchList.size(); i++)
	{
		batchList[i].DrawCall();
	}
}

