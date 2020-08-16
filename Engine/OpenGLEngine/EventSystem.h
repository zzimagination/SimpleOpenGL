#ifndef EVENTSYSTEM
#define EVENTSYSTEM
#include <vector>
#include "KeyEvent.h"
#include "MouseButtonEvent.h"
#include "Mathz.h"

namespace SemperEngine {

	using namespace std;

	class EventSystem
	{
	private:

		static float keepInterval;

	public:

		static void ProcessEvent();

		static vector<Event::KeyEvent> GetKeyEvents();

		static vector<Event::MouseButtonEvent> GetMouseButtonEvents();

		static Vector2 GetMousePosition();

		static void EndEvents();

		static bool GetKeyAction(Event::Key key, Event::ButtonAction action);

		static bool GetMouseButtonAction(Event::MouseButton button, Event::ButtonAction action);
	};
}
#endif