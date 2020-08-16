#ifndef PLAYER
#define PLAYER
#include "GameObject.h"

namespace SemperEngine {

	class Player :public GameObject
	{
	public:

		Player();

		Player(string name);

		~Player();

		virtual void Start() override;

		virtual void Update() override;

		virtual void OnDestory() override;

	public:

		float times;

		float color;

	private:

	};
}
#endif // !PLAYER


