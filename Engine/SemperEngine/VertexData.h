#pragma once
#ifndef __VERTEXDATA__
#define __VERTEXDATA__

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

			typedef unsigned int GPUResourceID;

			std::vector<Vector3> vertices;

			int vertexCount;

			std::vector<Vector2> uv;

			std::vector<int> index;

			GPUResourceID gid;

		public:

			VertexData();

			~VertexData();
		};
	}
}

#endif // !VERTEXDATA
