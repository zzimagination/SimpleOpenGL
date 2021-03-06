#include "InsideWorldAction.h"
#include "Debug.h"
#include "Event.h"
#include "GameSetting.h"
#include "RenderSetting.h"

namespace Semper
{
	InsideWorldAction::~InsideWorldAction()
	{
	}

	void InsideWorldAction::Start()
	{
	}

	void InsideWorldAction::Update()
	{
		if (Event::KeyAction(Keyboard::Key::f1, InputAction::Button::press))
		{
			Debug::Log("hello world");
		}
		if (Event::KeyAction(Keyboard::Key::f2, InputAction::Button::press))
		{
			RenderSetting::SetWireframeMode(!RenderSetting::wireframe);
		}
	}

	void InsideWorldAction::End()
	{
	}
}