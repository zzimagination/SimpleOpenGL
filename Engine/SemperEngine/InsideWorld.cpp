#include "InsideWorld.h"
#include "InsideWorldAction.h"
#include "Debug.h"


namespace SemperEngine
{
	using namespace std;

	InsideWorld::InsideWorld() : WorldBuilder("inside", 0)
	{
	}

	World InsideWorld::Build()
	{
		auto world = World(name, id);
		AddAction(new InsideWorldAction());
		return world;
	}

}


