#pragma once
#ifndef __TEXTURE_OBJECT__
#define __TEXTURE_OBJECT__

#include <memory>
#include <vector>
#include "Common.h"
#include "ResourceObject.h"
#include "ResourceConfig.h"
#include "Graphic/Graphic.h"


namespace Semper
{
	namespace Core
	{

		class TextureObject : public ResourceObject, public IGraphicResource
		{
		public:

			struct Setting
			{
				bool readOnly = false;
			};

		public:

			ArrayList<ColorByte> pixels;

			int width = 0;

			int height = 0;

			ResourceConfig::TextureFilter filter = ResourceConfig::TextureFilter::Nearest;

			GraphicDataInfo graphicDataInfo;

			bool graphicBind = false;

		public:

			static TextureObject* Create(int width, int height);

		public:

			TextureObject();

			virtual ~TextureObject() override;

			TextureObject* Copy();

		protected:

			virtual void EndDelete() override;

			virtual void EndModify() override;

		public:

			// Í¨¹ý IGraphicResource ¼Ì³Ð
			virtual void CreateGraphicResource() override;

			virtual void DeleteGraphicResource() override;

		};
	}
}


#endif // !__TEXTURE_OBJECT__
