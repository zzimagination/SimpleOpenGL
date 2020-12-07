#include "World.h"
#include "WorldManager.h"
#include "WorldTree.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	std::string SemperEngine::World::GetInside()
	{
		return WorldManager::GetInside();
	}

	std::string SemperEngine::World::GetActive()
	{
		return WorldManager::GetActive();
	}

	void SemperEngine::World::SetActive(std::string name)
	{
		WorldManager::SetActive(name);
	}

	bool SemperEngine::World::Inside()
	{
		return WorldManager::Inside();
	}

	void World::AddGameObject(std::string world, GameObject* gameObject)
	{
		WorldTree::FindContainer(world)->AddGameObject(gameObject);
	}
}