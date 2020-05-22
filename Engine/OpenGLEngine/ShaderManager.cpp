#include "ShaderManager.h"


std::map<std::string, Shader> ShaderManager::shaderMap;

void ShaderManager::CompileShader()
{
	Shader GeometryShader("Shader/GL.vs", "Shader/GL.fs");
	GeometryShader.name = "GL";

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

