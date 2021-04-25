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
#include "ProjectState.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		void GameStart::Start()
		{
			ProjectState::state = ProjectState::State::Start;
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
			while (true)
			{
				if (GameWindow::WindowShouldClose())
				{
					ProjectState::close = true;
					break;
				}
				if (LogoPipeline::isCompleted)
				{
					break;
				}
				GameWindow::PollWindowEvent();
				LogoPipeline::Update();
				GameWindow::SwapFrameBuffers();
			}
			LogoPipeline::End();
		}
	}
}
