#include "GameLoop.h"
#include <thread>
#include "Debug.h"
#include "GameWindow.h"
#include "FrameManager.h"
#include "EventSystem.h"
#include "WorldSystem.h"
#include "GraphicSystem.h"
#include "ResourceSystem.h"
#include "Render/Pipeline/RenderPipeline.h"

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
			WorldSystem::BeforeLoop();
			ResourceSystem::BeforeLoop();
			RenderPipeline::PreRender();
			//GraphicSystem::Resource();
			//GraphicSystem::SwapCommands();
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
				FrameManager::Begin();
				GameWindow::PollWindowEvent();

				/*���Ϳ�ʼ����*/
				mainSignal.SendAll();

				/*���߳�ִ��*/
				GraphicSystem::Render();
				GameWindow::SwapFrameBuffers();

				/*�ȴ������߳�ִ�����*/
				logicSignal.Wait();

				/*֡����*/
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
				/*����Ƿ����ѭ��*/
				if (loopSignal.Wait() == Exit)
				{
					break;
				}
				/*�ȴ���ʼ����*/
				mainSignal.Wait();

				/*������Ϸ�߼�*/
				EventSystem::ProcessEvent();
				WorldSystem::Loop();
				ResourceSystem::Loop();
				RenderPipeline::Render();
				EventSystem::EndEvents();
				/*�����������*/
				logicSignal.Send();
			}
		}

		void GameLoop::AfterLoop()
		{
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
	}
}