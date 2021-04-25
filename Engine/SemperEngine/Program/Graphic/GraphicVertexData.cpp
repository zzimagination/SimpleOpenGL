#include "GraphicVertexData.h"

namespace Semper
{
	namespace Core
	{
		GraphicVertexData::GraphicVertexData()
		{
		}

		GraphicVertexData::~GraphicVertexData()
		{
		}

		void GraphicVertexData::SetGL(unsigned int VAO, unsigned int VBO, int pointCount)
		{
			this->VAO = VAO;
			this->VBO = VBO;
			this->pointCount = pointCount;
			this->Complete();
		}

		void GraphicVertexData::SetGL(unsigned int VAO, unsigned int VBO, unsigned int EBO, int pointCount)
		{
			this->VAO = VAO;
			this->VBO = VBO;
			this->EBO = EBO;
			this->pointCount = pointCount;
			this->Complete();
		}
	}
}