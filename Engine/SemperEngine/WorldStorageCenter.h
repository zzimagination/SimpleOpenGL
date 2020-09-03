#pragma once
#ifndef WORLD_STORAGECENTER
#define WORLD_STORAGECENTER

#include <vector>

namespace SemperEngine
{
	namespace Core
	{
		class WorldInternal;

		class WorldStorageCenter
		{
		private:

			struct WorldItem
			{
				std::string name;

				int id;

				WorldInternal* world;

				WorldItem(std::string _name, int _id, WorldInternal* _world)
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

			static void Add(WorldInternal* world);

			static WorldInternal* GetWorld(std::string name);

			static WorldInternal* GetWorld(int id);

			static WorldInternal* GetActive();

			static void SetNextActive(WorldInternal* world);

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
