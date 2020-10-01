#include "CubeData.h"

namespace SemperEngine
{
	int CubeData::vertexCount = 24;

	Vector3 CubeData::vertices[24] = {
			Vector3(-1, 1, 1),Vector3(-1,-1, 1),Vector3(1,-1, 1),Vector3(1, 1, 1),//front
			Vector3(1, 1,-1),Vector3(1,-1,-1),Vector3(-1,-1,-1),Vector3(-1, 1,-1),//back
			Vector3(-1, 1,-1),Vector3(-1,-1,-1),Vector3(-1,-1, 1),Vector3(-1, 1, 1),//left
			Vector3(1, 1, 1),Vector3(1,-1, 1),Vector3(1,-1,-1),Vector3(1, 1,-1),//right
			Vector3(-1, 1,-1),Vector3(-1, 1, 1),Vector3(1, 1, 1),Vector3(1, 1,-1),//top
			Vector3(1,-1, 1),Vector3(1,-1,-1),Vector3(-1,-1,-1),Vector3(-1,-1, 1)//bottom
	};


	Vector2 CubeData::uvs[24] = {
		   Vector2(0,0),Vector2(0,1),Vector2(1,1),Vector2(1,0),//front
		   Vector2(0,0),Vector2(0,1),Vector2(1,1),Vector2(1,0),//back
		   Vector2(0,0),Vector2(0,1),Vector2(1,1),Vector2(1,0),//left
		   Vector2(0,0),Vector2(0,1),Vector2(1,1),Vector2(1,0),//right
		   Vector2(0,0),Vector2(0,1),Vector2(1,1),Vector2(1,0),//top
		   Vector2(0,0),Vector2(0,1),Vector2(1,1),Vector2(1,0)//bottom
	};

	int CubeData::indices[36] = {
		0, 1, 2, 2, 3, 0,
		4, 5, 6, 6, 7, 4,
		8, 9,10,10,11, 8,
	   12,13,14,14,15,12,
	   16,17,18,18,19,16,
	   20,21,22,22,23,20
	};
}