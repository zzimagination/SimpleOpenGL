#include "RenderCollection.h"
#include "RenderObject.h"
#include "RendererGenerator.h"
#include "WorldManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		vector<LifeContainer<RenderObject>> RenderCollection::renderObjects;

		void RenderCollection::AddRenderObject(LifeContainer<RenderObject> robject)
		{
			if (WorldManager::currentWorld == WorldManager::GetInside())
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
				if (renderObjects[i].life)
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
	}
}