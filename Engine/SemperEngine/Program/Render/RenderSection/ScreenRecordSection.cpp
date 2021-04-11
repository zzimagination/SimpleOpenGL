#include "ScreenRecordSection.h"
#include "../RenderRecordManager.h"
#include "../RenderBatchManager.h"
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
			auto clear = shared_ptr<ClearBatch>(new ClearBatch(Color::Black(), ClearColorDepth));
			RenderBatchManager::AddBatch(clear);
			auto batch = shared_ptr<ScreenRenderBatch>(new ScreenRenderBatch);
			batch->records.push_back(RenderRecord(camera, "Depth"));
			auto m = ResourceInternal::ScreenViewMaterial();
			batch->material = m.get();
			RenderBatchManager::AddBatch(batch);
		}
	}
}