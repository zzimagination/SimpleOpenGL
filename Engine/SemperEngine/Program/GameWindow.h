#ifndef __GAMEWINDOW__
#define __GAMEWINDOW__

#include "GLWindow.h"

namespace Semper {

	namespace Core
	{
		class GameWindow
		{
		public:

			static GLWindow* window;

			static void CreateGameWindow();

			static void TerminateGameWindow();

			static bool WindowShouldClose();

			static void SwapFrameBuffers();

			static void PollWindowEvent();

			static void OnSizeChanged(int width, int height);

		};
	}
}
#endif // !GAMEWINDOW


