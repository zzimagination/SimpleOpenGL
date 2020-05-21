#include "ShaderManager.h"


std::map<std::string, Shader> ShaderManager::shaderMap;

void ShaderManager::CompileShader()
{
	Shader screen("screen", "Shader/GL.vs", "Shader/GL.fs");
	Shader GeometryShader("Geometry", "Shader/Geometry.vs", "Shader/Geometry.fs", "Shader/Geometry.gs");

	shaderMap.insert(std::pair<std::string, Shader>(screen.name, screen));
	shaderMap.insert(std::pair<std::string, Shader>(GeometryShader.name, GeometryShader));
}

Shader* ShaderManager::GetShader(std::string name)
{
	return nullptr;
}

