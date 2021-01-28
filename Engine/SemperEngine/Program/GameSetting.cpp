#include "GameSetting.h"

namespace SemperEngine {

	using namespace std;

	wstring GameSetting::gameTitle = L"semperÒýÇæ";

	int GameSetting::windowWidth = 2560;

	int GameSetting::windowHeight = 1440;

	GameSetting::Vsync GameSetting::vsync = GameSetting::Vsync::vsync;

	bool GameSetting::logo = true;
}