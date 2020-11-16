#pragma once
#ifndef __RESOURCEINTERNAL__
#define __RESOURCEINTERNAL__

#include <string>
#include <map>
#include <memory>
#include "Texture.h"
#include "Mesh.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceInternal
		{
		private:

			static std::map < std::string, std::shared_ptr<Texture>> _texutures;

			static Mesh _cube;

		public:

			static void AddTexture(std::string name, std::shared_ptr<Texture> texture);

			static std::weak_ptr<Texture> GetTexture(std::string name);

			static std::shared_ptr<Mesh> GetCube();

		private:

			static VertexData* CreateCubeData();
		};
	}
}

#endif // !__RESOURCEINTERNAL__
