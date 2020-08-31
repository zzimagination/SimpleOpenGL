#include "World.h"
#include "Camera.h"
#include "GameObject.h"

namespace SemperEngine {

	World::~World()
	{
		_nostartGameObjects.Reset();
		while (true)
		{
			auto obj = _nostartGameObjects.Next();
			if (obj == nullptr)
			{
				break;
			}
			delete obj;
		}
	}

	void World::AddGameObject(GameObject * gameObject)
	{
		switch (_myState)
		{
		case WorldState::EW_UnActive:
			_nostartGameObjects.Add(gameObject);
			break;
		case WorldState::EW_Active:
			_startedGameObjects.Add(gameObject);
			gameObject->WorldStart(this);
			break;
		case WorldState::EW_Loading:
		case WorldState::EW_Unloading:
			_startedGameObjects.Add(gameObject);
			gameObject->WorldStart(this);
			break;
		default:
			break;
		}
	}

	void World::RemoveGameObject(GameObject * gameObject)
	{
		switch (_myState)
		{
		case WorldState::EW_UnActive:
			_nostartGameObjects.Remove(gameObject);
			return;
		case WorldState::EW_Active:
			_startedGameObjects.Remove(gameObject);
			gameObject->WorldEnd(this);
			return;
		case WorldState::EW_Loading:
		case WorldState::EW_Unloading:
			if (_startedGameObjects.Contain(gameObject))
			{
				gameObject->WorldEnd(this);
				_startedGameObjects.Remove(gameObject);
			}
			else if (_nostartGameObjects.Contain(gameObject))
			{
				_nostartGameObjects.Remove(gameObject);
			}
			else
			{
				throw "don't has this gameObject";
			}
			return;
		default:
			return;
		}
	}

	void World::Active()
	{
		_myState = WorldState::EW_Loading;
		_nostartGameObjects.Reset();
		while (true)
		{
			auto obj = _nostartGameObjects.Next();
			if (obj == nullptr)
			{
				break;
			}
			_nostartGameObjects.Remove(obj);
			_startedGameObjects.Add(obj);
			obj->WorldStart(this);
		}
		_nostartGameObjects.Clear();
	}

	void World::UnActive()
	{
		_myState = WorldState::EW_Unloading;
		_startedGameObjects.Reset();
		while (true)
		{
			auto obj = _startedGameObjects.Next();
			if (obj == nullptr)
			{
				break;
			}
			_startedGameObjects.Remove(obj);
			_nostartGameObjects.Add(obj);
			obj->WorldEnd(this);
		}
		_startedGameObjects.Clear();
		_myState = WorldState::EW_UnActive;
	}

	void World::Update()
	{
		_myState = WorldState::EW_Active;
		_startedGameObjects.Reset();
		while (true)
		{
			auto obj = _startedGameObjects.Next();
			if (obj == nullptr)
			{
				break;
			}
			obj->WorldUpdate(this);
		}
	}
}