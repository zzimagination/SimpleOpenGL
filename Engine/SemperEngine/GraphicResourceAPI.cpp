#include "GraphicResouceAPI.h"
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
		GraphicTextureData GraphicResouceAPI::AddTextureData(TextureData* data)
		{
			auto mid = GLResourceAPI::AddTextureData(data->data.get(), data->width, data->height);
			GraphicTextureData resource;
			resource.glid = mid.texture;
			return resource;
		}
		void GraphicResouceAPI::ClearTextureData(GraphicTextureData data)
		{
			GLResourceAPI::ClearTextureData(data.glid);
		}
	}
}