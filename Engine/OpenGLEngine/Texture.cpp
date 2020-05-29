#include "Texture.h"
#include "Reference/stb_image.h"

Texture::Texture()
{

}

Texture::~Texture()
{
	stbi_image_free(data);
}

void Texture::LoadTexture()
{
	data = stbi_load(path.c_str(), &width, &height, &channels, 0);
	if (data == nullptr) {
		stbi_image_free(data);
		throw "Load Texture error";
	}
}
