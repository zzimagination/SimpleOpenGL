#include "GameEnd.h"
#include "DebugSystem.h"
#include "GameWindow.h"

namespace SemperEngine {
	void GameEnd::End()
	{
		GameWindow::TerminateGameWindow();
		DebugSystem::Close();
	}
}