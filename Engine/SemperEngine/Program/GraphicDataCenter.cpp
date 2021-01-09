#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"
#include "GraphicResouceAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GraphicDataInfo GraphicResource::screenVertexData;

		FillList<shared_ptr<GraphicTextureData>> GraphicResource::_textureData;

		FillList<shared_ptr<GraphicVertexData>> GraphicResource::_vertexData;

		void GraphicResource::Initialize()
		{
			auto data = VertexData::CreateRectangle();
			screenVertexData = AddVertexData(data);
		}

		GraphicDataInfo GraphicResource::AddVertexData(VertexData* data)
		{
			auto gdata = shared_ptr<GraphicVertexData>(new GraphicVertexData());
			gdata->SetSource(data);
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
			return _vertexData[info.index].value;
		}

		GraphicDataInfo GraphicResource::AddTextureData(TextureData* data)
		{
			auto gdata = shared_ptr<GraphicTextureData>(new GraphicTextureData());
			gdata->SetSource(data);
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
			if (_textureData[info.index].usable)
			{
				return _textureData[info.index].value;
			}
			else
			{
				return shared_ptr<GraphicTextureData>();
			}
		}
	}
}