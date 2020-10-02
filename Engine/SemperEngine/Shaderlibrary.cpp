#include "ShaderSource.h"

namespace SemperEngine
{
	namespace Core
	{

		std::vector<Shaderfile> Shaderlibrary::shaderfiles = {
			Shaderfile("Unlit","Shader/Unlit.vs", "Shader/Unlit.fs"),
			Shaderfile("Debug", "Shader/Debug.vs", "Shader/Debug.fs")
		};


	}
}