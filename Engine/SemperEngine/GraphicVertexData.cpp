#include<glad/glad.h>

#include "GraphicVertexData.h"
#include "RenderObject.h"
#include "RenderVertexData.h"

namespace SemperEngine
{
	GraphicVertexData::GraphicVertexData(RenderVertexData* gameData, unsigned int vao, unsigned int vbo, unsigned int ebo, int count)
	{
		this->gameData = gameData;
		this->VAO = vao;
		this->VBO = vbo;
		this->EBO = ebo;
		this->pointCount = count;
	}

	GraphicVertexData::~GraphicVertexData()
	{
	}

}