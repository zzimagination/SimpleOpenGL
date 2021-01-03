#include "GameEnd.h"
#include "DebugSystem.h"
#include "GameWindow.h"
#include "ResourceObjectLoop.h"
#include "GraphicManager.h"

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