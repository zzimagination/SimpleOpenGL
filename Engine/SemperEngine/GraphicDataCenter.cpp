#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"
#include "GraphicResouceAPI.h"
#include "ScreenTextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GraphicDataInfo GraphicDataCenter::screenVertexData;

		FillList<shared_ptr<GraphicTextureData>> GraphicDataCenter::_textureData;

		FillList<shared_ptr<GraphicVertexData>> GraphicDataCenter::_vertexData;

		void GraphicDataCenter::Initialize()
		{
			auto data = VertexData::CreateScreen();
			screenVertexData = AddVertexData(data);
		}

		GraphicDataInfo GraphicDataCenter::AddVertexData(VertexData* data)
		{
			auto gdata = shared_ptr<GraphicVertexData>(new GraphicVertexData());
			gdata->SetSource(data);
			GraphicDataInfo info;
			info.index = _vertexData.Add(gdata);
			GraphicCommandManager::AddVertexBuffer(info);
			return info;
		}

		void GraphicDataCenter::RemoveVertexData(GraphicDataInfo info)
		{
			GraphicCommandManager::ClearVertexBuffer(info);
		}

		void GraphicDataCenter::DeleteGraphicVertexData(GraphicDataInfo info)
		{
			_vertexData.Remove(info.index);
		}

		std::shared_ptr<GraphicVertexData> GraphicDataCenter::GetVertexData(GraphicDataInfo info)
		{
			return _vertexData[info.index].value;
		}

		GraphicDataInfo GraphicDataCenter::AddTextureData(TextureData* data)
		{
			auto gdata = shared_ptr<GraphicTextureData>(new GraphicTextureData());
			gdata->SetSource(data);
			GraphicDataInfo info;
			info.index = _textureData.Add(gdata);
			GraphicCommandManager::AddTextureBuffer(info);
			return info;
		}

		void GraphicDataCenter::RemoveTextureData(GraphicDataInfo info)
		{
			GraphicCommandManager::ClearTextureBuffer(info);
		}

		void GraphicDataCenter::DeleteGraphicTextureData(GraphicDataInfo info)
		{
			_textureData.Remove(info.index);
		}

		std::shared_ptr<GraphicTextureData> GraphicDataCenter::GetTextureData(GraphicDataInfo info)
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