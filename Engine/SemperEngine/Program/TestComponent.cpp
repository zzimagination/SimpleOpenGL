#include "TestComponent.h"
#include "Debug.h"
#include "Event.h"
#include "WorldController.h"
#include "Cube.h"

namespace Semper
{
	using namespace std;

	TestComponent::~TestComponent()
	{
	}

	void TestComponent::Start()
	{
	}

	void TestComponent::Update()
	{
		if (Event::KeyAction(Keyboard::Key::number4, InputAction::Button::press))
		{
			auto cube = new Cube();
			cube->transform.position = Float3(0, y, 0);
			WorldController::AddGameObject(cube);
			objects.push_back(cube);
			y++;
		}
		else if (Event::KeyAction(Keyboard::Key::number5, InputAction::Button::press))
		{
			if (objects.size() > 0)
			{
				delete* (objects.end() - 1);
				objects.pop_back();
				y--;
			}
		}
	}

}