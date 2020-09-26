#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <vector>
#include <typeinfo>
#include "Component.h"
#include "Transform.h"
#include "GameObjectContainer.h"
#include "LifeContainer.h"

namespace SemperEngine
{
	class GameObject
	{

	public:

		std::string name;

		Transform transform;

		Core::LifeContainer<GameObject> life = Core::LifeContainer<GameObject>(this);

		Core::GameObjectContainer container;

	public:

		virtual void Start();

		virtual void Update();

		virtual void End();

	public:

		GameObject();

		GameObject(std::string name);

		~GameObject();

	};
}
#endif // !GAMEOBJECT
