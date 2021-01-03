#include "EventManager.h"
#include "EventRecorder.h"
#include "GameSetting.h"
#include "Time.h"

namespace SemperEngine {

	namespace Core
	{
		using namespace std;

		float EventManager::keepInterval = 0.01f;

		void EventManager::ProcessEvent()
		{
			EventRecorder::keepInterval = keepInterval;
			EventRecorder::Keep();
		}

		void EventManager::EndEvents()
		{
			EventRecorder::Clear();
		}
	}
}