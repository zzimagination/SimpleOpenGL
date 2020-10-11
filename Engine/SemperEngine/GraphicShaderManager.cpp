#include "GraphicShaderManager.h"
namespace SemperEngine {

	using namespace std;

	map<string, GraphicShader> GraphicShaderManager::shaderMap;

	GraphicShader GraphicShaderManager::FindShader(string name)
	{
		return shaderMap[name];
	}

}