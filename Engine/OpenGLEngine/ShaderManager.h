#pragma once
#include <iostream>
#include <map>
#include "shader.h"

 class ShaderManager
{
public:

	static std::map<std::string, Shader> shaderMap;

	static void CompileShader();

	static Shader* GetShader(std::string name);
};

