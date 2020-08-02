#include "Texture.h"
#include "spng.h"
#include <fstream>
#include <iostream>

Texture::Texture()
{

}

Texture::~Texture()
{
	delete[] data;
	data = nullptr;
}

void Texture::LoadFile(string path)
{
	/*data = stbi_load(path.c_str(), &width, &height, &channels, 0);
	if (data == nullptr) {
		stbi_image_free(data);
		throw "Load Texture error";
	}*/

	ifstream image(path,ios::binary);
	image.seekg(0, ios_base::end);
	long inputSize = image.tellg();
	image.seekg(0);
	char *buf = new char[inputSize];
	image.read(buf, inputSize);
	image.close();

	if (this->data != nullptr)
	{
		delete[] this->data;
		this->data = nullptr;
	}

	spng_ctx *ctx = spng_ctx_new(0);
	int r = spng_set_crc_action(ctx, SPNG_CRC_USE, SPNG_CRC_USE);
	r = spng_set_png_buffer(ctx, buf, inputSize);
	if (r)
	{
		cout << "load texture error " << r << endl;
		throw;
	}

	struct spng_ihdr ihdr;
	r = spng_get_ihdr(ctx, &ihdr);
	if (r)
	{
		cout << "load texture error " << spng_strerror(r) << endl;
		throw;
	}
	this->width = ihdr.width;
	this->height = ihdr.height;
	int t= ihdr.color_type;
	//const char *clr_type_str;
	//if (ihdr.color_type == SPNG_COLOR_TYPE_GRAYSCALE)
	//	clr_type_str = "grayscale";
	//else if (ihdr.color_type == SPNG_COLOR_TYPE_TRUECOLOR)
	//	clr_type_str = "truecolor";
	//else if (ihdr.color_type == SPNG_COLOR_TYPE_INDEXED)
	//	clr_type_str = "indexed color";
	//else if (ihdr.color_type == SPNG_COLOR_TYPE_GRAYSCALE_ALPHA)
	//	clr_type_str = "grayscale with alpha";
	//else
	//	clr_type_str = "truecolor with alpha";


	/*printf("width: %" PRIu32 "\nheight: %" PRIu32 "\n"
		"bit depth: %" PRIu8 "\ncolor type: %" PRIu8 " - %s\n",
		ihdr.width, ihdr.height,
		ihdr.bit_depth, ihdr.color_type, clr_type_str);
	printf("compression method: %" PRIu8 "\nfilter method: %" PRIu8 "\n"
		"interlace method: %" PRIu8 "\n",
		ihdr.compression_method, ihdr.filter_method,
		ihdr.interlace_method);*/

	size_t out_size;
	r = spng_decoded_image_size(ctx, SPNG_FMT_RGBA8, &out_size);
	unsigned char *out = new unsigned char[out_size];
	r = spng_decode_image(ctx, out, out_size, SPNG_FMT_RGBA8, 0);
	this->data = out;

	delete[] buf;
	spng_ctx_free(ctx);
}
