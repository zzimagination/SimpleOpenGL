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

			unsigned char* textureData;

			unsigned int size = 0;

			int width = 0;

			int height = 0;

			ColorType colorType = ColorType::Truecolor;

			int depth = 0;

			int compression = 0;

			int filter = 0;

			int interlace = 0;

		public:

			void Dispose();

		};

		class TextureResource
		{
		public:

			static TextureFile Load(std::string path);

		private:

			static TextureFile LoadResource(std::string path);
		};
	}
}
#endif // !__TEXTURELIB__
