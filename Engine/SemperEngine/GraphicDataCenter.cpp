#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::map<Texture*, GraphicTextureData*> GraphicDataCenter::texturesData;

		std::vector<shared_ptr<Vertex>> GraphicDataCenter::vertexDatas;

		void GraphicDataCenter::AddVertexData(ResourcePackage<VertexData> package)
		{
			shared_ptr<Vertex> data = shared_ptr<Vertex>(new Vertex);
			data->package = package;
			data->package.graphicResourceID = EncodeResourceID((unsigned int)vertexDatas.size());
			GraphicCommandManager::AddVertexBuffer(data);
			vertexDatas.push_back(data);
		}

		void GraphicDataCenter::RemoveVertexData(ResourcePackage<VertexData> package)
		{
			auto id = DecodeResourceID(package.graphicResourceID.ID());
			auto data = vertexDatas[id];
			GraphicCommandManager::ClearVertexBuffer(data);
			vertexDatas.erase(vertexDatas.begin() + id);
			for (int i = id; i < vertexDatas.size(); i++)
			{
				vertexDatas[i]->package.graphicResourceID = EncodeResourceID(i);
			}
		}

		std::shared_ptr<Vertex> GraphicDataCenter::GetVertexCommandData(ResourcePackage<VertexData> package)
		{
			auto id = DecodeResourceID(package.graphicResourceID.ID());
			return vertexDatas[id];
		}

		unsigned int GraphicDataCenter::DecodeResourceID(unsigned int package)
		{
			return package - 1;
		}
		unsigned int GraphicDataCenter::EncodeResourceID(unsigned int i)
		{
			return i + 1;
		}



		GraphicTextureData* GraphicDataCenter::GetTextureData(Texture* tex)
		{
			auto result = texturesData[tex];
			return result;
		}

		std::vector<GraphicTextureData*> GraphicDataCenter::GetTexturesData(std::vector<Texture*> tex)
		{
			vector<GraphicTextureData*> result;
			for (int i = 0; i < tex.size(); i++)
			{
				result.push_back(GetTextureData(tex[i]));
			}
			return result;
		}

		void GraphicDataCenter::AddTextureDate(GraphicTextureData* data)
		{
			texturesData[data->gameData] = data;
		}

		GraphicTextureData* GraphicDataCenter::PopTextureData(Texture* data)
		{
			auto result = texturesData[data];
			texturesData.erase(data);
			return result;
		}

	}
}