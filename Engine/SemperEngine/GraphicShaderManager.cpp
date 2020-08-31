#include "GraphicShaderManager.h"
namespace SemperEngine {
	using namespace std;

	GraphicShader *ShaderManager::defaultShader;

	map<string, GraphicShader> ShaderManager::shaderMap;

	void ShaderManager::CompileShader()
	{
		GraphicShader unlit("Shader/Unlit.vs", "Shader/Unlit.fs");
		unlit.name = "Unlit";
		unlit.Apply();
		shaderMap.insert(std::pair<std::string, GraphicShader>(unlit.name, unlit));
		defaultShader = &unlit;

		GraphicShader debug("Shader/Debug.vs", "Shader/Debug.fs");
		debug.name = "Debug";
		debug.Apply();
		shaderMap.insert(std::pair<std::string, GraphicShader>(debug.name, debug));

		GraphicShader unlitTexture("Shader/Unlit.vs", "Shader/UnlitTexture.fs");
		unlitTexture.name = "UnlitTexture";
		unlitTexture.Apply();
		shaderMap.insert(pair<string, GraphicShader>(unlitTexture.name, unlitTexture));
	}

	GraphicShader* ShaderManager::GetShader(string name)
	{
		GraphicShader* s = &shaderMap[name];
		if (s == nullptr)
		{
			return defaultShader;
		}
		return s;
	}

}