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

		unsigned int VAO;

	private:

		unsigned int VBO;

		unsigned int EBO;

		int _pointCount;

	public:

		GraphicVertexData(RenderVertexData* renderVertex);

		~GraphicVertexData();

		int GetCount();

		void UseData();

	private:

		void BindData(Vector3* vertices, int count, int* index, Vector2* uv);
	};
}
#endif // !VERTEXDATA



