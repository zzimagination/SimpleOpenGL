#pragma once
#ifndef __VERTEXDATA__
#define __VERTEXDATA__

#include <memory>
#include <array>
#include "BaseData.h"

namespace SemperEngine
{
	namespace Core 
	{
		struct CubeData
		{
			static std::array<Float3, 24> vertices;

			static std::array<Float2, 24> uv;

			static std::array<int, 36> indices;
		};

		struct ScreenTextureData
		{
			static std::array<Float3, 4> vertices;

			static std::array<Float2, 4> uv;

			static std::array<int, 6> indices;
		};

		class VertexData : public BaseData
		{
		public:

			ArrayList<Float3> vertices;

			ArrayList<Float2> uv;

			ArrayList<int> index;

		public:

			static VertexData* CreateCube();

			static VertexData* CreateRectangle();

		public:

			VertexData();

			virtual ~VertexData() override;

			VertexData* Copy();
		};
	}
}

#endif // !VERTEXDATA
