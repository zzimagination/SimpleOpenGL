#include "GraphicResouce.h"
#include "GLResourceAPI.h"


namespace SemperEngine
{
	namespace Core
	{
		using namespace GraphicAPI;

		GraphicVertexData GraphicResouce::AddVertexData(VertexData* data)
		{
			auto result = GLResourceAPI::AddVertexData(data->vertices.data(), data->uv.data(), data->index.data(), data->vertexCount);
			return result;
		}

		void GraphicResouce::ClearVertexData(GraphicVertexData data)
		{
			GLResourceAPI::ClearVertexData(data.VAO, data.VBO, data.EBO);
		}
	}
}