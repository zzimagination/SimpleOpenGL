#include "InsideWorldAction.h"
#include "Debug.h"
#include "Event.h"


namespace SemperEngine
{
	using namespace Core;
	void InsideWorldAction::Start()
	{
		Debug::Log("Start Inside World");
	}
	void InsideWorldAction::Update()
	{
		if (Event::KeyAction(Keyboard::Key::number1, InputAction::Button::press))
		{
			Debug::Log(count);
			count++;
		}

	}
	void InsideWorldAction::End()
	{
		Debug::Log("End Inside World");
	}
}