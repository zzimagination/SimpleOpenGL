#pragma once
#ifndef GL_SHADERAPI
#define GL_SHADERAPI

#include <string>
#include "GraphicShader.h"

namespace SemperEngine
{
	namespace GraphicAPI
	{
		class GLShaderCompiler
		{
		public:

			static GraphicShader Compile(std::string vertexCode, std::string fragmentCode, std::string geometryCode);

		private:

			static unsigned int CompileOne(std::string code, unsigned int type);
		};
	}
}

#endif // !GL_SHADERAPI
