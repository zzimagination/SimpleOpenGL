#pragma once
#ifndef __SCEOND_WORLD__
#define __SECOND_WORLD__

#include "BeautifulWorld.h"

namespace SemperEngine
{
	class SecondWorld : public WorldBuilder
	{
	public:

		SecondWorld();
		// Í¨¹ý WorldBuilder ¼Ì³Ð
		virtual World Build() override;
	};
}

#endif // !SCEOND_WORLD
