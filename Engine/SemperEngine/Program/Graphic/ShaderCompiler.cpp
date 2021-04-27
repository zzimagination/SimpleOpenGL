#include "ShaderCompiler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "GraphicShaderManager.h"
#include "GL/GLShaderAPI.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;
		using namespace GL;

		GraphicShader* ShaderCompiler::Compile(Shaderfile& file)
		{
			GraphicShader* shader = new GraphicShader();
			auto codev = ReadCode(file.vertex);
			auto codef = ReadCode(file.fragment);
			auto codeg = ReadCode(file.geometry);
			auto sliver = GLShaderCompiler::Compile(codev, codef, codeg);
			shader->ConstructGL(sliver.program);
			return shader;
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