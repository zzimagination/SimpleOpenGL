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

			std::shared_ptr<unsigned char> data;

			int width = 0;

			int height = 0;

		public:

			TextureData();

			virtual ~TextureData() override;

		};
	}
}

#endif // !__TEXTUREDATA__
