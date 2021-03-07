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

			virtual ~RenderSection() {}

			virtual void Prepare() = 0;

			virtual void Start() = 0;
		};

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

		class CreateRecordSection : public RenderSection
		{
		public:

			virtual ~CreateRecordSection() override;

			// 通过 RenderSection 继承
			virtual void Prepare() override;
			virtual void Start() override;
		};

		class StopRecordSection : public RenderSection
		{
		public:

			virtual ~StopRecordSection() override;

			// 通过 RenderSection 继承
			virtual void Prepare() override;
			virtual void Start() override;
		};

		class ScreenRecordSection : public RenderSection
		{
		public:

			virtual ~ScreenRecordSection() override;

			// 通过 RenderSection 继承
			virtual void Prepare() override;
			virtual void Start() override;
		};
	}
}

#endif // !__RENDER_SECTION__
