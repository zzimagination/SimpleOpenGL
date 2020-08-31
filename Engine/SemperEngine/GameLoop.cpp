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
#include "DebugSystem.h"
#include "Debug.h"
#include <string>

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
				loopSignal.Send(Exit);
				break;
			}
			else
			{
				loopSignal.Send();
			}

			FrameRuntime::BeginFrame();
			GameWindow::PollWindowEvent();
			EventSystem::ProcessEvent();

			mainSignal.Send();

			GraphicRender::Render();
			GameWindow::SwapFrameBuffers();

			logicSignal.Wait();

			EventSystem::EndEvents();
			RenderBatchManager::SwapBatches();
			FrameRuntime::EndFrame();
		}
		logic.join();
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

			WorldManager::UpdateWorld();
			BaseRenderPipeline::Render();
			
			logicSignal.Send();
		}
	}

	bool GameLoop::ExitLoop()
	{
		bool isExit = GameWindow::WindowShouldClose();
		_isLooping = !isExit;
		return isExit;
	}
}