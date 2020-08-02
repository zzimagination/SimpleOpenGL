#pragma once
#include <vector>
#include "Camera.h"
#include "GameObject.h"

using namespace std;

class World
{
public:
	
	string name;

	Camera* camera;

	vector<GameObject*> newGameObjects;

	vector<GameObject*> gameObjects;

	~World();

	void AddGameObject(GameObject* gameObject);

	void RemoveGameObject(GameObject* gameObject);

	void Live();

private:

	bool isStart;

};

