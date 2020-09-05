#include "Component.h"

namespace SemperEngine
{
	void Component::GameObjectStart(GameObject * parent)
	{
		gameObject = parent;
		Start();
	}
	void Component::GameObjectUpdate(GameObject * parent)
	{
		gameObject = parent;
		Update();
	}
	void Component::GameObjectEnd(GameObject * parent)
	{
		gameObject = parent;
		End();
		gameObject = nullptr;
	}
}