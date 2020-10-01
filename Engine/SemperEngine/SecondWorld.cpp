#include "SecondWorld.h"
#include "SecondWorldAction.h"
#include "ComponentCreator.h"
#include "TestComponent.h"

namespace SemperEngine
{
	SecondWorld::SecondWorld() : WorldBuilder("second", 2)
	{
	}
	World SecondWorld::Build()
	{
		auto world = World(name, id);
		AddAction(new SecondWorldAction());
		auto B = new GameObject();
		B->name = "B";
		ComponentCreator::Create(new TestComponent(), B);
		AddGameObject(B);
		return world;
	}
}