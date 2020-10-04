#include "SecondWorldAction.h"
#include "WorldManager.h"
#include "Event.h"
#include "Debug.h"

namespace SemperEngine
{
	void SecondWorldAction::Start()
	{
		Debug::Log("Start Second World");
	}
	void SecondWorldAction::Update()
	{
		if (Event::KeyAction(Keyboard::Key::number2, InputAction::Button::press))
		{
			WorldManager::SetActive(1);
		}
	}
	void SecondWorldAction::End()
	{
		Debug::Log("End Second World");
	}
}