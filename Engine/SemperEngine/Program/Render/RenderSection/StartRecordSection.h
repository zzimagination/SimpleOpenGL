#ifndef __STARTRECORD_SECTION__
#define __STARTRECORD_SECTION__

#include "../RenderSection.h"

namespace Semper
{
	namespace Core
	{
		class StartRecordSection : public RenderSection
		{
		public:

			std::string key = "";

			Render::MSAA msaa = Render::MSAA::None;

		private:

			bool _created = false;

		public:

			StartRecordSection(std::string key);

			virtual ~StartRecordSection() override;

			virtual void Start() override;
		};
	}
}

#endif // !__STARTRECORD_SECTION__
