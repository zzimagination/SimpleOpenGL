#include "GameSystem.h"
#include "GameSetting.h"
#include <locale>


namespace Semper
{
	namespace Core
	{
		void GameSystem::LoadConfig()
		{
		
		}
		void GameSystem::Initialized()
		{
			setlocale(LC_CTYPE, "");
		}
	}
}