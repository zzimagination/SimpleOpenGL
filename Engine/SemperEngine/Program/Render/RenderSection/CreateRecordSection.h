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

			std::string name;

		public:

			CreateRecordSection(std::string name);

			virtual ~CreateRecordSection() override;

			// ͨ�� RenderSection �̳�
			virtual void Prepare() override;
			virtual void Start() override;
		};
	}
}
#endif // !__CREATE_RECORD_SECTION__