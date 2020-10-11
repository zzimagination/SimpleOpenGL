#pragma once
#ifndef __GAMEOBJECT_CREATER__
#define __GAMEOBJECT_CREATER__

#include "GameObject.h"

namespace SemperEngine
{
	class GameObjectCreator
	{
	public:

		static GameObject* Create(GameObject* gameObject);

		static void Destory(GameObject* gameObject);
	};
}

#endif // !GAMEOBJECT_CREATER
