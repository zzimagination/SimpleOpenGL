#include "ScreenRecordSection.h"
#include "../RenderRecordManager.h"
#include "../RenderBatchManager.h"
#include "../../ResourceInternal.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		ScreenRecordSection::ScreenRecordSection(initializer_list<string> records)
		{
			for (auto i = records.begin(); i != records.end(); i++)
			{
				this->records.push_back(*i);
			}
		}

		ScreenRecordSection::ScreenRecordSection()
		{
		}

		ScreenRecordSection::~ScreenRecordSection()
		{
		}

		void ScreenRecordSection::Prepare()
		{
		}


		void ScreenRecordSection::Start()
		{
			auto batch = shared_ptr<ScreenRenderBatch>(new ScreenRenderBatch);
			for (size_t i = 0; i < records.size(); i++)
			{
				batch->records.push_back(RenderRecord(camera, records[i]));
			}
			auto m = ResourceInternal::ScreenViewMaterial();
			batch->material = m.get();
			RenderBatchManager::AddBatch(batch);
		}
	}
}