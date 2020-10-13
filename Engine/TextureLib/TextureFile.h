#pragma once
#ifndef __TEXTUREFILE__
#define __TEXTUREFILE__

#include "framework.h"
#include <string>
#include <memory>

namespace SemperEngine
{
	namespace TextureLib
	{
		class TextureFile
		{
		public:

			enum class ColorType
			{
				Grayscale ,
				Truecolor,
				Indexed ,
				GrayscaleAlpha ,
				TruecolorAlpha
			};

		public:

			std::shared_ptr<unsigned char> textureData;

			std::string path;

			int width;

			int height;

			ColorType colorType;

			int depth;

			int compression;

			int filter;

			int interlace;

		public:

			TextureFile(std::string file);
		};
	}
}

#endif // !__TEXTUREFILE__


