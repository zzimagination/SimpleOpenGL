#include "GameCabin.h"

namespace SemperEngine
{
	namespace Core
	{
		GameCabin::GameCabin()
		{
		}
		GameCabin::~GameCabin()
		{
		}
		bool GameCabin::Dead()
		{
			return !(*objectLife.life);
		}
	}
}