#pragma once
#ifndef __TEXTURELIB__
#define __TEXTURELIB__

#include "TextureFile.h"

namespace SemperEngine
{
	namespace TextureLib
	{
		class TextureResource
		{
		public:

			static TextureFile Load(std::string file);

		private:

			static void LoadResource(TextureFile& tfile);
		};
	}
}
#endif // !__TEXTURELIB__
