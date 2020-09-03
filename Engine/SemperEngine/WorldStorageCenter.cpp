#include "WorldStorageCenter.h"
#include "WorldInternal.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		vector<WorldStorageCenter::WorldItem> WorldStorageCenter::worldList;

		WorldStorageCenter::WorldItem WorldStorageCenter::_active = { "", 0, nullptr };

		WorldStorageCenter::WorldItem WorldStorageCenter::_nextActive = { "",0,nullptr };

		void(*WorldStorageCenter::_worldAction)() = nullptr;

		void WorldStorageCenter::Add(WorldInternal * world)
		{
			if (world == nullptr)
			{
				throw "NULL";
			}
			for (int i = 0; i < worldList.size(); i++)
			{
				if (worldList[i].name == world->Name())
				{
					throw "already has the world";
				}
			}
			WorldItem item(world->Name(), worldList.size(), world);
			worldList.push_back(item);
		}

		WorldInternal* WorldStorageCenter::GetWorld(std::string name)
		{
			for (int i = 0; i < worldList.size(); i++)
			{
				if (worldList[i].name == name)
				{
					return worldList[i].world;
				}
			}
			throw "don't have this world";
		}

		WorldInternal* WorldStorageCenter::GetWorld(int id)
		{
			if (worldList.size() <= id)
			{
				throw "don't have this world";
			}
			return worldList[id].world;
		}

		WorldInternal * WorldStorageCenter::GetActive()
		{
			return _active.world;
		}

		void WorldStorageCenter::SetNextActive(WorldInternal * world)
		{
			if (world == nullptr)
			{
				throw "NULL";
			}

			if (world == _active.world || world == _nextActive.world)
			{
				return;
			}

			for (int i = 0; i < worldList.size(); i++)
			{
				if (worldList[i].world == world)
				{
					_nextActive = worldList[i];
					_worldAction = Change;
				}
			}

			throw "don't have the world";
		}

		void WorldStorageCenter::Init()
		{
			_active = worldList[0];
			_active.world->Active();
			_active.world->Start();
			_worldAction = Update;
		}

		void WorldStorageCenter::Loop()
		{
			_worldAction();
		}
		void WorldStorageCenter::Change()
		{
			_active.world->Update();
			_worldAction = End;
		}
		void WorldStorageCenter::Start()
		{
			_active = _nextActive;
			_nextActive.world->UnActive();
			_active.world->Active();
			_active.world->Start();

			_nextActive = { "", 0, nullptr };
			_worldAction = Update;
		}
		void WorldStorageCenter::End()
		{
			_active.world->End();
			_worldAction = Start;
		}
		void WorldStorageCenter::Update()
		{
			_active.world->Update();
		}
	}
}