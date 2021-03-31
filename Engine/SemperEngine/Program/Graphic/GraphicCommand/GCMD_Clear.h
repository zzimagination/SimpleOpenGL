#ifndef __GCMD_CLEAR__
#define __GCMD_CLEAR__

#include "../GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GClearCMD : public GraphicCommand
		{
		public:

			Color color;

			Graphic::ClearMode mode;

		public:

			GClearCMD(Color color, Graphic::ClearMode mode);

			virtual ~GClearCMD() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_CLEAR__
