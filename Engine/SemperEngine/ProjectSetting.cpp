#include "ProjectSetting.h"
#include "EngineDef.h"

namespace SemperEngine {

	int ProjectSetting::windowWidth = Window_Width;

	int ProjectSetting::windowHeight = Window_Height;

	void ProjectSetting::LoadConfig()
	{
	}

	int ProjectSetting::GetWindowWidth()
	{
		return windowWidth;
	}

	int ProjectSetting::GetWindowHeight()
	{
		return windowHeight;
	}
}