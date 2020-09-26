#ifndef VERTEXDATA
#define VERTEXDATA

#include <vector>
#include "Mathz.h"
namespace SemperEngine {
	class RenderObject;
	class RenderVertexData;

	using namespace std;

	class GraphicVertexData
	{
	public:

		RenderVertexData* gameData;

		unsigned int VAO;

		unsigned int VBO;

		unsigned int EBO;

		int pointCount;

	public:

		GraphicVertexData(RenderVertexData *gameData, unsigned int vao, unsigned int vbo, unsigned int ebo, int pointCount);

		~GraphicVertexData();

	};
}
#endif // !VERTEXDATA



