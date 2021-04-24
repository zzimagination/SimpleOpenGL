#include "GCMD_DefaultFrameBuffer.h"
#include "../GraphicRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		GCMD_DefaultFrameBuffer::GCMD_DefaultFrameBuffer(GraphicRecord* record)
		{
			this->record = record;
		}
		
		GCMD_DefaultFrameBuffer::~GCMD_DefaultFrameBuffer()
		{
		}
		
		void GCMD_DefaultFrameBuffer::Excute()
		{
			GraphicRenderAPI::DefaultFrameBuffer(record);
		}
	}
}