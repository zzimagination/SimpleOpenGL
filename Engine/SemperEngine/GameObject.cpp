#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "World.h"

namespace SemperEngine {

	using namespace std;

	GameObject::GameObject() :GameObject("New GameObject")
	{
	}

	GameObject::GameObject(string name)
	{
		this->name = name;
		_transform = new Transform();
	}

	GameObject::~GameObject()
	{
		delete _transform;
		_startedComponents.Reset();
		while (true)
		{
			auto com = _startedComponents.Next();
			if (com == nullptr)
			{
				break;
			}
			delete com;
		}
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


	void GameObject::AddComponent(Component* com)
	{
		_componentList.push_back(com);
		if (_isStart)
		{
			_startedComponents.Add(com);
			com->GameObjectStart(this);
		}
		else
		{
			_noStartComponents.Add(com);
		}
	}

	Component * GameObject::GetComponent(const std::type_info & type)
	{
		for (int i = 0; i < _componentList.size(); i++)
		{
			if (typeid(*_componentList[i]) == type)
			{
				return _componentList[i];
			}
		}
		return nullptr;
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
		if (_isStart)
		{
			_startedComponents.Remove(com);
			com->GameObjectEnd(this);
		}
		else
		{
			_noStartComponents.Remove(com);
		}
	}

	Transform * GameObject::GetTransform()
	{
		return _transform;
	}

	void GameObject::WorldStart(World* world)
	{
		_isStart = true;
		_noStartComponents.Reset();
		while (true)
		{
			auto com = _noStartComponents.Next();
			if (com == nullptr)
			{
				break;
			}
			_noStartComponents.Remove(com);
			_startedComponents.Add(com);
			com->GameObjectStart(this);
		}
		Start();
	}

	void GameObject::WorldUpdate(World* world)
	{
		_startedComponents.Reset();
		while (true)
		{
			auto com = _startedComponents.Next();
			if (com == nullptr)
			{
				break;
			}
			com->GameObjectUpdate(this);
		}
		Update();
	}

	void GameObject::WorldEnd(World* world)
	{
		_startedComponents.Reset();
		while (true)
		{
			auto com = _startedComponents.Next();
			if (com == nullptr)
			{
				break;
			}
			_startedComponents.Remove(com);
			_noStartComponents.Add(com);
			com->GameObjectEnd(this);
		}
		End();
		_isStart = false;
	}
}