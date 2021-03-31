#include "GCMD_CreateRecord.h"
#include "../../GameSetting.h"
#include "../GraphicRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		GCMD_CreateRecord::GCMD_CreateRecord()
		{
			record = GraphicRecordManager::CreateRecord(name);
			record->width = GameSetting::windowWidth;
			record->height = GameSetting::windowHeight;
			record->attach = GraphicRecord::Attach::None;
		}

		GCMD_CreateRecord::~GCMD_CreateRecord()
		{
		}

		void GCMD_CreateRecord::Excute()
		{
			GraphicRecordManager::currentRecord = record;
			GraphicRenderAPI::CreateRecord(record);
		}
	}
}