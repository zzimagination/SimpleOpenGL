#include "GameLoop.h"
#include <thread>
#include "Mathz.h"
#include "Debug.h"
#include "WorldLoop.h"
#include "GameWindow.h"
#include "EventManager.h"
#include "FrameRuntime.h"
#include "BaseRenderPipeline.h"
#include "ResourceObjectLoop.h"
#include "GraphicManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		bool GameLoop::_isLooping = true;

		CompletedSignal GameLoop::loopSignal;

		CompletedSignal GameLoop::mainSignal;

		CompletedSignal GameLoop::logicSignal;

		void GameLoop::BeforeLoop()
		{
			WorldLoop::BeforeLoop();
			ResourceObjectLoop::BeforeLoop();
			BaseRenderPipeline::Render();
			GraphicManager::Resource();
			GraphicManager::SwapCommands();
			_isLooping = true;
		}

		void GameLoop::MainLoop()
		{
			thread logic(LogicLoop);
			while (_isLooping)
			{
				/*检测是否继续循环*/
				if (IsExitLoop())
				{
					loopSignal.SendAll(Exit);
					break;
				}
				else
				{
					loopSignal.SendAll();
				}
				/*帧前处理*/
				FrameRuntime::Begin();
				GameWindow::PollWindowEvent();

				/*发送开始命令*/
				mainSignal.SendAll();

				/*主线程执行*/
				GraphicManager::Render();
				GameWindow::SwapFrameBuffers();

				/*等待其他线程执行完毕*/
				logicSignal.Wait();

				/*帧后处理*/
				GraphicManager::Resource();
				GraphicManager::SwapCommands();
				FrameRuntime::End();
			}
			logic.join();
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
				EventManager::ProcessEvent();
				WorldLoop::Loop();
				ResourceObjectLoop::Loop();
				BaseRenderPipeline::Render();
				EventManager::EndEvents();
				/*发送完毕命令*/
				logicSignal.Send();
			}
		}

		void GameLoop::AfterLoop()
		{
			WorldLoop::AfterLoop();
			ResourceObjectLoop::AfterLoop();
			GraphicManager::Dispose();
		}

		bool GameLoop::IsExitLoop()
		{
			bool isExit = GameWindow::WindowShouldClose();
			_isLooping = !isExit;
			return isExit;
		}
	}
}