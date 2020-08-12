#include "BaseRenderPipeline.h"
#include "Mathz.h"
#include "GameLoop.h"
#include "WorldManager.h"
#include "GameInit.h"
#include "GameWindow.h"
#include "FrameRuntime.h"
#include "CompletedSignal.h"
#include "GraphicRender.h"
#include "RenderBatchManager.h"
#include <thread>

bool GameLoop::isLooping = true;

CompletedSignal GameLoop::mainSignal;

CompletedSignal GameLoop::logicSignal;

void GameLoop::BeforeLoop()
{
	GameInit::Init();
	isLooping = true;
}

void GameLoop::MainLoop()
{
	thread logic(LogicLoop);

	while (isLooping) 
	{
		if (GameWindow::WindowShouldClose())
		{
			break;
		}

		FrameRuntime::BeginFrame();
		GameWindow::PollWindowEvent();

		
		GraphicRender::Render();
		GameWindow::SwapFrameBuffers();

		logicSignal.Wait();

		RenderBatchManager::SwapBuffer();
		FrameRuntime::EndFrame();

		mainSignal.Send();
	}

	logic.join();
}

void GameLoop::LogicLoop()
{
	
	while (isLooping)
	{
		if (GameWindow::WindowShouldClose())
		{
			break;
		}

		
		WorldManager::LiveWorld();
		BaseRenderPipeline::Render();

		logicSignal.Send();
		mainSignal.Wait();
	}
}
