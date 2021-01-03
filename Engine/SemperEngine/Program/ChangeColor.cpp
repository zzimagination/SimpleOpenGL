#include "ChangeColor.h"
#include "GameObject.h"
#include "Cube.h"
#include "Event.h"

void ChangeColor::Update()
{
	if (Event::KeyAction(Keyboard::Key::number2, InputAction::Button::release))
	{
		material->AddProperty("_color", color);
		if (color.R() == 1)
		{
			color = Color::ColorFloat(0, 0, 0);
		}
		else
		{
			color = Color::ColorFloat(1, 1, 1);
		}
	}
}
