#pragma once
#ifndef NEXTWORLD
#define NEXTWORLD

namespace SemperEngine
{
	namespace Core
	{
		struct NextWorld
		{
			int _primitive;

			int _next;

			bool isChange;

			NextWorld(int id);

			void SetID(int id);

			int GetID();

			void Reset();
		};
	}
}

#endif // !NEXTWORLD
