#pragma once
#ifndef WORLD_SCRIPT
#define WORLD_SCRIPT

#include <vector>
#include "GameObjectCollection.h"
#include "ObjectCollection.h"


namespace SemperEngine {

	class Camera;

	class GameObject;

	namespace Core
	{
		class WorldStorageCenter;
	}

	class World
	{

		typedef Collection::ObjectCollection<GameObject> GameObjectList;

	public:

		Camera* camera;

	protected:

		std::string _name;

		bool _isActive;

		GameObjectList _startedList;

		GameObjectList _noStartList;

	public:

		World(std::string name);

		~World();

		std::string Name();

		virtual void AddGameObject(GameObject* gameObject) = 0;

		virtual void RemoveGameObject(GameObject* gameObject) = 0;

		bool IsActive();

	protected:

		virtual void Active();

		virtual void UnActive();

		virtual void Start() = 0;

		virtual void Update() = 0;

		virtual void End() = 0;

	};

}

#endif // !WORLD_SCRIPT
