#ifndef COMPONENT
#define COMPONENT

namespace SemperEngine {

	class GameObject;

	class Component
	{
	private:


	public:

		GameObject* gameObject = nullptr;

		virtual void Start() = 0;

		virtual void Update() = 0;

		virtual void End() = 0;

		void GameObjectStart(GameObject* parent);

		void GameObjectUpdate(GameObject* parent);

		void GameObjectEnd(GameObject* parent);

	private:

		friend class GameObject;
	};
}
#endif // !COMPONENT


