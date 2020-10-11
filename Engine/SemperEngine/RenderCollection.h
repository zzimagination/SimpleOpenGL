#ifndef __RENDERER_COLLECTOR__
#define __RENDERER_COLLECTOR__

#include <vector>
#include <memory>
#include "RenderObject.h"
#include "Camera.h"

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

			static std::vector<RenderObject*> GetRenderObjects(Camera* camera);

			static void ClearRenders();

		private:

			static bool CheckLayer(std::vector<int> layers, int target);

		};
	}
}
#endif // !RENDERER_COLLECTOR

