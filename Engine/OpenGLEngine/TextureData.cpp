#include "TextureData.h"
#include "RenderObject.h"
#include<glad/glad.h>



TextureData::TextureData()
{
}

TextureData::~TextureData()
{
	for (int i = 0; i < textures.size(); i++)
	{
		glDeleteTextures(1, &textures[i]);
	}
}

void TextureData::BindData(RenderObject* renderObject)
{
	auto mat = renderObject->material;
	if (mat->textures.size() >= MAX_TEXTURE_COUNT)
	{
		throw "texture more than max";
	}
	for (int i = 0; i < mat->textures.size(); i++)
	{
		BindOpenGLTexture(mat->textures[i]);
	}
}

void TextureData::UseData()
{
	for (int i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, textures[i]);
	}
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
	this->textures.push_back(textureID);
}
