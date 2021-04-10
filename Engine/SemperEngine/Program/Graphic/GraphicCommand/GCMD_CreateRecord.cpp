#include "GCMD_CreateRecord.h"
#include "../../GameSetting.h"
#include "../GraphicRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		GCMD_CreateRecord::GCMD_CreateRecord(std::string name)
		{
			record = GraphicRecordManager::CreateRecord(name);
			record->name = name;
			record->width = GameSetting::windowWidth;
			record->height = GameSetting::windowHeight;
			record->attach = GraphicRecord::Attach::None;
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