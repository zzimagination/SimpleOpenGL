#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <vector>
#include <memory>
#include <string>
#include "Mathz.h"
#include "LifeContainer.h"
#include "Transform.h"
#include "GameObjectContainer.h"
#include "ComponentCreator.h"

namespace SemperEngine
{
	class GameObject
	{

	public:

		std::string name;

		Transform transform;

		Core::LifeContainer<GameObject> life;

		Core::GameObjectContainer container;

	public:

		GameObject();

		~GameObject();

	public:

		virtual void Start();

		virtual void Update();

		virtual void End();

	};
}
#endif // !GAMEOBJECT
