#pragma once
#ifndef __WORLD_CONVERTER__
#define __WORLD_CONVERTER__

#include <string>
#include "NextWorld.h"
#include "World.h"

namespace SemperEngine
{
	namespace Core
	{
		class WorldConverter
		{
		public:

			static NextWorld nextWorld;

		public:

			static void SetNext(std::string name);

			static void SetNext(int id);

			static void Convert();
		};
	}
}

#endif // !WORLD_CONVERTER
