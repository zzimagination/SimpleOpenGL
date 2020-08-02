#include "RenderCollector.h"
#include "RenderObject.h"
#include "RendererGenerator.h"
#include "Renderer.h"

vector<Renderer*> RenderCollector::renderers;

void RenderCollector::CollectRenderer(Renderer * renderer)
{
	if (renderer == nullptr)
	{
		throw "nulltr";
	}
	if (HasRenderer(renderer))
	{
		throw "Repeat";
	}
	renderers.push_back(renderer);
}

void RenderCollector::DropRenderer(Renderer * renderer)
{
	if (!HasRenderer(renderer))
	{
		throw "no renderer";
	}
	auto t = renderers.begin();
	for (auto i = renderers.begin(); i != renderers.end(); i++)
	{
		if (*i == renderer)
		{
			t = i;
			break;
		}
	}
	renderers.erase(t);
}

vector<RenderObject*> RenderCollector::GetRenderObjects()
{
	vector<RenderObject*> renderObjects;
	for (int i = 0; i < renderers.size(); i++)
	{
		renderObjects.push_back(renderers[i]->GetRenderObject());
	}
	return renderObjects;
}


bool RenderCollector::HasRenderer(Renderer * renderer)
{
	for (vector<Renderer*>::iterator i = renderers.begin(); i != renderers.end(); i++)
	{
		if (*i == renderer)
		{
			return true;
		}
	}
	return false;
}
