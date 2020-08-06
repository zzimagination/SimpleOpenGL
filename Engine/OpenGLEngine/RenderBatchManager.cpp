#include "RenderBatchManager.h"
#include "RenderObject.h"
#include "RenderBatch.h"
#include "VertexData.h"
#include "TextureData.h"
#include "VertexDataList.h"
#include "TextureDataList.h"

vector<RenderBatch> RenderBatchManager::batchs;

void RenderBatchManager::GenerateBatchs(vector<RenderObject*> renderObjects)
{
	for (int i = 0; i < renderObjects.size(); i++)
	{
		RenderObject *object = renderObjects[i];
		RenderBatch batch;
		batch.vertexData = GetVertexData(object->renderVertex);
		batch.textureDatas = GetTextureData(object->textures);
		batch.shader = object->shader;
		batch.floatProperty = object->floatProperty;
		batch.vector2Property = object->vector2Property;
		batch.vector3Property = object->vector3Property;
		batch.vector4Property = object->vector4Property;
		batch.matrixProperty = object->matrixProperty;
		batch.modelMatrix = object->modelMatrix;
		batchs.push_back(batch);
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

VertexData * RenderBatchManager::GetVertexData(RenderVertex * v)
{
	return VertexDataList::GetVertexData(v);
}

vector<TextureData*> RenderBatchManager::GetTextureData(vector<Texture*> tex)
{
	vector<TextureData*> data;
	for (int i = 0; i < tex.size(); i++)
	{
		data.push_back(TextureDataList::GetData(tex[i]));
	}
	return data;
}

