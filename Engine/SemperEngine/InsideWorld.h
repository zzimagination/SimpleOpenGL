#pragma once
#ifndef INSIDE_WORLD
#define INSIDE_WORLD

#include "WorldBuilder.h"

namespace SemperEngine
{
	class InsideWorld :public WorldBuilder
	{
	public:

		InsideWorld();

		virtual World Build() override;

	};
}


#endif // !INSIDE_WORLD
