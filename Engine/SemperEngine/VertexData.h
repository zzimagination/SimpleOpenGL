#pragma once
#ifndef __VERTEXDATA__
#define __VERTEXDATA__

#include <vector>
#include "Mathz.h"
#include "BaseData.h"

namespace SemperEngine
{
	namespace Core 
	{
		class VertexData : public BaseData
		{
		public:

			std::vector<Float3> vertices;

			int vertexCount;

			std::vector<Float2> uv;

			std::vector<int> index;

		public:

			static VertexData* CreateCube();

			static VertexData* CreateScreen();

		public:

			VertexData();

			virtual ~VertexData() override;

			VertexData* Copy();
		};
	}
}

#endif // !VERTEXDATA
