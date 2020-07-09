#include "GameObject.h"

class Player :public GameObject
{
public:
	
	Player();

	Player(string name);

	~Player();

	virtual void Start();

	virtual void Update();

private:

};
