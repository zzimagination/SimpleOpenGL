#ifndef __RENDER_SECTION__
#define __RENDER_SECTION__

#include <vector>
#include <memory>
#include "../Math/Math.h"
#include "../CameraObject.h"
#include "../RenderCustomObject.h"
#include "../Material.h"
#include "Render.h"

namespace Semper
{
	namespace Core
	{
		class RenderSection
		{
		public:

			CameraObject* camera = nullptr;

		public:

			virtual ~RenderSection() {}

			virtual void Prepare();

			virtual void Start() = 0;
		};
	}
}

#endif // !__RENDER_SECTION__


#include "RenderSection/UnlitSection.h"
#include "RenderSection/StartRecordSection.h"
#include "RenderSection/StopRecordSection.h"
#include "RenderSection/ScreenRecordSection.h"
#include "RenderSection/DepthSection.h"
#include "RenderSection/DefaultFrameBufferSection.h"