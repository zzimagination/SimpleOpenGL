#include "ShaderCompiler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <glad/glad.h>
#include "Debug.h"
#include "GraphicShaderManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		void ShaderCompiler::Compile()
		{
			auto files = Shaderlibrary::shaderfiles;
			for (int i = 0; i < files.size(); i++)
			{
				auto program = Shader(files[i]);
				GraphicShader shader(program);
				pair<string, unsigned int> pair(files[i].name, program);
				ShaderManager::shaderMap.insert(pair);
			}
			Debug::Log("Shader Compile");
		}

		unsigned int ShaderCompiler::Shader(Shaderfile file)
		{
			auto codev = ReadCode(file.vertex);
			auto codef = ReadCode(file.fragment);
			auto codeg = ReadCode(file.geometry);

			bool hasGeo = codeg != "";

			unsigned int vertex, frag, geo;
			vertex = Vertex(codev);
			frag = Fragment(codef);
			if (hasGeo)
			{
				geo = Geometry(codeg);
			}

			auto program = glCreateProgram();
			glAttachShader(program, vertex);
			glAttachShader(program, frag);
			if (hasGeo)
			{
				glAttachShader(program, geo);
			}

			glLinkProgram(program);
			int success = 0;
			char infoLog[512];
			glGetProgramiv(program, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(program, 512, NULL, infoLog);
				string log = "ERROR::SHADER::PROGRAM::LINKING_FAILED\n";
				log.append(infoLog);
				Debug::Log(log);
			}

			glDeleteShader(vertex);
			glDeleteShader(frag);
			if (hasGeo)
			{
				glDeleteShader(geo);
			}
			return program;
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
		unsigned int ShaderCompiler::Vertex(std::string code)
		{
			unsigned int shader = 0;
			int success = 0;
			char infoLog[512];
			auto shaderCode = code.c_str();
			shader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(shader, 1, &shaderCode, NULL);
			glCompileShader(shader);
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				string log = "ERROR::SHADER::";
				log.append(code);
				log.append("::COMPILATION_FAILED\n");
				log.append(infoLog);
				Debug::Log(log);
			};
			return shader;
		}
		unsigned int ShaderCompiler::Fragment(std::string code)
		{
			unsigned int shader = 0;
			int success = 0;
			char infoLog[512];
			auto shaderCode = code.c_str();
			shader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(shader, 1, &shaderCode, NULL);
			glCompileShader(shader);
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				string log = "ERROR::SHADER::";
				log.append(code);
				log.append("::COMPILATION_FAILED\n");
				log.append(infoLog);
				Debug::Log(log);
			};
			return shader;
		}
		unsigned int ShaderCompiler::Geometry(std::string code)
		{
			unsigned int shader = 0;
			int success = 0;
			char infoLog[512];
			auto shaderCode = code.c_str();
			shader = glCreateShader(GL_GEOMETRY_SHADER);
			glShaderSource(shader, 1, &shaderCode, NULL);
			glCompileShader(shader);
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				string log = "ERROR::SHADER::";
				log.append(code);
				log.append("::COMPILATION_FAILED\n");
				log.append(infoLog);
				Debug::Log(log);
			};
			return shader;
		}
	}
}