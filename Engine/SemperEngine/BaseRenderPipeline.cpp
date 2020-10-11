#include "BaseRenderPipeline.h"
#include "RenderBatchManager.h"
#include "RenderCollection.h"
#include "CameraCollection.h"
#include "GraphicCommandManager.h"

namespace SemperEngine
{
	namespace Core
	{
		void BaseRenderPipeline::Render()
		{
			auto cameras = CameraCollection::GetCameras();
			if (cameras.size() == 0)
			{
				EmptyClear();
				return;
			}

			for (int i = 0; i < cameras.size(); i++)
			{
				RenderCamera(cameras[i]);
				RenderBatchManager::Clear();
			}

			RenderCollection::ClearRenders();
			CameraCollection::ClearCameras();
		}

		void BaseRenderPipeline::CameraClear(Camera* camera)
		{
			Color clearColor = camera->clearColor;
			int clearMode = 0;
			switch ((int)camera->clearMode)
			{
			case 0:
				clearMode = 0;
				break;
			case 1:
				clearMode = 0x03;
				break;
			case 2:
				clearMode = 0x02;
			}
			GraphicCommandManager::Clear(clearColor, clearMode);
		}

		void BaseRenderPipeline::EmptyClear()
		{
			GraphicCommandManager::Clear(Vector4(0, 0, 0, 1), 0x03);
		}

		void BaseRenderPipeline::RenderCamera(Camera* camera)
		{
			CameraClear(camera);
			auto renderObjects = RenderCollection::GetRenderObjects(camera);
			RenderBatchManager::GenerateBatchs(camera, renderObjects);
			RenderBatchManager::GenerateGraphicCommands();
		}

	}
}