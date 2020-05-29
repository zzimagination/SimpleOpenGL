#include "ShaderManager.h"

using namespace std;

std::map<std::string, Shader> ShaderManager::shaderMap;

void ShaderManager::CompileShader()
{
	Shader unlit("Resources/Shader/Unlit.vs", "Resources/Shader/Unlit.fs");
	unlit.name = "Unlit";
	shaderMap.insert(std::pair<std::string, Shader>(unlit.name, unlit));

	Shader unlitTexture("Resources/Shader/Unlit.vs", "Resources/Shader/UnlitTexture.fs");
	unlitTexture.name = "UnlitTexture";
	shaderMap.insert(pair<string, Shader>(unlitTexture.name, unlitTexture));
}

Shader* ShaderManager::GetShader(std::string name)
{
	Shader* s= &shaderMap[name];
	if (s == nullptr)
	{
		return nullptr;
	}
	return s;
}

