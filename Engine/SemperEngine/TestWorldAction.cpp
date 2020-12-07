#include "TestWorldAction.h"
#include "WorldManager.h"
#include "Event.h"
#include "Debug.h"
#include "RenderSetting.h"
#include <TextureLib.h>

namespace SemperEngine
{
	TestWorldAction::~TestWorldAction()
	{
	}
	void TestWorldAction::Start()
	{
	}
	void TestWorldAction::Update()
	{
		if (Event::KeyAction(Keyboard::Key::number1, InputAction::Button::press))
		{
			Core::WorldManager::SetActive(2);
		}
	}
	void TestWorldAction::End()
	{
	}
}