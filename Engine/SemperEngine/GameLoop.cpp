#include "GameLoop.h"
#include <thread>
#include <iostream>
#include <string>
#include "Mathz.h"
#include "Debug.h"
#include "WorldLoop.h"
#include "GameWindow.h"
#include "EventSystem.h"
#include "FrameRuntime.h"
#include "GraphicRender.h"
#include "BaseRenderPipeline.h"
#include "GraphicCommandManager.h"
#include "VertexDataCenter.h"

namespace SemperEngine {

	namespace Core {

		bool GameLoop::_isLooping = true;

		CompletedSignal GameLoop::loopSignal;

		CompletedSignal GameLoop::mainSignal;

		CompletedSignal GameLoop::logicSignal;

		void GameLoop::BeforeLoop()
		{
			WorldLoop::BeforeLoop();
			BaseRenderPipeline::Render();
			GraphicCommandManager::SwapCommands();
			_isLooping = true;
		}

		void GameLoop::MainLoop()
		{
			thread logic(LogicLoop);
			while (_isLooping)
			{
				/*检测是否继续循环*/
				if (ExitLoop())
				{
					loopSignal.Send(Exit);
					break;
				}
				else
				{
					loopSignal.Send();
				}
				/*帧前处理*/
				FrameRuntime::BeginFrame();
				GameWindow::PollWindowEvent();
				/*发送开始命令*/
				mainSignal.Send();
				/*主线程执行*/

				GraphicRender::Render();
				GameWindow::SwapFrameBuffers();
				/*等待其他线程执行完毕*/
				logicSignal.Wait();
				/*帧后处理*/

				GraphicCommandManager::SwapCommands();
				FrameRuntime::EndFrame();
			}
			logic.join();
		}

		void GameLoop::AfterLoop()
		{
			WorldLoop::AfterLoop();
		}

		void GameLoop::LogicLoop()
		{
			while (_isLooping)
			{
				/*检测是否继续循环*/
				if (loopSignal.Wait() == Exit)
				{
					break;
				}
				/*等待开始命令*/
				mainSignal.Wait();
				/*处理游戏逻辑*/
				EventSystem::ProcessEvent();
				WorldLoop::Loop();
				BaseRenderPipeline::Render();
				VertexDataCenter::UnloadNoUse();
			
				EventSystem::EndEvents();
				/*发送完毕命令*/
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
}