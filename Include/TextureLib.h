#pragma once
#ifndef __TEXTURELIB__
#define __TEXTURELIB__

#define WIN32_LEAN_AND_MEAN 
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
				Grayscale,
				Truecolor,
				Indexed,
				GrayscaleAlpha,
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

		class TextureResource
		{
		public:

			static TextureFile Load(std::string file);

		private:

			static void LoadResource(TextureFile& tfile);
		};
	}
}
#endif // !__TEXTURELIB__
