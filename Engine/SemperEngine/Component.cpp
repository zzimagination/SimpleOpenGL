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
		Update();
	}
	void Component::GameObjectEnd(GameObject * parent)
	{
		End();
		gameObject = nullptr;
	}
}