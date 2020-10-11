#pragma once
#ifndef __GL_SHADERAPI__
#define __GL_SHADERAPI__

#include <string>
#include "GraphicShader.h"

namespace SemperEngine
{
	namespace Core
	{
		namespace GraphicAPI
		{
			class GLShader
			{
			public:

				unsigned int program;
			};

			class GLShaderCompiler
			{
			public:

				static GLShader Compile(std::string vertexCode, std::string fragmentCode, std::string geometryCode);

			private:

				static unsigned int CompileOne(std::string code, unsigned int type);
			};
		}
	}
}
#endif // !GL_SHADERAPI
