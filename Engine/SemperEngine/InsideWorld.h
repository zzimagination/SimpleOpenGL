#pragma once
#ifndef __INSIDE_WORLD__
#define __INSIDE_WORLD__

#include "BeautifulWorld.h"

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
