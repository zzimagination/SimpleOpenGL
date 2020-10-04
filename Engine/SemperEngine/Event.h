#pragma once
#ifndef EVENT_CLASS
#define EVENT_CLASS

#include "EventDef.h"

namespace SemperEngine
{
	class Event
	{
	public:

		static std::vector<KeyEvent> Keys();

		static std::vector<MouseButtonEvent> MouseButtons();

		static Vector2 MousePosition();

		static bool KeyAction(Keyboard::Key key, InputAction::Button action);

		static bool MouseButtonAction(Mouse::Button button, InputAction::Button action);
	};
}

#endif // !EVENT_CLASS
