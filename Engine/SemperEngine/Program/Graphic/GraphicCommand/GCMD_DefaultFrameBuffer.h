#ifndef __GCMD_DEFAULT_FRAMEBUFFER__
#define __GCMD_DEFAULT_FRAMEBUFFER__

#include "../GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GCMD_DefaultFrameBuffer : public GraphicCommand
		{
		public:

			GraphicRecord* record = nullptr;

		public:

			GCMD_DefaultFrameBuffer(GraphicRecord* record);

			virtual ~GCMD_DefaultFrameBuffer() override;

			// ͨ�� GraphicCommand �̳�
			virtual void Execute() override;

		};
	}
}
#endif // !__GCMD_DEFAULT_FRAMEBUFFER__
