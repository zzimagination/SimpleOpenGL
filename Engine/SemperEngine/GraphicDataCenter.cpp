#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		vector<shared_ptr<TextureCommandData>> GraphicDataCenter::_textureData;

		std::vector<shared_ptr<VertexCommandData>> GraphicDataCenter::_vertexData;

		void GraphicDataCenter::AddVertexData(ResourcePackage<VertexData> package)
		{
			shared_ptr<VertexCommandData> data = shared_ptr<VertexCommandData>(new VertexCommandData);
			data->package = package;
			data->package.GID = EncodeResourceID((unsigned int)_vertexData.size());
			GraphicCommandManager::AddVertexBuffer(data);
			_vertexData.push_back(data);
		}

		void GraphicDataCenter::RemoveVertexData(ResourcePackage<VertexData> package)
		{
			auto id = DecodeResourceID(package.GID.ID());
			auto data = _vertexData[id];
			GraphicCommandManager::ClearVertexBuffer(data);
			_vertexData.erase(_vertexData.begin() + id);
			for (int i = id; i < _vertexData.size(); i++)
			{
				_vertexData[i]->package.GID = EncodeResourceID(i);
			}
		}

		std::shared_ptr<VertexCommandData> GraphicDataCenter::GetVertexCommandData(ResourcePackage<VertexData> package)
		{
			auto id = DecodeResourceID(package.GID.ID());
			return _vertexData[id];
		}

		void GraphicDataCenter::AddTextureData(ResourcePackage<Texture> package)
		{
		}

		void GraphicDataCenter::RemoveTextureData(ResourcePackage<Texture> package)
		{
		}

		unsigned int GraphicDataCenter::DecodeResourceID(unsigned int gid)
		{
			return gid - 1;
		}
		unsigned int GraphicDataCenter::EncodeResourceID(unsigned int index)
		{
			return index + 1;
		}
	}
}