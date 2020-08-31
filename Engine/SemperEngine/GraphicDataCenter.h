#pragma once
#ifndef GRAPHICDATACENTER
#define GRAPHICDATACENTER

#include <vector>
#include <map>
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"

namespace SemperEngine
{
	class RenderVertexData;

	class Texture;

	class GraphicDataCenter
	{
	public:

		static std::map<RenderVertexData*, GraphicVertexData*> vertexDatas;

		static std::map<Texture*, GraphicTextureData*> textureDatas;

	public:

		static GraphicVertexData* GetVertexData(RenderVertexData* data);

		static GraphicTextureData* GetTextureData(Texture* tex);

	};
}

#endif // !GRAPHICDATACENTER
