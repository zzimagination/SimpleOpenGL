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
		// ͨ�� WorldBuilder �̳�
		virtual World Build() override;
	};
}

#endif // !SCEOND_WORLD
