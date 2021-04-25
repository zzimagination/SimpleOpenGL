#include "WorldFruit.h"

namespace Semper
{
	namespace Core
	{
		WorldFruit::WorldFruit()
		{
			action = std::unique_ptr<WorldAction>(new WorldAction());
			container = std::unique_ptr<WorldContainer>(new WorldContainer());
		}
		WorldFruit::~WorldFruit()
		{
		}
	}
}