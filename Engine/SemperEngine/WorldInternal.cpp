#include "WorldInternal.h"
#include "Camera.h"
#include "GameObject.h"

namespace SemperEngine
{
	namespace Core
	{
		WorldInternal::WorldInternal(std::string name) :World(name)
		{
		}

		WorldInternal::~WorldInternal()
		{
		}

		void WorldInternal::AddGameObject(GameObject * gameObject)
		{
			_gameObjectList.push_back(gameObject);
		}

		void WorldInternal::RemoveGameObject(GameObject * gameObject)
		{
		}

		void WorldInternal::Active()
		{
		}

		void WorldInternal::UnActive()
		{
		}

		void WorldInternal::Start()
		{
			for (int i = 0; i < _gameObjectList.size(); i++)
			{
				_gameObjectList[i]->WorldStart(this);
			}
		}

		void WorldInternal::Update()
		{
			for (int i = 0; i < _gameObjectList.size(); i++)
			{
				_gameObjectList[i]->WorldUpdate(this);
			}
		}

		void WorldInternal::End()
		{
			for (int i = 0; i < _gameObjectList.size(); i++)
			{
				_gameObjectList[i]->WorldEnd(this);
			}
		}
	}
}
