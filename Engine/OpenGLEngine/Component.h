#ifndef COMPONENT
#define COMPONENT

class GameObject;

class Component
{
public:

	GameObject* gameObject;

protected:

public:

	virtual void Start() = 0;

	virtual void Update() = 0;

};

#endif // !COMPONENT


