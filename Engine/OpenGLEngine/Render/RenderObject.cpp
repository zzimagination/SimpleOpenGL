#include<glad/glad.h>

#include "../Reference/stb_image.h"
#include "RenderObject.h"

RenderObject::RenderObject()
{
	isSetup = false;
}

RenderObject::~RenderObject()
{
}

void RenderObject::SetupGeometry()
{
	if (!isSetup)
	{
		isSetup = true;

		SetupVertexArray();
		SetupTextures();
	}
}

void RenderObject::ClearGeometry()
{
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);

	for (int i = 0; i < glTextures.size() ; i++)
	{
		glDeleteTextures(1, &glTextures[i].ID);
	}

	glTextures.clear();
	vertices.clear();
	uvs.clear();
	textures.clear();
}

void RenderObject::SetupVertexArray()
{
	if (VAO == 0) {
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
	}

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vec3)*vertices.size(), &vertices[0], GL_STATIC_DRAW);
	size_t vertexSize = ((size_t)sizeof(vec3))*vertices.size();
	size_t uvSize = ((size_t)sizeof(vec2))*uvs.size();
	dataSize = vertexSize + uvSize;

	glBufferData(GL_ARRAY_BUFFER, dataSize, 0, GL_STATIC_DRAW);
	int vertexOffset = 0;
	glBufferSubData(GL_ARRAY_BUFFER, vertexOffset, vertexSize, &vertices[0]);
	size_t uvOffset = vertexOffset + vertexSize;
	glBufferSubData(GL_ARRAY_BUFFER, uvOffset, uvSize, uvs.data());

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vec2), (void*)vertexSize);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}

void RenderObject::AddVec3Value(string name, vec3 color)
{
	vec3Map[name] = color;
}

void RenderObject::SetupTextures()
{
	for (int i = 0; i < textures.size(); i++)
	{
		if (textures[i]->data == nullptr)
		{
			continue;
		}

		bool had = false;
		for (int i = 0; i < glTextures.size(); i++)
		{
			if (textures[i]->path == glTextures[i].path)
			{
				had = true;
				break;
			}
		}

		if (had == false) {
			unsigned int id = 0;
			switch (textures[i]->textureType)
			{
			case BASE_TEXTURE:
				id = SetupBaseTexture(
					textures[i]->width,
					textures[i]->height,
					textures[i]->channels,
					textures[i]->data
				);
				break;
			case NORMAL_TEXTURE:
				id = SetupNormalTexture(
					textures[i]->width,
					textures[i]->height,
					textures[i]->data
				);
				break;
			}
			GLTexture tex;
			tex.ID = id;
			tex.path = textures[i]->path;
			
			glTextures.push_back(tex);
		}
	}
}

unsigned int RenderObject::SetupBaseTexture(int width, int height, int nrComponents, unsigned char* data)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	GLenum format, internalFormal;
	//if (nrComponents == 1)
	//{
	//	format = GL_RED;
	//	internalFormal = GL_RED;
	//}
	//else if (nrComponents == 3)
	//{
	//	format = GL_RGB;
	//	internalFormal = GL_RGB;
	//}
	//else if (nrComponents == 4)
	//{
		format = GL_RGBA;
		internalFormal = GL_RGBA;
	//}

	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormal, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return textureID;
}

unsigned int RenderObject::SetupNormalTexture(int width, int height, unsigned char* data)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return textureID;
}
