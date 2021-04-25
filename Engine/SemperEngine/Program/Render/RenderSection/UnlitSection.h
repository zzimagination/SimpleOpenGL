#ifndef __UNLIT_SECTION__
#define __UNLIT_SECTION__
#include "../RenderSection.h"

namespace Semper
{
	namespace Core 
	{
		class UnlitSection : public RenderSection
		{
		public:

			virtual ~UnlitSection() override;

			virtual void Prepare() override;

			virtual void Start() override;

		};
	}
}
#endif // !__UNLIT_SECTION__