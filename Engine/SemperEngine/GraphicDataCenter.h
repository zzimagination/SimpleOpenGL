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


		private:

			static std::vector<std::shared_ptr<TextureCommandData>> _textureData;

			static std::vector<std::shared_ptr<VertexCommandData>> _vertexData;

		public:

			static void AddVertexData(ResourcePackage<VertexData> package);

			static void RemoveVertexData(ResourcePackage<VertexData> package);

			static std::shared_ptr<VertexCommandData> GetVertexCommandData(ResourcePackage<VertexData> package);

			static void AddTextureData(ResourcePackage<Texture> package);

			static void RemoveTextureData(ResourcePackage<Texture> package);

		private:

			static unsigned int DecodeResourceID(unsigned int gid);

			static unsigned int EncodeResourceID(unsigned int index);
		};
	}
}

#endif // !GRAPHICDATACENTER
