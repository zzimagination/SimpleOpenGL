#include "GameObjectCreator.h"
#include "WorldManager.h"
#include "WorldTree.h"

namespace SemperEngine
{
	using namespace std;

	GameObject* GameObjectCreator::Create(GameObject * gameObject)
	{
		auto world = WorldManager::currentWorld;
		auto fruit = Core::WorldTree::GetFruit(world);
		fruit->container.AddGameObject(gameObject->life);
		return gameObject;
	}

	void GameObjectCreator::Destory(GameObject * gameObject)
	{
		gameObject->End();
		delete gameObject;
	}

}
