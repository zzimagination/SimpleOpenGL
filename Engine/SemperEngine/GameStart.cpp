#include "GameStart.h"
#include "ShaderCompiler.h"
#include "DebugSystem.h"
#include "GameSetting.h"
#include "GameWindow.h"
#include "LogoPipeline.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		void GameStart::Start()
		{
			setlocale(LC_CTYPE, "");
			DebugSystem::Initialization();
			GameSetting::LoadConfig();
			GameWindow::CreateGameWindow();
			ShaderCompiler::Compile();
			GraphicDataCenter::InitializeData();


			/*LogoPipeline::Render();
			GameWindow::SwapFrameBuffers();

			while (!GameWindow::WindowShouldClose())
			{
				GameWindow::PollWindowEvent();
			}*/
		}
	}
}
