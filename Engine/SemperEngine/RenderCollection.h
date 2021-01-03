#ifndef __RENDERER_COLLECTOR__
#define __RENDERER_COLLECTOR__

#include <vector>
#include <memory>
#include "RenderCustomObject.h"
#include "RenderScreenObject.h"
#include "CameraObject.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderCollection
		{
		private:

			static std::vector<LifeContainer<RenderObject>> _customObjects;

			static std::vector<LifeContainer<RenderObject>> _screenObjects;

		public:

			static void AddCustomObject(RenderCustomObject* object);

			static void AddScreenObject(RenderScreenObject* object);

			static std::vector<RenderObject*> GetCustomObjects(RenderLayer layer);

			static std::vector<RenderObject*> GetScreenObjects();

			static void ClearRenders();

		};
	}
}
#endif // !RENDERER_COLLECTOR

