#ifndef __GAMEWINDOW__
#define __GAMEWINDOW__

#include "GWindow.h"

namespace SemperEngine {

	namespace Core
	{
		class GameWindow
		{
		public:

			static GWindow* window;

			static void CreateGameWindow();

			static void TerminateGameWindow();

			static bool WindowShouldClose();

			static void SwapFrameBuffers();

			static void PollWindowEvent();

			static void OnSizeChanged(int width, int height);

			static void OnMouse(double xpos, double ypos);

			static void OnScroll(double xoffset, double yoffset);

		};
	}
}
#endif // !GAMEWINDOW


