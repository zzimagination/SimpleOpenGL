#pragma once
#include "../Object/GameObject.h"

class Component
{
public:

	GameObject* gameObject;

	virtual void Start();

	virtual void Update();

	virtual Component* GetType();
};

