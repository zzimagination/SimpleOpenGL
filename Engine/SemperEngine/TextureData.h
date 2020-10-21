#pragma once
#ifndef __TEXTUREDATA__
#define __TEXTUREDATA__

#include <string>
#include <memory>
#include "ResourcePackage.h"

namespace SemperEngine
{
	namespace Core
	{
		class TextureData
		{
		public:

			static TextureData* LoadFile(std::string png);

		public:

			std::shared_ptr<unsigned char> data;

			int width;

			int height;

			ResourcePackage<TextureData> package;

			bool isPackaged;

		public:

			TextureData();

			~TextureData();

			void Package(ResourcePackage<TextureData> mine);
		};
	}
}

#endif // !__TEXTUREDATA__
