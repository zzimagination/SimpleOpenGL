#pragma once
#ifndef __GL_RESOURCEAPI__
#define __GL_RESOURCEAPI__

#include "Mathz.h"
#include "GraphicVertexData.h"

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

				unsigned int pointCount = 0;

			};


			class GLResourceAPI
			{
			public:

				static GLVertexData AddVertexData(Vector3* vertices, Vector2* uv, int* index, int count);

				static GLVertexData AddVertexData(Vector3* vertices, int count);

				static void ClearVertexData(unsigned int VAO, unsigned int VBO, unsigned int EBO);

				static void ClearVertexData(unsigned int VAO, unsigned int VBO);
			};
		}
	}
}
#endif // !GLRESOURCE
