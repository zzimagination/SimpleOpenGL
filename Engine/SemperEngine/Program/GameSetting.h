#ifndef __PROJECT_SETTING__
#define __PROJECT_SETTING__

#include <string>

namespace Semper {

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

		static bool logo;

	};
}
#endif // !PROJECT_SETTING





