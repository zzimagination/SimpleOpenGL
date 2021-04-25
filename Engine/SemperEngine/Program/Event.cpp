#include "Event.h"
#include "EventRecorder.h"


namespace Semper
{
	using namespace std;
	using namespace Core;

	std::vector<KeyEvent> Event::Keys()
	{
		return EventRecorder::keyEvents;
	}
	std::vector<MouseButtonEvent> Event::MouseButtons()
	{
		return EventRecorder::mouseButtonEvents;
	}
	Float2 Event::MousePosition()
	{
		return EventRecorder::mousePosition;
	}
	bool Event::KeyAction(Keyboard::Key key, InputAction::Button action)
	{
		auto events = Keys();
		for (int i = 0; i < events.size(); i++)
		{
			if (events[i].value == key && events[i].action == action)
			{
				return true;
			}
		}
		return false;
	}
	bool Event::MouseButtonAction(Mouse::Button button, InputAction::Button action)
	{
		auto events = MouseButtons();
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