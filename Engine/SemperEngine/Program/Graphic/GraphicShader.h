#ifndef __GRAPHIC_SHADER__
#define __GRAPHIC_SHADER__

#include "Graphic.h"

namespace Semper 
{
	namespace Core
	{

		class GraphicShader
		{
		public:

			unsigned int glPrograme = 0;

		public:

			void ConstructGL(unsigned int program);
		};
	}
}
#endif