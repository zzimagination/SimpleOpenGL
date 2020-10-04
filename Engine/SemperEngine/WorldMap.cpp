#include "WorldMap.h"
#include "WorldTree.h"
#include "WorldBuilderList.h"
#include "WorldActionList.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<WorldBuilder*> WorldMap::_builders;

		void WorldMap::BuildWorld()
		{
			for (int i = 0; i < builders.size(); i++)
			{
				AddBuilder(builders[i]);
			}
		}

		World WorldMap::LoadWorld(int id)
		{
			auto builder = GetBuilder(id);
		 	auto worldTemplate = builder->Build(); 
			auto action = builder->GetAction();
			auto gameObjects = builder->GetGameObjects();

			auto world = WorldTree::AddWorld(worldTemplate, action, gameObjects);
			return world;
		}

		World WorldMap::LoadWorld(std::string name)
		{
			auto id = GetWorldID(name);
			return LoadWorld(id);
		}

		void WorldMap::UnloadWorld(World world)
		{
			WorldTree::RemoveWorld(world);
		}

		int WorldMap::GetWorldID(std::string name)
		{
			for (int i = 0; i < 2; i++)
			{
				if (_builders[i]->name == name)
				{
					return _builders[i]->id;
				}
			}
			throw "arguments error";
		}

		bool WorldMap::Contain(int id)
		{
			for (int i = 0; i < _builders.size(); i++)
			{
				if (_builders[i]->id == id)
				{
					return true;
				}
			}
			return false;
		}

		void WorldMap::AddBuilder(WorldBuilder * builder)
		{
			for (int i = 0; i < _builders.size(); i++)
			{
				if (builder->id == _builders[i]->id || builder->name == _builders[i]->name)
				{
					throw "world repeat";
				}
			}
			_builders.push_back(builder);
		}

		WorldBuilder * WorldMap::GetBuilder(int id)
		{
			for (int i = 0; i < _builders.size(); i++)
			{
				if (_builders[i]->id == id)
				{
					return _builders[i];
				}
			}
			throw "don't have this world";
		}

	}
}