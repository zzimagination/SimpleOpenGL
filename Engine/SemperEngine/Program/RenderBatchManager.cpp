#include "RenderBatchManager.h"
#include "GraphicRenderer.h"
#include "GraphicResource.h"
#include "ResourceInternal.h"
#include "Camera.h"
#include "Graphic.h"
#include <type_traits>

namespace SemperEngine {

	namespace Core
	{
		using namespace std;

		std::vector<std::shared_ptr<RenderBatch>> RenderBatchManager::batchList;

		vector<RenderBatch> RenderBatchManager::_batchs;

		void RenderBatchManager::AddBatch(std::shared_ptr<RenderBatch> batch)
		{
			batchList.push_back(batch);
		}

		void RenderBatchManager::ExecuteBatchs()
		{
			for (auto b = batchList.begin(); b < batchList.end(); b++)
			{
				b->get()->GenerateGraphicResource();
				b->get()->RenderGraphicObject();
			}
		}

		void RenderBatchManager::Clear()
		{
			_batchs.clear();
			batchList.clear();
		}

	}
}