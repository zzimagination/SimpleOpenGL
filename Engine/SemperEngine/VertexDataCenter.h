#pragma once
#ifndef __VERTEXDATA_CENTER__
#define __VERTEXDATA_CENTER__

#include "CubeData.h"
#include "VertexData.h"
#include "ResourcePackage.h"

namespace SemperEngine
{
	namespace Core
	{
		class VertexDataCenter
		{
		public:

			static ResourcePackage<VertexData> shareCube;

			static std::vector<ResourcePackage<VertexData>> cubes;

			static std::vector<ResourcePackage<VertexData>> shareResources;

			static std::vector<ResourcePackage<VertexData>> instanceResources;

		public:

			static ResourcePackage<VertexData> LoadCube(bool share);

			static void UnloadNoUse();

		private:

			static VertexData* CreateCubeData();

			static bool UnloadOnce(ResourcePackage<VertexData> package);
		};
	}
}

#endif // !VERTEXDATA_CENTER
