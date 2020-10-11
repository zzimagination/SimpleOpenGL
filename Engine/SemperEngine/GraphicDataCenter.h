#pragma once
#ifndef __GRAPHIC_DATACENTER__
#define __GRAPHIC_DATACENTER__

#include <vector>
#include <map>
#include "ResourcePackage.h"
#include "VertexData.h"
#include "GraphicCommand.h"
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"
#include "Texture.h"

namespace SemperEngine
{
	namespace Core 
	{
		class GraphicDataCenter
		{
		public:

			static std::map<Texture*, GraphicTextureData*> texturesData;

			static std::vector<std::shared_ptr<Vertex>> vertexDatas;

		public:

			static void AddVertexData(ResourcePackage<VertexData> package);

			static void RemoveVertexData(ResourcePackage<VertexData> package);

			static std::shared_ptr<Vertex> GetVertexCommandData(ResourcePackage<VertexData> package);

			static GraphicTextureData* GetTextureData(Texture* tex);

			static std::vector<GraphicTextureData*> GetTexturesData(std::vector<Texture*> tex);

			static void AddTextureDate(GraphicTextureData * data);

			static GraphicTextureData* PopTextureData(Texture* data);

		private:

			static unsigned int DecodeResourceID(unsigned int package);

			static unsigned int EncodeResourceID(unsigned int i);
		};
	}
}

#endif // !GRAPHICDATACENTER
