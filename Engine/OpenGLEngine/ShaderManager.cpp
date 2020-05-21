#include "ShaderManager.h"


std::map<std::string, Shader> ShaderManager::shaderMap;

void ShaderManager::CompileShader()
{
	std::string nameStr("Geometry");
	Shader GeometryShader("Shader/Geometry.vs", "Shader/Geometry.fs", "Shader/Geometry.gs");
	GeometryShader.name = nameStr;

	shaderMap.insert(std::pair<std::string, Shader>(GeometryShader.name, GeometryShader));
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

