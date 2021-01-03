#include "GraphicResouceAPI.h"
#include "GLResourceAPI.h"
#include <memory>
#include <vector>

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace GraphicAPI;

		GraphicVertexData GraphicResouceAPI::AddVertexData(VertexData* data)
		{
			auto deliver = GLResourceAPI::AddVertexData(data->vertices.DataPtr(), data->uv.DataPtr(), data->index.DataPtr(), (int)data->vertices.Size());
			GraphicVertexData result;
			result.VAO = deliver.VAO;
			result.VBO = deliver.VBO;
			result.EBO = deliver.EBO;
			result.pointCount = deliver.pointCount;
			return result;
		}

		void GraphicResouceAPI::ClearVertexData(GraphicVertexData data)
		{
			GLVertexData glData;
			glData.VAO = data.VAO;
			glData.VBO = data.VBO;
			glData.EBO = data.EBO;
			GLResourceAPI::ClearVertexData(glData);
		}

		GraphicTextureData GraphicResouceAPI::AddTextureData(TextureData* data)
		{
			auto mid = GLResourceAPI::AddTextureData(data->pixels.DataPtr(), data->width, data->height);
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