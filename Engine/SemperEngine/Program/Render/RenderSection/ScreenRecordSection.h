#ifndef __SCREEN_RECORD_SECTION__
#define __SCREEN_RECORD_SECTION__
#include "../RenderSection.h"

namespace SemperEngine
{
	namespace Core
	{
		class ScreenRecordSection : public RenderSection
		{
		public:

			virtual ~ScreenRecordSection() override;

			// ͨ�� RenderSection �̳�
			virtual void Prepare() override;
			virtual void Start() override;
		};
	}
}
#endif // !__SCREEN_RECORD_SECTION__