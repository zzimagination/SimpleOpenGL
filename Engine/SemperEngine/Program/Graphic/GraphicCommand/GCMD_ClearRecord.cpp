#include "GCMD_ClearRecord.h"

namespace SemperEngine
{
	namespace Core
	{
		GCMD_ClearRecord::~GCMD_ClearRecord()
		{

		}
		void GCMD_ClearRecord::Excute()
		{
			GraphicRenderAPI::DeleteRecord(record);
			record = nullptr;
		}
	}
}