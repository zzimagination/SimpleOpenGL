#ifndef EVENTRECORDER
#define EVENTRECORDER
#include <vector>
#include "Mathz.h"
#include "KeyEvent.h"
#include "MouseButtonEvent.h"

namespace SemperEngine {

	using namespace std;

	class EventRecorder
	{
	public:

		static vector<Event::KeyEvent> keyEvents;

		static vector<Event::KeyKeeper> pressedKeys;

		static vector<Event::MouseButtonEvent> mouseButtonEvents;

		static vector<Event::MouseButtonKeeper> mouseButtons;

		static Vector2 mousePosition;

	public:

		static void RecordKeyEvent(int key, int action);

		static void RecordCursorPosition(int x, int y);

		static void RecordMouseButton(int button, int action);

		static void Clear();

	};
}
#endif // !EVENTRECORD
