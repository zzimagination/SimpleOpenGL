#include "WorldFruit.h"

namespace SemperEngine
{
	namespace Core
	{
		WorldFruit::WorldFruit()
		{
			bad = false;
			isStarted = false;
			action = std::unique_ptr<WorldAction>(new WorldAction());
		}
		WorldFruit::~WorldFruit()
		{
		}
	}
}