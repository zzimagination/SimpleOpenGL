#include "TestWorldAction.h"
#include "Event.h"
#include "Debug.h"
#include "Cube.h"
#include "WorldController.h"
#include "Resource.h"

namespace SemperEngine
{
	using namespace std;

	TestWorldAction::~TestWorldAction()
	{
	}
	void TestWorldAction::Start()
	{
	}

	void TestWorldAction::Update()
	{
		if (Event::KeyAction(Keyboard::Key::number1, InputAction::Button::press))
		{
			WorldController::SetActive("second");
		}
	}
	void TestWorldAction::End()
	{
	}
}