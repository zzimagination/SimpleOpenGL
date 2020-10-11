#include "FrameRuntime.h"
#include "TimeManager.h"

namespace SemperEngine 
{
	namespace Core
	{
		void FrameRuntime::BeginFrame()
		{
			TimeManager::StartRecord();
		}

		void FrameRuntime::EndFrame()
		{
			TimeManager::EndRecord();
		}
	}
}