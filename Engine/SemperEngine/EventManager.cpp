#include "EventManager.h"
#include "EventRecorder.h"

namespace SemperEngine {

	namespace Core
	{
		using namespace std;

		float EventManager::keepInterval = 0.01f;

		void EventManager::ProcessEvent()
		{
			auto mouseButtons = &EventRecorder::mouseButtons;
			auto mouseButtonEvents = &EventRecorder::mouseButtonEvents;
			for (int i = 0; i < mouseButtons->size(); i++)
			{
				if ((*mouseButtons)[i].pressTime > keepInterval)
				{
					MouseButtonEvent e = { (*mouseButtons)[i].button, InputAction::Button::keep };
					mouseButtonEvents->push_back(e);
				}
				(*mouseButtons)[i].pressTime += Time::GetDeltaTime();
			}
			auto pressedKeys = &EventRecorder::pressedKeys;
			auto keyEvents = &EventRecorder::keyEvents;
			for (int i = 0; i < pressedKeys->size(); i++)
			{
				if ((*pressedKeys)[i].pressTime > keepInterval)
				{
					KeyEvent e = { (*pressedKeys)[i].key, InputAction::Button::keep };
					keyEvents->push_back(e);
				}
				(*pressedKeys)[i].pressTime += Time::GetDeltaTime();
			}

		}

		void EventManager::EndEvents()
		{
			EventRecorder::Clear();
		}

	}
}