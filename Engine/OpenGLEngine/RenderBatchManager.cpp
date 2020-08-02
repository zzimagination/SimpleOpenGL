#include "RenderBatchManager.h"
#include "RenderObject.h"
#include "RenderBatch.h"

vector<RenderBatch> RenderBatchManager::batchs;

//void RenderBatchManager::GenerateBatchs()
//{
//	if (batchList.size() > 0)
//	{
//		batchList.clear();
//	}
//	for (size_t i = 0; i < RenderObjectManager::renderObjects.size(); i++)
//	{
//		RenderObject* ptr = RenderObjectManager::renderObjects[i];
//		int count = (int)ptr->indices.size();
//		RenderBatch batch(ptr->shader, ptr->VAO, count);
//		batch.modelMatrix = ptr->modelMatrix;
//		batch.viewMat = ptr->viewMatrix;
//		batch.projectionMat = ptr->projectionMatrix;
//		batch.vec3Map = ptr->vec3Map;
//		batchList.push_back(batch);
//	}
//}

void RenderBatchManager::GenerateBatchs(vector<RenderObject*> renderObjects)
{
	for (int i = 0; i < renderObjects.size(); i++)
	{
		RenderObject* o = renderObjects[i];
		RenderBatch b;
		b.vertexData = o->vertexData;
		b.textureData = o->textureData;
		b.material = o->material;
		b.modelMatrix = &o->modelMatrix;
		batchs.push_back(b);
	}
}

void RenderBatchManager::ClearBatchs()
{
	batchs.clear();
}

void RenderBatchManager::DrawBatchs(Camera* camera)
{
	for (int i = 0; i < batchs.size(); i++)
	{
		batchs[i].DrawCall(camera);
	}
}

