#include "Application.h"
#include "EngineDef.h"

namespace SemperEngine {

	int Application::windowWidth = Window_Width;

	int Application::windowHeight = Window_Height;

	void Application::LoadConfig()
	{
	}

	int Application::GetWindowWidth()
	{
		return windowWidth;
	}

	int Application::GetWindowHeight()
	{
		return windowHeight;
	}
}