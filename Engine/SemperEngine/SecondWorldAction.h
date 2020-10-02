#pragma once
#ifndef SECOND_WORLD_ACTION
#define SECOND_WORLD_ACTION

#include "BeautifulWorld.h"

namespace SemperEngine
{
	class SecondWorldAction :public WorldAction
	{
	public:

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;
	};
}

#endif // !SECOND_WORLD_ACTION
