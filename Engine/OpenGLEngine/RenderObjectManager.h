#pragma once
#include <vector>
#include "RenderObject.h"

class RenderObjectManager
{
public:
	static std::vector<RenderObject*> renderObjects;

	static void GenerateRenderObjects();

	static void ClearRenderObjects();
};

