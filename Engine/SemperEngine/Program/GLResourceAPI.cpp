#include "GLResourceAPI.h"
#include <glad/glad.h>

namespace SemperEngine
{
	namespace Core
	{
		namespace GraphicAPI
		{
			int GLResourceAPI::texNearest = GL_NEAREST;

			int GLResourceAPI::texLinear = GL_LINEAR;


			GLVertexData GLResourceAPI::AddVertexData(Float3* vertices, Float2* uv, int* index, int count)
			{
				GLuint VAO = 0, VBO = 0, EBO = 0, pointCount = 0;

				if (count >= 4)
				{
					pointCount = count / 4 * 6;
					if (count / 4 * 6 != pointCount)
					{
						throw "indexSize is not match indexSize vertexData";
					}
				}
				else
				{
					pointCount = count;
				}

				int verticesSize = count * sizeof(Float3);
				int uvSize = count * sizeof(Float2);
				int indexSize = pointCount * sizeof(int);
				int totalSize = verticesSize + uvSize + indexSize;

				if (verticesSize == 0 || indexSize == 0)
				{
					throw "vertexData is null";
				}

				glGenVertexArrays(1, &VAO);
				glGenBuffers(1, &VBO);
				glGenBuffers(1, &EBO);

				glBindVertexArray(VAO);
				glBindBuffer(GL_ARRAY_BUFFER, VBO);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

				glBufferData(GL_ARRAY_BUFFER, totalSize, 0, GL_STATIC_DRAW);//首先执行这个
				GLintptr voffset = 0;
				glBufferSubData(GL_ARRAY_BUFFER, voffset, verticesSize, vertices);
				GLintptr uvoffset = verticesSize;
				glBufferSubData(GL_ARRAY_BUFFER, uvoffset, uvSize, uv);

				glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, index, GL_STATIC_DRAW);

				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Float3), (void*)voffset);
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Float2), (void*)uvoffset);

				// note that this is allowed, the call to glVertexAttribPointer registered VBO 
				// as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
				glBindBuffer(GL_ARRAY_BUFFER, 0);
				// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
				//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
				// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
				// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
				glBindVertexArray(0);

				GLVertexData result;
				result.VAO = VAO;
				result.VBO = VBO;
				result.EBO = EBO;
				result.pointCount = pointCount;
				result.hasEBO = true;
				return result;
			}

			GLVertexData GLResourceAPI::AddVertexData(Float3* vertices, int count)
			{
				unsigned int VAO, VBO;
				glGenVertexArrays(1, &VAO);
				glGenBuffers(1, &VBO);
				glBindVertexArray(VAO);
				glBindBuffer(GL_ARRAY_BUFFER, VBO);
				auto size = count * sizeof(Float3);
				glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);//首先执行这个
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Float3), (void*)0);
				glBindBuffer(GL_ARRAY_BUFFER, 0);
				glBindVertexArray(0);
				GLVertexData result = { VAO, VBO };
				return result;
			}

			GLVertexData GLResourceAPI::AddVertexData(Float3* vertices, Float2* uv, int count)
			{
				GLuint VAO = 0, VBO = 0, pointCount = 0;
				pointCount = count;
				int verticesSize = count * sizeof(Float3);
				int uvSize = count * sizeof(Float2);
				int totalSize = verticesSize + uvSize;

				glGenVertexArrays(1, &VAO);
				glGenBuffers(1, &VBO);
				glBindVertexArray(VAO);
				glBindBuffer(GL_ARRAY_BUFFER, VBO);
				glBufferData(GL_ARRAY_BUFFER, totalSize, 0, GL_STATIC_DRAW);
				GLintptr voffset = 0;
				glBufferSubData(GL_ARRAY_BUFFER, voffset, verticesSize, vertices);
				GLintptr uvoffset = verticesSize;
				glBufferSubData(GL_ARRAY_BUFFER, uvoffset, uvSize, uv);

				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Float3), (void*)voffset);
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Float2), (void*)uvoffset);

				glBindBuffer(GL_ARRAY_BUFFER, 0);
				glBindVertexArray(0);

				GLVertexData result;
				result.VAO = VAO;
				result.VBO = VBO;
				result.pointCount = pointCount;
				result.hasEBO = false;
				return result;
			}

			void GLResourceAPI::ClearVertexData(GLVertexData data)
			{
				if (data.hasEBO)
				{
					glDeleteBuffers(1, &data.EBO);//注意顺序
				}
				glDeleteBuffers(1, &data.VBO);
				glDeleteVertexArrays(1, &data.VAO);
			}

			void GLResourceAPI::ClearVertexData(unsigned int VAO, unsigned int VBO)
			{
				glDeleteBuffers(1, &VBO);
				glDeleteVertexArrays(1, &VAO);
			}

			GLTextureData GLResourceAPI::AddTextureData(unsigned char* data, int width, int height, int filter)
			{
				unsigned int texture = 0;
				glGenTextures(1, &texture);
				GLenum format, internalFormal;
				format = GL_RGBA;
				internalFormal = GL_RGBA;
				glBindTexture(GL_TEXTURE_2D, texture);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
				//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
				//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
				glTexImage2D(GL_TEXTURE_2D, 0, internalFormal, width, height, 0, format, GL_UNSIGNED_BYTE, data);
				GLTextureData result;
				result.texture = texture;
				return result;
			}

			void GLResourceAPI::ClearTextureData(unsigned int texture)
			{
				glDeleteTextures(1, &texture);
			}
		}
	}
}