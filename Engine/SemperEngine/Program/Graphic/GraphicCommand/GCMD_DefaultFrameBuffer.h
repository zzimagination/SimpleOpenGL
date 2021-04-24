#ifndef __GCMD_DEFAULT_FRAMEBUFFER__
#define __GCMD_DEFAULT_FRAMEBUFFER__

#include "../GraphicCommand.h"

namespace SemperEngine
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

			// Í¨¹ý GraphicCommand ¼Ì³Ð
			virtual void Excute() override;

		};
	}
}
#endif // !__GCMD_DEFAULT_FRAMEBUFFER__
