#include "GameSlot.h"

namespace Semper
{
	namespace Core
	{
		bool GameSlot::Dead()
		{
			return !(*componentLife.life);
		}
	}
}