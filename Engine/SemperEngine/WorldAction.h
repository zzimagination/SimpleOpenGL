#pragma once
#ifndef WORLD_ACTION
#define WORLD_ACTION

namespace SemperEngine
{
	class WorldAction
	{
	public:

		virtual void Start();

		virtual void Update();

		virtual void End();
	};
}

#endif // !WORLD_ACTION
