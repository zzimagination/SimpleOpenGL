#pragma once
#ifndef __GRAPHIC_DATACENTER__
#define __GRAPHIC_DATACENTER__

#include <vector>
#include <map>
#include "Resource.h"
#include "GraphicCommand.h"
#include "GraphicResource.h"


namespace SemperEngine
{
	namespace Core
	{
		class GraphicDataCenter
		{
		public:


		private:

			static std::vector<TextureCommandData> _textureData;

			static std::vector<unsigned int> _unusedTexture;

			static std::vector<VertexCommandData> _vertexData;

			static std::vector<unsigned int> _unusedVertex;

		public:

			static void AddVertexData(ResourcePackage<VertexData> package);

			static void RemoveVertexData(ResourcePackage<VertexData> package);

			static VertexCommandData GetVertexCommandData(ResourcePackage<VertexData> package);

			static void AddTextureData(ResourcePackage<TextureData> package);

			static void RemoveTextureData(ResourcePackage<TextureData> package);

			static TextureCommandData GetTextureCommandData(ResourcePackage<TextureData> package);

		private:

			static unsigned int DecodeGID(unsigned int gid);

			static unsigned int EncodeGID(unsigned int index);
		};
	}
}

#endif // !GRAPHICDATACENTER
