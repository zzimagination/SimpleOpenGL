#ifndef PLAYER
#define PLAYER
#include "GameObject.h"

namespace SemperEngine {

	class Player :public GameObject
	{
	public:

		Player(std::string name);

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;

	public:

		float times;

		float color;

	private:

	};
}
#endif // !PLAYER


