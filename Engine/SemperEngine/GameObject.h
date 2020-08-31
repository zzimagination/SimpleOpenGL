#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <vector>
#include <type_traits>
#include "ComponentCollection.h"

namespace SemperEngine {

	class World;

	class Component;

	class Transform;

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

	public:

		std::string name;

		Transform* transform;

		World* myWorld;

	public:

		GameObject();

		GameObject(std::string name);

		~GameObject();

		void AddComponent(Component* com);

		void RemoveComponent(Component* com);

		/*template<typename T>
		T GetComponent() {
			for (int i = 0; i < ComponentCount(); i++)
			{
				if ((T)(components[i]) != nullptr)
				{
					return (T)components[i];
				}
			}

			_noStartComponents.Size();
			while (true)
			{

			}

			throw "don't have component";
		}*/

		int ComponentCount();

	private:

		virtual void Start();

		virtual void Update();

		virtual void End();

		void WorldStart(World* world);

		void WorldUpdate(World* world);

		void WorldEnd(World* world);

	private:

		friend class World;
	};

}
#endif // !GAMEOBJECT
