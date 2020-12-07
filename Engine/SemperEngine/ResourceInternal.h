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
		constexpr const char* WHITE_TEXTURE = "white";
		constexpr const char* BLACK_TEXTURE = "black";
		constexpr const char* BUMP_TEXTURE = "bump";

		class ResourceInternal
		{
		public:

			static std::map<std::string, std::shared_ptr<Texture>> textures;

		public:

			static void PreLoad();

			static std::shared_ptr<Texture> GetTexture(std::string name);

			static std::shared_ptr<Texture> LoadTexture(std::string name);

			static std::shared_ptr<Mesh> CreateCube();

			static void Dispose();

		private:

			static std::shared_ptr<Texture> LoadTexture(std::string name, TextureObject::Setting setting);

			static std::string InternalFile(std::string file);
		};
	}
}

#endif // !__RESOURCEINTERNAL__
