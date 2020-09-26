#pragma once
#ifndef SCEOND_WORLD
#define SECOND_WORLD

#include "WorldBuilder.h"

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
