#pragma once
#ifndef SHADER_SOURCE
#define SHADER_SOURCE

#include <string>
#include <vector>

namespace SemperEngine
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

		class Shaderlibrary
		{
		public:

			static std::vector<Shaderfile> shaderfiles;

		};
	}
}

#endif // !SHADER_SOURCE
