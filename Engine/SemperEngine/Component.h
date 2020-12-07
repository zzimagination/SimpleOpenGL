#ifndef __COMPONENT__
#define __COMPONENT__

#include "ObjectIndex.h"
#include "LifeContainer.h"

namespace SemperEngine {

	class GameObject;

	class Component
	{
	public:

		GameObject* gameObject;

		Core::LifeContainer<Component> life;

		int gameObjectId;

	public:

		virtual void Start() = 0;

		virtual void Update() = 0;

	public:

		Component();

		virtual ~Component();

	};
}
#endif // !COMPONENT


