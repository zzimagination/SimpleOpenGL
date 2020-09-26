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
			auto inside = new InsideWorld();
			AddBuilder(inside);

			auto test = new TestWorld();
			AddBuilder(test);

			auto second = new SecondWorld();
			AddBuilder(second);
		}

		World* WorldMap::LoadWorld(int id)
		{
			auto builder = GetBuilder(id);
		 	auto world = builder->Build(); 
			auto action = builder->GetAction();

			auto worldPtr = WorldTree::AddWorld(world, action);
			auto fruit = WorldTree::GetFruit(worldPtr);
			auto gameObjects = builder->GetGameObjects();
			for (int i = 0; i < gameObjects.size(); i++)
			{
				fruit->container.AddGameObject(gameObjects[i]);
			}
			return worldPtr;
		}

		World* WorldMap::LoadWorld(std::string name)
		{
			auto id = GetWorldID(name);
			return LoadWorld(id);
		}

		void WorldMap::UnloadWorld(World* world)
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