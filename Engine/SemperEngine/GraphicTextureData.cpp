#include "GraphicTextureData.h"
#include "RenderObject.h"
#include<glad/glad.h>


namespace SemperEngine {
	GraphicTextureData::GraphicTextureData(Texture* textures)
	{
		BindData(textures);
	}

	GraphicTextureData::~GraphicTextureData()
	{
		glDeleteTextures(1, &textureId);
	}

	void GraphicTextureData::BindData(Texture* textures)
	{
		BindOpenGLTexture(textures);
	}

	void GraphicTextureData::BindOpenGLTexture(Texture* tex)
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
}