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
		class VertexData : public IPackage<VertexData>
		{
		public:

			std::vector<Float3> vertices;

			int vertexCount;

			std::vector<Float2> uv;

			std::vector<int> index;

			ResourcePackage<VertexData> package;

		private:

			bool _isPackage;

		public:

			VertexData();

			~VertexData();

			virtual void Package(ResourcePackage<VertexData> mine) override;
		};
	}
}

#endif // !VERTEXDATA
