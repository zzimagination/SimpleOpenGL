#ifndef EVENTRECORDER
#define EVENTRECORDER
#include <vector>
#include "Mathz.h"
#include "UserInputEvent.h"

namespace SemperEngine {

	using namespace std;

	class EventRecorder
	{
	public:

		static vector<KeyEvent> keyEvents;

		static vector<KeyKeeper> pressedKeys;

		static vector<MouseButtonEvent> mouseButtonEvents;

		static vector<MouseButtonKeeper> mouseButtons;

		static Vector2 mousePosition;

	public:

		static void RecordKeyEvent(int key, int action);

		static void RecordCursorPosition(int x, int y);

		static void RecordMouseButton(int button, int action);

		static void Clear();

	};
}
#endif // !EVENTRECORD
