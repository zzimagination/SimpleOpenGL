#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		vector<TextureCommandData> GraphicDataCenter::_textureData;

		vector<unsigned int> GraphicDataCenter::_unusedTexture;

		vector<VertexCommandData> GraphicDataCenter::_vertexData;

		vector<unsigned int> GraphicDataCenter::_unusedVertex;

		void GraphicDataCenter::AddVertexData(ResourcePackage<VertexData> package)
		{
			auto data = VertexCommandDataInstance;
			data->package = package;
			unsigned int id = 0;
			if (_unusedVertex.size() > 0)
			{
				id = *(_unusedVertex.end() - 1);
				_unusedVertex.pop_back();
				_vertexData[id] = data;
			}
			else
			{
				id = (unsigned int)_vertexData.size();
				_vertexData.push_back(data);
			}
			data->package.gid = EncodeGID(id);
			GraphicCommandManager::AddVertexBuffer(data);
		}

		void GraphicDataCenter::RemoveVertexData(ResourcePackage<VertexData> package)
		{
			auto id = DecodeGID(package.gid());
			auto data = _vertexData[id];
			GraphicCommandManager::ClearVertexBuffer(data);
			data.reset();
			_unusedVertex.push_back(id);
		}

		VertexCommandData GraphicDataCenter::GetVertexCommandData(ResourcePackage<VertexData> package)
		{
			auto id = DecodeGID(package.gid());
			return _vertexData[id];
		}

		void GraphicDataCenter::AddTextureData(ResourcePackage<TextureData> package)
		{
			auto data = TextureCommandDataInstance;
			data->package = package;
			unsigned int id = 0;
			if (_unusedTexture.size() > 0)
			{
				id = *(_unusedTexture.end() - 1);
				_unusedTexture.pop_back();
				_textureData[id] = data;
			}
			else
			{
				id = (unsigned int)_textureData.size();
				_textureData.push_back(data);
			}
			data->package.gid = EncodeGID(id);
			GraphicCommandManager::AddTextureBuffer(data);
		}

		void GraphicDataCenter::RemoveTextureData(ResourcePackage<TextureData> package)
		{
			auto id = DecodeGID(package.gid());
			auto data = _textureData[id];
			GraphicCommandManager::ClearTextureBuffer(data);
			data.reset();
			_unusedTexture.push_back(id);
		}

		TextureCommandData GraphicDataCenter::GetTextureCommandData(ResourcePackage<TextureData> package)
		{
			auto id = DecodeGID(package.gid());
			return _textureData[id];
		}

		unsigned int GraphicDataCenter::DecodeGID(unsigned int gid)
		{
			return gid - 1;
		}
		unsigned int GraphicDataCenter::EncodeGID(unsigned int index)
		{
			return index + 1;
		}
	}
}