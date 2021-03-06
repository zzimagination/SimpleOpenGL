#include "GLShaderAPI.h"
#include <glad/glad.h>

namespace Semper
{
	namespace GL
	{
		using namespace std;

		GLShader GLShaderCompiler::Compile(std::string vertexCode, std::string fragmentCode, std::string geometryCode)
		{
			auto hasGeometry = geometryCode != "";
			auto vertex = CompileOne(vertexCode, GL_VERTEX_SHADER);
			auto frag = CompileOne(fragmentCode, GL_FRAGMENT_SHADER);
			unsigned int geo = 0;
			if (hasGeometry)
				geo = CompileOne(geometryCode, GL_GEOMETRY_SHADER);

			auto program = glCreateProgram();
			glAttachShader(program, vertex);
			glAttachShader(program, frag);
			if (hasGeometry)
				glAttachShader(program, geo);
			glLinkProgram(program);
			int success = 0;
			char infoLog[512];
			glGetProgramiv(program, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(program, 512, NULL, infoLog);
				string log = "ERROR::SHADER::PROGRAM::LINKING_FAILED\n";
				log.append(infoLog);
				Debug::LogError(log);
			}

			glDeleteShader(vertex);
			glDeleteShader(frag);
			if (hasGeometry)
				glDeleteShader(geo);

			GLShader shader;
			shader.program = program;
			return shader;
		}

		unsigned int GLShaderCompiler::CompileOne(std::string code, unsigned int type)
		{
			unsigned int shader = 0;
			int success = 0;
			char infoLog[512];
			auto shaderCode = code.c_str();
			shader = glCreateShader(type);
			glShaderSource(shader, 1, &shaderCode, NULL);
			glCompileShader(shader);
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				string log = "ERROR::SHADER::";
				log.append(to_string(type));
				log.append("::COMPILATION_FAILED\n");
				log.append(infoLog);
				Debug::LogError(log);
			};
			return shader;
		}
	}
}