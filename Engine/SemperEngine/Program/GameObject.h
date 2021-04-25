#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <vector>
#include <memory>
#include <string>
#include <typeindex>
#include "Common.h"
#include "Transform.h"
#include "GameObjectContainer.h"

namespace Semper
{
	class Component;

	class GameObject
	{
	public:

		std::string name = "NewGameObject";

		Transform transform;

		LifeContainer<GameObject> life;

		Core::GameObjectContainer container;

	public:

		GameObject();

		GameObject(std::string name);

		virtual ~GameObject();

		void AddComponent(Component* com);

		Component* GetComponent(std::type_index type);

	public:

		virtual void Start();

		virtual void Update();

	};
}
#endif // !GAMEOBJECT
