#include "GameSlot.h"

namespace SemperEngine
{
	namespace Core
	{
		bool GameSlot::Dead()
		{
			return !(*componentLife.life);
		}
	}
}