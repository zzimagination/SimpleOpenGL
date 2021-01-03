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
			for (int i = 0; i < shaderfiles.size(); i++)
			{
				GraphicShaderManager::shaderMap[shaderfiles[i].name] = Shader(shaderfiles[i]);
			}
		}

		GraphicShader ShaderCompiler::Shader(Shaderfile file)
		{
			auto codev = ReadCode(file.vertex);
			auto codef = ReadCode(file.fragment);
			auto codeg = ReadCode(file.geometry);
			auto sliver = GLShaderCompiler::Compile(codev, codef, codeg);
			GraphicShader result;
			result.opengl_id = sliver.program;
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