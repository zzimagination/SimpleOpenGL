#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
#include "Program/GameProject.h"

using namespace Semper::Core;

int main()
{
	GameStart::Start();
	GameLoop::BeforeLoop();
	GameLoop::MainLoop();
	GameLoop::AfterLoop();
	GameEnd::End();
	return 0;
}