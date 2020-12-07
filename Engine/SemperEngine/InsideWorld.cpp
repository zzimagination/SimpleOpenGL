#include "InsideWorld.h"
#include "BeautifulWorld.h"
#include "InsideWorldAction.h"
#include "Debug.h"


namespace SemperEngine
{
	using namespace std;

	InsideWorld::InsideWorld() : WorldBuilder("inside", 0)
	{
	}

	void InsideWorld::Build()
	{
		AddAction(new InsideWorldAction());
	}

}


