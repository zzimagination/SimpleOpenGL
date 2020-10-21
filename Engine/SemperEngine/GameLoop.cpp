#include "GameLoop.h"
#include <thread>
#include <iostream>
#include <string>
#include "Mathz.h"
#include "Debug.h"
#include "WorldLoop.h"
#include "GameWindow.h"
#include "EventManager.h"
#include "FrameRuntime.h"
#include "BaseRenderPipeline.h"
#include "GraphicCommandManager.h"
#include "ResourceManager.h"
#include "LogoPipeline.h"

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
			BaseRenderPipeline::Render();
			GraphicCommandManager::Resource();
			GraphicCommandManager::SwapCommands();
			_isLooping = true;
		}

		void GameLoop::MainLoop()
		{
			thread logic(LogicLoop);
			while (_isLooping)
			{
				/*����Ƿ����ѭ��*/
				if (ExitLoop())
				{
					loopSignal.Send(Exit);
					break;
				}
				else
				{
					loopSignal.Send();
				}
				/*֡ǰ����*/
				FrameRuntime::BeginFrame();
				GameWindow::PollWindowEvent();

				/*���Ϳ�ʼ����*/
				mainSignal.Send();

				/*���߳�ִ��*/
				GraphicCommandManager::Render();
				GameWindow::SwapFrameBuffers();

				/*�ȴ������߳�ִ�����*/
				logicSignal.Wait();

				/*֡����*/
				GraphicCommandManager::Resource();
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
				/*����Ƿ����ѭ��*/
				if (loopSignal.Wait() == Exit)
				{
					break;
				}
				/*�ȴ���ʼ����*/
				mainSignal.Wait();

				/*������Ϸ�߼�*/
				EventManager::ProcessEvent();
				WorldLoop::Loop();
				BaseRenderPipeline::Render();
				EventManager::EndEvents();

				/*�����������*/
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