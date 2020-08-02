#include "ProjectSetting.h"
#include "BaseRenderPipeline.h"
#include "RenderBatchManager.h"
#include "RenderObjectManager.h"
#include "RenderCollector.h"
#include "RenderObjectGenerator.h"
#include "RenderDraw.h"
#include "WorldManager.h"

void BaseRenderPipeline::Render()
{
	Camera* mainCamera = WorldManager::active->camera;

	RenderDraw::SetClear(ClearMode::Color | ClearMode::Depth, Vector4(0.2f, 0.2f, 0.2f, 1));
	RenderObjectManager::AddRenderObject(RenderCollector::GetRenderObjects());
	RenderObjectManager::Culling(mainCamera);
	RenderObjectManager::BindVertexData();
	RenderBatchManager::GenerateBatchs(RenderObjectManager::GetRenderObject());
	RenderObjectManager::ClearRenderObject();
	RenderBatchManager::DrawBatchs(mainCamera);
	RenderBatchManager::ClearBatchs();


	RenderBatchManager::ClearBatchs();
}
