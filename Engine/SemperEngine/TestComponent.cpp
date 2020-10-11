#include "TestComponent.h"
#include <iostream>
#include "Debug.h"
#include <string>
#include <Windows.h>

namespace SemperEngine
{
	using namespace std;

	TestComponent::~TestComponent()
	{
	}

	void TestComponent::Start()
	{
		Debug::Log("Component Start");
	}

	void TestComponent::Update()
	{
		//auto es = SemperEngine::EventSystem::GetKeyEvents();

		//Vector3 moveDelt;
		//typedef SemperEngine::EventSystem EventSystem;
		//typedef SemperEngine::Event::Key Key;
		//typedef SemperEngine::Event::ButtonAction Action;
		//if (EventSystem::GetKeyAction(Key::up, InputAction::keep) || EventSystem::GetKeyAction(Key::w, InputAction::keep))
		//{
		//	moveDelt.y += Time::GetDeltaTime() * 10;
		//}
		//if (EventSystem::GetKeyAction(Key::down, InputAction::keep) || EventSystem::GetKeyAction(Key::s, InputAction::keep))
		//{
		//	moveDelt.y -= Time::GetDeltaTime() * 10;
		//}
		//if (EventSystem::GetKeyAction(Key::left, InputAction::keep) || EventSystem::GetKeyAction(Key::a, InputAction::keep))
		//{
		//	moveDelt.x -= Time::GetDeltaTime() * 10;
		//}
		//if (EventSystem::GetKeyAction(Key::right, InputAction::keep) || EventSystem::GetKeyAction(Key::d, InputAction::keep))
		//{
		//	moveDelt.x += Time::GetDeltaTime() * 10;
		//}
		//_gameObject->GetTransform()->position = _gameObject->GetTransform()->position + moveDelt;

		//if (EventSystem::GetKeyAction(Key::p, InputAction::press))
		//{
		//	auto a = TEXT("ƒ„∫√ ¿ΩÁ");
		//	Debug::Log(a);
		//	Debug::Log(1 / Time::GetDeltaTime());
		//}
	}

	void TestComponent::End()
	{
		Debug::Log("Component End");
	}
}