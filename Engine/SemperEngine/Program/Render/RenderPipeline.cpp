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
			auto record = new CreateRecordSection();
			sectionList.push_back(record);
			auto section = new UnlitSection();
			sectionList.push_back(section);
			auto stop = new StopRecordSection();
			sectionList.push_back(stop);
			auto render = new ScreenRecordSection();
			sectionList.push_back(render);
		}
		void RenderPipeline::Render()
		{
			for (auto s = sectionList.begin(); s != sectionList.end(); s++)
			{
				(*s)->Prepare();
				(*s)->Start();
				RenderBatchManager::ExecuteBatchs();
				RenderBatchManager::Clear();
			}

			CameraCollection::ClearCameras();
			RenderCollection::ClearRenders();
		}
	}
}