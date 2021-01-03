#include "BaseRenderPipeline.h"
#include "RenderBatchManager.h"
#include "RenderCollection.h"
#include "CameraCollection.h"
#include "GraphicRenderer.h"
#include "CameraObject.h"

namespace SemperEngine
{
	namespace Core
	{
		void BaseRenderPipeline::Render()
		{
			auto cameras = CameraCollection::GetCameras();
			if (cameras.size() == 0)
			{
				GraphicRenderer::Clear(Float4(0, 0, 0, 1));
			}
			else
			{
				for (int i = 0; i < cameras.size(); i++)
				{
					RenderCamera(cameras[i]);
				}
			}
			RenderScreen();

			RenderBatchManager::GenerateGraphicCommands();

			RenderBatchManager::Clear();
			RenderCollection::ClearRenders();
			CameraCollection::ClearCameras();
		}

		void BaseRenderPipeline::RenderScreen()
		{
			auto renderObjects = RenderCollection::GetScreenObjects();
			RenderBatchManager::GenerateBatchs(renderObjects);
		}

		void BaseRenderPipeline::RenderCamera(CameraObject* camera)
		{
			GraphicRenderer::Clear(camera->clearColor, camera->clearMode);
			auto renderObjects = RenderCollection::GetCustomObjects(camera->renderLayer);
			RenderBatchManager::GenerateBatchs(camera, renderObjects);
		}

	}
}