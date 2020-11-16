#include "EventManager.h"
#include "EventRecorder.h"
#include "GameSetting.h"
#include "Time.h"

namespace SemperEngine {

	namespace Core
	{
		using namespace std;

		void EventManager::ProcessEvent()
		{
			EventRecorder::keepInterval = GameSetting::buttonPressT;
			EventRecorder::Keep();
		}

		void EventManager::EndEvents()
		{
			EventRecorder::Clear();
		}
	}
}