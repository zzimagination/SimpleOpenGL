#ifndef __DEPTH_SECTION__
#define __DEPTH_SECTION__

#include "../RenderSection.h"

namespace SemperEngine
{
	namespace Core
	{
		class DepthSection : public RenderSection
		{
		private:

			Material* _material;

		public:

			virtual ~DepthSection() override;

			// Í¨¹ý RenderSection ¼Ì³Ð
			virtual void Prepare() override;
			virtual void Start() override;

		};
	}
}


#endif // !__DEPTH_SECTION__
