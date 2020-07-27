#pragma once
#include <vector>
#include "RenderObject.h"
#include "Renderer.h"
#include "RenderObjectGenerator.h"
#include "Camera.h"

using namespace std;

class RenderObjectManager
{

private:

	struct RendererPair {
		RenderObject* object;

		vector<Renderer*> renderers;

		bool Contain(Renderer* renderer)
		{
			for (int i = 0; i < renderers.size(); i++)
			{
				if (renderers[i] == renderer)
				{
					return true;
				}
			}

			return false;
		}
	};

public:

	static vector<RenderObject*> prepareObjects;

	static vector<RenderObject*> renderObjects;

public:

	static void Culling(Camera *camera);

	static void AddRenderer(Renderer* renderer);

	static void UpdateRenderer(Renderer* renderer);

	static void RemoveRenderer(Renderer* renderer);

	//static void GenerateRenderObjects();

	//static void ClearRenderObjects();

private:

	static vector<RendererPair> rendererPairs;

	static int ContainRenderer(Renderer* renderer);

	static void DeleteRenderObject(RenderObject* object);
};

