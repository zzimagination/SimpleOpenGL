#pragma once
#ifndef __INSIDE_WORLD__
#define __INSIDE_WORLD__

#include "WorldBuilder.h"

namespace SemperEngine
{
	class InsideWorld :public WorldBuilder
	{
	public:

		InsideWorld();

		virtual void Build() override;

	};
}


#endif // !INSIDE_WORLD
