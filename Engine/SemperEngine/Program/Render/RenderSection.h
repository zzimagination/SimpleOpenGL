#ifndef __RENDER_SECTION__
#define __RENDER_SECTION__

#include <vector>
#include <memory>
#include "../Math/Math.h"
#include "../CameraObject.h"
#include "../RenderCustomObject.h"
#include "../Material.h"

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
	}
}

#include "RenderSection/UnlitSection.h"
#include "RenderSection/CreateRecordSection.h"
#include "RenderSection/StopRecordSection.h"
#include "RenderSection/ScreenRecordSection.h"
#include "RenderSection/DepthSection.h"

#endif // !__RENDER_SECTION__
