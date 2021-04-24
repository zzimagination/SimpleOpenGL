#include "GCMD_DefaultFrameBuffer.h"
#include "../GraphicRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		GCMD_DefaultFrameBuffer::GCMD_DefaultFrameBuffer(int recordID)
		{
			this->recordID = recordID;
		}
		
		GCMD_DefaultFrameBuffer::~GCMD_DefaultFrameBuffer()
		{
		}
		
		void GCMD_DefaultFrameBuffer::Excute()
		{
			auto record = GraphicRecordManager::UseRecord(recordID);
			GraphicRenderAPI::DefaultFrameBuffer(record);
		}
	}
}