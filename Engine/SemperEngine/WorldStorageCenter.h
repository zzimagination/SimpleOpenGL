#pragma once
#ifndef WORLD_STORAGECENTER
#define WORLD_STORAGECENTER

#include <vector>

namespace SemperEngine
{
	namespace Core
	{
		class WorldInstance;

		class WorldStorageCenter
		{
		private:

			struct WorldItem
			{
				std::string name;

				int id;

				WorldInstance* world;

				WorldItem(std::string _name, int _id, WorldInstance* _world)
				{
					name = _name;
					id = _id;
					world = _world;
				}
			};

		public:

			static WorldItem _active;

		private:

			static std::vector<WorldItem> worldList;

			static WorldItem _nextActive;

			static bool _changeWorld;

			static void(*_worldAction)(); 

		public:

			static void Add(WorldInstance* world);

			static WorldInstance* GetWorld(std::string name);

			static WorldInstance* GetWorld(int id);

			static WorldInstance* GetActive();

			static void SetNextActive(WorldInstance* world);

			static void Init();

			static void Loop();

		private:

			static void Change();

			static void Start();

			static void End();

			static void Update();
		};
	}
}

#endif // !WORLD_STORAGECENTER
