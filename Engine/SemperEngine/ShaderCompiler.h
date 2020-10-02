#pragma once
#ifndef SHADER_COMPILER
#define SHADER_COMPILER

#include <string>
#include "ShaderSource.h"

namespace SemperEngine
{
	namespace Core
	{
		class ShaderCompiler
		{
		public:

			static void Compile();

		private:

			static unsigned int Shader(Shaderfile file);

			static std::string ReadCode(std::string fileName);

			static unsigned int Vertex(std::string code);

			static unsigned int Fragment(std::string code);

			static unsigned int Geometry(std::string code);
		};
	}
}


#endif // !SHADER_COMPILER

