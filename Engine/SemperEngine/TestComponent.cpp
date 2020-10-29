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
	}

	void TestComponent::End()
	{
		Debug::Log("Component End");
	}
}