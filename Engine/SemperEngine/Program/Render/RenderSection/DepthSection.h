#ifndef __DEPTH_SECTION__
#define __DEPTH_SECTION__

#include "../RenderSection.h"

namespace SemperEngine
{
	namespace Core
	{
		class DepthSection : public RenderSection
		{
		public:

			 std::vector<Material*> _materials;

		public:

			virtual ~DepthSection() override;

			// Í¨¹ý RenderSection ¼Ì³Ð
			virtual void Prepare() override;
			virtual void Start() override;

		private:

			void RenderCamera(CameraObject* camera);

			void RenderObject(RenderCustomObject* object, CameraObject* camera, Material* material);
		};
	}
}


#endif // !__DEPTH_SECTION__
