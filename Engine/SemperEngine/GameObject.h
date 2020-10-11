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

		Core::ObjectIndex worldID;

	public:

		GameObject();

		virtual ~GameObject();

	public:

		virtual void Start();

		virtual void Update();

		virtual void End();

	};
}
#endif // !GAMEOBJECT
