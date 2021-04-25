#include "Component.h"
#include "GameObject.h"

namespace Semper
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