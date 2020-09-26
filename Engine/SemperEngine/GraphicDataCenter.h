#pragma once
#ifndef GRAPHICDATACENTER
#define GRAPHICDATACENTER

#include <vector>
#include <map>
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"
#include "RenderVertexData.h"
#include "Texture.h"

namespace SemperEngine
{

	class GraphicDataCenter
	{
	public:

		static std::map<RenderVertexData*, GraphicVertexData*> verticesData;

		static std::map<Texture*, GraphicTextureData*> texturesData;

	public:

		static GraphicVertexData* GetVertexData(RenderVertexData* data);

		static GraphicTextureData* GetTextureData(Texture* tex);

		static std::vector<GraphicTextureData*> GetTexturesData(std::vector<Texture*> tex);

		static void AddVertexData(GraphicVertexData* data);

		static void AddTextureDate(GraphicTextureData * data);

		static GraphicVertexData* PopVertexData(RenderVertexData* data);

		static GraphicTextureData* PopTextureData(Texture* data);

	};
}

#endif // !GRAPHICDATACENTER
