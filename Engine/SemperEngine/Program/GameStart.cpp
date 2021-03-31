#include "GameStart.h"
#include <locale>
#include "DebugSystem.h"
#include "GameSetting.h"
#include "GameSystem.h"
#include "GameWindow.h"
#include "LogoPipeline.h"
#include "Graphic/GraphicSystem.h"
#include "ResourceSystem.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		void GameStart::Start()
		{
			GameSystem::LoadConfig();
			GameSystem::Initialized();
			DebugSystem::Initialization();
			GameWindow::CreateGameWindow();
			GraphicSystem::Initialize();
			ResourceSystem::Start();

			if (GameSetting::logo)
			{
				Logo();
			}
		}

		void GameStart::Logo()
		{
			LogoPipeline::Start();
			while (!GameWindow::WindowShouldClose() && !LogoPipeline::isCompleted)
			{
				GameWindow::PollWindowEvent();
				LogoPipeline::Update();
				GameWindow::SwapFrameBuffers();
			}
			LogoPipeline::End();
		}
	}
}
