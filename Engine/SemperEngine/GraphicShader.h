#ifndef __GRAPHIC_SHADER__
#define __GRAPHIC_SHADER__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Mathz.h"

namespace SemperEngine 
{
	namespace Core
	{
		constexpr const char* MODEL_MATRIX = "_model";
		constexpr const char* VIEW_MATRIX = "_view";
		constexpr const char* PROJECTION_MARIX = "_projection";
		constexpr const char* MAINCOLOR = "_color";

		class GraphicShader
		{
		public:

			unsigned int opengl_id;

		public:

		};
	}
}
#endif