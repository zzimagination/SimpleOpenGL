#ifndef COMPONENT
#define COMPONENT

#include "LifeContainer.h"

namespace SemperEngine {

	class GameObject;

	class Component
	{
	public:

		GameObject* gameObject;

		Core::LifeContainer<Component> life = Core::LifeContainer<Component>(this);

	public:

		virtual void Start() = 0;

		virtual void Update() = 0;

		virtual void End() = 0;

	public:

		Component();

		~Component();

	};
}
#endif // !COMPONENT


