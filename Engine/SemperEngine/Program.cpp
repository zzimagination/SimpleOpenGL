#include"pch.h"
#include "GameStart.h"
#include "GameEnd.h"
#include "GameLoop.h"

using namespace SemperEngine::Core;

int main()
{
	GameStart::Start();
	GameLoop::BeforeLoop();
	GameLoop::MainLoop();
	GameLoop::AfterLoop();
	GameEnd::End();
	return 0;
}