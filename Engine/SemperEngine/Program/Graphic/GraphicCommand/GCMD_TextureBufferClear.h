#ifndef __GCMD_TEXTUREBUFFER_CLEAR__
#define __GCMD_TEXTUREBUFFER_CLEAR__

#include "../GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GCMD_DeleteTexture : public GraphicCommand
		{
		public:

			GraphicTextureData* textureData = nullptr;

			typedef void (*DeleteFunc)(GraphicTextureData*);
			DeleteFunc deleteFunc = nullptr;

		public:

			GCMD_DeleteTexture(GraphicTextureData* data, DeleteFunc func = nullptr);

			virtual ~GCMD_DeleteTexture() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_TEXTUREBUFFER_CLEAR__
