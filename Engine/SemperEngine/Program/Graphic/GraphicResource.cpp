#include "GraphicResource.h"
#include "GraphicCommandManager.h"
#include "GraphicResouceAPI.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		void GraphicResource::Initialize()
		{
		}

#pragma region VertexData

		FillList<GraphicVertexData*> GraphicResource::_vertexData;

		GraphicDataInfo GraphicResource::AddVertexData(GraphicVertexResource resource)
		{
			auto gdata = new GraphicVertexData();
			gdata->source = resource;
			GraphicDataInfo info;
			info.index = _vertexData.Add(gdata);
			auto cmd = shared_ptr<GCMD_CreateVertex>(new GCMD_CreateVertex(gdata));
			GraphicCommandManager::AddResource(cmd);
			return info;
		}

		void GraphicResource::RemoveVertexData(GraphicDataInfo info)
		{
			auto data = _vertexData[info.index];
			_vertexData.Remove(info.index);
			auto cmd = shared_ptr<GCMD_DeleteVertex>(new GCMD_DeleteVertex(data, DeleteVertexFunc));
			GraphicCommandManager::AddResource(cmd);
		}

		GraphicVertexData* GraphicResource::GetVertexData(GraphicDataInfo info)
		{
			return _vertexData[info.index];
		}

		void GraphicResource::DeleteVertexFunc(GraphicVertexData* data)
		{
			delete data;
		}

#pragma endregion

#pragma region Texture

		FillList<GraphicTextureData*> GraphicResource::_textureData;

		GraphicDataInfo GraphicResource::AddTextureData(GraphicTextureResource resource)
		{
			auto gdata = new GraphicTextureData();
			gdata->source = resource;
			gdata->name = resource.name;
			GraphicDataInfo info;
			info.name = gdata->name;
			info.index = _textureData.Add(gdata);
			auto cmd = shared_ptr<GCMD_CreateTexture>(new GCMD_CreateTexture(gdata));
			GraphicCommandManager::AddResource(cmd);
			return info;
		}

		void GraphicResource::RemoveTextureData(GraphicDataInfo info)
		{
			auto data = _textureData[info.index];
			_textureData.Remove(info.index);
			auto cmd = shared_ptr<GCMD_DeleteTexture>(new GCMD_DeleteTexture(data, DeleteTextureFunc));
			GraphicCommandManager::AddResource(cmd);
		}

		GraphicTextureData* GraphicResource::GetTexture(GraphicDataInfo info)
		{
			return _textureData[info.index];
		}

		void GraphicResource::DeleteTextureFunc(GraphicTextureData* data)
		{
			delete data;
		}

#pragma endregion
	}
}