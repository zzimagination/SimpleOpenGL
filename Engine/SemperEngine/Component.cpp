#include "Component.h"
#include "GameObject.h"

namespace SemperEngine
{
	void Component::Start()
	{
	}
	void Component::Update()
	{
	}
	Component::Component()
	{
		life = LifeContainer<Component>(this);
	}

	Component::~Component()
	{
		(*life.life) = false;
	}

}