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

			int recordID = 0;

		public:

			GCMD_DefaultFrameBuffer(int recordID);

			virtual ~GCMD_DefaultFrameBuffer() override;

			// Í¨¹ý GraphicCommand ¼Ì³Ð
			virtual void Excute() override;

		};
	}
}
#endif // !__GCMD_DEFAULT_FRAMEBUFFER__
