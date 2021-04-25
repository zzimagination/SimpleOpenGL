#pragma once
#ifndef __NEXTWORLD__
#define __NEXTWORLD__

namespace Semper
{
	namespace Core
	{
		struct NextWorld
		{
			int _primitive;

			int _next;

			bool isChange;

			NextWorld();

			NextWorld(int id);

			void SetID(int id);

			int GetID();

			void Reset();
		};
	}
}

#endif // !NEXTWORLD
