#include "GameObject.h"
#include "Component.h"
#include "World.h"
#include <iostream>

void GameObject::Destory(GameObject* gameObjcet)
{
	gameObjcet->myWorld->RemoveGameObject(gameObjcet);
	gameObjcet->OnDesory_Internal();
	gameObjcet->OnDestory();
	delete gameObjcet;
}


GameObject::GameObject()
{
	name = "New GameObject";
	transform = new Transform();
}

GameObject::GameObject(string name): name(name)
{
	transform = new Transform();
}

GameObject::~GameObject()
{
	for (int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
}

void GameObject::Start()
{
}

void GameObject::Update()
{
}

void GameObject::OnDestory()
{
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

void GameObject::OnDesory_Internal()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->OnDestory();
	}
}



