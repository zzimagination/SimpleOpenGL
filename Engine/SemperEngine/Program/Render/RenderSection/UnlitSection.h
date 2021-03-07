#include "../RenderSection.h"

namespace SemperEngine
{
	namespace Core {
		class UnlitSection : public RenderSection
		{
		private:

			std::vector<CameraObject*> _cameras;

			std::vector<RenderCustomObject*> _objects;

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