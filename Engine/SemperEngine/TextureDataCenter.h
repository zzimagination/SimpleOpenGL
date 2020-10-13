#pragma once
#ifndef __TEXTURE_DATACENTER__
#define __TEXTURE_DATACENTER__

#include <string>
#include <memory>
#include <vector>
#include "Texture.h"
#include "ResourcePackage.h"

namespace SemperEngine
{
	namespace Core
	{
		class TextureDataCenter
		{
		public:

			static std::vector<ResourcePackage<Texture>> instances;

		public:

			static ResourcePackage<Texture> LoadTexture(std::string path);

			static void UnloadUnuse();

		private:

			static Texture* CreateTexture(std::string path);

			static bool UnloadOnce(ResourcePackage<Texture>);
		};
	}
}

#endif // !__TEXTURE_DATACENTER__
