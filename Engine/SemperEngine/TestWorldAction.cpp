#include "TestWorldAction.h"
#include "WorldManager.h"
#include "GameObjectCreator.h"
#include "Event.h"
#include "Debug.h"

namespace SemperEngine
{
	void TestWorldAction::Start()
	{
		Debug::Log("Start Test World");
	}
	void TestWorldAction::Update()
	{
		if (Event::KeyAction(Keyboard::Key::number2, InputAction::Button::press))
		{
			WorldManager::SetActive(2);
		}
		else if(Event::KeyAction(Keyboard::Key::number3, InputAction::Button::press))
		{
			mid = GameObjectCreator::Create(new GameObject());
		}
		else if (Event::KeyAction(Keyboard::Key::number4, InputAction::Button::press))
		{
			GameObjectCreator::Destory(mid);
		}
	}
	void TestWorldAction::End()
	{
		Debug::Log("End Test World");
	}
}