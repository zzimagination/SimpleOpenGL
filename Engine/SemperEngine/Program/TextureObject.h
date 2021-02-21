#pragma once
#ifndef __TEXTURE_OBJECT__
#define __TEXTURE_OBJECT__

#include <memory>
#include <vector>
#include "Common.h"
#include "ResourceObject.h"
#include "Graphic.h"

namespace SemperEngine
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

			std::unique_ptr<TextureData> data;

			GraphicDataInfo graphicDataInfo;

			bool graphicBind = false;

		public:

			static TextureObject* Create(int width, int height);

		public:

			TextureObject();

			virtual ~TextureObject() override;

			void ColorBytes(ArrayList<ColorByte> data);

			TextureObject* Copy();

			ArrayList<ColorByte> ColorBytes();

		

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
