#include "ShaderManager.h"

using namespace std;

ShaderProgram *ShaderManager::defaultShader;

map<string, ShaderProgram> ShaderManager::shaderMap;

void ShaderManager::CompileShader()
{
	ShaderProgram unlit("Shader/Unlit.vs", "Shader/Unlit.fs");
	unlit.name = "Unlit";
	unlit.Apply();
	shaderMap.insert(std::pair<std::string, ShaderProgram>(unlit.name, unlit));
	defaultShader = &unlit;

	ShaderProgram debug("Shader/Debug.vs", "Shader/Debug.fs");
	debug.name = "Debug";
	debug.Apply();
	shaderMap.insert(std::pair<std::string, ShaderProgram>(debug.name, debug));

	ShaderProgram unlitTexture("Shader/Unlit.vs", "Shader/UnlitTexture.fs");
	unlitTexture.name = "UnlitTexture";
	unlitTexture.Apply();
	shaderMap.insert(pair<string, ShaderProgram>(unlitTexture.name, unlitTexture));
}

ShaderProgram* ShaderManager::GetShader(string name)
{
	ShaderProgram* s= &shaderMap[name];
	if (s == nullptr)
	{
		return defaultShader;
	}
	return s;
}

