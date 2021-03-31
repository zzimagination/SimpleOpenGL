#ifndef __CREATE_RECORD_SECTION__
#define __CREATE_RECORD_SECTION__
#include "../RenderSection.h"

namespace SemperEngine
{
	namespace Core
	{
		class CreateRecordSection : public RenderSection
		{
		public:

			virtual ~CreateRecordSection() override;

			// Í¨¹ý RenderSection ¼Ì³Ð
			virtual void Prepare() override;
			virtual void Start() override;
		};
	}
}
#endif // !__CREATE_RECORD_SECTION__