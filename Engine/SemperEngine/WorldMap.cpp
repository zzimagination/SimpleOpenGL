#include "WorldMap.h"
#include "WorldTree.h"
#include "WorldActionList.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		WorldBuilderList WorldMap::builderList;

		void WorldMap::Initialize()
		{
			auto list = builderList.worldBuilders;
			for (int i = 0; i < list.size(); i++)
			{
				CheckRepeat(list[i]->name, list[i]->id , i);
			}
		}

		void WorldMap::BuildWorld(string name)
		{
			auto builder = GetBuilder(name);
			builder->Build();
			auto action = builder->GetAction();
			auto gameObjects = builder->GetGameObjects();
			WorldTree::AddWorld(builder->name, builder->id, action, gameObjects);
		}

		void WorldMap::BuildWorld(int id)
		{
			auto builder = GetBuilder(id);
			builder->Build();
			auto action = builder->GetAction();
			auto gameObjects = builder->GetGameObjects();
			WorldTree::AddWorld(builder->name, builder->id, action, gameObjects);
		}

		bool WorldMap::Contain(string name)
		{
			auto list = builderList.worldBuilders;
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i]->name == name)
				{
					return true;
				}
			}
			return false;
		}

		bool WorldMap::Contain(int id)
		{
			auto list = builderList.worldBuilders;
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i]->id == id)
				{
					return true;
				}
			}
			return false;
		}

		int WorldMap::WorldId(std::string name)
		{
			auto list = builderList.worldBuilders;
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i]->name == name)
				{
					return list[i]->id;
				}
			}
			string log = "don't have the world ";
			log.append(name);
			Debug::Log(log);
			throw log;
		}

		std::string WorldMap::WorldName(int id)
		{
			auto list = builderList.worldBuilders;
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i]->id == id)
				{
					return list[i]->name;
				}
			}
			string log = "don't have the world ";
			log.append(to_string(id));
			Debug::Log(log);
			throw log;
		}

		void WorldMap::CheckRepeat(std::string name, int id, int listId)
		{
			auto list = builderList.worldBuilders;
			for (int i = 0; i < builderList.worldBuilders.size(); i++)
			{
				if (i == listId)
				{
					continue;
				}
				if (name == list[i]->name || id == list[i]->id)
				{
					string log = "world name repeat ";
					log.append(name);
					log.append(":");
					log.append(to_string(id));
					Debug::Log(log);
					throw log;
				}
			}
		}

		WorldBuilder* WorldMap::GetBuilder(string name)
		{
			auto list = builderList.worldBuilders;
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i]->name == name)
				{
					auto ptr = list[i];
					return ptr;
				}
			}
			string log = "don't have the world ";
			log.append(name);
			Debug::Log(log);
			throw log;
		}

		WorldBuilder* WorldMap::GetBuilder(int id)
		{
			auto list = builderList.worldBuilders;
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i]->id == id)
				{
					auto ptr = list[i];
					return ptr;
				}
			}
			string log = "don't have the world ";
			log.append(to_string(id));
			Debug::Log(log);
			throw log;
		}
	}
}