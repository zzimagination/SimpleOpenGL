#ifndef __GRAPHIC_VERTEXDATA__
#define __GRAPHIC_VERTEXDATA__

#include <vector>
#include "Mathz.h"
#include "VertexData.h"

namespace SemperEngine {

	class GraphicVertexData
	{
	public:

		unsigned int VAO;

		unsigned int VBO;

		unsigned int EBO;

		int pointCount;

	public:

		GraphicVertexData();

		GraphicVertexData(unsigned int vao, unsigned int vbo, unsigned int ebo, int pointCount);

		~GraphicVertexData();

	};
}
#endif // !VERTEXDATA



