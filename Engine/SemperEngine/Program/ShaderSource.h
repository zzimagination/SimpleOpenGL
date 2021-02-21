#pragma once
#ifndef __SHADER_SOURCE__
#define __SHADER_SOURCE__

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

		const std::vector<Shaderfile> shaderfiles = {
			Shaderfile("Color","Shader/Color.vs", "Shader/Color.fs"),
			Shaderfile("Debug", "Shader/Debug.vs", "Shader/Debug.fs"),
			Shaderfile("Texture", "Shader/Texture.vs", "Shader/Texture.fs"),
			Shaderfile("ScreenTexture", "Shader/ScreenTexture.vs", "Shader/ScreenTexture.fs")
		};
	}
}

#endif // !SHADER_SOURCE
