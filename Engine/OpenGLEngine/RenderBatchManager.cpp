#include "RenderBatchManager.h"
#include "RenderObject.h"
#include "RenderBatch.h"
#include "VertexData.h"
#include "TextureData.h"

vector<RenderBatch*> RenderBatchManager::batchs;
vector<RenderObject*> RenderBatchManager::_noBatchObjects;

void RenderBatchManager::GenerateBatchs(vector<RenderObject*> renderObjects)
{
	for (int i = batchs.size() - 1; i >= 0; i--)
	{
		if (batchs[i]->IsBreak())
		{
			batchs[i]->Break();
			delete batchs[i];
			batchs.erase(batchs.begin() + i);
		}
	}
	for (int i = 0; i < renderObjects.size(); i++)
	{
		RenderObject* o = renderObjects[i];
		if (!o->HasBatch())
		{
			_noBatchObjects.push_back(o);
		}
	}
	GenerateNewBatchs();
}

void RenderBatchManager::ClearBatchs()
{
	for (int i = 0; i < batchs.size(); i++)
	{
		delete batchs[i];
	}
	batchs.clear();
}

void RenderBatchManager::DrawBatchs(Camera* camera)
{
	for (int i = 0; i < batchs.size(); i++)
	{
		batchs[i]->DrawCall(camera);
	}
}

void RenderBatchManager::GenerateNewBatchs()
{
	for (int i = 0; i < _noBatchObjects.size(); i++)
	{
		RenderObject* o = _noBatchObjects[i];
		RenderBatch* b = new RenderBatch();
		VertexData* vertex = new VertexData(
			o->GetVertices(),
			o->GetVertexCount(),
			o->GetIndex(),
			o->GetUV());
		b->vertexData = vertex;

		TextureData* texture = new TextureData(o->GetMaterial()->textures);
		b->textureData = texture;

		b->material = o->GetMaterial();
		b->modelMatrix = o->GetModelMatrix();
		batchs.push_back(b);
		o->SetRenderBatch(b);
	}
	_noBatchObjects.clear();
}

