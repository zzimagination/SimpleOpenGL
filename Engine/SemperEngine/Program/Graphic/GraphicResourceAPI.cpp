#include "GraphicResouceAPI.h"
#include <memory>
#include <vector>
#include "GL\GLResourceAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace GraphicAPI;

		GraphicVertexData GraphicResouceAPI::AddVertexData(GraphicVertexResource resource)
		{
			if (resource.index->Size() == 0)
			{
				auto deliver = GLResourceAPI::AddVertexData(resource.vertices->DataPtr(), resource.uv->DataPtr(), (int)resource.vertices->Size());
				GraphicVertexData result(deliver.VAO, deliver.VBO, deliver.pointCount);
				return result;
			}

			auto deliver = GLResourceAPI::AddVertexData(resource.vertices->DataPtr(), resource.uv->DataPtr(), resource.index->DataPtr(), (int)resource.vertices->Size());
			GraphicVertexData result(deliver.VAO, deliver.VBO, deliver.EBO, deliver.pointCount);
			return result;
		}

		void GraphicResouceAPI::ClearVertexData(GraphicVertexData data)
		{
			GLVertexData glData;
			glData.VAO = data.VAO;
			glData.VBO = data.VBO;
			if (data.indexDraw)
			{
				glData.EBO = data.EBO;
				glData.hasEBO = true;
			}
			else
			{
				glData.hasEBO = true;
			}
			GLResourceAPI::ClearVertexData(glData);
		}

		GraphicTextureData GraphicResouceAPI::AddTextureData(GraphicTextureResource resource)
		{
			int filter = 0x2600;
			switch (resource.filter)
			{
			case Graphic::TextureFilter::Nearest:
				filter = GLResourceAPI::texNearest;
				break;
			case Graphic::TextureFilter::Linear:
				filter = GLResourceAPI::texLinear;
				break;
			}
			auto deliver = GLResourceAPI::AddTextureData(resource.pixels->DataPtr(), resource.width, resource.height, filter);
			GraphicTextureData result;
			result.SetGLTexture(deliver.texture);
			return result;
		}

		void GraphicResouceAPI::ClearTextureData(GraphicTextureData data)
		{
			GLResourceAPI::ClearTextureData(data.glID);
		}
	}
}