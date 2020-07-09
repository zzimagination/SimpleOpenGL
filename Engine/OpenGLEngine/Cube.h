#pragma once
#include <vector>
#include "Mathz.h"
#include "BuildInData.h"

using namespace glm;
using namespace std;

class Cube :
	public BuildInData
{
public:

	vec3 vertices[24] = {
			vec3(-1, 1, 1),vec3(-1,-1, 1),vec3(1,-1, 1),vec3(1, 1, 1),//front
			vec3(1, 1,-1),vec3(1,-1,-1),vec3(-1,-1,-1),vec3(-1, 1,-1),//back
			vec3(-1, 1,-1),vec3(-1,-1,-1),vec3(-1,-1, 1),vec3(-1, 1, 1),//left
			vec3(1, 1, 1),vec3(1,-1, 1),vec3(1,-1,-1),vec3(1, 1,-1),//right
			vec3(-1, 1,-1),vec3(-1, 1, 1),vec3(1, 1, 1),vec3(1, 1,-1),//top
			vec3(1,-1, 1),vec3(1,-1,-1),vec3(-1,-1,-1),vec3(-1,-1, 1)//bottom
	};

	vec2 uvs[24] = {
			vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0),//front
			vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0),//back
			vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0),//left
			vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0),//right
			vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0),//top
			vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0)//bottom
	};

	int indices[36] = {
		0,1,2,3,2,0,
		4,5,6,7,6,4,
		8,9,10,11,10,8,
		12,13,14,15,14,12,
		16,17,18,19,18,16,
		20,21,22,23,22,20
	};
};

