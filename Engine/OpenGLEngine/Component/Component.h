#pragma once

class GameObject;

class Component
{
public:

	GameObject* gameObject;

	virtual void Start();

	virtual void Update();

	virtual Component* GetType();
};

