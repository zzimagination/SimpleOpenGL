#include "GameLoop.h"
#include <thread>
#include "Debug.h"
#include "GameWindow.h"
#include "FrameManager.h"
#include "EventSystem.h"
#include "WorldSystem.h"
#include "ResourceSystem.h"
#include "Render/RenderPipeline.h"
#include "Graphic/GraphicSystem.h"
#include "ProjectState.h"

namespace Semper
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
			if (Skip())
			{
				return;
			}

			ProjectState::state = ProjectState::State::Loop;
			WorldSystem::BeforeLoop();
			ResourceSystem::BeforeLoop();
			RenderPipeline::PreRender();
			_isLooping = true;
		}

		void GameLoop::MainLoop()
		{
			if (Skip())
			{
				return;
			}

			thread logic(LogicLoop);
			while (_isLooping)
			{
				/*检测是否继续循环*/
				if (IsExitLoop())
				{
					loopSignal.SendAll(CompletedSignal::WaitCode::Exit);
					break;
				}
				else
				{
					loopSignal.SendAll();
				}
				/*帧前处理*/
				FrameManager::Begin();
				GameWindow::PollWindowEvent();

				/*发送开始命令*/
				mainSignal.SendAll();

				/*主线程执行*/
				GraphicSystem::Render();
				GameWindow::SwapFrameBuffers();

				/*等待其他线程执行完毕*/
				logicSignal.Wait();

				/*帧后处理*/
				GraphicSystem::Resource();
				GraphicSystem::SwapCommands();
				FrameManager::End();
			}
			logic.join();
		}

		void GameLoop::LogicLoop()
		{
			while (_isLooping)
			{
				/*检测是否继续循环*/
				if (loopSignal.Wait() == CompletedSignal::WaitCode::Exit)
				{
					break;
				}
				/*等待开始命令*/
				mainSignal.Wait();

				/*处理游戏逻辑*/
				EventSystem::ProcessEvent();
				WorldSystem::Loop();
				ResourceSystem::Loop();
				RenderPipeline::Render();
				EventSystem::EndEvents();
				/*发送完毕命令*/
				logicSignal.Send();
			}
		}

		void GameLoop::AfterLoop()
		{
			if (Skip())
			{
				return;
			}
			WorldSystem::AfterLoop();
			ResourceSystem::AfterLoop();
			GraphicSystem::Dispose();
		}

		bool GameLoop::IsExitLoop()
		{
			bool isExit = GameWindow::WindowShouldClose();
			_isLooping = !isExit;
			return isExit;
		}
		bool GameLoop::Skip()
		{
			if (ProjectState::close)
			{
				return true;
			}
			return false;
		}
	}
}