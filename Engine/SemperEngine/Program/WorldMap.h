#pragma once
#ifndef __WORLD_MAP__
#define __WORLD_MAP__

#include "WorldBuilder.h"
#include "WorldBuilderList.h"

namespace SemperEngine
{
	namespace Core
	{
		class WorldMap
		{
		private:

			static WorldBuilderList builderList;

		public:

			static void Initialize();

			static void BuildWorld(std::string name);

			static void BuildWorld(int id);

			static bool Contain(std::string name);

			static bool Contain(int id);

			static int WorldId(std::string name);

			static std::string WorldName(int id);

		private:

			static void CheckRepeat(std::string name, int id, int listId);

			static WorldBuilder* GetBuilder(std::string name);

			static WorldBuilder* GetBuilder(int id);
		};
	}
}

#endif // !WORLD_MAP
