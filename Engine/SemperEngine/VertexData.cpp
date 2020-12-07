#include "VertexData.h"
#include "CubeData.h"
#include "ScreenTextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		VertexData* VertexData::CreateCube()
		{
			auto cube = new VertexData();
			auto size = sizeof(CubeData::vertices);
			cube->vertices.resize(size);
			memcpy(cube->vertices.data(), CubeData::vertices, size);
			size = sizeof(CubeData::uvs);
			cube->uv.resize(size);
			memcpy(cube->uv.data(), CubeData::uvs, size);
			size = sizeof(CubeData::indices);
			cube->index.resize(size);
			memcpy(cube->index.data(), CubeData::indices, size);
			cube->vertexCount = CubeData::vertexCount;
			return cube;
		}

		VertexData* VertexData::CreateScreen()
		{
			auto vert = new VertexData();
			auto size = sizeof(ScreenTextureData::vertices);
			vert->vertices.resize(size);
			memcpy(vert->vertices.data(), ScreenTextureData::vertices, size);
			size = sizeof(ScreenTextureData::uvs);
			vert->uv.resize(size);
			memcpy(vert->uv.data(), ScreenTextureData::uvs, size);
			size = sizeof(ScreenTextureData::indices);
			vert->index.resize(size);
			memcpy(vert->index.data(), ScreenTextureData::indices, size);
			vert->vertexCount = ScreenTextureData::vertexCount;
			return vert;
		}

		VertexData::VertexData()
		{
			vertexCount = 0;
		}

		VertexData::~VertexData()
		{
		}
		VertexData* VertexData::Copy()
		{
			auto vertexData = new VertexData();
			vertexData->vertices.assign(this->vertices.begin(), this->vertices.end());
			vertexData->vertexCount = this->vertexCount;
			vertexData->uv.assign(this->uv.begin(), this->uv.end());
			vertexData->index.assign(this->index.begin(), this->index.end());
			return vertexData;
		}
	}
}