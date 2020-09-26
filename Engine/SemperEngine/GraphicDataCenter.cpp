#include "GraphicDataCenter.h"

namespace SemperEngine
{
	using namespace std;

	std::map<RenderVertexData*, GraphicVertexData*> GraphicDataCenter::verticesData;

	std::map<Texture*, GraphicTextureData*> GraphicDataCenter::texturesData;

	GraphicVertexData * GraphicDataCenter::GetVertexData(RenderVertexData* data)
	{
		auto result = verticesData[data];
		return result;
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

	void GraphicDataCenter::AddVertexData(GraphicVertexData * data)
	{
		verticesData[data->gameData] = data;
	}

	void GraphicDataCenter::AddTextureDate(GraphicTextureData * data)
	{
		texturesData[data->gameData] = data;
	}

	GraphicVertexData * GraphicDataCenter::PopVertexData(RenderVertexData * data)
	{
		auto result = verticesData[data];
		verticesData.erase(data);
		return result;
	}
	GraphicTextureData * GraphicDataCenter::PopTextureData(Texture * data)
	{
		auto result = texturesData[data];
		texturesData.erase(data);
		return result;
	}
}