#include "BaseRenderPipeline.h"
#include "RenderBatchManager.h"
#include "RenderObjectManager.h"
#include "RenderCollection.h"
#include "RenderObjectGenerator.h"
#include "WorldManager.h"
#include "World.h"
#include "CameraCollection.h"

namespace SemperEngine
{
	namespace Core
	{
		void BaseRenderPipeline::Render()
		{
			auto cameras = CameraCollection::GetCameras();
			auto renderObjects = RenderCollection::GetRenderObjects();

			for (int i = 0; i < cameras.size(); i++)
			{
				auto camera = cameras[i];
				RenderBatchManager::GenerateBatchs(camera, renderObjects);
			}

			RenderBatchManager::GenerateGraphicCommands();
			RenderBatchManager::Clear();
			RenderCollection::ClearRenders();
			CameraCollection::ClearCameras();
		}
	}
}