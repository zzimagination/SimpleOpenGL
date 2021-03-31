#ifndef __GCMD_TEXTUREBUFFER_CLEAR__
#define __GCMD_TEXTUREBUFFER_CLEAR__

#include "../GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GTextureBufferClearCMD : public GraphicCommand
		{
		public:

			GraphicDataInfo dataInfo;

		public:

			GTextureBufferClearCMD(GraphicDataInfo info);

			virtual ~GTextureBufferClearCMD() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_TEXTUREBUFFER_CLEAR__
