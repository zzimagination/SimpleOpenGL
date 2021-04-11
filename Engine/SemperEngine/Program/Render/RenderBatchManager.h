#ifndef __RENDERBATCH_MANAGER__
#define __RENDERBATCH_MANAGER__

#include <vector>
#include <memory>
#include "RenderBatch.h"

namespace SemperEngine {

	namespace Core {

		class RenderBatchManager
		{
		private:

			static std::vector<RenderBatch> _batchs;

		public:

			static std::vector<std::shared_ptr<RenderBatch>> batchList;

		public:

			static void AddBatch(std::shared_ptr<RenderBatch> batch);

			static void ExecuteBatchs();

			static void Clear();

		};
	}
}

#endif // !RENDERBATCH_MANAGER
