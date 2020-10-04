#pragma once
#ifndef GL_RESOURCEAPI
#define GL_RESOURCEAPI

#include "Mathz.h"
#include "GraphicVertexData.h"

namespace SemperEngine
{
	namespace GraphicAPI
	{
		class GLResourceAPI
		{
		public:

			static GraphicVertexData AddVertexData(Vector3* vertices, Vector2* uv, int* index, int count);

			static void ClearVertexData(const unsigned int VAO, const unsigned int VBO, const  unsigned int EBO);
		};
	}
}

#endif // !GLRESOURCE
