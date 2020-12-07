#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <vector>
#include <memory>
#include <string>
#include "Mathz.h"
#include "LifeContainer.h"
#include "ObjectIndex.h"
#include "Transform.h"
#include "GameObjectContainer.h"
#include "Component.h"

namespace SemperEngine
{
	class GameObject
	{

	public:

		std::string name;

		Transform transform;

		Core::LifeContainer<GameObject> life;

		Core::GameObjectContainer container;

		int worldID;

	public:

		GameObject();

		virtual ~GameObject();

		void AddComponent(Component* com);

	public:

		virtual void Start();

		virtual void Update();

	};
}
#endif // !GAMEOBJECT
