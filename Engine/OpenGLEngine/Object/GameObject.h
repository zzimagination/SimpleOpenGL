#pragma once
#include <string>
#include <vector>
#include "../Math/Mathz.h"

using namespace glm;
using namespace std;

class Component;

class GameObject
{
public:

	virtual void Start();

	virtual void Update();

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

	void Start_Internal();

	void Update_Internal();

	void StartObject();

	bool IsStart();

private:

	bool _isStart;

};

