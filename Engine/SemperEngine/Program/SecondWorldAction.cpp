#include "SecondWorldAction.h"
#include "WorldManager.h"
#include "Event.h"
#include "Debug.h"

namespace SemperEngine
{
	SecondWorldAction::~SecondWorldAction()
	{
	}
	void SecondWorldAction::Start()
	{
	}
	void SecondWorldAction::Update()
	{
		if (Event::KeyAction(Keyboard::Key::number1, InputAction::Button::press))
		{
			Core::WorldManager::SetActive(1);
		}
	}
	void SecondWorldAction::End()
	{
	}
}