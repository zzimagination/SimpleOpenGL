#pragma once
#include <vector>
#include "BuildInData.h"
#include "Camera.h"
#include "GameObject.h"

using namespace std;

class World
{
public:
	
	string name;

	Camera* camera;

	vector<GameObject*> gameObjects;

	~World();

	void AddGameObject(GameObject* gameObject);

	void RemoveGameObject(GameObject* gameObject);

	void Live();

private:

	bool isStart;

	void CheckingGameObject(GameObject* gameObject);
};

