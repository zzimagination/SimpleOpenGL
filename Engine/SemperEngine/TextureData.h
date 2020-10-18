#pragma once
#ifndef __TEXTUREDATA__
#define __TEXTUREDATA__

#include <memory>

namespace SemperEngine
{
	namespace Core
	{
		class TextureData
		{
		public:

			std::shared_ptr<unsigned char> data;

			int width;

			int height;

		public:

			TextureData();

			~TextureData();
		};
	}
}

#endif // !__TEXTUREDATA__
