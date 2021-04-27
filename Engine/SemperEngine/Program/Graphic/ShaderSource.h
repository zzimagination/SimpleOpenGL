#ifndef __SHADER_SOURCE__
#define __SHADER_SOURCE__

#include <string>
#include <vector>

namespace Semper
{
	namespace Core
	{
		class Shaderfile
		{
		public:

			std::string name;

			std::string vertex;

			std::string fragment;

			std::string geometry;

		public:

			Shaderfile(std::string name, std::string v, std::string f, std::string g = "")
			{
				this->name = name;
				this->vertex = v;
				this->fragment = f;
				this->geometry = g;
			}

		};
	}
}

#endif // !SHADER_SOURCE
