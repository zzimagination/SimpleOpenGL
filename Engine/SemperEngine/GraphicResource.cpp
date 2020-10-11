#include "GraphicResouce.h"
#include "GLResourceAPI.h"


namespace SemperEngine
{
	namespace Core
	{
		using namespace GraphicAPI;

		GraphicVertexData GraphicResouceAPI::AddVertexData(VertexData* data)
		{
			auto deliver = GLResourceAPI::AddVertexData(data->vertices.data(), data->uv.data(), data->index.data(), data->vertexCount);
			GraphicVertexData result;
			result.VAO = deliver.VAO;
			result.VBO = deliver.VBO;
			result.EBO = deliver.EBO;
			result.pointCount = deliver.pointCount;
			return result;
		}

		void GraphicResouceAPI::ClearVertexData(GraphicVertexData data)
		{
			GLResourceAPI::ClearVertexData(data.VAO, data.VBO, data.EBO);
		}
	}
}