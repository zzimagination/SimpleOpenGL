#include "TextureData.h"
#include "RenderObject.h"
#include<glad/glad.h>



TextureData::TextureData(Texture* textures)
{
	BindData(textures);
}

TextureData::~TextureData()
{
	glDeleteTextures(1, &textureId);
}

void TextureData::BindData(Texture* textures)
{
	BindOpenGLTexture(textures);
}

void TextureData::BindOpenGLTexture(Texture* tex)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);
	GLenum format, internalFormal;
	format = GL_RGBA;
	internalFormal = GL_RGBA;
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormal, tex->width, tex->height, 0, format, GL_UNSIGNED_BYTE, tex->data);
	this->textureId = textureID;
}
