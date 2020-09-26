#ifndef EVENTSYSTEM
#define EVENTSYSTEM
#include <vector>
#include "Mathz.h"
#include "UserInputEvent.h"

namespace SemperEngine {

	class EventSystem
	{
	private:

		static float keepInterval;

	public:

		static void ProcessEvent();

		static std::vector<KeyEvent> GetKeyEvents();

		static std::vector<MouseButtonEvent> GetMouseButtonEvents();

		static Vector2 GetMousePosition();

		static void EndEvents();

		static bool GetKeyAction(Keyboard::Key key, InputAction::Button action);

		static bool GetMouseButtonAction(Mouse::Button button, InputAction::Button action);
	};
}
#endif