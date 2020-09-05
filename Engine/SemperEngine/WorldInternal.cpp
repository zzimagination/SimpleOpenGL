#include "WorldInternal.h"
#include "Camera.h"
#include "GameObject.h"
#include "ObjectCollection.h"

namespace SemperEngine
{
	namespace Core
	{
		WorldInstance::WorldInstance(std::string name) :World(name)
		{

		}

		WorldInstance::~WorldInstance()
		{
		}

		void WorldInstance::AddGameObject(GameObject * gameObject)
		{
			if (_isStart)
			{
				_startedList.Add(gameObject);
				gameObject->WorldStart(this);
			}
			else
			{
				_noStartList.Add(gameObject);
			}
		}

		void WorldInstance::RemoveGameObject(GameObject * gameObject)
		{
			if (_isStart)
			{
				if (_startedList.Contain(gameObject))
				{
					_startedList.Remove(gameObject);
					gameObject->WorldEnd(this);
					return;
				}
				else if (_noStartList.Contain(gameObject))
				{
					_noStartList.Remove(gameObject);
					return;
				}
			}
			else
			{
				_noStartList.Remove(gameObject);
				return;
			}
			throw "don't have this gameObject";
		}

		void WorldInstance::Start()
		{
			_isStart = true;
			_noStartList.Reset();
			while (true)
			{
				auto gameObject = _noStartList.Next();
				if (gameObject == nullptr)
				{
					break;
				}
				_noStartList.Remove(gameObject);
				_startedList.Add(gameObject);
				gameObject->WorldStart(this);
			}
		}

		void WorldInstance::Update()
		{
			_startedList.Reset();
			while (true)
			{
				auto gameObject = _startedList.Next();
				if (gameObject == nullptr)
				{
					break;
				}
				gameObject->WorldUpdate(this);
			}
		}

		void WorldInstance::End()
		{
			_startedList.Reset();
			while (true)
			{
				auto gameObject = _startedList.Next();
				if (gameObject == nullptr)
				{
					break;
				}
				gameObject->WorldEnd(this);
				_startedList.Remove(gameObject);
				_noStartList.Add(gameObject);
			}
			_isStart = false;
		}
	}
}
