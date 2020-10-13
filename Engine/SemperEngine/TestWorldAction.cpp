#include "TestWorldAction.h"
#include "WorldManager.h"
#include "GameObjectCreator.h"
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
		Debug::Log("Start Test World");
		auto file = TextureLib::TextureResource::Load("Resources/Textures/test.png");
		file.width;
	}
	void TestWorldAction::Update()
	{
		if (Event::KeyAction(Keyboard::Key::number2, InputAction::Button::press))
		{
			WorldManager::SetActive(2);
		}
	}
	void TestWorldAction::End()
	{
		Debug::Log("End Test World");
	}
}