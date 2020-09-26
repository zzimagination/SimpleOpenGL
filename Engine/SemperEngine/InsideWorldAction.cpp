#include "InsideWorldAction.h"
#include "Debug.h"
#include "EventSystem.h"


namespace SemperEngine
{

	void InsideWorldAction::Start()
	{
		Debug::Log("Start Inside World");
	}
	void InsideWorldAction::Update()
	{
		if (EventSystem::GetKeyAction(Keyboard::Key::number1, InputAction::Button::press))
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