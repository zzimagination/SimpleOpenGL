#include "GraphicResource.h"
#include "GraphicCommandManager.h"
#include "GraphicResouceAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		FillList<shared_ptr<GraphicTextureData>> GraphicResource::_textureData;

		FillList<shared_ptr<GraphicVertexData>> GraphicResource::_vertexData;

		void GraphicResource::Initialize()
		{
		}

		GraphicDataInfo GraphicResource::AddVertexData(GraphicVertexResource resource)
		{
			auto gdata = shared_ptr<GraphicVertexData>(new GraphicVertexData());
			gdata->source = resource;
			GraphicDataInfo info;
			info.index = _vertexData.Add(gdata);
			GraphicCommandManager::AddVertexBuffer(info);
			return info;
		}

		void GraphicResource::RemoveVertexData(GraphicDataInfo info)
		{
			GraphicCommandManager::ClearVertexBuffer(info);
		}

		void GraphicResource::DeleteGraphicVertexData(GraphicDataInfo info)
		{
			_vertexData.Remove(info.index);
		}

		std::shared_ptr<GraphicVertexData> GraphicResource::GetVertexData(GraphicDataInfo info)
		{
			return _vertexData[info.index];
		}

		GraphicDataInfo GraphicResource::AddTextureData(GraphicTextureResource resource)
		{
			auto gdata = shared_ptr<GraphicTextureData>(new GraphicTextureData());
			gdata->source = resource;
			GraphicDataInfo info;
			info.index = _textureData.Add(gdata);
			GraphicCommandManager::AddTextureBuffer(info);
			return info;
		}

		void GraphicResource::RemoveTextureData(GraphicDataInfo info)
		{
			GraphicCommandManager::ClearTextureBuffer(info);
		}

		void GraphicResource::DeleteGraphicTextureData(GraphicDataInfo info)
		{
			_textureData.Remove(info.index);
		}

		std::shared_ptr<GraphicTextureData> GraphicResource::GetTextureData(GraphicDataInfo info)
		{
			return _textureData[info.index];
		}
	}
}