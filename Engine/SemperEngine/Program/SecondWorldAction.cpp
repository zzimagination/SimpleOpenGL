#include "SecondWorldAction.h"
#include "WorldManager.h"
#include "Event.h"
#include "Debug.h"
#include "Resource.h"

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
		else if (Event::KeyAction(Keyboard::Key::number2, InputAction::Button::press))
		{
			Resource::DisposeUnuse();
		}
	}
	void SecondWorldAction::End()
	{
	}
}