#ifndef __DEFAULT_FRAMEBUFF_SECTION__
#define __DEFAULT_FRAMEBUFF_SECTION__

#include "../RenderSection.h"

namespace SemperEngine
{
	namespace Core
	{
		class DefaultFramebufferSection : public RenderSection
		{
		public:

			std::string key;

		public:

			virtual void Start() override;

		};
	}
}

#endif // !__DEFAULT_FRAMEBUFF__
