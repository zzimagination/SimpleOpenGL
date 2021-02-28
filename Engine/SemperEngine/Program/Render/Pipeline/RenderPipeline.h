#ifndef __RENDER__PIPELINE__
#define __RENDER__PIPELINE__

#include <vector>
#include <list>
#include "RenderSection.h"

namespace SemperEngine
{
	namespace Core
	{
		class RenderPipeline
		{
		public:

			static std::list<RenderSection*> sectionList;

		public:

			static void PreRender();

			static void Render();
		};
	}
}
#endif // !__RENDER__PIPELINE__
