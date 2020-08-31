#ifndef EVENTDATA
#define EVENTDATA
#include "KeyDef.h"

namespace SemperEngine {

	namespace Event {

		struct KeyEvent {

			Key value;

			ButtonAction action;

		};

		struct KeyKeeper
		{
			Key key;

			float pressTime=0;

		};
	}
}
#endif // !KEY_EVENT
