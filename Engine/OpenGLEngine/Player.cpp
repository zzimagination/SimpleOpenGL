#include "Player.h"
#include "Mathz.hpp"
#include "Time.h"
#include <iostream>
#include "Mathz.hpp"

Player::Player()
{
}

Player::Player(string name):GameObject(name)
{
}

Player::~Player()
{
}

void Player::Start()
{

}

void Player::Update()
{
	transform.eulerAngle.y += Time::GetDeltaTime() * 10;
}
