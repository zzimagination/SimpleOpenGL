#pragma once
#ifndef __TEXTURE_DATACENTER__
#define __TEXTURE_DATACENTER__

#include <string>
#include <memory>
#include <vector>
#include "Texture.h"
#include "TextureData.h"
#include "ResourcePackage.h"
#include "Texture.h"

namespace SemperEngine
{
	namespace Core
	{
		class TextureDataCenter
		{
		public:

			static std::vector<ResourcePackage<TextureData>> instances;

			static std::vector<ResourceID> unused;

		public:

			static std::shared_ptr<Texture> LoadTexture(std::string path);

		private:

			static void Unload(ResourceID id);

		};
	}
}

#endif // !__TEXTURE_DATACENTER__
