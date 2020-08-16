#include "EventRecorder.h"
#include "Mathz.h"
#include "KeyIdentity.h"
#include "Time.h"
#include <iostream>

namespace SemperEngine {

	using namespace Event;

	vector<KeyEvent> EventRecorder::keyEvents;
	vector<KeyKeeper> EventRecorder::pressedKeys;
	vector<MouseButtonEvent> EventRecorder::mouseButtonEvents;
	vector<MouseButtonKeeper> EventRecorder::mouseButtons;
	Vector2 EventRecorder::mousePosition = Vector2(0, 0);

	void SemperEngine::EventRecorder::RecordKeyEvent(int key, int action)
	{
		KeyEvent e;
		KeyKeeper keeper;
		keeper.pressTime = 0;
		switch (key)
		{
		case KEY_SPACE:
			e.value = Key::space;
			break;
		case KEY_APOSTROPHE:
			e.value = Key::apostrophe;
			break;
		case KEY_COMMA:
			e.value = Key::comma;
			break;
		case KEY_MINUS:
			e.value = Key::minus;
			break;
		case KEY_PERIOD:
			e.value = Key::space;
			break;
		case KEY_SLASH:
			e.value = Key::slash;
			break;
		case KEY_0:
			e.value = Key::number0;
			break;
		case KEY_1:
			e.value = Key::number1;
			break;
		case KEY_2:
			e.value = Key::number2;
			break;
		case KEY_3:
			e.value = Key::number3;
			break;
		case KEY_4:
			e.value = Key::number4;
			break;
		case KEY_5:
			e.value = Key::number5;
			break;
		case KEY_6:
			e.value = Key::number6;
			break;
		case KEY_7:
			e.value = Key::number7;
			break;
		case KEY_8:
			e.value = Key::number8;
			break;
		case KEY_9:
			e.value = Key::number9;
			break;
		case KEY_SEMICOLON:
			e.value = Key::semicolon;
			break;
		case KEY_EQUAL:
			e.value = Key::equal;
			break;
		case KEY_A:
			e.value = Key::a;
			break;
		case KEY_B:
			e.value = Key::b;
			break;
		case KEY_C:
			e.value = Key::c;
			break;
		case KEY_D:
			e.value = Key::d;
			break;
		case KEY_E:
			e.value = Key::e;
			break;
		case KEY_F:
			e.value = Key::f;
			break;
		case KEY_G:
			e.value = Key::g;
			break;
		case KEY_H:
			e.value = Key::h;
			break;
		case KEY_I:
			e.value = Key::i;
			break;
		case KEY_J:
			e.value = Key::j;
			break;
		case KEY_K:
			e.value = Key::k;
			break;
		case KEY_L:
			e.value = Key::l;
			break;
		case KEY_M:
			e.value = Key::m;
			break;
		case KEY_N:
			e.value = Key::n;
			break;
		case KEY_O:
			e.value = Key::o;
			break;
		case KEY_P:
			e.value = Key::p;
			break;
		case KEY_Q:
			e.value = Key::q;
			break;
		case KEY_R:
			e.value = Key::r;
			break;
		case KEY_S:
			e.value = Key::s;
			break;
		case KEY_T:
			e.value = Key::t;
			break;
		case KEY_U:
			e.value = Key::u;
			break;
		case KEY_V:
			e.value = Key::v;
			break;
		case KEY_W:
			e.value = Key::w;
			break;
		case KEY_X:
			e.value = Key::x;
			break;
		case KEY_Y:
			e.value = Key::y;
			break;
		case KEY_Z:
			e.value = Key::z;
			break;
		case KEY_LEFT_BRACKET:
			e.value = Key::left_bracket;
			break;
		case KEY_BACKSLASH:
			e.value = Key::backslash;
			break;
		case KEY_RIGHT_BRACKET:
			e.value = Key::right_bracket;
			break;
		case KEY_GRAVE_ACCENT:
			e.value = Key::grave_accent;
			break;
		case KEY_WORLD_1:
			e.value = Key::world_1;
			break;
		case KEY_WORLD_2:
			e.value = Key::world_2;
			break;
		case KEY_ESCAPE:
			e.value = Key::escape;
			break;
		case KEY_ENTER:
			e.value = Key::enter;
			break;
		case KEY_TAB:
			e.value = Key::tab;
			break;
		case KEY_BACKSPACE:
			e.value = Key::backspace;
			break;
		case KEY_INSERT:
			e.value = Key::insert;
			break;
		case KEY_DELETE:
			e.value = Key::kp_delete;
			break;
		case KEY_RIGHT:
			e.value = Key::right;
			break;
		case KEY_LEFT:
			e.value = Key::left;
			break;
		case KEY_DOWN:
			e.value = Key::down;
			break;
		case KEY_UP:
			e.value = Key::up;
			break;
		case KEY_PAGE_UP:
			e.value = Key::page_up;
			break;
		case KEY_PAGE_DOWN:
			e.value = Key::page_down;
			break;
		case KEY_HOME:
			e.value = Key::home;
			break;
		case KEY_END:
			e.value = Key::end;
			break;
		case KEY_CAPS_LOCK:
			e.value = Key::caps_lock;
			break;
		case KEY_SCROLL_LOCK:
			e.value = Key::scroll_lock;
			break;
		case KEY_NUM_LOCK:
			e.value = Key::num_lock;
			break;
		case KEY_PRINT_SCREEN:
			e.value = Key::print_screen;
			break;
		case KEY_PAUSE:
			e.value = Key::pause;
			break;
		case KEY_F1:
			e.value = Key::f1;
			break;
		case KEY_F2:
			e.value = Key::f2;
			break;
		case KEY_F3:
			e.value = Key::f3;
			break;
		case KEY_F4:
			e.value = Key::f4;
			break;
		case KEY_F5:
			e.value = Key::f5;
			break;
		case KEY_F6:
			e.value = Key::f6;
			break;
		case KEY_F7:
			e.value = Key::f7;
			break;
		case KEY_F8:
			e.value = Key::f8;
			break;
		case KEY_F9:
			e.value = Key::f9;
			break;
		case KEY_F10:
			e.value = Key::f10;
			break;
		case KEY_F11:
			e.value = Key::f11;
			break;
		case KEY_F12:
			e.value = Key::f12;
			break;
		case KEY_F13:
			e.value = Key::f13;
			break;
		case KEY_F14:
			e.value = Key::f14;
			break;
		case KEY_F15:
			e.value = Key::f15;
			break;
		case KEY_F16:
			e.value = Key::f16;
			break;
		case KEY_F17:
			e.value = Key::f17;
			break;
		case KEY_F18:
			e.value = Key::f18;
			break;
		case KEY_F19:
			e.value = Key::f19;
			break;
		case KEY_F20:
			e.value = Key::f20;
			break;
		case KEY_F21:
			e.value = Key::f21;
			break;
		case KEY_F22:
			e.value = Key::f22;
			break;
		case KEY_F23:
			e.value = Key::f23;
			break;
		case KEY_F24:
			e.value = Key::f24;
			break;
		case KEY_F25:
			e.value = Key::f25;
			break;
		case KEY_KP_0:
			e.value = Key::kp_0;
			break;
		case KEY_KP_1:
			e.value = Key::kp_1;
			break;
		case KEY_KP_2:
			e.value = Key::kp_2;
			break;
		case KEY_KP_3:
			e.value = Key::kp_3;
			break;
		case KEY_KP_4:
			e.value = Key::kp_4;
			break;
		case KEY_KP_5:
			e.value = Key::kp_5;
			break;
		case KEY_KP_6:
			e.value = Key::kp_6;
			break;
		case KEY_KP_7:
			e.value = Key::kp_7;
			break;
		case KEY_KP_8:
			e.value = Key::kp_8;
			break;
		case KEY_KP_9:
			e.value = Key::kp_9;
			break;
		case KEY_KP_DECIMAL:
			e.value = Key::kp_decimal;
			break;
		case KEY_KP_DIVIDE:
			e.value = Key::kp_divide;
			break;
		case KEY_KP_MULTIPLY:
			e.value = Key::kp_multiply;
			break;
		case KEY_KP_SUBTRACT:
			e.value = Key::kp_subtract;
			break;
		case KEY_KP_ADD:
			e.value = Key::kp_add;
			break;
		case KEY_KP_ENTER:
			e.value = Key::kp_enter;
			break;
		case KEY_KP_EQUAL:
			e.value = Key::kp_equal;
			break;
		case KEY_LEFT_SHIFT:
			e.value = Key::left_shift;
			break;
		case KEY_LEFT_CONTROL:
			e.value = Key::left_control;
			break;
		case KEY_LEFT_ALT:
			e.value = Key::left_alt;
			break;
		case KEY_LEFT_SUPER:
			e.value = Key::left_super;
			break;
		case KEY_RIGHT_SHIFT:
			e.value = Key::right_shift;
			break;
		case KEY_RIGHT_CONTROL:
			e.value = Key::right_control;
			break;
		case KEY_RIGHT_ALT:
			e.value = Key::right_alt;
			break;
		case KEY_RIGHT_SUPER:
			e.value = Key::right_super;
			break;
		case KEY_MENU:
			e.value = Key::menu;
			break;
		default:
			return;
		}
		keeper.key = e.value;
		switch (action)
		{
		case PRESS:
			e.action = ButtonAction::press;
			pressedKeys.push_back(keeper);
			break;
		case RELEASE:
			e.action = ButtonAction::release;
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

	void SemperEngine::EventRecorder::RecordCursorPosition(int x, int y)
	{
		mousePosition.x = (float)x;
		mousePosition.y = (float)y;
	}

	void SemperEngine::EventRecorder::RecordMouseButton(int button, int action)
	{
		MouseButtonEvent e;
		MouseButtonKeeper keeper;
		keeper.pressTime = 0;
		switch (button)
		{
		case MOUSE_BUTTON_LEFT:
			e.value = MouseButton::mouse_left;
			break;
		case MOUSE_BUTTON_RIGHT:
			e.value = MouseButton::mouse_right;
			break;
		case MOUSE_BUTTON_MIDDLE:
			e.value = MouseButton::mouse_middle;
			break;
		case MOUSE_BUTTON_4:
			e.value = MouseButton::mouse_button_4;
			break;
		case MOUSE_BUTTON_5:
			e.value = MouseButton::mouse_button_5;
			break;
		case MOUSE_BUTTON_6:
			e.value = MouseButton::mouse_button_6;
			break;
		case MOUSE_BUTTON_7:
			e.value = MouseButton::mouse_button_7;
			break;
		case MOUSE_BUTTON_8:
			e.value = MouseButton::mouse_button_8;
			break;
		default:
			return;
		}
		keeper.button = e.value;
		switch (action)
		{
		case PRESS:
			e.action = ButtonAction::press;
			mouseButtons.push_back(keeper);
			break;
		case RELEASE:
			e.action = ButtonAction::release;
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