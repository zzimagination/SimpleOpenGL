#ifndef __SCREEN_RENDERBATCH__
#define __SCREEN_RENDERBATCH__

#include "../RenderBatch.h"

namespace Semper
{
	namespace Core
	{
		class ScreenRenderBatch : public RenderBatch
		{
		public:

			Material* material = nullptr;

		public:

			ScreenRenderBatch();

			virtual ~ScreenRenderBatch() override;

			// Í¨¹ý RenderBatch ¼Ì³Ð
			virtual void GenerateGraphicResource() override;

			virtual void RenderGraphicObject() override;
		};
	}
}

#endif // !__SCREEN_RENDERBATCH__
