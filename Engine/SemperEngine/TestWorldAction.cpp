#include "TestWorldAction.h"
#include "Debug.h"
#include "EventSystem.h"
#include "WorldManager.h"
#include "GameObjectCreator.h"


namespace SemperEngine
{
	TestWorldAction::TestWorldAction(World world) :WorldAction(world)
	{
	}
	void TestWorldAction::Start()
	{
		Debug::Log("Start Test World");
	}
	void TestWorldAction::Update()
	{
		if (EventSystem::GetKeyAction(Keyboard::Key::number2, InputAction::Button::press))
		{
			WorldManager::SetActive(2);
		}
		else if(EventSystem::GetKeyAction(Keyboard::Key::number3, InputAction::Button::press))
		{
			mid = GameObjectCreator::Create(new GameObject("Start"));
		}
		else if (EventSystem::GetKeyAction(Keyboard::Key::number4, InputAction::Button::press))
		{
			GameObjectCreator::Destory(mid);
		}
	}
	void TestWorldAction::End()
	{
		Debug::Log("End Test World");
	}
}