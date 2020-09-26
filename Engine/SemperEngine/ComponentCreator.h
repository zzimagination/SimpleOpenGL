#pragma once
#ifndef COMPONENT_CREATOR
#define COMPONENT_CREATOR

#include "Component.h"
#include "GameObject.h"

namespace SemperEngine
{
	class ComponentCreator
	{
	public:

		static Component* Create(Component* com, GameObject* gameObject);

		static void Destory(Component* com, GameObject* gameObject);
	};
}

#endif // !COMPONENT_CREATOR
