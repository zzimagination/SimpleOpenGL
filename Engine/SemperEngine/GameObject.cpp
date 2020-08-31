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

	int GameObject::ComponentCount()
	{

		return _noStartComponents.Size() + _startedComponents.Size();
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
		switch (_myState)
		{
		case GameObjectState::EG_Start:
		case GameObjectState::EG_Ending:
		case GameObjectState::EG_Update:
			_startedComponents.Add(com);
			com->GameObjectStart(this);
			return;
		case GameObjectState::EG_Ended:
			_noStartComponents.Add(com);
			return;
		default:
			break;
		}
	}

	void GameObject::RemoveComponent(Component * com)
	{
		switch (_myState)
		{
		case GameObjectState::EG_Start:
		case GameObjectState::EG_Ending:
			if (_noStartComponents.Contain(com))
			{
				_noStartComponents.Remove(com);
			}
			else if (_startedComponents.Contain(com))
			{
				_startedComponents.Remove(com);
				com->GameObjectEnd(this);
			}
			else
			{
				throw "don't have this component";
			}
		case GameObjectState::EG_Update:
			_startedComponents.Remove(com);
			com->GameObjectEnd(this);
			return;
		case GameObjectState::EG_Ended:
			_noStartComponents.Remove(com);
			return;
		default:
			return;
		}
	}

	void GameObject::WorldStart(World* world)
	{
		_myState = GameObjectState::EG_Start;
		myWorld = world;
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
		_myState = GameObjectState::EG_Update;
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
		_myState = GameObjectState::EG_Ending;
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
		myWorld = nullptr;
		_myState = GameObjectState::EG_Ended;
	}
}