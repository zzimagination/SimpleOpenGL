#pragma once
#ifndef __SECOND_WORLD_ACTION__
#define __SECOND_WORLD_ACTION__

#include "WorldAction.h"

namespace SemperEngine
{
	class SecondWorldAction :public WorldAction
	{
	public:

		virtual ~SecondWorldAction() override;

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;
	};
}

#endif // !SECOND_WORLD_ACTION
