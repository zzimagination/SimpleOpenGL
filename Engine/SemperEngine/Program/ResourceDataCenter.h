#pragma once
#ifndef __RESOURCEDATACENTER__
#define __RESOURCEDATACENTER__

#include <string>
#include <map>
#include "Common.h"
#include "DataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceDataCenter
		{
		public:

			static DataCenter<TextureData> textureDataCenter;

			static DataCenter<VertexData> vertexDataCetner;

		public:

			/*TextureData*/

			static ResourcePackage<TextureData> CreateTexture();

			static ResourcePackage<TextureData> CreateTexture(TextureData* data);

			static ResourcePackage<TextureData> CopyTexture(ResourcePackage<TextureData> package);

			static ResourcePackage<TextureData> LoadTexture(std::string path);

			/*VertexData*/

			static ResourcePackage<VertexData> CreateVertexData();

			static ResourcePackage<VertexData> CopyVertexData(ResourcePackage<VertexData> package);

			static ResourcePackage<VertexData> CreateCube();

			static ResourcePackage<VertexData> CreateRectangle();

		};
	}
}

#endif // !__RESOURCEDATACENTER__
