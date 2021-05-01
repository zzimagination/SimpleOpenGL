#pragma once
#ifndef __TEXTURELIB__
#define __TEXTURELIB__

#include <string>
#include <memory>

namespace Semper
{
	namespace TextureLib
	{
		constexpr auto GRAYSCALE = 0;
		constexpr auto TRUECOLOR = 1;
		constexpr auto INDEXED = 2;
		constexpr auto GRAYSCALEALPHA = 3;
		constexpr auto TRUECOLORALPHA = 4;

		struct Texture
		{
			std::string path = "";

			std::string error = "";

			unsigned char* data = nullptr;

			size_t size = 0;

			int width = 0;

			int height = 0;

			int colorType = GRAYSCALE;

			int depth = 0;

			int compression = 0;

			int filter = 0;

			int interlace = 0;

		};

		Texture LoadTexture(std::string path);
	}
}
#endif // !__TEXTURELIB__
