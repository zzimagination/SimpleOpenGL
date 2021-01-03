#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <vector>
#include <memory>
#include <string>
#include <typeindex>
#include "Mathz.h"
#include "LifeContainer.h"
#include "Transform.h"
#include "GameObjectContainer.h"
#include "Component.h"

namespace SemperEngine
{
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
