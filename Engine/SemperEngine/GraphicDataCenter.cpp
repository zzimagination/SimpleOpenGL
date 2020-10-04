#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::map<Texture*, GraphicTextureData*> GraphicDataCenter::texturesData;

		std::vector< shared_ptr<Vertex>> GraphicDataCenter::vertexDatas;

		void GraphicDataCenter::AddVertexData(ResourcePackage<VertexData> package)
		{
			int id = (int)vertexDatas.size();
			shared_ptr<Vertex> data = shared_ptr<Vertex>(new Vertex);
			data->package = package;
			*data->package.graphicCenterID = id;
			GraphicCommandManager::AddVertexBuffer(data);
			vertexDatas.push_back(data);
		}

		void GraphicDataCenter::RemoveVertexData(ResourcePackage<VertexData> package)
		{
			auto id = *package.graphicCenterID;
			auto data = vertexDatas[id];
			GraphicCommandManager::ClearVertexBuffer(data);
			vertexDatas.erase(vertexDatas.begin() + id);
			for (int i = id; i < vertexDatas.size(); i++)
			{
				*vertexDatas[i]->package.graphicCenterID = i;
			}
		}

		GraphicTextureData * GraphicDataCenter::GetTextureData(Texture* tex)
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

		void GraphicDataCenter::AddTextureDate(GraphicTextureData * data)
		{
			texturesData[data->gameData] = data;
		}

		GraphicTextureData * GraphicDataCenter::PopTextureData(Texture * data)
		{
			auto result = texturesData[data];
			texturesData.erase(data);
			return result;
		}
	}
}