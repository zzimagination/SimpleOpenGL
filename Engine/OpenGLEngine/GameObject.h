#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <vector>

namespace SemperEngine {

	using namespace std;

	class World;
	class Component;
	class Transform;

	class GameObject
	{
	public:

		virtual void Start();

		virtual void Update();

		virtual void OnDestory();

	public:

		string name;

		Transform* transform;

		vector<Component*> components;

		World* myWorld;

	public:

		static void Destory(GameObject* gameObject);

	public:

		GameObject();

		GameObject(string name);

		~GameObject();

		void AddComponent(Component* com);

		void RemoveComponent(Component* com);

		template<typename T>
		T GetComponent() {
			for (int i = 0; i < components.size(); i++)
			{
				if ((T)(components[i]) != nullptr)
				{
					return (T)components[i];
				}
			}
			throw "don't have component";
		}

		void Start_Internal();

		void Update_Internal();

		void OnDesory_Internal();

	private:

	};

}
#endif // !GAMEOBJECT
