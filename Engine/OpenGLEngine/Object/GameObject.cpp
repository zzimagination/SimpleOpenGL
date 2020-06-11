#include "GameObject.h"
#include "../Component/Component.h"
#include <iostream>


void GameObject::Start()
{
	cout << "start" << endl;
}

void GameObject::Update()
{

}

GameObject::GameObject()
{
	transform.rotation.w = 1;
	transform.rotation.x = 0;
	transform.rotation.y = 0;
	transform.rotation.z = 0;

	transform.scale = vec3(1);

}

GameObject::~GameObject()
{
	for (int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
}

GameObject::GameObject(string name)
{
	this->name = name;
	transform.rotation.w = 1;
	transform.rotation.x = 0;
	transform.rotation.y = 0;
	transform.rotation.z = 0;

	transform.scale = vec3(1);
}

void GameObject::AddComponent(Component* com)
{
	com->gameObject = this;
	components.push_back(com);
}

void GameObject::RemoveComponent(Component * com)
{
	for (auto i = components.begin(); i != components.end(); i++)
	{
		if (*i == com)
		{
			delete com;
			components.erase(i);
		}
	}
}

void GameObject::Start_Internal()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Start();
	}
}

void GameObject::Update_Internal()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Update();
	}
}

void GameObject::StartObject()
{
	_isStart = true;
}

bool GameObject::IsStart()
{
	return _isStart;
}

mat4 GameObject::Transform::GetModelMatrix()
{
	mat4 model = mat4(1);
	model = glm::scale(model, scale);
	model = glm::rotate(model, radians(eulerAngle.x), vec3(1, 0, 0));
	model = glm::rotate(model, radians(eulerAngle.y), vec3(0, 1, 0));
	model = glm::rotate(model, radians(eulerAngle.z), vec3(0, 0, 1));
	model = glm::translate(model, position);
	return model;
}
