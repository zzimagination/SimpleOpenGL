#pragma once
#include <map>
#include "GraphicShader.h"
namespace SemperEngine {
	using namespace std;

	class ShaderManager
	{
	public:

		static GraphicShader *defaultShader;

		static map<string, GraphicShader> shaderMap;

	public:

		static void CompileShader();

		static GraphicShader* GetShader(string name);

	};

}