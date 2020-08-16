#ifndef MOUSEBUTTON_EVENT
#define MOUSEBUTTON_EVENT
#include "KeyDef.h"

namespace SemperEngine
{
	namespace Event
	{
		struct MouseButtonEvent
		{
			MouseButton value;

			ButtonAction action;
		};

		struct MouseButtonKeeper
		{
			MouseButton button;

			float pressTime = 0;
		};
	}
}
#endif // !MOUSEBUTTON_KEEPER
