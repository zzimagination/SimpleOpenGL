#ifndef RENDERBATCH_MANAGER
#define RENDERBATCH_MANAGER

#include <vector>
#include "RenderBatch.h"
#include "RenderObject.h"
#include "Camera.h"

namespace SemperEngine {

	namespace Core {

		class RenderBatchManager
		{
		public:

			static std::vector<RenderBatch> batchs;

		public:

			static void GenerateBatchs(Camera* camera, std::vector<RenderObject*> renderObjects);

			static void GenerateGraphicCommands();

			static void Clear();
		};
	}
}

#endif // !RENDERBATCH_MANAGER
