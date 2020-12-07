#pragma once
#ifndef __SCEOND_WORLD__
#define __SECOND_WORLD__

#include "WorldBuilder.h"

namespace SemperEngine
{
	class SecondWorld : public WorldBuilder
	{
	public:

		SecondWorld();

		virtual void Build() override;
	};
}

#endif // !SCEOND_WORLD
