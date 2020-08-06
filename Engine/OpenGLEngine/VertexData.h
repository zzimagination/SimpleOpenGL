#ifndef VERTEXDATA
#define VERTEXDATA

#include <vector>
#include "Mathz.h"

class RenderObject;
class RenderVertex;

using namespace std;

class VertexData
{
public:

	unsigned int VAO;

private:

	unsigned int VBO;

	unsigned int EBO;

	int _pointCount;

public:

	VertexData(RenderVertex* renderVertex);

	~VertexData();

	int GetCount();

	void UseData();

private:

	void BindData(Vector3* vertices, int count, int* index, Vector2* uv);
};
#endif // !VERTEXDATA



