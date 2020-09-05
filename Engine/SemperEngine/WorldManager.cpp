#include "WorldManager.h"
#include "World.h"
#include "SemperEngine.h"
#include "TestComponent.h"
#include "WorldStorageCenter.h"

namespace SemperEngine {

	using namespace Core;

	World * WorldManager::GetActive()
	{
		return (World*)WorldStorageCenter::GetActive();
	}

	World * WorldManager::Get(std::string name)
	{
		return (World*)WorldStorageCenter::GetWorld(name);
	}

	World * WorldManager::Get(int id)
	{
		return (World*)WorldStorageCenter::GetWorld(id);
	}

	void WorldManager::SetActive(string name)
	{
		auto world = WorldStorageCenter::GetWorld(name);
		if (world == nullptr)
		{
			throw "don't have the world";
		}
		WorldStorageCenter::SetNextActive(world);
	}

	void WorldManager::SetActive(int id)
	{
		auto world = WorldStorageCenter::GetWorld(id);
		if (world == nullptr)
		{
			throw "don't have the world";
		}
		WorldStorageCenter::SetNextActive(world);
	}

	void WorldManager::SetActive(World * world)
	{
		if ((WorldInstance*)world == nullptr)
		{
			throw "don't have the world";
		}
		WorldStorageCenter::SetNextActive((WorldInstance*)world);
	}

}