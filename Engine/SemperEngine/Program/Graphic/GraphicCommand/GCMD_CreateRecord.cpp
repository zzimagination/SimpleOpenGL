#include "GCMD_CreateRecord.h"
#include "../../GameSetting.h"
#include "../GraphicRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		GCMD_CreateRecord::GCMD_CreateRecord(GraphicRecord* record)
		{
			this->record = record;
		}

		GCMD_CreateRecord::~GCMD_CreateRecord()
		{
		}

		void GCMD_CreateRecord::Excute()
		{
			GraphicRenderAPI::CreateRecord(record);
		}
	}
}