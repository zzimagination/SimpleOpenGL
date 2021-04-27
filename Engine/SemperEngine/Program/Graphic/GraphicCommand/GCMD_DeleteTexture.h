#ifndef __GCMD_DELETE_TEXTUREBUFFER__
#define __GCMD_DELETE_TEXTUREBUFFER__

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

			virtual void Execute() override;
		};
	}
}
#endif // !__GCMD_DELETE_TEXTUREBUFFER__
