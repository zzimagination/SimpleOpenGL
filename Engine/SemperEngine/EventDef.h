#pragma once
#ifndef EVENT_DEF
#define EVENT_DEF

#include <vector>
#include "Mathz.h"
#include "Time.h"

namespace SemperEngine
{

	struct Keyboard
	{
		enum struct Key
		{
			space,
			apostrophe,
			comma,
			minus,/* - */
			period,/* . */
			slash, /* / */
			number0,
			number1,
			number2,
			number3,
			number4,
			number5,
			number6,
			number7,
			number8,
			number9,
			semicolon,  /* ; */
			equal,/* = */
			a,
			b,
			c,
			d,
			e,
			f,
			g,
			h,
			i,
			j,
			k,
			l,
			m,
			n,
			o,
			p,
			q,
			r,
			s,
			t,
			u,
			v,
			w,
			x,
			y,
			z,
			left_bracket,/* [ */
			backslash, /* \ */
			right_bracket, /* ] */
			grave_accent,  /* ` */
			world_1,     /* non-us #1 */
			world_2,   /* non-us #2 */

			/* function keys */
			escape,
			enter,
			tab,
			backspace,
			insert,
			kp_delete,
			right,
			left,
			down,
			up,
			page_up,
			page_down,
			home,
			end,
			caps_lock,
			scroll_lock,
			num_lock,
			print_screen,
			pause,
			f1,
			f2,
			f3,
			f4,
			f5,
			f6,
			f7,
			f8,
			f9,
			f10,
			f11,
			f12,
			f13,
			f14,
			f15,
			f16,
			f17,
			f18,
			f19,
			f20,
			f21,
			f22,
			f23,
			f24,
			f25,
			kp_0,
			kp_1,
			kp_2,
			kp_3,
			kp_4,
			kp_5,
			kp_6,
			kp_7,
			kp_8,
			kp_9,
			kp_decimal,
			kp_divide,
			kp_multiply,
			kp_subtract,
			kp_add,
			kp_enter,
			kp_equal,
			left_shift,
			left_control,
			left_alt,
			left_super,
			right_shift,
			right_control,
			right_alt,
			right_super,
			menu
		};
	};

	struct Mouse
	{
		enum struct Button
		{
			left,
			right,
			middle,
			button_1,
			button_2,
			button_3,
			button_4,
			button_5,
			button_6,
			button_7,
			button_8
		};
	};

	struct InputAction
	{
		enum struct Button
		{
			press,
			release,
			keep
		};
	};

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


#endif // !EVENT_DEFINATION