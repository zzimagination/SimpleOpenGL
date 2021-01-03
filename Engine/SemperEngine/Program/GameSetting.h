#ifndef __PROJECT_SETTING__
#define __PROJECT_SETTING__

#include <string>

namespace SemperEngine {

	class GameSetting
	{
	public:

		enum class Vsync
		{
			none,

			half,

			vsync
		};

	public:

		static std::wstring gameTitle;

		static int windowWidth;

		static int windowHeight;

		static Vsync vsync;

	public:

		static void LoadConfig();
	};
}
#endif // !PROJECT_SETTING





