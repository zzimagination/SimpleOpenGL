#pragma once
#ifndef __INSIDE_WORLD__
#define __INSIDE_WORLD__

#include "WorldBuilder.h"

namespace Semper
{
	class InsideWorld :public WorldBuilder
	{
	public:

		InsideWorld();

		virtual void Build() override;

	};
}


#endif // !INSIDE_WORLD
