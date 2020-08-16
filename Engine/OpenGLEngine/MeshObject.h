#pragma once
#include <vector>

namespace SemperEngine {

	class MeshObject
	{
	public:
		std::vector<float> points;

		std::vector<unsigned int> indices;

		MeshObject();

		MeshObject(std::vector<float> points, std::vector<unsigned int> indices);
	};

}