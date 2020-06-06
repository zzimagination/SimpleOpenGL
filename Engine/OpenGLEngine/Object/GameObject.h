#pragma once
#include <string>
#include <vector>
#include "../Math/Mathz.h"
#include "../Component/Components.h"


using namespace glm;
using namespace std;

class World;

class GameObject
{

public:
	struct Transform
	{

	public:
		vec3 position;

		vec3 eulerAngle;

		quat rotation;

		vec3 scale;

		mat4 GetModelMatrix();
	};
public:

	Transform transform;

	string name;

	vector<Component*> components;

	GameObject();

	~GameObject();

	GameObject(string name);

	void AddComponent(Component* com);

	void RemoveComponent(Component* com);

	void Start();

	void Update();

private:

	bool _isStart;

	void Start_Internal();

	void Update_Internal();

private:

	friend class World;
};

