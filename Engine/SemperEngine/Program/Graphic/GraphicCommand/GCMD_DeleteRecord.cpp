#include "GCMD_DeleteRecord.h"

namespace Semper
{
	namespace Core
	{
		GCMD_DeleteRecord::GCMD_DeleteRecord(GraphicRecord* record, DeleteFunc func) : record(record), deleteFunc(func)
		{
		}

		GCMD_DeleteRecord::~GCMD_DeleteRecord()
		{
		}

		void GCMD_DeleteRecord::Excute()
		{
			GraphicRenderAPI::DeleteRecord(record);
			if (deleteFunc == nullptr)
			{
				delete record;
				return;
			}
			deleteFunc(record);
		}
	}
}