#include "WorldController.h"
#include "WorldManager.h"
#include "WorldTree.h"

namespace Semper
{
	using namespace std;
	using namespace Core;

	std::string Semper::WorldController::GetInside()
	{
		return WorldManager::GetInside();
	}

	std::string Semper::WorldController::GetActive()
	{
		return WorldManager::GetActive();
	}

	void Semper::WorldController::SetActive(std::string name)
	{
		WorldManager::SetActive(name);
	}

	bool Semper::WorldController::Inside()
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