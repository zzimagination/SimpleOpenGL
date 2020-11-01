#include "CubeData.h"

namespace SemperEngine
{
	int CubeData::vertexCount = 24;

	Float3 CubeData::vertices[24] = {
			Float3(-0.5f, 0.5f, 0.5f),Float3(-0.5f,-0.5f, 0.5f),Float3(0.5,-0.5f, 0.5f),Float3(0.5f, 0.5f, 0.5f),//front
			Float3(0.5f, 0.5f,-0.5f),Float3(0.5f,-0.5f,-0.5f),Float3(-0.5f,-0.5f,-0.5f),Float3(-0.5f, 0.5f,-0.5f),//back
			Float3(-0.5f, 0.5f,-0.5f),Float3(-0.5f,-0.5f,-0.5f),Float3(-0.5f,-0.5f, 0.5f),Float3(-0.5f, 0.5f, 0.5f),//left
			Float3(0.5f, 0.5f, 0.5f),Float3(0.5f,-0.5f, 0.5f),Float3(0.5f,-0.5f,-0.5f),Float3(0.5f, 0.5f,-0.5f),//right
			Float3(-0.5f, 0.5f,-0.5f),Float3(-0.5f, 0.5f, 0.5f),Float3(0.5f, 0.5f, 0.5f),Float3(0.5f, 0.5f,-0.5f),//top
			Float3(0.5f,-0.5f, 0.5f),Float3(0.5f,-0.5f,-0.5f),Float3(-0.5f,-0.5f,-0.5f),Float3(-0.5f,-0.5f, 0.5f)//bottom
	};


	Float2 CubeData::uvs[24] = {
		   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0),//front
		   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0),//back
		   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0),//left
		   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0),//right
		   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0),//top
		   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0)//bottom
	};

	int CubeData::indices[36] = {
		0, 1, 2, 2, 3, 0,
		4, 5, 6, 6, 7, 4,
		8, 9,10,10,11, 8,
	   12,13,14,14,15,12,
	   16,17,18,18,19,16,
	   22,21,20,20,23,22
	};
}