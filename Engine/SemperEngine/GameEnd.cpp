#include "GameEnd.h"
#include "DebugSystem.h"
#include "GameWindow.h"
#include "ResourceObjectManager.h"
#include "GraphicManager.h"

namespace SemperEngine 
{
	namespace Core
	{
		void GameEnd::End()
		{
			GameWindow::TerminateGameWindow();
			GraphicManager::Dispose();
			DebugSystem::Close();
		}
	}
}