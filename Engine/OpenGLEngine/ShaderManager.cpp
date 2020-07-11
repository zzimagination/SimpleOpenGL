#include "ShaderManager.h"

using namespace std;

map<string, ShaderProgram> ShaderManager::shaderMap;

void ShaderManager::CompileShader()
{
	ShaderProgram unlit("Shader/Unlit.vs", "Shader/Unlit.fs");
	unlit.name = "Unlit";
	shaderMap.insert(std::pair<std::string, ShaderProgram>(unlit.name, unlit));

	ShaderProgram unlitTexture("Shader/Unlit.vs", "Shader/UnlitTexture.fs");
	unlitTexture.name = "UnlitTexture";
	shaderMap.insert(pair<string, ShaderProgram>(unlitTexture.name, unlitTexture));
}

ShaderProgram* ShaderManager::GetShader(string name)
{
	ShaderProgram* s= &shaderMap[name];
	if (s == nullptr)
	{
		throw "no shader" + name;
	}
	return s;
}

