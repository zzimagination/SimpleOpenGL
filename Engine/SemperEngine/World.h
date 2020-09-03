#pragma once
#ifndef WORLD_SCRIPT
#define WORLD_SCRIPT

#include <vector>
#include "GameObjectCollection.h"

namespace SemperEngine {

	using namespace std;

	class Camera;

	class GameObject;

	namespace Core
	{
		class WorldStorageCenter;
	}

	class World
	{
	protected:

		enum class WorldState
		{
			EW_UnActive,

			EW_Active,

			EW_Loading,

			EW_Unloading
		};

	public:

		Camera* camera;

	protected:

		string _name;

		WorldState _myState;

		GameObjectCollection _startedGameObjects;

		GameObjectCollection _nostartGameObjects;

		std::vector<GameObject*> _gameObjectList;

	public:

		World(std::string name);

		~World();

		std::string Name();

		virtual void AddGameObject(GameObject* gameObject) = 0;

		virtual void RemoveGameObject(GameObject* gameObject) = 0;

		vector<GameObject*> GameObjectList();

	protected:

		virtual void Active() = 0;

		virtual void UnActive() = 0;

		virtual void Start() = 0;

		virtual void Update() = 0;

		virtual void End() = 0;

	};

}

#endif // !WORLD_SCRIPT
