#ifndef __GCMD_WIREFRAMEM__
#define __GCMD_WIREFRAMEM__

#include "../GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GWireframeCMD : public GraphicCommand
		{
		public:

			bool enable;

		public:

			GWireframeCMD(bool enable);

			virtual ~GWireframeCMD() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_WIREFRAMEM__
