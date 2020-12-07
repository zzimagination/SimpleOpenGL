﻿// TextureLib.cpp : 定义静态库的函数。
//
#include "TextureLib.h"
#include "spng.h"
#include <iostream>
#include <fstream>

namespace SemperEngine
{
	namespace TextureLib
	{
		using namespace std;

		TextureFile TextureResource::Load(std::string path)
		{
			return LoadResource(path);;
		}

		TextureFile TextureResource::LoadResource(string path)
		{
			TextureFile texFile;
			if (path == "")
			{
				throw "path is null";
			}
			struct stat buf;
			if (stat(path.c_str(), &buf))
			{
				return TextureFile();
			}
			ifstream file(path, ios::binary);
			auto inputSize = (unsigned int)buf.st_size;
			unique_ptr<char> buffer(new char[inputSize]);
			file.read(buffer.get(), inputSize);
			file.close();

			spng_ctx* ctx = spng_ctx_new(0);
			int error = spng_set_crc_action(ctx, SPNG_CRC_USE, SPNG_CRC_USE);
			if (error)
			{
				throw "load texture error ";
			}
			error = spng_set_png_buffer(ctx, buffer.get(), inputSize);
			if (error)
			{
				throw "load texture error ";
			}

			struct spng_ihdr ihdr;
			error = spng_get_ihdr(ctx, &ihdr);
			if (error)
			{
				throw "load texture error ";
			}
			texFile.width = ihdr.width;
			texFile.height = ihdr.height;
			switch (ihdr.color_type)
			{
			case SPNG_COLOR_TYPE_GRAYSCALE:
				texFile.colorType = TextureFile::ColorType::Grayscale;
				break;
			case SPNG_COLOR_TYPE_TRUECOLOR:
				texFile.colorType = TextureFile::ColorType::Truecolor;
				break;
			case SPNG_COLOR_TYPE_INDEXED:
				texFile.colorType = TextureFile::ColorType::Indexed;
				break;
			case SPNG_COLOR_TYPE_GRAYSCALE_ALPHA:
				texFile.colorType = TextureFile::ColorType::GrayscaleAlpha;
				break;
			case SPNG_COLOR_TYPE_TRUECOLOR_ALPHA:
				texFile.colorType = TextureFile::ColorType::TruecolorAlpha;
				break;
			}
			texFile.depth = ihdr.bit_depth;
			texFile.compression = ihdr.compression_method;
			texFile.filter = ihdr.filter_method;
			texFile.interlace = ihdr.interlace_method;
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

			texFile.textureData = new unsigned char[out_size];
			texFile.size = (unsigned int)out_size;
			error = spng_decode_image(ctx, texFile.textureData, out_size, SPNG_FMT_RGBA8, 0);
			if (error)
			{
				throw "image decoded error";
			}

			spng_ctx_free(ctx);
			return texFile;
		}

	}
}