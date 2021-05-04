#include "SecondWorldAction.h"
#include "WorldManager.h"
#include "Event.h"
#include "Debug.h"
#include "Resource.h"

namespace Semper
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

		}
		else if (Event::KeyAction(Keyboard::Key::number2, InputAction::Button::press))
		{
		}
	}
	void SecondWorldAction::End()
	{
	}
}