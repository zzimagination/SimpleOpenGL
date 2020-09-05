#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <vector>
#include <typeinfo>
#include "ObjectCollection.h"


namespace SemperEngine {

	class World;

	class Component;

	class Transform;

	namespace Core
	{
		class WorldInstance;
	}

	class GameObject
	{

		typedef Collection::ObjectCollection<Component> ComponentCollection;

	public:

		std::string name;

	private:

		bool _isStart;

		Transform* _transform;

		ComponentCollection _startedComponents;

		ComponentCollection _noStartComponents;

		std::vector<Component*> _componentList;

	public:

		GameObject();

		GameObject(std::string name);

		~GameObject();

		void AddComponent(Component* com);

		Component* GetComponent(const std::type_info & type);

		void RemoveComponent(Component* com);

		Transform* GetTransform();

	private:

		virtual void Start();

		virtual void Update();

		virtual void End();

		void WorldStart(World* world);

		void WorldUpdate(World* world);

		void WorldEnd(World* world);

	private:

		friend class Core::WorldInstance;

	};

}

#endif // !GAMEOBJECT
