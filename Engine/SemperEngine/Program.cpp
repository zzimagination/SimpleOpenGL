#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ�ļ����ų�����ʹ�õ�����
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