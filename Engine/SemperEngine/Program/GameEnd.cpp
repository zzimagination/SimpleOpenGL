#include "GameEnd.h"
#include "GameWindow.h"
#include "DebugSystem.h"
#include "ProjectState.h"

namespace Semper 
{
	namespace Core
	{
		void GameEnd::End()
		{
			ProjectState::state = ProjectState::State::End;
			GameWindow::TerminateGameWindow();
			DebugSystem::Close();
		}
	}
}