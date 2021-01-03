#include "TestWorldAction.h"
#include "Event.h"
#include "Debug.h"
#include "Cube.h"
#include "WorldController.h"

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
		else if (Event::KeyAction(Keyboard::Key::number3, InputAction::Button::press))
		{
			Debug::LogError("aaaa");
		}
	}
	void TestWorldAction::End()
	{
	}
}