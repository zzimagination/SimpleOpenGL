#include "Component.h"
#include "GameObject.h"

namespace SemperEngine
{
	Component::Component()
	{
	}

	Component::~Component()
	{
		(*life.life) = false;
	}

}