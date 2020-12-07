#ifndef __RENDERBATCH_MANAGER__
#define __RENDERBATCH_MANAGER__

#include <vector>
#include "RenderBatch.h"
#include "RenderObject.h"
#include "CameraObject.h"
#include "Graphic.h"
#include "Material.h"

namespace SemperEngine {

	namespace Core {

		class RenderBatchManager
		{
		public:

			static std::vector<RenderBatch> batchs;

		public:

			static void GenerateBatchs(CameraObject* camera, std::vector<RenderObject*> renderObjects);

			static void GenerateGraphicCommands();

			static void Clear();

		private:

			static std::vector<GraphicTextureInfo> GetGraphicTextureInfos(std::shared_ptr<Material> material);

		};
	}
}

#endif // !RENDERBATCH_MANAGER
