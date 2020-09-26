#pragma once
#ifndef GAMEOBJECT_CREATER
#define GAMEOBJECT_CREATER

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
