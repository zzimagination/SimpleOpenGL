#include "CubeData.h"
#include "GraphicCommandManager.h"

namespace SemperEngine {

	CubeData::CubeData()
	{
		Core::GraphicCommandManager::AddVertexBuffer(this);
	}

	CubeData::~CubeData()
	{
		Core::GraphicCommandManager::ClearVertexBuffer(this);
	}

	int CubeData::VertexCount()
	{
		return sizeof(vertices) / sizeof(Vector3);
	}

	Vector3 * CubeData::GetVertices()
	{
		return vertices;
	}

	Vector2* CubeData::GetUV()
	{
		return uvs;
	}

	int* CubeData::GetIndices()
	{
		return indices;
	}
}