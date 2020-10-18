#include "TextureLib.h"
#include <iostream>
#include <fstream>
#include "spng.h"

namespace SemperEngine
{
	namespace TextureLib
	{
		using namespace std;

		TextureFile::TextureFile(std::string file)
		{
			this->path = file;
			this->compression = 0;
			this->depth = 0;
			this->filter = 0;
			this->height = 0;
			this->width = 0;
			this->interlace = 0;
			this->colorType = ColorType::Grayscale;
		}

	}
}