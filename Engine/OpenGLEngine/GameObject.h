#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <string>
#include <vector>
#include "Transform.h"
#include "Mathz.h"
#include <typeinfo>

using namespace std;

class Component;

class GameObject
{
public:

	virtual void Start();

	virtual void Update();

public:

	string name;

	Transform transform;

	vector<Component*> components;

public:

	GameObject();

	GameObject(string name);

	~GameObject();

	void AddComponent(Component* com);

	void RemoveComponent(Component* com);

	template<typename T>
	T GetComponent() {
		for (int i = 0; i < components.size(); i++)
		{
			if ((T)(components[i]) != nullptr)
			{
				return (T)components[i];
			}
		}
		throw "don't have component";
	}

	void Start_Internal();

	void Update_Internal();

private:

};


#endif // !GAMEOBJECT
