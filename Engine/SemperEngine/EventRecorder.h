#ifndef EVENTRECORDER
#define EVENTRECORDER

#include "EventDef.h"

namespace SemperEngine {

	namespace Core
	{
		struct KeyKeeper
		{
			Keyboard::Key key = Keyboard::Key::none;

			float pressTime = 0;
		};

		struct MouseButtonKeeper
		{
			Mouse::Button button = Mouse::Button::none;

			float pressTime = 0;
		};

		class EventRecorder
		{
		public:

			static std::vector<KeyEvent> keyEvents;

			static std::vector<KeyKeeper> pressedKeys;

			static std::vector<MouseButtonEvent> mouseButtonEvents;

			static std::vector<MouseButtonKeeper> mouseButtons;

			static Vector2 mousePosition;

		public:

			static void RecordKeyEvent(int key, int action);

			static void RecordCursorPosition(int x, int y);

			static void RecordMouseButton(int button, int action);

			static void Clear();

		};
	}
}
#endif // !EVENTRECORD
