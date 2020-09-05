#include "TestComponent.h"
#include <iostream>
#include "Debug.h"
#include <string>
#include <Windows.h>

using namespace SemperEngine;

void TestComponent::Start()
{
}

void TestComponent::Update()
{
	auto es = SemperEngine::EventSystem::GetKeyEvents();

	Vector3 moveDelt;
	typedef SemperEngine::EventSystem EventSystem;
	typedef SemperEngine::Event::Key Key;
	typedef SemperEngine::Event::ButtonAction Action;
	if (EventSystem::GetKeyAction(Key::up, Action::keep) || EventSystem::GetKeyAction(Key::w, Action::keep))
	{
		moveDelt.y += Time::GetDeltaTime() * 10;
	}
	if (EventSystem::GetKeyAction(Key::down, Action::keep) || EventSystem::GetKeyAction(Key::s, Action::keep))
	{
		moveDelt.y -= Time::GetDeltaTime() * 10;
	}
	if (EventSystem::GetKeyAction(Key::left, Action::keep) || EventSystem::GetKeyAction(Key::a, Action::keep))
	{
		moveDelt.x -= Time::GetDeltaTime() * 10;
	}
	if (EventSystem::GetKeyAction(Key::right, Action::keep) || EventSystem::GetKeyAction(Key::d, Action::keep))
	{
		moveDelt.x += Time::GetDeltaTime() * 10;
	}
	gameObject->GetTransform()->position = gameObject->GetTransform()->position + moveDelt;

	if (EventSystem::GetKeyAction(Key::p, Action::press))
	{
		auto a = TEXT("ƒ„∫√ ¿ΩÁ");
		Debug::Log(a);
		Debug::Log(1 / Time::GetDeltaTime());
	}
	
}

void TestComponent::End()
{
	
}
