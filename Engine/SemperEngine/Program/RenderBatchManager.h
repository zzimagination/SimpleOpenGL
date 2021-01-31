#ifndef __RENDERBATCH_MANAGER__
#define __RENDERBATCH_MANAGER__

#include <vector>
#include "RenderBatch.h"
#include "CameraObject.h"
#include "RenderCustomObject.h"
#include "RenderScreenObject.h"
#include "Graphic.h"
#include "Material.h"

namespace SemperEngine {

	namespace Core {

		class RenderBatchManager
		{
		private:

			static std::vector<RenderBatch> _batchs;

		public:

			static void GenerateBatchs(CameraObject* camera, std::vector<RenderCustomObject*> objects);

			static void GenerateBatchs(std::vector<RenderScreenObject*> objects);

			static void GenerateBatch(RenderScreenObject* object);

			static void GenerateGraphicCommands();

			static void Clear();

		private:

			static void BindResource(RenderCustomObject* obj);

			static void BindResource(RenderScreenObject* obj);

			static void DrawCustom(RenderBatch batch);

			static void DrawScreen(RenderBatch batch);
		};
	}
}

#endif // !RENDERBATCH_MANAGER