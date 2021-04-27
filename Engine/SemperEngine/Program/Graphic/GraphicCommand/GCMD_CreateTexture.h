#ifndef __GCMD_CREATE_TEXTURE__
#define __GCMD_CREATE_TEXTURE__

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

			virtual void Execute() override;
		};
	}
}
#endif // !__GCMD_CREATE_TEXTURE__
