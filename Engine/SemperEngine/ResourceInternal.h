#pragma once
#ifndef __RESOURCEINTERNAL__
#define __RESOURCEINTERNAL__

#include <string>
#include <map>
#include <memory>
#include "Texture.h"
#include "Mesh.h"
#include "ResourceTextureLibrary.h"

namespace SemperEngine
{
	namespace Core
	{
		constexpr const char* WHITE_TEXTURE = "white";
		constexpr const char* BLACK_TEXTURE = "black";
		constexpr const char* BUMP_TEXTURE = "bump";

		class ResourceInternal
		{
		private:

			static std::map<std::string, std::shared_ptr<Texture>> textureMap;

			static ResourceTextureLibrary textureLibrary;

		public:

			static std::shared_ptr<Texture> WhiteTex();

			static std::shared_ptr<Texture> BlackTex();

			static std::shared_ptr<Texture> BumpTex();

			static void PreLoad();

			static void Dispose();

			static std::shared_ptr<Texture> GetTexture(std::string name);

		private:

			static std::shared_ptr<Texture> LoadTexture(std::string name);

			static std::string InternalFile(std::string file);
		};
	}
}

#endif // !__RESOURCEINTERNAL__
