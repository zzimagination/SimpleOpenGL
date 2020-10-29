#include "GameStart.h"
#include "ShaderCompiler.h"
#include "DebugSystem.h"
#include "GameSetting.h"
#include "GameWindow.h"
#include "LogoPipeline.h"
#include "GraphicDataCenter.h"
#include "BeforeAnything.h"
#include <locale>

#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{

		using namespace std;

		void GameStart::Start()
		{
			BeforeAnything::Start();
			SetLocale();
			DebugSystem::Initialization();
			GameSetting::LoadConfig();
			GameWindow::CreateGameWindow();
			ShaderCompiler::Compile();
			GraphicDataCenter::InitializeData();
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
