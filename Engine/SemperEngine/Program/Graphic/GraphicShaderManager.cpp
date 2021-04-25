#include "GraphicShaderManager.h"

namespace Semper 
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