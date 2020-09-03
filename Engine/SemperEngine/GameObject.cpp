#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "World.h"

namespace SemperEngine {

	GameObject::GameObject():GameObject("New GameObject")
	{
	}

	GameObject::GameObject(string name)
	{
		this->name = name;
		transform = new Transform();
		_myState = GameObjectState::EG_Ended;
		myWorld = nullptr;
	}

	GameObject::~GameObject()
	{
		_noStartComponents.Reset();
		while (true)
		{
			auto com = _noStartComponents.Next();
			if (com == nullptr)
			{
				break;
			}
			delete com;
		}
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

	void GameObject::AddComponentInternal(Component* com)
	{
		_componentList.push_back(com);
	}

	void GameObject::RemoveComponent(Component * com)
	{
		for (int i = 0; i < _componentList.size(); i++)
		{
			if (_componentList[i] == com)
			{
				_componentList.erase(_componentList.begin() + i);
				break;
			}
		}
	}

	void GameObject::WorldStart(World* world)
	{
		for (int i = 0; i < _componentList.size(); i++)
		{
			_componentList[i]->GameObjectStart(this);
		}
		Start();
	}

	void GameObject::WorldUpdate(World* world)
	{
		for (int i = 0; i < _componentList.size(); i++)
		{
			_componentList[i]->GameObjectUpdate(this);
		}
		Update();
	}

	void GameObject::WorldEnd(World* world)
	{
		for (int i = 0; i < _componentList.size(); i++)
		{
			_componentList[i]->GameObjectEnd(this);
		}
		End();
	}
}