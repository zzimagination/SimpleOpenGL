#ifndef __GCMD_WIREFRAMEM__
#define __GCMD_WIREFRAMEM__

#include "../GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GCMD_Wireframe : public GraphicCommand
		{
		public:

			bool enable;

		public:

			GCMD_Wireframe(bool enable);

			virtual ~GCMD_Wireframe() override;

			virtual void Execute() override;
		};
	}
}
#endif // !__GCMD_WIREFRAMEM__
