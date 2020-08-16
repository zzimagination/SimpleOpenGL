#ifndef COMPONENT
#define COMPONENT

namespace SemperEngine {

	class GameObject;

	class Component
	{
	public:

		GameObject* gameObject = nullptr;

	protected:

	public:

		virtual void Start() = 0;

		virtual void Update() = 0;

		virtual void OnDestory() = 0;

	};
}
#endif // !COMPONENT


