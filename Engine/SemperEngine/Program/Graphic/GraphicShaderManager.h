#ifndef __SHADER_MANAGER__
#define __SHADER_MANAGER__

#include <map>
#include <string>
#include "GraphicShader.h"

namespace SemperEngine 
{
	namespace Core
	{
		class GraphicShaderManager
		{
		public:

			static std::map<std::string, GraphicShader> shaderMap;

		public:

			static GraphicShader FindShader(std::string name);

		};
	}
}

#endif // !SHADER_MANAGER

