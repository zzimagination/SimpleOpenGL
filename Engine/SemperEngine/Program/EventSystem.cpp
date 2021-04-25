#include "EventSystem.h"
#include "EventRecorder.h"
#include "GameSetting.h"
#include "Time.h"

namespace Semper {

	namespace Core
	{
		using namespace std;

		float EventSystem::keepInterval = 0.01f;

		void EventSystem::ProcessEvent()
		{
			EventRecorder::keepInterval = keepInterval;
			EventRecorder::Keep();
		}

		void EventSystem::EndEvents()
		{
			EventRecorder::Clear();
		}
	}
}