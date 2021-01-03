#ifndef EVENTRECORDER
#define EVENTRECORDER

#include "EventDef.h"

namespace SemperEngine {

	namespace Core
	{

		struct EventKeeper
		{
			float pressTime = 0;
		};

		struct KeyKeeper : EventKeeper
		{
			Keyboard::Key key = Keyboard::Key::none;
		};

		struct MouseButtonKeeper : EventKeeper
		{
			Mouse::Button button = Mouse::Button::none;
		};

		class EventRecorder
		{
		public:

			static float keepInterval;

			static std::vector<KeyEvent> keyEvents;

			static std::vector<KeyKeeper> pressedKeys;

			static std::vector<MouseButtonEvent> mouseButtonEvents;

			static std::vector<MouseButtonKeeper> mouseButtons;

			static Float2 mousePosition;

		public:

			static void RecordKeyEvent(int key, int action);

			static void RecordCursorPosition(int x, int y);

			static void RecordMouseButton(int button, int action);

			static void Clear();

			static void Keep();

		private:
			
			static void MouseButtonKeep();

			static void KeyKeep();

		};
	}
}
#endif // !EVENTRECORD
