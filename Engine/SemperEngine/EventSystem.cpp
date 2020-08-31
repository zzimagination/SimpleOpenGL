#include "EventSystem.h"
#include "EventRecorder.h"
#include "KeyIdentity.h"
#include "Time.h"
#include <iostream>
namespace SemperEngine {

	using namespace Event;

	float EventSystem::keepInterval = 0.01f;

	void EventSystem::ProcessEvent()
	{
		auto mouseButtons = &EventRecorder::mouseButtons;
		auto mouseButtonEvents = &EventRecorder::mouseButtonEvents;
		for (int i = 0; i < mouseButtons->size(); i++)
		{
			if ((*mouseButtons)[i].pressTime > keepInterval)
			{
				MouseButtonEvent e = { (*mouseButtons)[i].button, ButtonAction::keep };
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
				KeyEvent e = { (*pressedKeys)[i].key, ButtonAction::keep };
				keyEvents->push_back(e);
			}
			(*pressedKeys)[i].pressTime += Time::GetDeltaTime();
		}
		
	}
	vector<KeyEvent> EventSystem::GetKeyEvents()
	{
		return EventRecorder::keyEvents;
	}
	vector<Event::MouseButtonEvent> EventSystem::GetMouseButtonEvents()
	{
		return EventRecorder::mouseButtonEvents;
	}
	Vector2 EventSystem::GetMousePosition()
	{
		return EventRecorder::mousePosition;
	}

	void EventSystem::EndEvents()
	{
		EventRecorder::Clear();
	}

	bool EventSystem::GetKeyAction(Event::Key key, Event::ButtonAction action)
	{
		auto events = GetKeyEvents();
		for (int i = 0; i < events.size(); i++)
		{
			if (events[i].value == key && events[i].action == action)
			{
				return true;
			}
		}
		return false;
	}

	bool EventSystem::GetMouseButtonAction(Event::MouseButton button, Event::ButtonAction action)
	{
		auto events = GetMouseButtonEvents();
		for (int i = 0; i < events.size(); i++)
		{
			if (events[i].value == button && events[i].action == action)
			{
				return true;
			}
		}
		return false;
	}

}