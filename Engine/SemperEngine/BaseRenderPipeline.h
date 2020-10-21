#ifndef __BASE_RENDER_PIPLINE__
#define __BASE_RENDER_PIPLINE__

#include <vector>

namespace SemperEngine
{
	namespace Core
	{
		class CameraObject;

		class BaseRenderPipeline
		{
		public:

			static void Render();

		private:

			static void CameraClear(CameraObject* camera);

			static void EmptyClear();

			static void RenderCamera(CameraObject* camera);

		};
	}
}
#endif // !BASE_RENDER_PIPLINE

