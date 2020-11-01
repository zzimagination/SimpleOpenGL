#ifndef __RENDERER_COLLECTOR__
#define __RENDERER_COLLECTOR__

#include <vector>
#include <memory>
#include "RenderObject.h"
#include "CameraObject.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderCollection
		{
		public:

			static std::vector<LifeContainer<RenderObject>> renderObjects;

#define Check int a=1

		public:

			static void AddRenderObject(LifeContainer<RenderObject> robject);

			static std::vector<RenderObject*> GetRenderObjects();

			static std::vector<RenderObject*> GetRenderObjects(CameraObject* camera);

			static void ClearRenders();

		private:

			static bool CheckLayer(std::vector<int> layers, int target);

		};
	}
}
#endif // !RENDERER_COLLECTOR

