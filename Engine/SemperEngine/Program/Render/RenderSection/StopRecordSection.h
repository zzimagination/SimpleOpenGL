#ifndef __STOP_RECORD_SECTION__
#define __STOP_RECORD_SECTION__
#include "../RenderSection.h"

namespace Semper
{
	namespace Core
	{
		class StopRecordSection : public RenderSection
		{
		public:

			virtual void Start() override;
		};
	}
}
#endif // !__STOP_RECORD_SECTION__