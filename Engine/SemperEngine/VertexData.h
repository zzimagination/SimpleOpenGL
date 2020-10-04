#pragma once
#ifndef VERTEXDATA
#define VERTEXDATA

#include <vector>
#include "Mathz.h"
#include "ResourcePackage.h"

namespace SemperEngine
{
	namespace Core 
	{
		class VertexData
		{
		public:

			std::vector<Vector3> vertices;

			int vertexCount;

			std::vector<Vector2> uv;

			std::vector<int> index;

			int* s;

			VertexData();

			~VertexData();
		};
	}
}

#endif // !VERTEXDATA