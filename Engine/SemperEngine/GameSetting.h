#ifndef __PROJECT_SETTING__
#define __PROJECT_SETTING__

namespace SemperEngine {

	class GameSetting
	{
	public:

		static int windowWidth;

		static int windowHeight;

		static int vsync;

		static float buttonPressT;

	public:

		static void LoadConfig();
	};
}
#endif // !PROJECT_SETTING





