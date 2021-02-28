#include "RenderPipeline.h"
#include "../../RenderBatchManager.h"
#include "../../CameraCollection.h"
#include "../../RenderCollection.h"

namespace SemperEngine
{
	namespace Core
	{
		std::list<RenderSection*> RenderPipeline::sectionList;

		void RenderPipeline::PreRender()
		{
			UnlitSection* section = new UnlitSection();
			sectionList.push_back(section);
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