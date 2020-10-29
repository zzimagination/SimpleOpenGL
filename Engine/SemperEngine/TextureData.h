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
		class TextureData :public IPackage<TextureData>
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

			virtual void Package(ResourcePackage<TextureData> mine) override;

		};
	}
}

#endif // !__TEXTUREDATA__
