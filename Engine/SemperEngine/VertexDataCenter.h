#pragma once
#ifndef __VERTEXDATA_CENTER__
#define __VERTEXDATA_CENTER__

#include <memory>
#include "CubeData.h"
#include "VertexData.h"
#include "ResourcePackage.h"
#include "ResourceReference.h"

namespace SemperEngine
{
	namespace Core
	{
		typedef std::shared_ptr< ResourceReference<VertexData>> RsVertexRef;

		class VertexDataCenter
		{
		public:

			static ResourcePackage<VertexData> shareCube;

			static std::vector<ResourcePackage<VertexData>> cubes;

			static std::vector<int> unuseCube;

		public:

			static RsVertexRef LoadCube(bool share);

		private:

			static VertexData* CreateCubeData();

			static void Unload(ResourceID id);
		};
	}
}

#endif // !VERTEXDATA_CENTER
