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

			std::unique_ptr<unsigned char> data;

			int size = 0;

			int width = 0;

			int height = 0;

			ColorType colorType = ColorType::Truecolor;

			int depth = 0;

			int compression = 0;

			int filter = 0;

			int interlace = 0;

		};

		class TextureResource
		{
		public:

			static std::shared_ptr<TextureFile> Load(std::string path);

		private:

			static std::shared_ptr<TextureFile> LoadResource(std::string path);
		};
	}
}
#endif // !__TEXTURELIB__
