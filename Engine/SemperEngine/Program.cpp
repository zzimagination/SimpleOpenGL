#include"pch.h"
#include "GameWindow.h"
#include "GameStart.h"
#include "GameEnd.h"
#include "GameLoop.h"
#include "DebugSystem.h"
#include <fstream>

using namespace SemperEngine;

int main()
{
	//Test::UnitTesting();
	Core::GameStart::Start();
	Core::GameLoop::BeforeLoop();
	Core::GameLoop::MainLoop();
	Core::GameLoop::AfterLoop();
	Core::GameEnd::End();

	return 0;
}