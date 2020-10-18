#pragma once
#ifndef __INSIDE_WORLD_ACTION__
#define __INSIDE_WORLD_ACTION__

#include "BeautifulWorld.h"

namespace SemperEngine
{
	class InsideWorldAction : public WorldAction
	{
	public:

		int count = 0;

		virtual ~InsideWorldAction() override;

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;
	};
}

#endif // !INSIDE_WORLD_ACTION
