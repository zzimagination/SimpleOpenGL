#include "ShaderCompiler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "GraphicShaderManager.h"
#include "GLShaderAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace GraphicAPI;

		void ShaderCompiler::Compile()
		{
			auto files = Shaderlibrary::shaderfiles;
			for (int i = 0; i < files.size(); i++)
			{
				auto shader = Shader(files[i]);
				pair<string, GraphicShader> pair(files[i].name, shader);
				ShaderManager::shaderMap.insert(pair);
			}
		}

		GraphicShader ShaderCompiler::Shader(Shaderfile file)
		{
			auto codev = ReadCode(file.vertex);
			auto codef = ReadCode(file.fragment);
			auto codeg = ReadCode(file.geometry);
			auto result = GLShaderCompiler::Compile(codev, codef, codeg);
			return result;
		}

		std::string ShaderCompiler::ReadCode(string fileName)
		{
			if (fileName == "")
			{
				return "";
			}
			ifstream file;
			file.exceptions((ifstream::failbit | ifstream::badbit));
			file.open(fileName, ios::in, _SH_DENYRW);
			stringstream strStream;
			strStream << file.rdbuf();
			file.close();
			return strStream.str();
		}
	}
}