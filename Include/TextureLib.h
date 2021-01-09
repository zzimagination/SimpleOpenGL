#pragma once
#ifndef __TEXTURELIB__
#define __TEXTURELIB__

#define WIN32_LEAN_AND_MEAN 

#include <string>
#include <memory>
#include <vector>

namespace SemperEngine
{
	namespace TextureLib
	{
		class Texture
		{
		public:

			enum class PixelType
			{
				Grayscale,

				Truecolor,

				Indexed,

				GrayscaleAlpha,

				TruecolorAlpha
			};

		public:

			std::unique_ptr<unsigned char> data;

			int size = 0;

			int width = 0;

			int height = 0;

			PixelType colorType = PixelType::Truecolor;

			int depth = 0;

			int compression = 0;

			int filter = 0;

			int interlace = 0;

		};

		 std::shared_ptr<Texture> LoadTexture(std::string path);

	}
}
#endif // !__TEXTURELIB__
