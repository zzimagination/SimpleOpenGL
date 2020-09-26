#ifndef RENDERER_COLLECTOR
#define RENDERER_COLLECTOR

#include <vector>
#include <memory>
#include "LifeContainer.h"
#include "RenderObject.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderCollection
		{
		public:

			static std::vector<LifeContainer<RenderObject>> renderObjects;

		public:

			static void AddRenderObject(LifeContainer<RenderObject> robject);

			static std::vector<RenderObject*> GetRenderObjects();

			static void ClearRenders();

		};
	}
}
#endif // !RENDERER_COLLECTOR

