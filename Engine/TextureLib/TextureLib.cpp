// TextureLib.cpp : 定义静态库的函数。
//
#include "TextureLib.h"
#include "spng.h"
#include <iostream>
#include <fstream>

namespace Semper
{
	namespace TextureLib
	{
		using namespace std;

		Texture LoadResource(string path)
		{
			Texture tex;
			tex.path = path;

			if (path == "")
			{
				tex.error = "Path is null.";
				return tex;
			}


			ifstream file(path, ios::binary);
			if (file.fail())
			{
				tex.error = "Can't load file";
				return tex;
			}

			struct stat buf;
			stat(path.c_str(), &buf);
			auto inputSize = (int)buf.st_size;
			unique_ptr<char> buffer(new char[inputSize]);
			file.read(buffer.get(), inputSize);
			file.close();

			spng_ctx* ctx = spng_ctx_new(0);
			int error = spng_set_crc_action(ctx, SPNG_CRC_USE, SPNG_CRC_USE);
			if (error)
			{
				tex.error = "load texture error ";
				return tex;
			}
			error = spng_set_png_buffer(ctx, buffer.get(), inputSize);
			if (error)
			{
				tex.error = "load texture error ";
				return tex;
			}

			struct spng_ihdr ihdr;
			error = spng_get_ihdr(ctx, &ihdr);
			if (error)
			{
				tex.error = "load texture error ";
				return tex;
			}
			tex.width = ihdr.width;
			tex.height = ihdr.height;
			switch (ihdr.color_type)
			{
			case SPNG_COLOR_TYPE_GRAYSCALE:
				tex.colorType = GRAYSCALE;
				break;
			case SPNG_COLOR_TYPE_TRUECOLOR:
				tex.colorType = TRUECOLOR;
				break;
			case SPNG_COLOR_TYPE_INDEXED:
				tex.colorType = INDEXED;
				break;
			case SPNG_COLOR_TYPE_GRAYSCALE_ALPHA:
				tex.colorType = GRAYSCALEALPHA;
				break;
			case SPNG_COLOR_TYPE_TRUECOLOR_ALPHA:
				tex.colorType = TRUECOLORALPHA;
				break;
			}
			tex.depth = ihdr.bit_depth;
			tex.compression = ihdr.compression_method;
			tex.filter = ihdr.filter_method;
			tex.interlace = ihdr.interlace_method;

			////const char *clr_type_str;
			////if (ihdr.color_type == SPNG_COLOR_TYPE_GRAYSCALE)
			////	clr_type_str = "grayscale";
			////else if (ihdr.color_type == SPNG_COLOR_TYPE_TRUECOLOR)
			////	clr_type_str = "truecolor";
			////else if (ihdr.color_type == SPNG_COLOR_TYPE_INDEXED)
			////	clr_type_str = "indexed color";
			////else if (ihdr.color_type == SPNG_COLOR_TYPE_GRAYSCALE_ALPHA)
			////	clr_type_str = "grayscale with alpha";
			////else
			////	clr_type_str = "truecolor with alpha";
			///*printf("width: %" PRIu32 "\nheight: %" PRIu32 "\n"
			//	"bit depth: %" PRIu8 "\ncolor type: %" PRIu8 " - %s\n",
			//	ihdr.width, ihdr.height,
			//	ihdr.bit_depth, ihdr.color_type, clr_type_str);
			//printf("compression method: %" PRIu8 "\nfilter method: %" PRIu8 "\n"
			//	"interlace method: %" PRIu8 "\n",
			//	ihdr.compression_method, ihdr.filter_method,
			//	ihdr.interlace_method);*/

			size_t out_size;
			error = spng_decoded_image_size(ctx, SPNG_FMT_RGBA8, &out_size);
			if (error)
			{
				throw "image decoded error";
			}

			tex.data = new unsigned char[out_size];
			tex.size = out_size;
			error = spng_decode_image(ctx, tex.data, out_size, SPNG_FMT_RGBA8, 0);
			if (error)
			{
				throw "image decoded error";
			}

			spng_ctx_free(ctx);
			return tex;
		}

		Texture LoadTexture(std::string path)
		{
			return LoadResource(path);
		}
	}
}