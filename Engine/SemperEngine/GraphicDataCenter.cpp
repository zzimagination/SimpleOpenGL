#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"
#include "GraphicResouceAPI.h"
#include "ScreenTextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		shared_ptr<GraphicVertexData> GraphicDataCenter::screenVertexData = shared_ptr<GraphicVertexData>(new GraphicVertexData());

		FillList<shared_ptr<GraphicTextureData>> GraphicDataCenter::_textureData;

		FillList<shared_ptr<GraphicVertexData>> GraphicDataCenter::_vertexData;

		void GraphicDataCenter::Initialize()
		{
			GenerateScreenVertex();
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
			return _vertexData[info.index];
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
			return _textureData[info.index];
		}

		void GraphicDataCenter::GenerateScreenVertex()
		{
			auto vert = unique_ptr<VertexData>(new VertexData());
			auto size = sizeof(ScreenTextureData::vertices);
			vert->vertices.resize(size);
			memcpy(vert->vertices.data(), ScreenTextureData::vertices, size);
			size = sizeof(ScreenTextureData::uvs);
			vert->uv.resize(size);
			memcpy(vert->uv.data(), ScreenTextureData::uvs, size);
			size = sizeof(ScreenTextureData::indices);
			vert->index.resize(size);
			memcpy(vert->index.data(), ScreenTextureData::indices, size);
			vert->vertexCount = ScreenTextureData::vertexCount;
			screenVertexData.reset(new GraphicVertexData(GraphicResouceAPI::AddVertexData(vert.get())));
		}
	}
}