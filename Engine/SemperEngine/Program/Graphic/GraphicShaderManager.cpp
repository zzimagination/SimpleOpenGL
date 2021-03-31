#include "GraphicShaderManager.h"

namespace SemperEngine 
{
	namespace Core
	{
		using namespace std;

		map<string, GraphicShader> GraphicShaderManager::shaderMap;

		GraphicShader GraphicShaderManager::FindShader(string name)
		{
			return shaderMap[name];
		}
	}
}