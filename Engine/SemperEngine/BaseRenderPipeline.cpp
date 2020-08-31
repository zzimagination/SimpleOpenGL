#include "BaseRenderPipeline.h"
#include "ProjectSetting.h"
#include "RenderBatchManager.h"
#include "RenderObjectManager.h"
#include "RenderCollector.h"
#include "RenderObjectGenerator.h"
#include "WorldManager.h"

namespace SemperEngine {

	void BaseRenderPipeline::Render()
	{
		Camera* mainCamera = WorldManager::GetActive()->camera;

		vector<RenderObject*> startRenderObjects = RenderCollector::GetRenderObjects();
		RenderObjectManager::Culling(mainCamera, startRenderObjects);
		RenderBatchManager::GenerateBatchs(startRenderObjects, mainCamera);

	}
}