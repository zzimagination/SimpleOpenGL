#include "GraphicShaderManager.h"
namespace SemperEngine {

	using namespace std;

	map<string, GraphicShader> ShaderManager::shaderMap;

	GraphicShader ShaderManager::GetShader(string name)
	{
		return shaderMap[name];
	}

}