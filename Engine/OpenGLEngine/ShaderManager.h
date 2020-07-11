#pragma once
#include <map>
#include "ShaderProgram.h"

using namespace std;

 class ShaderManager
{
public:

	static map<string, ShaderProgram> shaderMap;

	static void CompileShader();

	static ShaderProgram* GetShader(std::string name);

};

