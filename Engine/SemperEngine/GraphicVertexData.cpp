#include "GraphicVertexData.h"

namespace SemperEngine
{
	namespace Core
	{
		GraphicVertexData::GraphicVertexData()
		{
			this->VAO = 0;
			this->VBO = 0;
			this->EBO = 0;
			this->pointCount = 0;
			_source = nullptr;
		}

		GraphicVertexData::GraphicVertexData(unsigned int vao, unsigned int vbo, unsigned int ebo, int count)
		{
			this->VAO = vao;
			this->VBO = vbo;
			this->EBO = ebo;
			this->pointCount = count;
			_source = nullptr;
		}

		GraphicVertexData::~GraphicVertexData()
		{
		}
		void GraphicVertexData::SetSource(VertexData* source)
		{
			_source = source;
			isPrimitived = true;
		}

		VertexData* GraphicVertexData::GetSource()
		{
			return _source;
		}

		void GraphicVertexData::Complete()
		{
			isPrimitived = false;
			_source = nullptr;
		}
		
	}
}