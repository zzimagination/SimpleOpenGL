#pragma once
#ifndef __TEXTUREDATA__
#define __TEXTUREDATA__

#include <string>
#include <memory>
#include <vector>
#include "Mathz.h"
#include "BaseData.h"

namespace SemperEngine
{
	namespace Core
	{
		class TextureData : public BaseData
		{
		public:

			std::shared_ptr<std::vector<unsigned char>> data;

			int width = 0;

			int height = 0;

		public:

			TextureData();

			virtual ~TextureData() override;

			TextureData* Copy();

			unsigned char* SourceData();
		};
	}
}

#endif // !__TEXTUREDATA__
