#include "RenderPipeline.h"
#include "../RenderBatchManager.h"
#include "../CameraCollection.h"
#include "../RenderCollection.h"
#include <memory>

namespace SemperEngine
{
	namespace Core
	{
		std::list<RenderSection*> RenderPipeline::sectionList;

		void RenderPipeline::PreRender()
		{
			auto record = new CreateRecordSection("Depth");
			sectionList.push_back(record);
			auto depthSection = new DepthSection();
			sectionList.push_back(depthSection);
			auto stop = new StopRecordSection();
			sectionList.push_back(stop);
			record = new CreateRecordSection("Unlit");
			sectionList.push_back(record);
			auto unlitSection = new UnlitSection();
			sectionList.push_back(unlitSection);
			stop = new StopRecordSection();
			sectionList.push_back(stop);
			auto render = new ScreenRecordSection();
			sectionList.push_back(render);
		}
		void RenderPipeline::Render()
		{
			for (auto section = sectionList.begin(); section != sectionList.end(); section++)
			{
				(*section)->Prepare();
			}
			for (auto section = sectionList.begin(); section != sectionList.end(); section++)
			{
				(*section)->Start();
				RenderBatchManager::ExecuteBatchs();
				RenderBatchManager::Clear();
			}
			CameraCollection::ClearCameras();
			RenderCollection::ClearRenders();
		}
	}
}