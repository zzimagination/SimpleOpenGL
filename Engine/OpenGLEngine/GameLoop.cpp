#include "GameLoop.h"
#include "BaseRenderPipeline.h"
#include "Mathz.h"
#include "WorldManager.h"
#include "GameInit.h"
#include "GameWindow.h"
#include "FrameRuntime.h"
#include "GraphicRender.h"
#include "RenderBatchManager.h"
#include "EventSystem.h"
#include <thread>
#include <iostream>

namespace SemperEngine {
	bool GameLoop::_isLooping = true;

	CompletedSignal GameLoop::loopSignal;

	CompletedSignal GameLoop::mainSignal;

	CompletedSignal GameLoop::logicSignal;

	void GameLoop::BeforeLoop()
	{
		GameInit::Init();
		_isLooping = true;
	}

	void GameLoop::MainLoop()
	{
		thread logic(LogicLoop);
		while (_isLooping)
		{
			if (ExitLoop())
			{
				logic.join();
				break;
			}
			loopSignal.Send();

			FrameRuntime::BeginFrame();
			GameWindow::PollWindowEvent();
			EventSystem::ProcessEvent();

			mainSignal.Send();

			GraphicRender::Render();
			GameWindow::SwapFrameBuffers();

			logicSignal.Wait();

			EventSystem::EndEvents();
			RenderBatchManager::SwapBuffer();
			FrameRuntime::EndFrame();
		}

	}

	void GameLoop::LogicLoop()
	{
		while (_isLooping)
		{
			if (loopSignal.Wait() == Exit)
			{
				break;
			}

			mainSignal.Wait();
			WorldManager::LiveWorld();
			BaseRenderPipeline::Render();

			logicSignal.Send();
		}
	}

	bool GameLoop::ExitLoop()
	{
		bool isExit = GameWindow::WindowShouldClose();
		_isLooping = !isExit;
		if (isExit) {
			loopSignal.Send(Exit);
		}
		return isExit;
	}
}