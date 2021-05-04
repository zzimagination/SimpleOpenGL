#include "WorldMap.h"
#include "WorldTree.h"
#include "WorldActionList.h"
#include "Debug.h"
#include "WorldBuilderList.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		map<string, WorldBuilder*> WorldMap::builders;

		string WorldMap::start;

		string WorldMap::inside;

		void WorldMap::Initialize()
		{
			WorldBuilderList list;
			builders = list.GenerateBuilders();
			start = list.start;
			inside = list.inside;
		}

		void WorldMap::BuildWorld(string name)
		{
			auto builder = GetBuilder(name);
			builder->Build();
			auto action = builder->GetAction();
			auto gameObjects = builder->GetGameObjects();
			WorldTree::AddWorld(builder->name, builder->id, action, gameObjects);
		}

		bool WorldMap::Contain(string name)
		{
			auto i = builders.find(name);
			if (i == builders.end())
			{
				return false;
			}
			return true;
		}

		WorldBuilder* WorldMap::GetBuilder(string name)
		{
			return builders[name];
		}
	}
}