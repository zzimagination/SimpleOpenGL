#include "MeshObject.h"
namespace SemperEngine {
	MeshObject::MeshObject()
	{
	}

	MeshObject::MeshObject(std::vector<float> points, std::vector<unsigned int> indices)
	{
		this->points = points;
		this->indices = indices;
	}
}