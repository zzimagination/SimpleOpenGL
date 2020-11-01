#include "RenderCollection.h"
#include "RenderObject.h"
#include "RendererGenerator.h"
#include "RenderLayer.h"
#include "WorldManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		vector<LifeContainer<RenderObject>> RenderCollection::renderObjects;

		void RenderCollection::AddRenderObject(LifeContainer<RenderObject> robject)
		{
			if (WorldManager::Inside())
			{
				return;
			}
			renderObjects.push_back(robject);
		}

		vector<RenderObject*> RenderCollection::GetRenderObjects()
		{
			vector<RenderObject*> result;
			for (int i = 0; i < renderObjects.size(); i++)
			{
				if (*renderObjects[i].life)
				{
					result.push_back(renderObjects[i].self);
				}
			}
			return result;
		}
		std::vector<RenderObject*> RenderCollection::GetRenderObjects(CameraObject* camera)
		{
			vector<RenderObject*> result;
			for (int i = 0; i < renderObjects.size(); i++)
			{
				if (!*renderObjects[i].life)
				{
					continue;
				}
				if (camera->renderLayer == renderObjects[i].self->layer)
				{
					result.push_back(renderObjects[i].self);
				}
			}
			return result;
		}
		void RenderCollection::ClearRenders()
		{
			renderObjects.clear();
		}
		bool RenderCollection::CheckLayer(std::vector<int> layers, int target)
		{
			for (int i = 0; i < layers.size(); i++)
			{
				if (layers[i] == target)
				{
					return true;
				}
			}
			return false;
		}
	}
}