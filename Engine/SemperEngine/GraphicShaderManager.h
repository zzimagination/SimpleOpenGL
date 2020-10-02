#pragma once
#include <map>
#include <string>
#include "GraphicShader.h"
namespace SemperEngine {

	class ShaderManager
	{
	public:

		static std::map<std::string, GraphicShader> shaderMap;

	public:

		static GraphicShader GetShader(string name);

	};

}