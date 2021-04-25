#include "GameObject.h"
#include "Component.h"
#include "Debug.h"
#include <typeinfo>
#include <typeindex>

namespace Semper {

	using namespace std;

	GameObject::GameObject()
	{
		life = LifeContainer<GameObject>(this);
	}

	GameObject::GameObject(std::string name)
	{
		life = LifeContainer<GameObject>(this);
		this->name = name;
	}

	GameObject::~GameObject()
	{
		container.End();
		*(life.life) = false;
	}

	void GameObject::AddComponent(Component* com)
	{
		com->gameObject = this;
		this->container.AddComponent(com);
	}

	Component* GameObject::GetComponent(type_index type)
	{
		auto result = container.GetComponent(type);
		return result;
	}

	void GameObject::Start()
	{
	}

	void GameObject::Update() 
	{
	}

}