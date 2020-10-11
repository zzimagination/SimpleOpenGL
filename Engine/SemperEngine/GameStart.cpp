#include "GameStart.h"
#include "ShaderCompiler.h"
#include "DebugSystem.h"
#include "GameSetting.h"
#include "GameWindow.h"

namespace SemperEngine 
{
	namespace Core
	{
		void GameStart::Start()
		{
			setlocale(LC_CTYPE, "");
			DebugSystem::Initialization();
			GameWindow::CreateGameWindow();
			ShaderCompiler::Compile();
			GameSetting::LoadConfig();
		}
	}
}
