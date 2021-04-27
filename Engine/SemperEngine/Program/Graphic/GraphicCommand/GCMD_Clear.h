#ifndef __GCMD_CLEAR__
#define __GCMD_CLEAR__

#include "../GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GCMD_Clear : public GraphicCommand
		{
		public:

			Color color;

			Graphic::ClearMode mode = ClearColorDepth;

		public:

			GCMD_Clear(Color color, Graphic::ClearMode mode);

			virtual ~GCMD_Clear() override;

			virtual void Execute() override;
		};
	}
}
#endif // !__GCMD_CLEAR__
