#include "ChangeTexture.h"
#include "Event.h"

void ChangeTexture::Update()
{
	if (Event::KeyAction(Keyboard::Key::number2, InputAction::Button::release))
	{
		auto data = texture->GetColors();
		for (int i = 0; i < (int)data.Size(); i += 4)
		{
			data[i] = color.R32();
			data[i + 1] = color.G32();
			data[i + 2] = color.B32();
		}
		color = Color::ColorFloat(color.R() - 0.2f, color.G() - 0.2f, color.B() - 0.2f);
		if (color.R() < 0)
		{
			color = Color();
		}
		texture->SetColors(data);
	}
}
