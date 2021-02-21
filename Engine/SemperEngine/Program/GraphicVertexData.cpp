#include "GraphicVertexData.h"

namespace SemperEngine
{
	namespace Core
	{
		GraphicVertexData::GraphicVertexData()
		{
		}

		GraphicVertexData::GraphicVertexData(unsigned int vao, unsigned int vbo, int pointCount)
		{
			this->VAO = vao;
			this->VBO = vbo;
			this->pointCount = pointCount;
		}

		GraphicVertexData::GraphicVertexData(unsigned int vao, unsigned int vbo, unsigned int ebo, int count)
		{
			this->VAO = vao;
			this->VBO = vbo;
			this->EBO = ebo;
			this->pointCount = count;
			this->indexDraw = true;
		}

		GraphicVertexData::~GraphicVertexData()
		{
		}
	}
}