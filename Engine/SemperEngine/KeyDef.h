#pragma once
#ifndef KEY_DEFINITION
#define KEY_DEFINITION

namespace SemperEngine {
	namespace Event {
		enum Key {

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

		enum ButtonAction {
			press,
			release,
			keep
		};

		enum MouseButton
		{
			mouse_left,
			mouse_right,
			mouse_middle,
			mouse_button_1,
			mouse_button_2,
			mouse_button_3,
			mouse_button_4,
			mouse_button_5,
			mouse_button_6,
			mouse_button_7,
			mouse_button_8
		};
	}
}

#endif // !KEY_DEFINITION
