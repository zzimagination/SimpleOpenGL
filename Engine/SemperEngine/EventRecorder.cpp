#include "EventRecorder.h"
#include "KeyIdentity.h"

namespace SemperEngine {

	namespace Core
	{
		using namespace std;

		vector<KeyEvent> EventRecorder::keyEvents;
		vector<KeyKeeper> EventRecorder::pressedKeys;
		vector<MouseButtonEvent> EventRecorder::mouseButtonEvents;
		vector<MouseButtonKeeper> EventRecorder::mouseButtons;
		Float2 EventRecorder::mousePosition = Float2(0, 0);

		void EventRecorder::RecordKeyEvent(int key, int action)
		{
			KeyEvent e;
			KeyKeeper keeper;
			keeper.pressTime = 0;
			switch (key)
			{
			case KEY_SPACE:
				e.value = Keyboard::Key::space;
				break;
			case KEY_APOSTROPHE:
				e.value = Keyboard::Key::apostrophe;
				break;
			case KEY_COMMA:
				e.value = Keyboard::Key::comma;
				break;
			case KEY_MINUS:
				e.value = Keyboard::Key::minus;
				break;
			case KEY_PERIOD:
				e.value = Keyboard::Key::space;
				break;
			case KEY_SLASH:
				e.value = Keyboard::Key::slash;
				break;
			case KEY_0:
				e.value = Keyboard::Key::number0;
				break;
			case KEY_1:
				e.value = Keyboard::Key::number1;
				break;
			case KEY_2:
				e.value = Keyboard::Key::number2;
				break;
			case KEY_3:
				e.value = Keyboard::Key::number3;
				break;
			case KEY_4:
				e.value = Keyboard::Key::number4;
				break;
			case KEY_5:
				e.value = Keyboard::Key::number5;
				break;
			case KEY_6:
				e.value = Keyboard::Key::number6;
				break;
			case KEY_7:
				e.value = Keyboard::Key::number7;
				break;
			case KEY_8:
				e.value = Keyboard::Key::number8;
				break;
			case KEY_9:
				e.value = Keyboard::Key::number9;
				break;
			case KEY_SEMICOLON:
				e.value = Keyboard::Key::semicolon;
				break;
			case KEY_EQUAL:
				e.value = Keyboard::Key::equal;
				break;
			case KEY_A:
				e.value = Keyboard::Key::a;
				break;
			case KEY_B:
				e.value = Keyboard::Key::b;
				break;
			case KEY_C:
				e.value = Keyboard::Key::c;
				break;
			case KEY_D:
				e.value = Keyboard::Key::d;
				break;
			case KEY_E:
				e.value = Keyboard::Key::e;
				break;
			case KEY_F:
				e.value = Keyboard::Key::f;
				break;
			case KEY_G:
				e.value = Keyboard::Key::g;
				break;
			case KEY_H:
				e.value = Keyboard::Key::h;
				break;
			case KEY_I:
				e.value = Keyboard::Key::i;
				break;
			case KEY_J:
				e.value = Keyboard::Key::j;
				break;
			case KEY_K:
				e.value = Keyboard::Key::k;
				break;
			case KEY_L:
				e.value = Keyboard::Key::l;
				break;
			case KEY_M:
				e.value = Keyboard::Key::m;
				break;
			case KEY_N:
				e.value = Keyboard::Key::n;
				break;
			case KEY_O:
				e.value = Keyboard::Key::o;
				break;
			case KEY_P:
				e.value = Keyboard::Key::p;
				break;
			case KEY_Q:
				e.value = Keyboard::Key::q;
				break;
			case KEY_R:
				e.value = Keyboard::Key::r;
				break;
			case KEY_S:
				e.value = Keyboard::Key::s;
				break;
			case KEY_T:
				e.value = Keyboard::Key::t;
				break;
			case KEY_U:
				e.value = Keyboard::Key::u;
				break;
			case KEY_V:
				e.value = Keyboard::Key::v;
				break;
			case KEY_W:
				e.value = Keyboard::Key::w;
				break;
			case KEY_X:
				e.value = Keyboard::Key::x;
				break;
			case KEY_Y:
				e.value = Keyboard::Key::y;
				break;
			case KEY_Z:
				e.value = Keyboard::Key::z;
				break;
			case KEY_LEFT_BRACKET:
				e.value = Keyboard::Key::left_bracket;
				break;
			case KEY_BACKSLASH:
				e.value = Keyboard::Key::backslash;
				break;
			case KEY_RIGHT_BRACKET:
				e.value = Keyboard::Key::right_bracket;
				break;
			case KEY_GRAVE_ACCENT:
				e.value = Keyboard::Key::grave_accent;
				break;
			case KEY_WORLD_1:
				e.value = Keyboard::Key::world_1;
				break;
			case KEY_WORLD_2:
				e.value = Keyboard::Key::world_2;
				break;
			case KEY_ESCAPE:
				e.value = Keyboard::Key::escape;
				break;
			case KEY_ENTER:
				e.value = Keyboard::Key::enter;
				break;
			case KEY_TAB:
				e.value = Keyboard::Key::tab;
				break;
			case KEY_BACKSPACE:
				e.value = Keyboard::Key::backspace;
				break;
			case KEY_INSERT:
				e.value = Keyboard::Key::insert;
				break;
			case KEY_DELETE:
				e.value = Keyboard::Key::kp_delete;
				break;
			case KEY_RIGHT:
				e.value = Keyboard::Key::right;
				break;
			case KEY_LEFT:
				e.value = Keyboard::Key::left;
				break;
			case KEY_DOWN:
				e.value = Keyboard::Key::down;
				break;
			case KEY_UP:
				e.value = Keyboard::Key::up;
				break;
			case KEY_PAGE_UP:
				e.value = Keyboard::Key::page_up;
				break;
			case KEY_PAGE_DOWN:
				e.value = Keyboard::Key::page_down;
				break;
			case KEY_HOME:
				e.value = Keyboard::Key::home;
				break;
			case KEY_END:
				e.value = Keyboard::Key::end;
				break;
			case KEY_CAPS_LOCK:
				e.value = Keyboard::Key::caps_lock;
				break;
			case KEY_SCROLL_LOCK:
				e.value = Keyboard::Key::scroll_lock;
				break;
			case KEY_NUM_LOCK:
				e.value = Keyboard::Key::num_lock;
				break;
			case KEY_PRINT_SCREEN:
				e.value = Keyboard::Key::print_screen;
				break;
			case KEY_PAUSE:
				e.value = Keyboard::Key::pause;
				break;
			case KEY_F1:
				e.value = Keyboard::Key::f1;
				break;
			case KEY_F2:
				e.value = Keyboard::Key::f2;
				break;
			case KEY_F3:
				e.value = Keyboard::Key::f3;
				break;
			case KEY_F4:
				e.value = Keyboard::Key::f4;
				break;
			case KEY_F5:
				e.value = Keyboard::Key::f5;
				break;
			case KEY_F6:
				e.value = Keyboard::Key::f6;
				break;
			case KEY_F7:
				e.value = Keyboard::Key::f7;
				break;
			case KEY_F8:
				e.value = Keyboard::Key::f8;
				break;
			case KEY_F9:
				e.value = Keyboard::Key::f9;
				break;
			case KEY_F10:
				e.value = Keyboard::Key::f10;
				break;
			case KEY_F11:
				e.value = Keyboard::Key::f11;
				break;
			case KEY_F12:
				e.value = Keyboard::Key::f12;
				break;
			case KEY_F13:
				e.value = Keyboard::Key::f13;
				break;
			case KEY_F14:
				e.value = Keyboard::Key::f14;
				break;
			case KEY_F15:
				e.value = Keyboard::Key::f15;
				break;
			case KEY_F16:
				e.value = Keyboard::Key::f16;
				break;
			case KEY_F17:
				e.value = Keyboard::Key::f17;
				break;
			case KEY_F18:
				e.value = Keyboard::Key::f18;
				break;
			case KEY_F19:
				e.value = Keyboard::Key::f19;
				break;
			case KEY_F20:
				e.value = Keyboard::Key::f20;
				break;
			case KEY_F21:
				e.value = Keyboard::Key::f21;
				break;
			case KEY_F22:
				e.value = Keyboard::Key::f22;
				break;
			case KEY_F23:
				e.value = Keyboard::Key::f23;
				break;
			case KEY_F24:
				e.value = Keyboard::Key::f24;
				break;
			case KEY_F25:
				e.value = Keyboard::Key::f25;
				break;
			case KEY_KP_0:
				e.value = Keyboard::Key::kp_0;
				break;
			case KEY_KP_1:
				e.value = Keyboard::Key::kp_1;
				break;
			case KEY_KP_2:
				e.value = Keyboard::Key::kp_2;
				break;
			case KEY_KP_3:
				e.value = Keyboard::Key::kp_3;
				break;
			case KEY_KP_4:
				e.value = Keyboard::Key::kp_4;
				break;
			case KEY_KP_5:
				e.value = Keyboard::Key::kp_5;
				break;
			case KEY_KP_6:
				e.value = Keyboard::Key::kp_6;
				break;
			case KEY_KP_7:
				e.value = Keyboard::Key::kp_7;
				break;
			case KEY_KP_8:
				e.value = Keyboard::Key::kp_8;
				break;
			case KEY_KP_9:
				e.value = Keyboard::Key::kp_9;
				break;
			case KEY_KP_DECIMAL:
				e.value = Keyboard::Key::kp_decimal;
				break;
			case KEY_KP_DIVIDE:
				e.value = Keyboard::Key::kp_divide;
				break;
			case KEY_KP_MULTIPLY:
				e.value = Keyboard::Key::kp_multiply;
				break;
			case KEY_KP_SUBTRACT:
				e.value = Keyboard::Key::kp_subtract;
				break;
			case KEY_KP_ADD:
				e.value = Keyboard::Key::kp_add;
				break;
			case KEY_KP_ENTER:
				e.value = Keyboard::Key::kp_enter;
				break;
			case KEY_KP_EQUAL:
				e.value = Keyboard::Key::kp_equal;
				break;
			case KEY_LEFT_SHIFT:
				e.value = Keyboard::Key::left_shift;
				break;
			case KEY_LEFT_CONTROL:
				e.value = Keyboard::Key::left_control;
				break;
			case KEY_LEFT_ALT:
				e.value = Keyboard::Key::left_alt;
				break;
			case KEY_LEFT_SUPER:
				e.value = Keyboard::Key::left_super;
				break;
			case KEY_RIGHT_SHIFT:
				e.value = Keyboard::Key::right_shift;
				break;
			case KEY_RIGHT_CONTROL:
				e.value = Keyboard::Key::right_control;
				break;
			case KEY_RIGHT_ALT:
				e.value = Keyboard::Key::right_alt;
				break;
			case KEY_RIGHT_SUPER:
				e.value = Keyboard::Key::right_super;
				break;
			case KEY_MENU:
				e.value = Keyboard::Key::menu;
				break;
			default:
				return;
			}

			keeper.key = e.value;
			switch (action)
			{
			case PRESS:
				e.action = InputAction::Button::press;
				pressedKeys.push_back(keeper);
				break;
			case RELEASE:
				e.action = InputAction::Button::release;
				for (int i = 0; i < pressedKeys.size(); i++)
				{
					if (pressedKeys[i].key == e.value)
					{
						pressedKeys.erase(pressedKeys.begin() + i);
						break;
					}
				}
				break;
			default:
				return;
			}

			keyEvents.push_back(e);
		}

		void EventRecorder::RecordCursorPosition(int x, int y)
		{
			mousePosition.x = (float)x;
			mousePosition.y = (float)y;
		}

		void EventRecorder::RecordMouseButton(int button, int action)
		{
			MouseButtonEvent e;
			MouseButtonKeeper keeper;
			keeper.pressTime = 0;
			switch (button)
			{
			case MOUSE_BUTTON_LEFT:
				e.value = Mouse::Button::left;
				break;
			case MOUSE_BUTTON_RIGHT:
				e.value = Mouse::Button::right;
				break;
			case MOUSE_BUTTON_MIDDLE:
				e.value = Mouse::Button::middle;
				break;
			case MOUSE_BUTTON_4:
				e.value = Mouse::Button::button_4;
				break;
			case MOUSE_BUTTON_5:
				e.value = Mouse::Button::button_5;
				break;
			case MOUSE_BUTTON_6:
				e.value = Mouse::Button::button_6;
				break;
			case MOUSE_BUTTON_7:
				e.value = Mouse::Button::button_7;
				break;
			case MOUSE_BUTTON_8:
				e.value = Mouse::Button::button_8;
				break;
			default:
				return;
			}
			keeper.button = e.value;
			switch (action)
			{
			case PRESS:
				e.action = InputAction::Button::press;
				mouseButtons.push_back(keeper);
				break;
			case RELEASE:
				e.action = InputAction::Button::release;
				for (int i = 0; i < mouseButtons.size(); i++)
				{
					if (mouseButtons[i].button == e.value)
					{
						mouseButtons.erase(mouseButtons.begin() + i);
						break;
					}
				}
				break;
			default:
				return;
			}
			mouseButtonEvents.push_back(e);
		}

		void EventRecorder::Clear()
		{
			mouseButtonEvents.clear();
			keyEvents.clear();
		}
	}
}