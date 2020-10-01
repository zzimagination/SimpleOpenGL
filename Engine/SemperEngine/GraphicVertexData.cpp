#include "GraphicVertexData.h"

namespace SemperEngine
{
	GraphicVertexData::GraphicVertexData()
	{
		this->VAO = 0;
		this->VBO = 0;
		this->EBO = 0;
		this->pointCount = 0;
	}
	GraphicVertexData::GraphicVertexData(unsigned int vao, unsigned int vbo, unsigned int ebo, int count)
	{
		this->VAO = vao;
		this->VBO = vbo;
		this->EBO = ebo;
		this->pointCount = count;
	}

	GraphicVertexData::~GraphicVertexData()
	{
	}

}