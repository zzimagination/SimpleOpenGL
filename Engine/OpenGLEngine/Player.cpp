#include "Player.h"
#include "Mathz.h"
#include "Time.h"
#include <iostream>

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
