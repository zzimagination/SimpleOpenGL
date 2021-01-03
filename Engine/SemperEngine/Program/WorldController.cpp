#include "WorldController.h"
#include "WorldManager.h"
#include "WorldTree.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	std::string SemperEngine::WorldController::GetInside()
	{
		return WorldManager::GetInside();
	}

	std::string SemperEngine::WorldController::GetActive()
	{
		return WorldManager::GetActive();
	}

	void SemperEngine::WorldController::SetActive(std::string name)
	{
		WorldManager::SetActive(name);
	}

	bool SemperEngine::WorldController::Inside()
	{
		return WorldManager::Inside();
	}

	void WorldController::AddGameObject(std::string world, GameObject* gameObject)
	{
		WorldTree::FindWorld(world)->container->Add(gameObject);
	}

	void WorldController::AddGameObject(GameObject* object)
	{
		auto world = WorldManager::currentWorld;
		WorldTree::FindWorld(world)->container->Add(object);
	}
}