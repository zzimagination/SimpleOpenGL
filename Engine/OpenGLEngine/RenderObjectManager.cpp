#include "RenderObjectManager.h"
#include "ShaderManager.h"

std::vector<RenderObject*> RenderObjectManager::renderObjects;

void RenderObjectManager::GenerateRenderObjects()
{
	if (renderObjects.size() < 2)
	{
		RenderObject *robj = new RenderObject();
		robj->points = {
				-0.5, 0.5,
				-0.5, 0.0,
				 0.0, 0.0,
				 0.0, 0.5
		};
		robj->indices = {
				0, 1, 2,
				0,2,3
		};
		robj->shader = ShaderManager::GetShader("GL");
		renderObjects.push_back(robj);

		RenderObject* robj2 = new RenderObject();
		robj2->points = {
				 0.0, 0.0,
				 0.0,-0.5,
				 0.5,-0.5,
				 0.5, 0.0
		};
		robj2->indices = {
				0, 1, 2,
				0,2,3
		};
		robj2->shader = ShaderManager::GetShader("GL");
		renderObjects.push_back(robj2);
	}
}

void RenderObjectManager::ClearRenderObjects()
{
	for (std::vector<RenderObject*>::iterator it = renderObjects.begin();
		it != renderObjects.end(); it++)
	{
		RenderObject* ptr = *it;
		if (ptr->isDelete)
		{
			ptr->ClearGeometry();
			renderObjects.erase(it);
			delete ptr;
		}	
	}
}
