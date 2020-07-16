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
	Vector2 a;
	Vector2 b(1, 2);
	Vector2 c = a + b;
	Matrix4x4 mat;
	float t = mat[0][3];
	cout << t << endl;
}

void Player::Update()
{
	transform.eulerAngle.y += Time::GetDeltaTime() * 10;
}
