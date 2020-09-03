#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <vector>
#include <type_traits>
#include "ComponentCollection.h"

namespace SemperEngine {

	class World;

	class Component;

	class Transform;

	namespace Core
	{
		class WorldInternal;
	}

	class GameObject
	{
	private:

		enum class GameObjectState {

			EG_Ended,

			EG_Ending,

			EG_Start,

			EG_Update

		} ;

	private:

		GameObjectState _myState;

		ComponentCollection _startedComponents;

		ComponentCollection _noStartComponents;

		std::vector<Component* > _componentList;

	public:

		std::string name;

		Transform* transform;

		World* myWorld;

	public:

		GameObject();

		GameObject(std::string name);

		~GameObject();


		template<typename T>
		T* AddComponent()
		{
			static_assert(std::is_base_of<Component, T>::value, "error");
			auto com = new T();
			AddComponentInternal(com);
			return com;
		}

		void RemoveComponent(Component* com);

		template<typename T>
		T* GetComponent() {
			static_assert(std::is_base_of<Component, T>::value, "error");
			
			for (int i = 0; i < _componentList.size(); i++)
			{
				if (typeid(T*) == typeid(_componentList[i]))
				{
					return (T*)_componentList[i];
				}
			}
			throw "don't have component";
		}

	private:

		virtual void Start();

		virtual void Update();

		virtual void End();

		void WorldStart(World* world);

		void WorldUpdate(World* world);

		void WorldEnd(World* world);

		void AddComponentInternal(Component* com);

	private:

		friend class Core::WorldInternal;
	};

}
#endif // !GAMEOBJECT
