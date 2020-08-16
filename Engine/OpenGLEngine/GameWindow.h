#ifndef GAMEWINDOW
#define GAMEWINDOW

namespace SemperEngine {

	class GWindow;

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
#endif // !GAMEWINDOW


