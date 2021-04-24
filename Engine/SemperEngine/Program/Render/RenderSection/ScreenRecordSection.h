#ifndef __SCREEN_RECORD_SECTION__
#define __SCREEN_RECORD_SECTION__

#include "../RenderSection.h"
#include "../Render.h"
#include <string>
#include <initializer_list>

namespace SemperEngine
{
	namespace Core
	{
		class ScreenRecordSection : public RenderSection
		{
		public:

			std::vector<std::string> records;

		public:

			ScreenRecordSection();

			ScreenRecordSection(std::initializer_list<std::string> records);

			virtual ~ScreenRecordSection() override;

			// Í¨¹ý RenderSection ¼Ì³Ð
			virtual void Prepare() override;
			virtual void Start() override;
		};
	}
}
#endif // !__SCREEN_RECORD_SECTION__