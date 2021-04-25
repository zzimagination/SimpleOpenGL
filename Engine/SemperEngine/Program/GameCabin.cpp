#include "GameCabin.h"

namespace Semper
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