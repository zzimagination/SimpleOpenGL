#include "ScreenRecordSection.h"
#include "../RenderRecordManager.h"
#include "../../RenderBatchManager.h"
#include "../../ResourceInternal.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		ScreenRecordSection::~ScreenRecordSection()
		{
		}
		void ScreenRecordSection::Prepare()
		{
			auto batch = shared_ptr<ClearBatch>(new ClearBatch());
			RenderBatchManager::AddBatch(batch);
		}
		void ScreenRecordSection::Start()
		{
			auto batch = shared_ptr<ScreenRenderBatch>(new ScreenRenderBatch);
			batch->useRecord = true;
			batch->recordIDs.push_back(0);
			auto mat = ResourceInternal::ScreenViewMat();
			batch->material = mat.get();
			RenderBatchManager::AddBatch(batch);
		}
	}
}