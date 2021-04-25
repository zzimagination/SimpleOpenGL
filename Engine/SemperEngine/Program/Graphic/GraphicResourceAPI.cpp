#include "GraphicResouceAPI.h"
#include <memory>
#include <vector>
#include "GL\GLResourceAPI.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;
		using namespace GraphicAPI;

		GraphicVertexData GraphicResouceAPI::AddVertexData(GraphicVertexData* data)
		{
			if (data->source.index->Size() == 0)
			{
				auto deliver = GLResourceAPI::AddVertexData(
					data->source.vertices->DataPtr(), 
					data->source.uv->DataPtr(), 
					(int)data->source.vertices->Size());
				GraphicVertexData result;
				result.SetGL(deliver.VAO, deliver.VBO, deliver.pointCount);
				return result;
			}

			auto deliver = GLResourceAPI::AddVertexData(
				data->source.vertices->DataPtr(), 
				data->source.uv->DataPtr(), 
				data->source.index->DataPtr(), 
				(int)data->source.vertices->Size());
			GraphicVertexData result;
			result.SetGL(deliver.VAO, deliver.VBO, deliver.EBO, deliver.pointCount);
			return result;
		}

		void GraphicResouceAPI::ClearVertexData(GraphicVertexData* data)
		{
			GLVertexData glData;
			glData.VAO = data->VAO;
			glData.VBO = data->VBO;
			glData.EBO = data->EBO;
			GLResourceAPI::ClearVertexData(glData);
		}

		GraphicTextureData GraphicResouceAPI::AddTextureData(GraphicTextureData* data)
		{
			int filter = 0x2600;
			switch (data->source.filter)
			{
			case Graphic::TextureFilter::Nearest:
				filter = GLResourceAPI::texNearest;
				break;
			case Graphic::TextureFilter::Linear:
				filter = GLResourceAPI::texLinear;
				break;
			}
			auto deliver = GLResourceAPI::AddTextureData(data->source.pixels->DataPtr(), data->source.width, data->source.height, filter);
			GraphicTextureData result;
			result.SetGLTexture(deliver.texture);
			return result;
		}

		void GraphicResouceAPI::ClearTextureData(GraphicTextureData* data)
		{
			GLResourceAPI::ClearTextureData(data->glID);
		}
	}
}