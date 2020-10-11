#ifndef __BASE_RENDER_PIPLINE__
#define __BASE_RENDER_PIPLINE__

#include <vector>
#include "Camera.h"

namespace SemperEngine 
{
	namespace Core
	{
		class BaseRenderPipeline
		{
		private:


		public:

			static void Render();

		private:

			static void CameraClear(Camera* camera);

			static void EmptyClear();

			static void RenderCamera(Camera* camera);

		};
	}
}
#endif // !BASE_RENDER_PIPLINE

