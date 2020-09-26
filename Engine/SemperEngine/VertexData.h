#pragma once
#ifndef VERTEXDATA
#define VERTEXDATA

#include <vector>
#include "Mathz.h"

namespace SemperEngine
{
	class VertexData
	{
	public:

		std::vector<Vector3> vertices;

		std::vector<Vector2> uv;

		std::vector<int> index;
	};
}

#endif // !VERTEXDATA
