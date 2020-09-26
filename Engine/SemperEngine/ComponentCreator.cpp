#include "ComponentCreator.h"

namespace SemperEngine
{
	Component * ComponentCreator::Create(Component * com, GameObject * gameObject)
	{
		com->gameObject = gameObject;
		gameObject->container.AddComponent(com->life);
		return com;
	}
	void ComponentCreator::Destory(Component * com, GameObject * gameObject)
	{
		com->End();
		delete com;
	}
}


