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
				/*����Ƿ����ѭ��*/
				if (IsExitLoop())
				{
					loopSignal.SendAll(Exit);
					break;
				}
				else
				{
					loopSignal.SendAll();
				}
				/*֡ǰ����*/
				FrameRuntime::Begin();
				GameWindow::PollWindowEvent();

				/*���Ϳ�ʼ����*/
				mainSignal.SendAll();

				/*���߳�ִ��*/
				GraphicManager::Render();
				GameWindow::SwapFrameBuffers();

				/*�ȴ������߳�ִ�����*/
				logicSignal.Wait();

				/*֡����*/
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
				ResourceObjectLoop::Loop();
				BaseRenderPipeline::Render();
				EventManager::EndEvents();
				/*�����������*/
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