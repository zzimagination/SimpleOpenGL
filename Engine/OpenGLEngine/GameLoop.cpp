#include "BaseRenderPipeline.h"
#include "Mathz.h"
#include "GameLoop.h"
#include "WorldManager.h"
#include "GameInit.h"
#include "GameWindow.h"
#include "FrameRuntime.h"

bool GameLoop::isLooping = true;

void GameLoop::BeforeLoop()
{
	GameInit::Init();
	isLooping = true;
}

void GameLoop::MainLoop()
{
	while (isLooping) 
	{
		if (GameWindow::WindowShouldClose())
		{
			break;
		}
		GameWindow::PollWindowEvent();
		FrameRuntime::BeginFrame();
		WorldManager::LiveWorld();
		BaseRenderPipeline::Render();
		FrameRuntime::EndFrame();
		GameWindow::SwapFrameBuffers();
	}
}
