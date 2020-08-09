#include "GameObject.h"

class Player :public GameObject
{
public:
	
	Player();

	Player(string name);

	~Player();

	virtual void Start() override;

	virtual void Update() override;

	virtual void OnDestory() override;

public:

	float times;

	float color;

private:

};
