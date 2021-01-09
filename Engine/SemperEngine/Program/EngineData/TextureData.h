#pragma once
#ifndef __TEXTUREDATA__
#define __TEXTUREDATA__

#include <string>
#include <memory>
#include "BaseData.h"

namespace SemperEngine
{
	namespace Core
	{
		class TextureData : public BaseData
		{
		public:

			ArrayList<ColorByte> pixels;

			int width = 0;

			int height = 0;

		public:

			TextureData();

			virtual ~TextureData() override;

			TextureData* Copy();
		};
	}
}

#endif // !__TEXTUREDATA__
