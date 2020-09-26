#include "GameStart.h"
#include "GraphicShaderManager.h"
#include "DebugSystem.h"
#include "Application.h"
#include "GameWindow.h"

namespace SemperEngine {
	void GameStart::Start()
	{
		DebugSystem::Initialization();
		GameWindow::CreateGameWindow();
		Application::LoadConfig();
		ShaderManager::CompileShader();
	}
}
