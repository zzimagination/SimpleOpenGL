#include "Player.h"
#include <iostream>
#include "SemperEngine.h"

namespace SemperEngine {

	using namespace std;

	Player::Player(string name) :GameObject(name)
	{
		//Renderer *renderer = new Renderer();
		//AddComponent(renderer);
	}

	void Player::Start()
	{

	}

	void Player::Update()
	{
		float y = Time::GetDeltaTime() * times + transform->eulerAngle.y;
		transform->eulerAngle.y = y;
	}

	void Player::End()
	{
	}
}