#pragma once
#ifndef __WORLD_ACTION__
#define __WORLD_ACTION__

namespace SemperEngine
{
	class WorldAction
	{
	public:

		virtual ~WorldAction();

		virtual void Start();

		virtual void Update();

		virtual void End();
	};
}

#endif // !WORLD_ACTION
