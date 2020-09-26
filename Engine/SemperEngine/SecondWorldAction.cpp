#include "SecondWorldAction.h"
#include "Debug.h"
#include "EventSystem.h"
#include "WorldManager.h"

namespace SemperEngine
{
	void SecondWorldAction::Start()
	{
		Debug::Log("Start Second World");
	}
	void SecondWorldAction::Update()
	{
		if (EventSystem::GetKeyAction(Keyboard::Key::number2, InputAction::Button::press))
		{
			WorldManager::SetActive(1);
		}
	}
	void SecondWorldAction::End()
	{
		Debug::Log("End Second World");
	}
}