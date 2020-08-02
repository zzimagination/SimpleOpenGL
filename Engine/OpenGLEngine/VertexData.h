#ifndef VERTEXDATA
#define VERTEXDATA

#include <vector>

class RenderObject;

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

	VertexData();

	~VertexData();

	void BindData(RenderObject* renderObject);

	int GetCount();
	
	void UseData();
};
#endif // !VERTEXDATA



