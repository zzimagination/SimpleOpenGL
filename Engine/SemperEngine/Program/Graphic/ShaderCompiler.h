#ifndef __SHADER_COMPILER__
#define __SHADER_COMPILER__

#include <string>
#include "ShaderSource.h"
#include "GraphicShader.h"

namespace Semper
{
	namespace Core
	{
		class ShaderCompiler
		{
		public:

			static GraphicShader* Compile(Shaderfile &file);

		private:

			static std::string ReadCode(std::string fileName);

		};
	}
}
#endif // !SHADER_COMPILER

