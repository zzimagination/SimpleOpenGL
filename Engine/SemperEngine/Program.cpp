#include"pch.h"

int main()
{
	GameStart::Start();
	GameLoop::BeforeLoop();
	GameLoop::MainLoop();
	GameLoop::AfterLoop();
	GameEnd::End();
	return 0;
}