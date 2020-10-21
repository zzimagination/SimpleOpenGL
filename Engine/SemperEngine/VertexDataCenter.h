#pragma once
#ifndef __VERTEXDATA_CENTER__
#define __VERTEXDATA_CENTER__

#include <memory>
#include "CubeData.h"
#include "VertexData.h"
#include "ResourcePackage.h"
#include "Mesh.h"

namespace SemperEngine
{
	namespace Core
	{
		class VertexDataCenter
		{
		public:

			static ResourcePackage<VertexData> shareCube;

			static std::vector<ResourcePackage<VertexData>> cubes;

			static std::vector<int> unuseCube;

		public:

			static std::shared_ptr<Mesh> LoadCube(bool share);

		private:

			static VertexData* CreateCubeData();

			static void UnloadCube(ResourceID id);
		};
	}
}

#endif // !VERTEXDATA_CENTER
