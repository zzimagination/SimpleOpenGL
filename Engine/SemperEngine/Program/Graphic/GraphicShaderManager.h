#ifndef __SHADER_MANAGER__
#define __SHADER_MANAGER__

#include <map>
#include <string>
#include "GraphicShader.h"
#include "ShaderSource.h"

namespace Semper 
{
	namespace Core
	{
		class GraphicShaderManager
		{
		private:

			static std::vector<std::string> _shaderNameList;

			static std::vector<GraphicShader*> _shaderList;
			
		public:

			static void Initialize();

			static GraphicShader* GetShader(std::string name);

			static GraphicShader* GetShader(int id);

			static int GetShaderID(std::string name);

		private:

			static void AddShader(Shaderfile &&file);
		};
	}
}

#endif // !SHADER_MANAGER

