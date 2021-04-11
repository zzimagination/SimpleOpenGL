#ifndef __RENDER__PIPELINE__
#define __RENDER__PIPELINE__

#include <vector>
#include <list>
#include <vector>
#include "Render.h"
#include "RenderSection.h"

namespace SemperEngine
{
	namespace Core
	{
		class RenderPipeline
		{
		private:

			static std::vector<RenderSection*> _cameraSections;

			static std::vector<RenderSection*> _sections;

		public:

			static void PreRender();

			static void Render();

		private:

			static void RenderCamera(CameraObject* camera);

			static void RenderEnd();
		};
	}
}
#endif // !__RENDER__PIPELINE__
