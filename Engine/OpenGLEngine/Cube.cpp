#include "Cube.h"

int Cube::VertexCount()
{
	return sizeof(vertices) / sizeof(Vector3);
}

Vector3 * Cube::GetVertices()
{
	return vertices;
}

Vector2* Cube::GetUV()
{
	return uvs;
}

int* Cube::GetIndices()
{
	return indices;
}
