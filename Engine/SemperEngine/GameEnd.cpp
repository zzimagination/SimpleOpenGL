#include "GameEnd.h"
#include "DebugSystem.h"
#include "GameWindow.h"

namespace SemperEngine 
{
	namespace Core
	{
		void GameEnd::End()
		{
			GameWindow::TerminateGameWindow();
			DebugSystem::Close();
		}
	}
}