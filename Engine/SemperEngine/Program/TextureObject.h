#pragma once
#ifndef __TEXTURE_OBJECT__
#define __TEXTURE_OBJECT__

#include <memory>
#include <vector>
#include "Common.h"
#include "ResourcePackage.h"
#include "ResourceObject.h"
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{

		class TextureObject : public ResourceObject
		{
		public:

			struct Setting
			{
				bool readOnly = false;
			};

		public:

			ResourcePackage<TextureData> resourcePackage;

			GraphicDataInfo graphicDataInfo;

		public:

			static TextureObject* Create();

		public:

			TextureObject();

			virtual ~TextureObject() override;

			virtual void EndCreate() override;

			virtual void EndDelete() override;

			virtual void EndModify() override;

			void ColorBytes(ArrayList<ColorByte> data);

			TextureObject* Copy();

			ArrayList<ColorByte> ColorBytes();
		};
	}
}


#endif // !__TEXTURE_OBJECT__
