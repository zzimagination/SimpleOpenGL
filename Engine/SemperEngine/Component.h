#ifndef __COMPONENT__
#define __COMPONENT__

#include "LifeContainer.h"

namespace SemperEngine {

	class GameObject;

	class Component
	{
	public:

		GameObject* gameObject;

		LifeContainer<Component> life;

	public:

		virtual void Start();

		virtual void Update();

	public:

		Component();

		virtual ~Component();

	};
}
#endif // !COMPONENT


