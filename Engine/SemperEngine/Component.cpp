#include "Component.h"
#include "GameObject.h"

namespace SemperEngine
{
	Component::Component()
	{
		life = Core::LifeContainer<Component>(this);
	}

	Component::~Component()
	{
		(*life.life) = false;
	}

}