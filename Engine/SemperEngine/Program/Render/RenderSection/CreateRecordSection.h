#ifndef __CREATE_RECORD_SECTION__
#define __CREATE_RECORD_SECTION__

#include "../RenderSection.h"
#include "../Render.h"

namespace SemperEngine
{
	namespace Core
	{
		class CreateRecordSection : public RenderSection
		{
		public:

			std::string name;

			bool MSAA = false;

			Render::MSAA MSAASample = Render::MSAA::m8;

		public:

			CreateRecordSection(std::string name);

			virtual ~CreateRecordSection() override;

			// Í¨¹ý RenderSection ¼Ì³Ð
			virtual void Prepare() override;
			virtual void Start() override;
		};
	}
}
#endif // !__CREATE_RECORD_SECTION__