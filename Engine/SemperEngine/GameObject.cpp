#include "GameObject.h"
#include "Debug.h"

namespace SemperEngine {

	using namespace std;

	GameObject::GameObject()
	{
		life = Core::LifeContainer<GameObject>(this);
		this->name = "NewGameObject";
	}

	GameObject::~GameObject()
	{
		*(life.life) = false;
	}

	void GameObject::Start() 
	{
	}

	void GameObject::Update() 
	{
	}

	void GameObject::End() 
	{
	}

}