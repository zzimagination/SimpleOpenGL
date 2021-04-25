#ifndef __GCMD_TEXTUREBUFFER__
#define __GCMD_TEXTUREBUFFER__

#include "../GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GCMD_CreateTexture :public GraphicCommand
		{
		public:

			GraphicTextureData* textureData = nullptr;

		public:

			GCMD_CreateTexture(GraphicTextureData* data);

			virtual ~GCMD_CreateTexture() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_TEXTUREBUFFER__
