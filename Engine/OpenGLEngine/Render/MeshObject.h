#pragma once
#include <vector>



class MeshObject
{
public:
	std::vector<float> points;

	std::vector<unsigned int> indices;

	MeshObject();

	MeshObject(std::vector<float> points, std::vector<unsigned int> indices);
};

