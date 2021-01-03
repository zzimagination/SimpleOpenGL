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
				CheckRepeat(list[i]->name, list[i]->id, i);
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

			Debug::LogError({ "don't have the world " , name});
			return 0;
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

			Debug::LogError({ "don't have the world " , to_string(id)});
			return "";
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
					Debug::LogError({ "world name repeat", name, to_string(id) });
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
			Debug::LogError({ "don't have the world ", name });
			return nullptr;
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
			Debug::LogError({ "don't have the world " , to_string(id) });
			return nullptr;
		}
	}
}