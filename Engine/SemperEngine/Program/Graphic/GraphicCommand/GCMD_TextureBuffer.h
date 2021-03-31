#ifndef __GCMD_TEXTUREBUFFER__
#define __GCMD_TEXTUREBUFFER__

#include "../GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GTextureBufferCMD :public GraphicCommand
		{
		public:

			GraphicDataInfo dataInfo;

		public:

			GTextureBufferCMD(GraphicDataInfo info);

			virtual ~GTextureBufferCMD() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_TEXTUREBUFFER__
