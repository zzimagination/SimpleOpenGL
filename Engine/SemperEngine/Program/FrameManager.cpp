#include "FrameManager.h"
#include "TimeManager.h"

namespace Semper 
{
	namespace Core
	{
		void FrameManager::Begin()
		{
			TimeManager::StartRecord();
		}

		void FrameManager::End()
		{
			TimeManager::EndRecord();
		}
	}
}