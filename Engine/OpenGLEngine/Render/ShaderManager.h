#pragma once
#include <map>
#include "shader.h"

using namespace std;

 class ShaderManager
{
public:

	static map<string, Shader> shaderMap;

	static void CompileShader();

	static Shader* GetShader(std::string name);
};

