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
		}
		void ScreenRecordSection::Start()
		{
			auto clearBatch = shared_ptr<ClearBatch>(new ClearBatch());
			RenderBatchManager::AddBatch(clearBatch);

			auto batch = shared_ptr<ScreenRenderBatch>(new ScreenRenderBatch);
			batch->useRecord = true;
			batch->recordIDs.push_back(0);
			auto mat = ResourceInternal::ScreenViewMat();
			batch->material = mat.get();
			RenderBatchManager::AddBatch(batch);
		}
	}
}