#pragma once
#ifndef __EVENT_CLASS__
#define __EVENT_CLASS__

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
