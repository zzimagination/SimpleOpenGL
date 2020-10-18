#pragma once
#ifndef __TEXTURE_DATACENTER__
#define __TEXTURE_DATACENTER__

#include <string>
#include <memory>
#include <vector>
#include "Texture.h"
#include "TextureData.h"
#include "ResourcePackage.h"
#include "ResourceReference.h"

namespace SemperEngine
{
	namespace Core
	{

		typedef std::shared_ptr<ResourceReference<TextureData>> RsTextureRef;

		class TextureDataCenter
		{
		public:

			static std::vector<ResourcePackage<TextureData>> instances;

			static std::vector<ResourceID> unused;

		public:

			static RsTextureRef LoadTexture(std::string path);

		private:

			static void Unload(ResourceID id);

			static TextureData* CreateTexture(std::string path);

		};
	}
}

#endif // !__TEXTURE_DATACENTER__
