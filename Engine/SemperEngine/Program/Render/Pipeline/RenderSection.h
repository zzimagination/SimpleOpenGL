#ifndef __RENDER_SECTION__
#define __RENDER_SECTION__

#include "../../CameraObject.h"
#include "../../RenderCustomObject.h"

namespace SemperEngine
{
	namespace Core
	{
		class RenderSection
		{
		public:

			virtual void Prepare() = 0;

			virtual void Start() = 0;
		};

		class UnlitSection : public RenderSection
		{
		private:

			std::vector<CameraObject*> _cameras;

			std::vector<RenderCustomObject*> _objects;

		public:

			virtual void Prepare() override;

			virtual void Start() override;

		private:

			void RenderCamera(CameraObject* camera);

			void RenderObject(RenderCustomObject* object, CameraObject* camera);
		};
	}
}

#endif // !__RENDER_SECTION__
