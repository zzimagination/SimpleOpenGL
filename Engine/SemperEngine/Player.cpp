#include "Player.h"
#include <iostream>
#include "Time.h"
#include "Transform.h"
#include "Renderer.h"
#include "Material.h"
#include "Texture.h"

namespace SemperEngine {

	using namespace std;

	Player::Player(string name) :GameObject(name) 
	{
		auto renderer = new Renderer();
		auto material = new Material("Unlit");
		material->SetVector3(Vector3(1, 1, 1), "_color");
		renderer->SetMaterial(material);
		this->AddComponent(renderer);
	}

	Player::Player()
	{
		auto renderer = new Renderer();
		auto material = new Material("Unlit");
		material->SetVector3(Vector3(1, 1, 1), "_color");
		renderer->SetMaterial(material);
		this->AddComponent(renderer);
	}

	void Player::Start()
	{

	}

	void Player::Update()
	{
		float y = Time::GetDeltaTime() * times + GetTransform()->eulerAngle.y;
		GetTransform()->eulerAngle.y = y;
	}

	void Player::End()
	{

	}
}