#pragma once
#include <vector>
#include "RenderObject.h"
#include "Renderer.h"
#include "Camera.h"

using namespace std;

class RenderObjectManager
{
private:

	static vector<RenderObject*> renderObjects;

public:

	static void Culling(Camera *camera);

	static void AddRenderObject(RenderObject* object);

	static void AddRenderObject(vector<RenderObject*> objects);

	static vector<RenderObject*> GetRenderObject();

	static void BindVertexData();

	static void ClearRenderObject();
};

