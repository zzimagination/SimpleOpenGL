#include "ShaderManager.h"

using namespace std;

map<string, Shader> ShaderManager::shaderMap;

void ShaderManager::CompileShader()
{
	Shader unlit("Resources/Shader/Unlit.vs", "Resources/Shader/Unlit.fs");
	unlit.name = "Unlit";
	shaderMap.insert(std::pair<std::string, Shader>(unlit.name, unlit));

	Shader unlitTexture("Resources/Shader/Unlit.vs", "Resources/Shader/UnlitTexture.fs");
	unlitTexture.name = "UnlitTexture";
	shaderMap.insert(pair<string, Shader>(unlitTexture.name, unlitTexture));
}

Shader* ShaderManager::GetShader(string name)
{
	Shader* s= &shaderMap[name];
	if (s == nullptr)
	{
		throw "no shader" + name;
	}
	return s;
}

