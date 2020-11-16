#include "GameStart.h"
#include "ShaderCompiler.h"
#include "DebugSystem.h"
#include "GameSetting.h"
#include "GameWindow.h"
#include "LogoPipeline.h"
#include "GraphicDataCenter.h"
#include "ResourceManager.h"
#include <locale>

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
			GraphicDataCenter::Initialize();
			Logo();
			ResourceManager::PreLoad();
			ResourceManager::AddAndDelete();
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
