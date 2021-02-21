#pragma once
#ifndef __GL_RESOURCEAPI__
#define __GL_RESOURCEAPI__

#include "Math/Math.h"
#include <array>

namespace SemperEngine
{
	namespace Core
	{
		namespace GraphicAPI
		{
			struct GLVertexData
			{
				unsigned int VAO = 0;

				unsigned int VBO = 0;

				unsigned int EBO = 0;

				bool hasEBO = false;

				unsigned int pointCount = 0;

			};

			struct GLTextureData
			{
				unsigned int texture = 0;
			};

			class GLResourceAPI
			{
			public:

				static int texNearest;

				static int texLinear;

			public:

				static GLVertexData AddVertexData(Float3* vertices, Float2* uv, int* index, int count);

				static GLVertexData AddVertexData(Float3* vertices, int count);

				static GLVertexData AddVertexData(Float3* vertices, Float2* uv, int count);

				static void ClearVertexData(GLVertexData data);

				static void ClearVertexData(unsigned int VAO, unsigned int VBO);

				static GLTextureData AddTextureData(unsigned char* data, int width, int height, int filter);

				static void ClearTextureData(unsigned int texture);
			};
		}
	}
}
#endif // !GLRESOURCE
