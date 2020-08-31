#pragma once
#ifndef WORLD_SCRIPT
#define WORLD_SCRIPT

#include <vector>
#include "GameObjectCollection.h"

namespace SemperEngine {

	class Camera;

	class GameObject;

	class WorldManager;

	using namespace std;



	class World
	{
	private:

		enum class WorldState
		{
			EW_UnActive,

			EW_Active,

			EW_Loading,

			EW_Unloading
		} ;

	public:

		string name;

		Camera* camera;

	private:

		WorldState _myState;

		GameObjectCollection _startedGameObjects;

		GameObjectCollection _nostartGameObjects;

	public:

		~World();

		void AddGameObject(GameObject* gameObject);

		void RemoveGameObject(GameObject* gameObject);

	private:

		void Active();

		void UnActive();

		void Update();

		friend class WorldManager;

	};

}

#endif // !WORLD_SCRIPT
