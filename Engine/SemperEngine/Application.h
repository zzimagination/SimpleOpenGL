#ifndef PROJECT_SETTING
#define PROJECT_SETTING

namespace SemperEngine {

	class GameWindow;

	class Application
	{
	private:

		static int windowWidth;

		static int windowHeight;

		friend GameWindow;

	public:

		static void LoadConfig();

		static int GetWindowWidth();

		static int GetWindowHeight();
	};
}
#endif // !PROJECT_SETTING





