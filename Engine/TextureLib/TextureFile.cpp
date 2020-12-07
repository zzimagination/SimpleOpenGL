#include "TextureLib.h"
#include <iostream>
#include <fstream>
#include "spng.h"

namespace SemperEngine
{
	namespace TextureLib
	{
		using namespace std;

		void TextureFile::Dispose()
		{
			delete [] this->textureData;
		}
	}
}