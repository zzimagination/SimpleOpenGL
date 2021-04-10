#include "GCMD_StopRecord.h"
#include "../GraphicRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		GCMD_StopRecord::GCMD_StopRecord()
		{
		}
		GCMD_StopRecord::~GCMD_StopRecord()
		{
		}
		void GCMD_StopRecord::Excute()
		{
			GraphicRenderAPI::StopRecord();
		}
	}
}