#include "GCMD_StartRecord.h"

namespace Semper
{
	namespace Core
	{
		GCMD_StartRecord::GCMD_StartRecord(GraphicRecord* record):record(record)
		{
		}

		GCMD_StartRecord::~GCMD_StartRecord()
		{
		}
		
		void GCMD_StartRecord::Excute()
		{
			GraphicRenderAPI::StartRecord(record);
		}
	}
}