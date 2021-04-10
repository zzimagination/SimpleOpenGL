#ifndef __UNLIT_SECTION__
#define __UNLIT_SECTION__
#include "../RenderSection.h"

namespace SemperEngine
{
	namespace Core {
		class UnlitSection : public RenderSection
		{
		public:

			virtual ~UnlitSection() override;

			virtual void Prepare() override;

			virtual void Start() override;

		private:

			void RenderCamera(CameraObject* camera);

			void RenderObject(RenderCustomObject* object, CameraObject* camera);
		};
	}
}
#endif // !__UNLIT_SECTION__