#pragma once
#ifndef __TEXTURE_OBJECT__
#define __TEXTURE_OBJECT__

#include "ResourcePackage.h"
#include "ResourceObject.h"
#include "TextureData.h"
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

			TextureObject();

			TextureObject(bool share);

			TextureObject(bool share, Setting setting);

			virtual ~TextureObject() override;

		};
	}
}


#endif // !__TEXTURE_OBJECT__
