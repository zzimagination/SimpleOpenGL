#ifndef __CUSTOM_RENDERBATCH__
#define __CUSTOM_RENDERBATCH__

#include <vector>
#include "../RenderBatch.h"

namespace Semper
{
	namespace Core
	{
		class CustomRenderBatch : public RenderBatch
		{
		public:

			Mesh* mesh = nullptr;

			CameraObject* camera = nullptr;

			Material* material = nullptr;

			Matrix4x4 model;

		public:

			virtual ~CustomRenderBatch() override;

			virtual void RenderGraphicObject() override;

			virtual void GenerateGraphicResource() override;

		};
	}
}
#endif // !__CUSTOM_RENDERBATCH__
