#pragma once
#ifndef USER_INPUT_EVENT
#define USER_INPUT_EVNET

#include "EventDefination.h"

namespace SemperEngine
{
	struct KeyEvent {

		Keyboard::Key value;

		InputAction::Button action;

	};

	struct KeyKeeper
	{
		Keyboard::Key key;

		float pressTime = 0;

	};

	struct MouseButtonEvent
	{
		Mouse::Button value;

		InputAction::Button action;
	};

	struct MouseButtonKeeper
	{
		Mouse::Button button;

		float pressTime = 0;
	};
}

#endif // !USER_INPUT_EVENT
