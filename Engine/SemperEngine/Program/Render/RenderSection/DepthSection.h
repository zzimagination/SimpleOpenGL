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

			// ͨ�� RenderSection �̳�
			virtual void Prepare() override;
			virtual void Start() override;

		};
	}
}


#endif // !__DEPTH_SECTION__
