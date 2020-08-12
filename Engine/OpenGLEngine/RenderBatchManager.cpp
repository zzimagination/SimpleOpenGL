#include "RenderBatchManager.h"
#include "RenderObject.h"
#include "RenderBatch.h"
#include "Camera.h"

vector<RenderBatch> *RenderBatchManager::frontBatchs;

vector<RenderBatch> *RenderBatchManager::backBatchs;

void RenderBatchManager::GenerateBatchs(vector<RenderObject*> renderObjects, Camera* camera)
{
	vector<RenderBatch> *batchs = new vector<RenderBatch>();
	for (int i = 0; i < renderObjects.size(); i++)
	{
		RenderObject *object = renderObjects[i];
		RenderBatch batch;
		batch.vertexData = object->renderVertex;
		batch.textureDatas = object->textures;
		batch.shader = object->shader;
		batch.floatProperty = object->floatProperty;
		batch.vector2Property = object->vector2Property;
		batch.vector3Property = object->vector3Property;
		batch.vector4Property = object->vector4Property;
		batch.matrixProperty = object->matrixProperty;
		batch.modelMatrix = object->modelMatrix;
		batch.viewMatrix = camera->CalculateViewMatrix();
		batch.projectionMatrix = camera->CalculateProjectionMatrix();

		batchs->push_back(batch);
	}

	backBatchs = batchs;
}

void RenderBatchManager::SwapBuffer()
{
	delete frontBatchs;
	frontBatchs = backBatchs;
}

void RenderBatchManager::ClearBatchs()
{

}

