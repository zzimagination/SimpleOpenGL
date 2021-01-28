#include "GameEnd.h"
#include "GameWindow.h"
#include "DebugSystem.h"

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