#pragma once
#ifndef __SHADER_COMPILER__
#define __SHADER_COMPILER__

#include <string>
#include "ShaderSource.h"
#include "GraphicShader.h"

namespace SemperEngine
{
	namespace Core
	{
		class ShaderCompiler
		{
		public:

			static void Compile();

		private:

			static GraphicShader Shader(Shaderfile file);

			static std::string ReadCode(std::string fileName);

		};
	}
}


#endif // !SHADER_COMPILER

