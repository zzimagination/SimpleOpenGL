#include "RenderPipeline.h"
#include "RenderBatchManager.h"
#include "../CameraCollection.h"
#include "../RenderCollection.h"
#include <memory>

namespace Semper
{
	namespace Core
	{
		std::vector<RenderSection*> RenderPipeline::_cameraSections;
		std::vector<RenderSection*> RenderPipeline::_sections;

		void RenderPipeline::PreRender()
		{
			//auto record = new CreateRecordSection(DEPTHSECTION);
			//_cameraSections.push_back(record);
			//auto depthSection = new DepthSection();
			//_cameraSections.push_back(depthSection);
			//auto stop = new StopRecordSection();
			//_cameraSections.push_back(stop);

			auto record = new StartRecordSection(UNLITSECTION);
			record->msaa = Render::MSAA::Eight;
			_cameraSections.push_back(record);
			auto unlitSection = new UnlitSection();
			_cameraSections.push_back(unlitSection);
			auto stop = new StopRecordSection();
			_cameraSections.push_back(stop);

			auto defaultFB = new DefaultFramebufferSection();
			defaultFB->key = UNLITSECTION;
			_cameraSections.push_back(defaultFB);
			//auto screen = new ScreenRecordSection({UNLITSECTION});
			//_cameraSections.push_back(screen);
		}

		void RenderPipeline::Render()
		{
			auto cameras = CameraCollection::GetCameras();
			for (auto i = 0; i < cameras.size(); i++)
			{
				RenderCamera(cameras[i]);
			}
			RenderEnd();
			CameraCollection::ClearCameras();
			RenderCollection::ClearRenders();
		}

		void RenderPipeline::RenderCamera(CameraObject* camera)
		{
			for (auto i = 0; i < _cameraSections.size(); i++)
			{
				auto section = _cameraSections[i];
				section->camera = camera;
				section->Prepare();
			}
			for (auto i = 0; i < _cameraSections.size(); i++)
			{
				auto section = _cameraSections[i];
				section->Start();
				RenderBatchManager::ExecuteBatchs();
				RenderBatchManager::Clear();
			}
		}
		void RenderPipeline::RenderEnd()
		{
			for (auto i = 0; i < _sections.size(); i++)
			{
				auto section = _sections[i];
				section->Prepare();
			}
			for (auto i = 0; i < _sections.size(); i++)
			{
				auto section = _sections[i];
				section->Start();
				RenderBatchManager::ExecuteBatchs();
				RenderBatchManager::Clear();
			}
		}
	}
}