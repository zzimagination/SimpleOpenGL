#include "BatchManager.h"
#include "RenderObjectManager.h"

std::vector<RenderBatch> BatchManager::batchList;

void BatchManager::GenerateBatchs()
{
	for (size_t i = 0; i < RenderObjectManager::renderObjects.size(); i++)
	{
		RenderObject* ptr= RenderObjectManager::renderObjects[i];
		int count = ptr->indices.size();
		RenderBatch batch(ptr->shader, ptr->VAO, GL_TRIANGLES, count);
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

void BatchManager::ClearBatchs()
{
	batchList.clear();
}
