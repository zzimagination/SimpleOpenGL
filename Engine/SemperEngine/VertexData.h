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

			std::vector<Vector3> vertices;

			int vertexCount;

			std::vector<Vector2> uv;

			std::vector<int> index;

			ResourcePackage<VertexData> package;

		private:

			bool _isPackage;

		public:

			VertexData();

			~VertexData();

			void Package(ResourcePackage<VertexData> mine);
		};
	}
}

#endif // !VERTEXDATA
