#include "FrameRuntime.h"
#include "TimeManager.h"

namespace SemperEngine 
{
	namespace Core
	{
		void FrameRuntime::Begin()
		{
			TimeManager::StartRecord();
		}

		void FrameRuntime::End()
		{
			TimeManager::EndRecord();
		}
	}
}