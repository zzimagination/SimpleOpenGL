#pragma once
#include <string>
#include <vector>
#include "Transform.h"
#include "Mathz.hpp"

using namespace glm;
using namespace std;

class Component;

class GameObject
{
public:

	virtual void Start();

	virtual void Update();

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

