#pragma once
#include <vector>
#include <map>
#include <glad/glad.h>
#include "Mathz.hpp"
#include "shader.h"

using namespace glm;
using namespace std;

class RenderBatch
{
public:

	mat4 modelMat;

	mat4 viewMat;

	mat4 projectionMat;

	map<string, vec3> vec3Map;

	std::vector<unsigned int> glTextures;

	void (*func_shader)(Shader* shader);

	RenderBatch(Shader* shader, unsigned int VAO, GLsizei count);

	void DrawCall();

private:

	Shader* _shader;

	unsigned int _VAO;

	int _glCount;
};

