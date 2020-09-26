#include "NextWorld.h"

namespace SemperEngine
{
	namespace Core
	{
		NextWorld::NextWorld(int id)
		{
			_primitive = id;
			_next = id;
			isChange = false;
		}

		void NextWorld::SetID(int id)
		{
			_next = id;
			isChange = _next != _primitive;
		}

		int NextWorld::GetID()
		{
			return _next;
		}
		void NextWorld::Reset()
		{
			_primitive = _next;
			isChange = false;
		}
	}
}