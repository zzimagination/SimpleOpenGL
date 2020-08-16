#pragma once
#include <map>
#include "ShaderProgram.h"
namespace SemperEngine {
	using namespace std;

	class ShaderManager
	{
	public:

		static ShaderProgram *defaultShader;

		static map<string, ShaderProgram> shaderMap;

	public:

		static void CompileShader();

		static ShaderProgram* GetShader(string name);

	};

}