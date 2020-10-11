#pragma once
#ifndef __COMPONENT_CREATOR__
#define __COMPONENT_CREATOR__

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
