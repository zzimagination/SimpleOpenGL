#include "Player.h"
#include "Mathz.h"
#include "Time.h"
#include <iostream>
#include "Renderer.h"
#include "ShaderManager.h"

Player::Player():GameObject()
{
	Renderer* renderer = new Renderer();
	AddComponent(renderer);
}

Player::Player(string name):GameObject(name)
{
	Renderer* renderer = new Renderer();
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
	float y = Time::GetDeltaTime() * times + transform.eulerAngle.y;
	transform.eulerAngle.y = y;
}
