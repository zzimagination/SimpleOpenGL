#ifndef __STOP_RECORD_SECTION__
#define __STOP_RECORD_SECTION__
#include "../RenderSection.h"

namespace SemperEngine
{
	namespace Core
	{
		class StopRecordSection : public RenderSection
		{
		public:

			virtual ~StopRecordSection() override;

			// Í¨¹ý RenderSection ¼Ì³Ð
			virtual void Prepare() override;
			virtual void Start() override;
		};
	}
}
#endif // !__STOP_RECORD_SECTION__