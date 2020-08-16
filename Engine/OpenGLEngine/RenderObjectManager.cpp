#include "RenderObjectManager.h"
#include "ShaderManager.h"
#include "Camera.h"
#include "BuildInMesh.h"
#include "WorldManager.h"

namespace SemperEngine {

	using namespace std;

	vector<RenderObject*> RenderObjectManager::renderObjects;

	void RenderObjectManager::Culling(Camera * camera, vector<RenderObject*> &objects)
	{

	}

	void RenderObjectManager::AddRenderObject(RenderObject * object)
	{
		if (object == nullptr)
		{
			throw "Null";
		}
		renderObjects.push_back(object);
	}

	void RenderObjectManager::AddRenderObject(vector<RenderObject*> objects)
	{
		if (objects.size() == 0)
		{
			return;
		}
		renderObjects.assign(objects.begin(), objects.end());
	}

	vector<RenderObject*> RenderObjectManager::GetRenderObject()
	{
		return renderObjects;
	}

	void RenderObjectManager::ClearRenderObject()
	{
		renderObjects.clear();
	}
}