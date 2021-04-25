#ifndef __COMPONENT__
#define __COMPONENT__

#include "Common.h"

namespace Semper {

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


