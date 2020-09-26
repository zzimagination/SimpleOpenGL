#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "World.h"
#include "Debug.h"

namespace SemperEngine {

	using namespace std;

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

	GameObject::GameObject():GameObject("NewGameObject")
	{
		
	}

	GameObject::GameObject(std::string name)
	{
		this->name = name;
	}

	GameObject::~GameObject()
	{
		(*life.life) = false;
	}
}