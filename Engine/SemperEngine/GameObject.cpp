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
		string log = string(name);
		log.append(" GameObject Start");
		Debug::Log(log);
	}

	void GameObject::Update() 
	{
	}

	void GameObject::End() 
	{
		string log = string(name);
		log.append(" GameObject End");
		Debug::Log(log);
	}

}