#include "Player.h"
#include <iostream>
#include "SemperEngine.h"

namespace SemperEngine {

	Player::Player()
	{
		Renderer *renderer = new Renderer();
		AddComponent(renderer);
	}

	Player::Player(string name) :GameObject(name)
	{
		Renderer *renderer = new Renderer();
		AddComponent(renderer);
	}

	Player::~Player()
	{
		for (int i = 0; i < components.size(); i++)
		{
			delete components[i];
		}
		components.clear();
	}

	void Player::Start()
	{

	}

	void Player::Update()
	{
		float y = Time::GetDeltaTime() * times + transform->eulerAngle.y;
		transform->eulerAngle.y = y;
	}

	void Player::OnDestory()
	{
	}
}