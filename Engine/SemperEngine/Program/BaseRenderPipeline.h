#ifndef __BASE_RENDER_PIPLINE__
#define __BASE_RENDER_PIPLINE__

#include <vector>
#include "CameraObject.h"

namespace SemperEngine
{
	namespace Core
	{
		class BaseRenderPipeline
		{
		public:

			static void Render();

		private:

			static void RenderScreen();

			static void RenderCamera(CameraObject* camera);

		};
	}
}
#endif // !BASE_RENDER_PIPLINE

