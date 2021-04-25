#include "RenderCollection.h"
#include "RenderObject.h"
#include "RendererGenerator.h"
#include "RenderLayer.h"
#include "WorldManager.h"
#include "Debug.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		vector<LifeContainer<RenderObject>> RenderCollection::_customObjects;

		vector<LifeContainer<RenderObject>> RenderCollection::_screenObjects;

		void RenderCollection::AddCustomObject(RenderCustomObject* object)
		{
			_customObjects.push_back(object->mylife);
		}

		void RenderCollection::AddScreenObject(RenderScreenObject* object)
		{
			_screenObjects.push_back(object->mylife);
		}

		std::vector<RenderCustomObject*> RenderCollection::GetCustomObjects(RenderLayer layer)
		{
			vector<RenderCustomObject*> result;
			for (size_t i = 0; i < _customObjects.size(); i++)
			{
				if (!_customObjects[i].Life())
				{
					continue;
				}
				if (layer == _customObjects[i].self->layer)
				{
					result.push_back((RenderCustomObject*) _customObjects[i].self);
				}
			}
			return result;
		}
		std::vector<RenderScreenObject*> RenderCollection::GetScreenObjects()
		{
			vector<RenderScreenObject*> result;
			for (size_t i = 0; i < _screenObjects.size(); i++)
			{
				if (!_screenObjects[i].Life())
				{
					continue;
				}
				result.push_back((RenderScreenObject*)_screenObjects[i].self);
			}
			return result;
		}
		void RenderCollection::ClearRenders()
		{
			_customObjects.clear();
			_screenObjects.clear();
		}
	}
}