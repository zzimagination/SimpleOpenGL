#include "GameStart.h"
#include <locale>
#include "ShaderCompiler.h"
#include "DebugSystem.h"
#include "GameSetting.h"
#include "GameWindow.h"
#include "LogoPipeline.h"
#include "GraphicManager.h"
#include "ResourceObjectManager.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		void GameStart::Start()
		{
			SetLocale();
			DebugSystem::Initialization();
			GameSetting::LoadConfig();

			GameWindow::CreateGameWindow();

			ShaderCompiler::Compile();

			GraphicManager::Initialize();

			ResourceObjectManager::PreLoad();

			Logo();
		}

		void GameStart::SetLocale()
		{
			setlocale(LC_CTYPE, "");
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
